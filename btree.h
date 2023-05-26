/* 	Garrett Jennings | ZID: z1927185
	Binary Tree Assignment
	CS340 - 3
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <cstdlib>       //rand, srand

typedef enum {left_side, right_side } SIDE;

SIDE rnd(){ 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

template <typename T> class BinaryTree{

public:

    BinaryTree(){                                      // default constructor
        size = 0;
        root = nullptr;
    }

    unsigned getSize() const {                                // returns size of tree
        return size;
    }

    unsigned getHeight() const {                          // returns height of tree
        if (root == nullptr) return 0;                  // If the tree is empty, return 0
        else return _getHeight(root);
    }

    virtual void Insert(const T& data){                     // inserts node in tree
        _Insert(root, data);
        size++;
    }
    void Inorder(void (*print) (const T&) ){          // inorder traversal of tree
        _Inorder(root, print);
    }

protected:
    Node<T> *root;                                      // root of tree
    unsigned int size;

private:

    unsigned _getSize(Node<T> *) const{                 // private version of getSize()
        return size;
    }

    unsigned _getHeight(Node<T> *inode) const {               // private version of getHeight()
        if (inode->left == nullptr && inode->right == nullptr) return 1;    // Base case: A leaf will have no branches and thusly a height of 1

        unsigned int left, right;
        if (inode->left != nullptr) left = _getHeight(inode->left) + 1;
        else left = 0;
        if (inode->right != nullptr) right = _getHeight(inode->right) + 1;
        else right = 0;

        if (left > right) return left;  // A parent will have a height one more than the max height between its two children
        else return right; 
        return 0;
    }

    void _Insert(Node<T> *&cnode, const T& data){             // private version of Insert()
        if (cnode == nullptr) { cnode = new Node<T>(data); return; }    // Base case: the current node is a nullptr;
        if (!rnd() /* rnd() returns 0 for left, 1 for right*/ ) { _Insert(cnode->left, data); } // LEFT SIDE
        else { _Insert(cnode->right, data); }  // RIGHT SIDE
    }

    void _Inorder(Node<T> *cnode, void (*print)(const T&)){   // private version of Inorder()
        if (cnode == nullptr) return;
        if (cnode->left != nullptr) _Inorder(cnode->left, print);
        print (cnode->data);
        if (cnode->right != nullptr) _Inorder(cnode->right, print);
    }
};

#endif // End of H_BTREE
