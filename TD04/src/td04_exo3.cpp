#include "td04_exo3.hpp"

bool is_palindrome(std::string const& str)
{
    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}

int main()
{
    std::string test {"test"};
    std::string kayak {"kayak"};
    std::cout << std::boolalpha << std::endl;
    std::cout << is_palindrome(test) << std::endl;
    std::cout << is_palindrome(kayak) << std::endl;
    return 0;
}