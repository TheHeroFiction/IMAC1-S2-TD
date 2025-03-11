#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

// debut Exercice 5
Fraction Fraction::operator+=(Fraction const& f1){
    numerator = numerator*f1.denominator + f1.numerator * denominator;
    denominator = denominator * f1.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction Fraction::operator-=(Fraction const& f1){
    numerator = numerator*f1.denominator - f1.numerator * denominator;
    denominator = denominator * f1.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction Fraction::operator*=(Fraction const& f1){
    numerator = numerator*f1.numerator;
    denominator = denominator * f1.denominator;
    *this = simplify(*this);
    return *this;
}

Fraction Fraction::operator/=(Fraction const& f1){
    numerator = numerator*f1.denominator;
    denominator = denominator * f1.numerator;
    *this = simplify(*this);
    return *this;
}

Fraction operator+(Fraction const& f1, Fraction const& f2){
    Fraction temp = f1;
    return temp += f2;
}

Fraction operator-(Fraction const& f1, Fraction const& f2){
    Fraction temp = f1;
    return temp -= f2;
}

Fraction operator*(Fraction const& f1, Fraction const& f2){
    Fraction temp = f1;
    return temp *= f2;
}

Fraction operator/(Fraction const& f1, Fraction const& f2){
    Fraction temp = f1;
    return temp /= f2;
}
// fin exercice 5

// debut exercice 6
float Fraction::to_float() const{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}
// fin exercice 6

// debut exercice 2
std::ostream& operator<<(std::ostream& os, Fraction const& f){
    return os << f.numerator << "/" << f.denominator;
}
// fin exercice 2


Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

/* debut Exercice 1 
Fraction operator+(Fraction const& f1, Fraction const& f2){
    Fraction temp  = {
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    };
    return simplify(temp);
}

Fraction operator-(Fraction const& f1, Fraction const& f2){
    Fraction temp = {
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    };
    return simplify(temp);
}

Fraction operator*(Fraction const& f1, Fraction const& f2){
    Fraction temp = {
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    };
    return simplify(temp);
}

Fraction operator/(Fraction const& f1, Fraction const& f2){
    Fraction temp {
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    };
    return simplify(temp);
}
// fin exercice 1
*/

// debut exercice 3
bool operator==(Fraction const& f1, Fraction const& f2){
    return (f1.numerator*f2.denominator == f2.numerator * f1.denominator);
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1 == f2);
}
// fin exercice 3

// debut exercice 4
bool operator<(Fraction const& f1, Fraction const& f2){
    return (f1.numerator * f2.denominator < f2.numerator * f1.denominator);
}

bool operator<=(Fraction const& f1, Fraction const& f2){
    return (f1 < f2) || (f1 == f2);
}

bool operator>(Fraction const& f1, Fraction const& f2){
    return !(f1 < f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2){
    return (f1 > f2) || (f1 == f2);
}
// fin exercice 4

// debut ALLER PLUS LOIN
Fraction operator+(Fraction  const& f, int const i){
    Fraction temp = {
        f.denominator * i,
        f.denominator 
    };
    return simplify(f+temp);
}

Fraction operator+(int const i, Fraction  const& f){
    return f + i; 
}

Fraction operator-(Fraction  const& f, int const i){
    Fraction temp = {
        f.denominator * i,
        f.denominator 
    };
    return simplify(f - temp);
}

Fraction operator-(int const i, Fraction  const& f){
    Fraction temp = {
        f.denominator * i,
        f.denominator 
    };
    return simplify(temp - f); 
}

Fraction operator*(Fraction  const& f, int const i){
    Fraction temp = {
        f.numerator * i,
        f.denominator 
    };
    return simplify(temp);
}

Fraction operator*(int const i, Fraction  const& f){
    return f*i; 
}

Fraction operator/(Fraction  const& f, int const i){
    Fraction temp = {
        f.numerator,
        f.denominator * i 
    };
    return simplify(temp);
}

Fraction operator/(int const i, Fraction  const& f){
    Fraction temp = {
        f.denominator * i,
        f.numerator
    };
    return simplify(temp); 
}

float Fraction::abs(){
    float f {static_cast<float>(*this)};
    if (f < 0){
        return -f;
    }
    return f;
}

int Fraction::ceil(){
    return (this->numerator/this->denominator + 1);
}

int Fraction::floor(){
    return this->numerator / this->denominator;
}

int Fraction::round(){
    float high {static_cast<float>(this->ceil())};
    float low {static_cast<float>(this->floor())};
    float current {static_cast<float>(*this)};
    if (high - current <= current - low){
        return this->ceil();
    } else {
        return this->floor();
    }
}

// fin ALLER PLUS LOIN