#pragma once  // if this file is already included in the project,
              // this will stop doing it again
#include <iostream>

struct complex {  // there's struct, because its object by default are public
    complex();
    complex(double, double);
    complex operator + (complex);
    complex operator - (complex);
    complex operator * (complex);
    bool operator < (complex);
    friend std::istream& operator >> (std::istream&, complex&);
    friend std::ostream& operator << (std::ostream&, const complex&);// printing an objec like "a +bi"
    complex mulByConst(double); // multiply the complex objec by real number
    double abs();  // counting the absalutely value of an object
    friend struct complexArray;
private:
    double a;
    double b;
};


struct complexArray {
    complexArray(unsigned);
    ~complexArray();
    friend std::ostream& operator<<(std::ostream&, const complexArray&);
    void sort(); // workes with QuickSort's algorithm
private:
    unsigned length;
    complex* array;
};
