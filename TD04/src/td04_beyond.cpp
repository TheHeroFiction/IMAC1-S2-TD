#include "td04_beyond.hpp"

auto squared = [](int accumulator, int num) { return accumulator + num*num; };
auto even_product = [](int accumulator, int num) 
{   
    if (num % 2 == 0)
    {
        return accumulator * num;
    }
    return accumulator;
     
};
//debut Q1
int sum_of_squared_nb(std::vector<int> const& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0, squared );
}
//fin Q1

//debut Q2
int product_of_even_nb(std::vector<int> const& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 1, even_product );
}
//fin Q2

int main()
{
    std::vector<int> test {1,2,3,4};
    std::cout << sum_of_squared_nb(test) << std::endl;
    std::cout << product_of_even_nb(test) << std::endl;
    return 0;
}