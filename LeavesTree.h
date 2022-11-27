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
};


template <typename key_type, typename secundary_type = void>
struct Node : Key<key_type>{
    Key<key_type> * left = NULL, * right = NULL;
    secundary_type data;
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


//  ! incomplete !
template <typename key_type, typename data_type>
bool add(Leaf<key_type, data_type> root, data_type data, bool add_at_right = true){
    if(!root)
        return false;
    
    key_type key = (root.key << 1) + 1 && add_at_right;
    
    Leaf<key_type, data_type> * a = root;
    
}