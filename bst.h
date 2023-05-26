/* 	Garrett Jennings | ZID: z1927185
	Binary Search Tree Assignment
	CS340 - 3
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include "btree.h"

using namespace std;

#ifndef H_BST
#define H_BST

#define SEED 1      // seed for RNG
#define N 100       // num of rand ints

#define NO_ITEMS 16 // max num of elems printed in line
#define ITEM_W 3    // size of each elem in print

unsigned sz;        // size of vector/binTree

// macro to print size
#define COUT_SZ cout << "size = " << setw ( ITEM_W ) << sz << " :"

// class to generate rand ints
class RND {
private:
    int seed;   
public:
    RND ( const int& s = SEED ) : seed ( s ) { srand ( seed ); }
    int operator ( ) ( ) { return rand ( ) % N + 1; }
};

// function to print elems on stdout
template < typename T > void print ( const T& x )
{
    static unsigned cnt = 0;
    const string sp ( 12, ' ' );

    cout << setw ( ITEM_W ) << x << ' '; cnt++;
    if ( cnt % NO_ITEMS == 0 || cnt == sz ) cout << endl << sp;
    if ( cnt == sz ) cnt = 0;
}

template <typename T> class BinarySearchTree : public BinaryTree<T>
{
    public:
        void Insert(const T &x);       // inserts node with value x
        bool Search(const T &x) const; // searches leaf with value x
        bool Remove(const T &x);       // removes leaf with value x
    private:
        void _Insert(Node<T> *&, const T &);      // private version of insert
        bool _Search(Node<T> *, const T &) const; // private version of search
        void _Remove(Node<T> *&, const T &);      // private version of remove
        bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

#endif
