#include "td07_ex01.hpp"

void Graph::WeightedGraph::add_vertex(int const id)
{
    auto sommet {adjacency_list.find(id)};
    if (sommet == adjacency_list.end())
    {
        std::vector<Graph::WeightedGraphEdge> new_vec {};
        adjacency_list.insert({id,new_vec});
    }
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
{
    Graph::WeightedGraphEdge new_edge {to,weight};
    Graph::WeightedGraph::add_vertex(from);
    Graph::WeightedGraph::add_vertex(to);
    auto sommet {adjacency_list.find(from)};
    (*sommet).second.push_back(new_edge);
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
{
    Graph::WeightedGraph::add_directed_edge(from,to,weight);
    Graph::WeightedGraph::add_directed_edge(to,from,weight);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix)
{
    Graph::WeightedGraph new_graph {};
    std::unordered_map<int, std::vector<Graph::WeightedGraphEdge>> new_map {};
    for (int i {0}; i < adjacency_matrix.size(); i++)
    {
        std::vector<Graph::WeightedGraphEdge> new_vec {};
        for (int j {0}; j < adjacency_matrix[i].size(); j++)
        {
            if (adjacency_matrix[i][j] != 0)
            {
                new_vec.push_back({j,adjacency_matrix[i][j]});
            }
        }
        new_map.insert({i,new_vec});
    }
    new_graph.adjacency_list = new_map;
    return new_graph;
}