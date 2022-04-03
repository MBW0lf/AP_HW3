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
    os << "adress of left: " << node.left << std::endl;
    os << "adress of right: " << node.right << std::endl;
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
BST::Node*& BST :: get_root()
{
    return root;
}
bool BST :: add_node(int value)
{
    Node* root_1 {root};
    if(root == nullptr)
    {
        root = new Node{value, nullptr, nullptr};
    }
    else
    {
        while(1)
        {
            if(root_1->value > value)
            {
                if(root_1->left == nullptr)
                {
                    root_1->left = new Node{value, nullptr, nullptr};
                    break;
                }
                else
                    root_1 = root_1->left; 
            }
            else if(root_1->value < value)
            {
                if(root_1->right == nullptr)
                {
                    root_1->right = new Node{value, nullptr, nullptr};
                    break;
                }
                else
                    root_1 = root_1->right; 
            }
            else
                return false;
        }
    }
    return true;
}
void BST::bfs(std::function<void(BST::Node*& node)> func) const
{
    std::list<Node*> queue;
    queue.push_back(root);
    while(!queue.empty())
    {
        auto node =  queue.front();
        queue.pop_front();
        func(node);
        if(node->left)
            queue.push_back(node->left);
        if(node->right)
            queue.push_back(node->right);
    }
}