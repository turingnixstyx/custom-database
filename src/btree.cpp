#include "btree.hpp"
#include <iostream>

BTree::BTree(int t) : root(nullptr), t(t) {}

void BTree::traverse()
{
    if (root != nullptr)
        traverse(root);
}

Node *BTree::search(int key)
{
    return (root == nullptr) ? nullptr : search(root, key);
}

void BTree::insert(int key)
{
    if (root == nullptr)
    {
        root = new Node(true);
        root->keys.push_back(key);
    }
    else
    {
        if (root->keys.size() == 2 * t - 1)
        {
            Node *s = new Node(false);
            s->children.push_back(root);
            splitChild(s, 0, root);
            int i = 0;
            if (s->keys[0] < key)
                i++;
            insertNonFull(s->children[i], key);
            root = s;
        }
        else
        {
            insertNonFull(root, key);
        }
    }
}

void BTree::insertNonFull(Node *node, int key)
{
    int i = node->keys.size() - 1;
    if (node->isLeaf)
    {
        node->keys.push_back(0);
        while (i >= 0 && node->keys[i] > key)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    }
    else
    {
        while (i >= 0 && node->keys[i] > key)
            i--;
        if (node->children[i + 1]->keys.size() == 2 * t - 1)
        {
            splitChild(node, i + 1, node->children[i + 1]);
            if (node->keys[i + 1] < key)
                i++;
        }
        insertNonFull(node->children[i + 1], key);
    }
}

void BTree::splitChild(Node *parent, int i, Node *child)
{
    Node *z = new Node(child->isLeaf);
    z->keys.resize(t - 1);
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = child->keys[j + t];
    if (!child->isLeaf)
    {
        z->children.resize(t);
        for (int j = 0; j < t; j++)
            z->children[j] = child->children[j + t];
    }
    child->keys.resize(t - 1);
    parent->children.insert(parent->children.begin() + i + 1, z);
    parent->keys.insert(parent->keys.begin() + i, child->keys[t - 1]);
}

void BTree::traverse(Node *node)
{
    int i;
    for (i = 0; i < node->keys.size(); i++)
    {
        if (!node->isLeaf)
            traverse(node->children[i]);
        std::cout << " " << node->keys[i];
    }
    if (!node->isLeaf)
        traverse(node->children[i]);
}

Node *BTree::search(Node *node, int key)
{
    int i = 0;
    while (i < node->keys.size() && key > node->keys[i])
        i++;
    if (i < node->keys.size() && key == node->keys[i])
        return node;
    if (node->isLeaf)
        return nullptr;
    return search(node->children[i], key);
}
