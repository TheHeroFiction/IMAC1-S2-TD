#include "td04_exo2.hpp"

auto const is_space = [](char letter){ return letter == ' '; };

//debut Q1
int number_of_letters_in_first_word(std::string const& str)
{
    auto it_begin {std::find_if_not(str.begin(), str.end(), is_space)};
    auto it_ends {std::find_if(it_begin, str.end(), is_space)};
    return std::distance(it_begin,it_ends);
}
//fin Q1

//debut Q2
std::vector<std::string> split_string(std::string const& str)
{
    std::vector<std::string> new_vec {};
    auto it_begin {std::find_if_not(str.begin(), str.end(), is_space)};
    std::string new_str {*it_begin};
    for (auto it {std::find_if_not(it_begin+1, str.end(), is_space)}; it != str.end(); it++)
    {
        if (it == std::find_if(it, str.end(), is_space))
        {
            new_vec.push_back(new_str);
            new_str = "";
        }
        else 
        {
            new_str.push_back(*it);
        }
    }
    new_vec.push_back(new_str);
    return new_vec;
}
//fin Q2

int main()
{   
    std::string str {" Love is blind"};
    std::cout << number_of_letters_in_first_word(str)<< std::endl;
    std::vector<std::string> test {split_string(str)};
    for (auto it {test.begin()}; it != test.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}