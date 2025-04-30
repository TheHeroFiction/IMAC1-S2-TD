#include "td07_ex02.hpp"

void Graph::WeightedGraph::print_DFS(int const start) const
{
    std::cout << "depth-first search: " << std::endl;
    std::stack<int> pile {};
    auto sommet_dep {adjacency_list.find(start)};
    pile.push(start);
    while (!(pile.empty()))
    {
        std::cout << pile.top() << ", ";
        int temp {pile.top()};
        pile.pop();
        auto sommet {adjacency_list.find(temp)};
        for (int i {0}; i < (*sommet).second.size(); i++)
        {
            pile.push((*sommet).second[i].to);
        }
    }
    std::cout << std::endl;
}

void Graph::WeightedGraph::print_BFS(int const start) const
{
    std::cout << "breadth-first search: " << std::endl;
    std::queue<int> file {};
    auto sommet_dep {adjacency_list.find(start)};
    file.push(start);
    while (!(file.empty()))
    {
        std::cout << file.front() << ", ";
        int temp {file.front()};
        file.pop();
        auto sommet {adjacency_list.find(temp)};
        for (int i {0}; i < (*sommet).second.size(); i++)
        {
            file.push((*sommet).second[i].to);
        }
    }
    std::cout << std::endl;
}