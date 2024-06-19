#ifndef BTREE_HPP
#define BTREE_HPP

#include "node.hpp"

class BTree {
   public:
    BTree(int t);
    void traverse();
    Node *search(int key);
    void insert(int key);

   private:
    Node *root;
    int t;  // Minimum degree
    void insertNonFull(Node *node, int key);
    void splitChild(Node *parent, int i, Node *child);
    void traverse(Node *node);
    Node *search(Node *node, int key);
};

#endif  // BTREE_HPP
