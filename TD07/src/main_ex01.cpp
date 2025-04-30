#include "td07_ex01.hpp"

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

    Graph::WeightedGraph graph_2 {};
    graph_2.add_directed_edge(0,1,1.f);
    graph_2.add_directed_edge(0,4,2.f);

    graph_2.add_directed_edge(1,2,2.f);
    graph_2.add_directed_edge(1,3,4.f);

    graph_2.add_directed_edge(2,3,1.f);

    graph_2.add_directed_edge(3,4,6.f);

    bool test {graph_1 == graph_2};
    std::cout << std::boolalpha;
    std::cout << test << std::endl;

    return 0;
}