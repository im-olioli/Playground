#include <iostream>

#include "Node/Node.h"

int main(int argc, char* argv[])
{
    auto root = Node("root", nullptr);
    auto child1 = Node("child", &root);
    auto child2 = Node("child1", &root);
    auto child3 = Node("child", &root);
    auto child4 = Node("child", &child1);

    Array<Node*> found = root.find_node_in_offspring("child");

    for (size_t i = 0; i < found.size(); ++i)
    {
        std::cout << found[i]->name << " " << found[i] << '\n';
    }
    
    return 0;
}
