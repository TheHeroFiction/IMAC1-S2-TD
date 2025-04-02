#include "td05_exo1.hpp"
size_t folding_string_hash(std::string const& s, size_t max) 
{
    size_t hash {0};
    for (char c : s) {
        hash += static_cast<size_t>(c);
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max)
{
    size_t hash {0};
    for (size_t i {0}; i < s.size(); i++) {
        hash += (static_cast<size_t>(s[i]) * (i+1));
        hash %= max;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
{
    size_t hash {0};
    size_t p_product {1};
    for (size_t i {0}; i < s.size(); i++) {
        hash += (static_cast<size_t>(s[i]) * (p_product));
        hash %= m;
        p_product *= p;
    }
    return hash;
}

int main()
{   
    std::string test {"IMAC"};
    std::string test2 {"MICA"};
    size_t max {100};
    size_t p {31};
    size_t m {1000000009};

    std::cout << "Le hachage de " << test << " donne " << folding_string_hash(test,max) << " par la premiere methode et un max de " << max << std::endl;
    std::cout << "Le hachage de " << test2 << " donne " << folding_string_hash(test2,max) << " par la premiere methode et un max de " << max << std::endl;

    std::cout << "Le hachage de " << test << " donne " << folding_string_ordered_hash(test,max) << " par la deuxieme methode et un max de " << max << std::endl;
    std::cout << "Le hachage de " << test2 << " donne " << folding_string_ordered_hash(test2,max) << " par la deuxieme methode et un max de " << max << std::endl;

    std::cout << "Le hachage de " << test << " donne " << polynomial_rolling_hash(test,p,m) << " par la troisieme methode avec p egale a " << p << " et m egale a " << m << std::endl;
    std::cout << "Le hachage de " << test2 << " donne " << polynomial_rolling_hash(test2,p,m) << " par la troisieme methode avec p egale a " << p << " et m egale a " << m << std::endl;
    return 0;
}