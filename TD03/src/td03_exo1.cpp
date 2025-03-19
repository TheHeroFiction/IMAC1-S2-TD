#include "td03_exo1.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void selection_sort(std::vector<int> & vec)
{
    int minimum {0};
    int swap_index {0};
    for (int i {0}; i < vec.size();i++)
    {
        for (int j {i}; j < vec.size(); j++)
        {
            if (j == i)
            {
                minimum = vec[i];
            }
            else
            {
                if (minimum > vec[j])
                {
                    minimum = vec[j];
                    swap_index = j;
                }
            }
        }
        vec[swap_index] = vec[i];
        vec[i] = minimum;
    }
}