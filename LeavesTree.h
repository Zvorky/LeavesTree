//  LeavesTree.h
//  Prototype 0.0

/* ─                     · ─ +
 |  Enzo Zavorski Delevatti  |
 .  @Zvorky                  ·
             ___,
          .~´    `-,
         /  _    _ \.        .
        ,\`|_|''|_|´\
 .       /          /)       |
        (\  ,    , .\`
 |       `) ;`,; `,^,)
         ´,´  `,  `  `
        
 |__ _  November  2022    _  |
/                           */

/*
    A Binary Tree...

           ...but:
      Nodes contains just
    addresses and optionall
        secundary data.
    
    Main data goes always
        in the Leaves.
                            */



template <typename key_type>
struct Key{
    key_type key;
    Key(key_type k){
        key = k;
    }
};


template <typename key_type, typename data_type>
struct Leaf : Key<key_type>{
    data_type data = 0;

    Leaf(key_type key) : Key<key_type>(key){}
};


template <typename key_type, typename secundary_type = void>
struct Node : Key<key_type>{
    Key<key_type> * left = NULL, * right = NULL;
    secundary_type data = NULL;

    Node(key_type key){
        this->key = key;
    }
};



template <typename key_type, typename data_type>
Leaf<key_type, data_type> * search(Node<key_type> * root, key_type key){
    if(!root)
        return NULL;
    
    Node<key_type> * nav = root;
    while(nav && key){
        if(key && 0b1)
            nav = nav->right;
        else
            nav = nav->left;
        key = key >> 1;
    }
    
    return nav;
}


//  Create new Leaf beside another
//  ! incomplete !
template <typename key_type, typename data_type, typename secundary_type = void>
bool add(Key<key_type> * node, data_type data, secundary_type node_data = NULL, bool add_at_right = true){
    if(!node){
        node = new Leaf<key_type, data_type>(node->key);
        node.data = data;
        return true;
    }

    key_type key = node->key << 1;
    Node<key_type> * nav = node;

    if(add_at_right){

        //  I think it gonna except, a Leaf dont have 'right'
        //  Make sure its at the
        while(nav->right){
            // key = key << 1 + 1;
            nav = nav->right;
        }
        
        Leaf<key_type, data_type> * existent = * nav->right;
        nav = nav->right;

        //  A new Node get the position
        nav = new Node<key_type, secundary_type>(nav->right->key);
        nav.data = node_data;

        //  Existent Leaf assumes its new position
        nav->left = existent;
        existent->key = existent->key << 1;

        //  Finally, the new Leaf
        nav->right = new Leaf<key_type, data_type>(nav->key << 1 + 1);
        nav->right->data = data;
        
        return true;
    // // It needs optimization
    // }else{
    //     while(nav->left){
    //         nav = nav->left;
    //     }
    }
}


template <typename key_type, typename data_type>
bool swap(Leaf<key_type, data_type> * a, Leaf<key_type, data_type> * b){
    if(!a || !b)
        return false; // Can't swap with NULL, it would be a move()
    
    Leaf<key_type, data_type> * swap = * a;
    
    swap->key   = b->key;
    b->key      = a->key;

    * a = * b;
    * b = swap;
    
    return true;
}