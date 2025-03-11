#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    Fraction f3 { add(f1, f2) };

    std::cout << "add(f1, f2) = ";
    f3.display();

    std::cout << std::endl << "sub(f1, f2) = ";
    (sub(f1, f2)).display();

    std::cout << std::endl << "mul(f1, f2) = ";
    (mul(f1, f2)).display();

    std::cout << std::endl << "div(f1, f2) = ";
    (div(f1, f2)).display();

    std::cout << std::endl << "add(1/6, 2/6) = ";
    (add({1, 6}, {2, 6})).display();

    std::cout << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Display: " <<  f1 << std::endl;
    std::cout << "Addition: " << f1 + f2 << std::endl;
    std::cout << "Substraction: " << f1 - f2 << std::endl;
    std::cout << "Multplication: " <<f1 * f2 << std::endl;
    std::cout << "Division: " <<f1 / f2 << std::endl;
    std::cout << "Egalite: " << (f1==f2) << std::endl;
    std::cout << "Inegalite: " << (f1!=f2) << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2: " << (f1<=f2) << std::endl;
    std::cout << "f1 > f2: " << (f1>f2) << std::endl;
    std::cout << "f1 >= f2: " << (f1>=f2) << std::endl;
    /*
    std::cout << "f1 += f2: " << (f1 += f2) << std::endl;
    std::cout << "f1 -= f2: " << (f1 -= f2) << std::endl;
    std::cout << "f1 *= f2: " << (f1 *= f2) << std::endl;
    std::cout << "f1 /= f2: " << (f1 /= f2) << std::endl;
    */
    std::cout << "Conversion float via to_float: " << f1.to_float() << std::endl;
    std::cout << "Conversion float via static_cast: " << static_cast<float>(f1) << std::endl;

    std::cout << "f1 + 5: " << f1 + 5 << std::endl;
    std::cout << "5 + f1: " << 5 + f1 << std::endl;
    std::cout << "f1 - 5: " << f1 - 5 << std::endl;
    std::cout << "5 - f1: " << 5 - f1 << std::endl;
    std::cout << "f1 * 5: " << f1 * 5 << std::endl;
    std::cout << "5 * f1: " << 5 * f1 << std::endl;
    std::cout << "f1 / 5: " << f1 / 5 << std::endl;
    std::cout << "5 / f1: " << 5 / f1 << std::endl;

    std::cout << "Absolue: " << f1.abs() << std::endl;
    std::cout << "Arrondie inferieur: " << f1.floor() << std::endl; 
    std::cout << "Arrondie superieur: " << f1.ceil() << std::endl; 
    std::cout << "Arrondie: " << f1.round() << std::endl;  
    return 0;
}