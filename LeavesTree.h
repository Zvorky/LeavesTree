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
    Non-Nodes Tree. At real
   it's a list of pairs that
    acts like a binary tree
                            */


#include <vector>


template <typename type>
struct Leaf{
    std::vector<bool> key;
    type data;  

    Leaf(Leaf(std::vector<bool> leaf_key, type leaf_data)){
        key  = leaf_key;
        data = leaf_data;
    }
};

template <typename type>
struct Tree{
    Leaf<type> * leaves = NULL;
};