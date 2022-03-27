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
std::ostream& operator<<(std::ostream& os,BST::Node node)
{
    os << "adress of node: " << &node << std::endl;
    os << "adress of left: " << &node.left << std::endl;
    os << "adress of right: " << &node.right << std::endl;
    os << "value: " << node.value;
    return os;
}
bool operator<(int _value,BST::Node node)
{
    if(_value < node.value)
        return true;
    return false;
}
bool operator<(BST::Node node,int _value)
{
    if(node.value < _value)
        return true;
    return false;
}
bool operator>(int _value,BST::Node node)
{
    if(_value > node.value)
        return true;
    return false;
}
bool operator>(BST::Node node,int _value)
{
    if(node.value > _value)
        return true;
    return false;
}
bool operator<=(int _value,BST::Node node)
{
    if(_value <= node.value)
        return true;
    return false;
}
bool operator<=(BST::Node node,int _value)
{
    if(node.value <= _value)
        return true;
    return false;
}
bool operator>=(int _value,BST::Node node)
{
    if(_value >= node.value)
        return true;
    return false;
}
bool operator>=(BST::Node node,int _value)
{
    if(node.value >= _value)
        return true;
    return false;
}
bool operator==(int _value,BST::Node node)
{
    if(_value == node.value)
        return true;
    return false;
}
bool operator==(BST::Node node,int _value)
{
    if(node.value == _value)
        return true;
    return false;
}