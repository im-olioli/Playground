#pragma once

#include <string>

#include "../Array/Array.h"

class Node
{
public:
    std::string name;
    Node* parent;
    Array<Node*> children;

    Node(std::string name, Node* parent);
    ~Node();
    Array<Node*> find_node_in_offspring(std::string name);
};