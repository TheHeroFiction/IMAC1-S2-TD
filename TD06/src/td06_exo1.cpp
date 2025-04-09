#include "td06_exo1.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) 
{
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) 
{
    pretty_print_left_right(node, "", true);
}

//debut TD06 ex01 (1)
Node* create_node(int value)
{
    Node* new_node {new Node{.value = value, .left = nullptr, .right = nullptr} };
    return new_node;
}
//fin TD06 ex01 (1)

//debut TD06 ex01 (2)
bool Node::is_leaf() const
{
    if (Node::left == nullptr && Node::right == nullptr)
    {
        return true;
    }
    return false;
}
//fin TD06 ex01 (2)

//debut TD06 ex01 (3)
void Node::insert(int value)
{
    Node* new_node {create_node(value)};
    if (is_leaf())
    {
        if (Node::value > value)
        {
            Node::left = new_node;
        }
        else
        {
            Node::right = new_node;
        }
    }
    else 
    {
        if(Node::value > value)
        {
            if(Node::left == nullptr)
            {
                Node::left = new_node;
            }
            else
            {
                Node::left->insert(value);
            }
        }
        else
        {
            if(Node::right == nullptr)
            {
                Node::right = new_node;
            }
            else
            {
                Node::right->insert(value);
            }
        }
    }
}
//fin TD06 ex01 (3)

//debut TD06 ex01 (4)
int Node::height() const
{
    if (is_leaf())
    {
        return 1;
    }
    else
    {
        if (Node::left == nullptr)
        {
            return Node::right->height() + 1;
        }
        else if (Node::right == nullptr)
        {
            return Node::left->height() + 1;
        }
        else
        {
            if (Node::left->height() > Node::right->height())
            {
                return Node::left->height() + 1;
            }
            else 
            {
                return Node::right->height() + 1;
            }
        }
    }
}
//fin TD06 ex01 (4)

//debut TD06 ex01 (5)
void Node::delete_children()
{
    if (Node::left->is_leaf())
    {
        delete Node::left;
        Node::left = nullptr;
    }
    else 
    {
        Node::left->delete_children();
        delete Node::left;
        Node::left = nullptr;
    }

    if (Node::right->is_leaf())
    {
        delete Node::right;
        Node::right = nullptr;
    }
    else
    {
        Node::right->delete_children();
        delete Node::right;
        Node::right = nullptr;
    }
}
//fin TD06 ex01 (5)

//debut TD06 ex01 (6)
void Node::display_infix() const
{
    if (is_leaf())
    {
        std::cout << " " << Node::value << " " << std::endl;
    }
    else
    {
        if (Node::left != nullptr)
        {
            Node::left->display_infix();
        }
        std::cout << " " << Node::value << " " << std::endl;
        if (Node::right != nullptr)
        {
            Node::right->display_infix();
        }
    }
}
//fin TD06 ex01 (6)

//debut TD06 ex01 (7)
std::vector<Node const*> Node::prefix() const
{
    std::vector<Node const*> vec {};
    Node const* new_node {create_node(Node::value)};
    vec.push_back(new_node);
    if (!(is_leaf()))
    {
        if(Node::left != nullptr)
        {
            auto left_nodes {Node::left->prefix()};
            vec.insert(vec.end(), left_nodes.begin(), left_nodes.end());
        }
        if(Node::right != nullptr)
        {
            auto right_nodes {Node::right->prefix()};
            vec.insert(vec.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    return vec;
}
//fin TD06 ex01 (7)

//debut TD06 ex01 (8)
void Node::display_postfix() const
{
    if (Node::left != nullptr)
    {
        Node::left->display_infix();
    }
    if (Node::right != nullptr)
    {
        Node::right->display_infix();
    }
    std::cout << " " << Node::value << " " << std::endl;
    
}
//fin TD06 ex01 (8)

//debut TD06 ex01 (9)
Node*& most_left(Node*& node)
{
    if(node->left != nullptr)
    {
        most_left(node->left);
    }
    else
    {
        return node;
    }
}
//fin TD06 ex01 (9)

//debut TD06 ex01 (10) A TERMINER
bool remove(Node*& node, int value)
{
    if (value == node->value) 
    {
        if (node->is_leaf())
        {
            // On supprime le nœud courant
            delete node;
            // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
            // Ainsi le parent du nœud courant aura un pointeur vers nullptr
            node = nullptr;
            // on retourne true car la suppression a été effectuée
            return true;
        }
        else 
        {
            if (node->left != nullptr || node->right != nullptr)
            {
                if(node->left != nullptr)
                {
                    node->value = node->left->value;
                    
                }
                else
                {
                    node->value = node->right->value;
                }
                node->delete_children();
            }
            else
            {
                Node*& replace_node {most_left(node)};
                node->value = replace_node->value;
                if (replace_node->is_leaf())
                {
                    delete replace_node;
                    replace_node = nullptr;
                }
                
            }
        } 
    }
    else
    {
        
    }
}
//fin TD06 ex01 (10)