#include "td04_exo1.hpp"

//debut Q1
std::vector<int> create_100_random_int()
{
    std::vector<int> new_vec {};
    for (int i {0}; i < 100; i++)
    {
        new_vec.push_back(rand()%101);
    }
    return new_vec;
}
//fin Q1

//debut Q2
void show_values(std::vector<int> const& vec)
{
    for (auto it {vec.begin()}; it != vec.end(); it++)
    {
        std::cout << *it << std::endl; 
    }
}
//fin Q2

//debut Q3
void is_my_value_here(std::vector<int> const& vec)
{
    int value {};
    std::cout << "Entrez la valeur que vous recherchez: ";
    std::cin >> value;
    std::cout << std::endl;

    auto it {std::find(vec.begin(),vec.end(),value)};

    if (it != vec.end())
    {
        std::cout << *it << " est presente dans cet ensemble" << std::endl;
    }
    else 
    {
        std::cout << "La valeur n'est pas presente dans l'ensemble" << std::endl;
    }
}
//fin Q3

//debut Q4
void number_of_appearances(std::vector<int> const& vec, int num)
{
    int nb_app {std::count(vec.begin(), vec.end(), num)};
    std::cout << "Le nombre " << num << " est apparu " << nb_app << " fois dans cet ensemble" << std::endl; 
}
//fin Q4

//debut Q6
void sum_of_ensemble(std::vector<int> const& vec)
{
    int sum {std::accumulate(vec.begin(), vec.end(), 0)};
    std::cout << "La somme de cet ensemble est " << sum << std::endl;
}
//fin Q6


int main()
{
    srand(time(nullptr));
    std::vector<int> vec {create_100_random_int()};
    //show_values(vec);
    //is_my_value_here(vec);
    //number_of_appearances(vec,9);
    //std::vector<int> vec2 {33,33,33};
    //number_of_appearances(vec2,33);

    //debut Q5
    std::sort(vec.begin(), vec.end());
    show_values(vec);
    //fin Q5

    sum_of_ensemble(vec);
    return 0;
}