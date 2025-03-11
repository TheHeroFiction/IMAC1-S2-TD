#pragma once

#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();

    Fraction operator+=(Fraction const& f1);
    Fraction operator-=(Fraction const& f1);
    Fraction operator*=(Fraction const& f1);
    Fraction operator/=(Fraction const& f1);

    float to_float() const;
    
    operator float() const;
    float abs();
    int ceil();
    int floor();
    int round();
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& f);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);

Fraction operator+(Fraction  const& f, int const i);
Fraction operator+(int const i, Fraction  const& f);
Fraction operator-(Fraction  const& f, int const i);
Fraction operator-(int const i, Fraction  const& f);
Fraction operator*(Fraction  const& f, int const i);
Fraction operator*(int const i, Fraction  const& f);
Fraction operator/(Fraction  const& f, int const i);
Fraction operator/(int const i, Fraction  const& f);