#include "td07_ex02.hpp"

int main()
{
    std::vector<std::vector<float>> matrix_test 
    {
        {0.f, 1.f, 0.f, 0.f, 2.f},
        {0.f, 0.f, 2.f, 4.f, 0.f},
        {0.f, 0.f, 0.f, 1.f, 0.f},
        {0.f, 0.f, 0.f, 0.f, 6.f},
        {0.f, 0.f, 0.f, 0.f, 0.f}        
    };
    Graph::WeightedGraph graph_1 {Graph::build_from_adjacency_matrix(matrix_test)};

    graph_1.print_DFS(0);
    graph_1.print_BFS(0);
    return 0;
}