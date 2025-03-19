#include "td03_exo2.hpp"

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot)
{
    size_t new_left {left+1};
    float temp {};
    if (left == right)
    {
        return pivot;
    }
    else
    {
        if (pivot != left) //on met le pivot à gauche de la partie à traiter
        {
            temp = vec[pivot];
            vec[pivot] = vec[left];
            vec[left] = temp;
        }
        for (size_t i {left+1}; i < right ;i++)
        {
            if ( vec[i] < vec[pivot])
            {
                temp = vec[new_left];
                vec[new_left] = vec[i];
                vec[i] = vec[new_left];
                new_left++;
            }
        }
        temp = vec[pivot];
        vec[pivot] = vec[new_left - 1];
        vec[new_left -1 ] = temp;
    }
    quick_sort(vec, left , new_left-1);
    quick_sort(vec, new_left , right);
    return pivot;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right)
{
    quick_sort_partition(vec, left, right, left);
}