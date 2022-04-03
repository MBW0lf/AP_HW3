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
std::ostream& operator<<(std::ostream& os,BST::Node &node)
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
size_t bst_length(BST::Node *node)
{
    if (node == nullptr)
        return 0;
    else
        return(bst_length(node->left) + 1 + bst_length(node->right));
}
size_t BST::length()
{
    if (root->left == nullptr and root->right == nullptr)
        return 1;
    else
        return(1 + bst_length(root->left) + bst_length(root->right));
}
std::ostream& operator<(std::ostream& os,BST::Node *node)
{
    os << node;
    os << "       => value:" << node->value;
    if(node->value < 10)
        os<< " ";
    os << "        left:" << node->left;
    if(node->left == nullptr)
        os<< "        ";
    os << "        right:" << node->right<<std::endl; 
    if(node->left)
        std::cout < node->left;
    if(node->right)
        std::cout < node->right;  
    return os;    
}
std::ostream& operator<<(std::ostream& os,BST bst)
{
    os << "********************************************************************************" << std::endl;
    os << bst.get_root();
    os << "       => value:" << bst.get_root()->value;
    os << "        left:" << bst.get_root()->left;
    os << "        right:" << bst.get_root()->right<<std::endl;
    if(bst.get_root()->left)
        std::cout < bst.get_root()->left;
    if(bst.get_root()->right)
        std::cout < bst.get_root()->right;
    os << "binary search tree size: " << bst.length() << std::endl;
    os << "********************************************************************************" << std::endl;
    return os;
}
BST::Node** BST::find_node(int value)
{
    Node** root_1 {&root};
    while(1)
    {
        if((*root_1)->value > value)
        {
            if((*root_1)->left)
                root_1 = &(*root_1)->left; 
            else
                return nullptr;  
        }
        else if((*root_1)->value < value)
        {
            if((*root_1)->right)
                root_1 = &(*root_1)->right; 
            else
                return nullptr;
        }
        else
            return root_1;
    }
}
BST::Node** BST::find_parrent(int value)
{
    Node** root_1 {&root};
    while(1)
    {
        if((*root_1)->value > value)
        {
            if((*root_1)->left)
                if((*root_1)->left->value == value)
                    return root_1; 
                else
                    root_1 = &(*root_1)->left;   
        }
        else if((*root_1)->value < value)
        {
            if((*root_1)->right)
                if((*root_1)->right->value == value)
                    return root_1; 
                else
                    root_1 = &(*root_1)->right; 
        }
        else
            return nullptr;
    }
}
BST::Node** BST::find_successor(int value)