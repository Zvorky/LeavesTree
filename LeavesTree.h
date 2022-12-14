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
        secondary data.
                            */



//  ===| Data Structure |===

template <typename key_type, typename data_type, typename secondary_type = bool>
struct Node{
    key_type          key;
    data_type       * data;
    secondary_type  * secondary_data;
    Node<key_type, data_type, secondary_type> * left, * right;

    //  Key only
    Node(key_type key = 0){
        this->key   = key;
    }

    //  Path Node
    Node(key_type key, secondary_type secondary_data){
        this->left  = NULL;
        this->right = NULL; 
        this->key   = key;
       *this->secondary_data = secondary_data;
    }

    //  Leaf
    Node(key_type key, data_type data, secondary_type secondary_data = NULL){
        this->key   = key;
        this->data  = new data_type;
       *this->data  = data;
        this->secondary_data = new secondary_type;
       *this->secondary_data = secondary_data;
    }

    //  Leaf with existent data
    Node(key_type key, data_type * data, secondary_type * secondary_data = NULL){
        this->key   = key;
        this->data  = data;
        this->secondary_data = secondary_data;
    }


    //  Add new data to right, by default.
    void add(data_type * data, bool add_right = true, secondary_type * secondary_data = NULL){
        if(!this){
            this = new Node<key_type, data_type, secondary_type>(0, data);
            return;
        }

        Node<key_type, data_type, secondary_type> * nav = this;

        if(add_right){
            //  Gets the right end leaf
            while(nav->right)
                nav = nav->right;
            
            //  Add new Leaf and copy older to left
            nav->right = new Node<key_type, data_type, secondary_type>(nav->key << 1 + 1, data);
            nav->left  = new Node<key_type, data_type, secondary_type>(nav->key << 1, nav->data);
            
        }else{
            //  Gets the left end leaf
            while(nav->left)
                nav = nav->left;
            
            //  Add new Leaf and copy older to right
            nav->left  = new Node<key_type, data_type, secondary_type>(nav->key << 1, data);
            nav->right = new Node<key_type, data_type, secondary_type>(nav->key << 1 + 1, nav->data);
        }

        //  Add the secondary data
        if(secondary_data)
            nav->secondary_data = secondary_data;
    }


    //  Add function overload for non-allocated data
    void add(data_type data, bool add_right = true, secondary_type secondary_data = NULL){
        data_type      * d = new data_type;
        secondary_type * s;

        d = data;

        if(secondary_data){
            s = new secondary_type;
            s = secondary_data;
            this->add(d, add_right, s);
            return;
        }
        this->add(d, add_right);
    }


    //  Delete this Node: the wrong way to remove a Node !
    bool deleva(){
        if(!this)   // I don't make sure if .remove() can be called from a null node, so...
            return false;
        
        if(this->left || this->right)
            return false; // You will not want to make his children orphans...
        
        delete this->data;
        delete this->secondary_data;
        delete this;

        return true;
    }


    //  Search and Remove
    //  ! incomplete !      ~ needs to rearrange non-removed
    bool remove(key_type key){
        if(!this)
            return false;
        
        if(this->left || this->right)
            return false; // You will not want to make his children orphans...
        
        Node<key_type, data_type, secondary_type> * nav = this;
        
        while(nav && key){
            if(key & 0b1)
                nav = nav->right;
            else
                nav = nav->left;
            key = key >> 1;
        }
        
        nav->deleva();
        return true;
    }


    //  Swap this Node with another
    bool swap(Node<key_type, data_type, secondary_type> * b){
        if(!this || !b)
            return false; // Can't swap with NULL, it would be a move()
        
        Node<key_type, data_type, secondary_type> * swap = * this;
        
        //  Swap keys
        swap->key   = b->key;
        b->key      = this->key;

        //  Swap pointers
        * this = * b;
        * b = swap;
        
        return true;
    }


    bool move(){}


    //  Returns the Node of the key
    Node<key_type, data_type, secondary_type> * search(key_type key){
        if(!this)
            return NULL;
        
        Node<key_type, data_type, secondary_type> * nav = this;
        
        while(nav && key){
            if(key & 0b1)
                nav = nav->right;
            else
                nav = nav->left;
            key = key >> 1;
        }
        
        return nav;
    }


    //  Removes a Node and returns a copy of it
    Node<key_type, data_type, secondary_type> pop(key_type key){
        if(!this)
            return NULL;
        
        Node<key_type, data_type, secondary_type> * nav = this;
        
        while(nav && key){
            if(key & 0b1)
                nav = nav->right;
            else
                nav = nav->left;
            key = key >> 1;
        }
        
        Node<key_type, data_type, secondary_type> node = nav;
        nav->deleva();
        return node;
    }
};