#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "bst.h"
#include "btree.h"
template<typename T>
void BinarySearchTree<T>::Insert(const T &x){       // inserts node with value x
    _Insert(BinarySearchTree<T>::root, x);
}
template<typename T>
bool BinarySearchTree<T>::Search(const T &x) const{ // searches leaf with value x
    return _Search(BinarySearchTree<T>::root, x);
}
template<typename T>
bool BinarySearchTree<T>::Remove(const T &x){       // removes leaf with value x
    if (Search(x)){ 
        _Remove(BinarySearchTree<T>::root, x);
        return true;
    }

    return false;
}

template<typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&cnode, const T &data){      // private version of insert
    if (cnode == nullptr) { BinarySearchTree<T>::size++; cnode = new Node<T>(data); return; }    // Base case: the current node is a nullptr;
    else if (cnode->data == data) return; // Discard duplicates
    else if (data < cnode->data) { _Insert(cnode->left, data); } // LEFT SIDE
    else { _Insert(cnode->right, data); }  // RIGHT SIDE
}
template<typename T>
bool BinarySearchTree<T>::_Search(Node<T> *cnode, const T &data) const { // private version of search
    if (cnode == nullptr) return false;
    else if (cnode->data == data) return true;
    else if (data < cnode->data) return _Search(cnode->left, data);
    else return _Search(cnode->right, data);
}
template<typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&cnode, const T &data){      // private version of remove
    if ( _Leaf(cnode) ) {
        BinarySearchTree<T>::size--;
        delete cnode;
        cnode = nullptr;
        return; 
    }
    else if (data == cnode->data) return;
    else if (data < cnode->data) { _Remove(cnode->left, data); }
    else { _Remove(cnode->right, data); }
}
template<typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const{          // checks if node is leaf
    if (node->right == nullptr && node->left == nullptr) return true;
    return false;
}

#endif
