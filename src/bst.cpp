#include "bst.h"

BST :: Node :: Node(int _value, Node* _left, Node* _right)
{
    value =  _value;
    left = _left;
    right = _right;
}
BST :: Node :: Node()
{
    value = 0;
    right = nullptr;
    left = nullptr;
}
BST :: Node :: Node(const Node& node)
{
    value = node.value;
    right = node.right;
    left = node.left;
}