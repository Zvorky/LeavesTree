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
     Main data goes always
        in the Leaves.

        Other Nodes are
     suposed to have only
    addresses and optional
        secundary data.
                            */



template <typename key_type, typename data_type, typename secundary_type>
struct Node{
    key_type          key;
    data_type       * data;
    secundary_type  * secundary_data;
    Node<key_type, data_type, secundary_type> * left, * right;

    //  Key only
    Node(key_type key = 0){
        this->key   = key;
    }

    //  Path Node
    Node(key_type key, secundary_type secundary_data){
        this->left  = NULL;
        this->right = NULL; 
        this->key   = key;
       *this->secundary_data = secundary_data;
    }

    //  Leaf
    Node(key_type key, data_type data, secundary_type secundary_data = NULL){
        this->key   = key;
        this->data  = new data_type;
       *this->data  = data;
        this->secundary_data = new secundary_type;
       *this->secundary_data = secundary_data;
    }
};



// template <typename key_type, typename data_type, typename secundary_type>
// Node<key_type, data_type, secundary_type> * search(Node<key_type, data_type, secundary_type> * root, key_type key){
//     if(!root)
//         return NULL;
    
//     Node<key_type, data_type, secundary_type> * nav = root;
//     while(nav && key){
//         if(key && 0b1)
//             nav = nav->right;
//         else
//             nav = nav->left;
//         key = key >> 1;
//     }
    
//     return nav;
// }


// //  Create new Leaf beside another
// //  ! incomplete !
// template <typename key_type, typename data_type, typename secundary_type>
// bool add(Node<key_type, data_type, secundary_type> * node, data_type data, secundary_type node_data = NULL, bool add_at_right = true){
//     if(!node){
//         node = new Node<key_type, data_type, secundary_type>(0, data);
//         return true;
//     }

//     key_type key = node->key << 1;
//     Node<key_type, data_type, secundary_type> * nav = node;

//     if(add_at_right){

//         //  I think it gonna except, a Leaf dont have 'right'
//         //  Make sure its at the
//         while(nav->right){
//             // key = key << 1 + 1;
//             nav = nav->right;
//         }
        
//         Node<key_type, data_type, secundary_type> * existent;
//         * existent = * nav->right;
//         nav = nav->right;

//         //  A new Node get the position
//         nav = new Node<key_type, data_type, secundary_type>(nav->right->key, node_data);

//         //  Existent Leaf assumes its new position
//         nav->left = existent;
//         existent->key = existent->key << 1;

//         //  Finally, the new Leaf
//         nav->right = new Node<key_type, data_type, secundary_type>(nav->key << 1 + 1, data);
        
//         return true;
//     // // It needs optimization
//     // }else{
//     //     while(nav->left){
//     //         nav = nav->left;
//     //     }
//     }

//     return false;
// }


// template <typename key_type, typename data_type, typename secundary_type>
// bool swap(Node<key_type, data_type, secundary_type> * a, Node<key_type, data_type, secundary_type> * b){
//     if(!a || !b)
//         return false; // Can't swap with NULL, it would be a move()
    
//     Node<key_type, data_type, secundary_type> * swap = * a;
    
//     swap->key   = b->key;
//     b->key      = a->key;

//     * a = * b;
//     * b = swap;
    
//     return true;
// }