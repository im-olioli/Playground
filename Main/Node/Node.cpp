#include "Node.h"

#include <utility>

Node::Node(std::string name, Node* parent)
{
    this->name = std::move(name);
    this->parent = parent;
    
    if(parent != nullptr) this->parent->children.push_back(this);
}

Node::~Node() = default;

Array<Node*> Node::find_node_in_offspring(std::string find_name)
{
    Array<Node*> found;

    for (size_t i = 0; i < children.size(); i++)
    {
        if(children[i]->name == find_name) found.push_back(children[i]);

        Array<Node*> child_find = children[i]->find_node_in_offspring(find_name);

        for (size_t x = 0; x < child_find.size(); x++)
        {
            found.push_back(child_find[x]);
        }
    }
    
    return found;
}