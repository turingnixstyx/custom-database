#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

class Node {
   public:
    bool isLeaf;
    std::vector<int> keys;
    std::vector<Node *> children;

    Node(bool isLeaf);
};

#endif
