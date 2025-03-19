#include <iostream>
#include "td03_exo1.hpp"
#include "td03_exo2.hpp"

int main()
{
    std::vector<int> test_selection_sort {3,1,2};
    if (is_sorted(test_selection_sort)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    selection_sort(test_selection_sort);
    if (is_sorted(test_selection_sort)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    std::vector<float> test_quick_sort {1.5f, 0.f, 2.f, 1.f,1.8f};
    quick_sort(test_quick_sort);
    std::cout << test_quick_sort[0] << test_quick_sort[1] << test_quick_sort[2] << test_quick_sort[3] << test_quick_sort[4] <<  std::endl;
    
}