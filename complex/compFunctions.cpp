#include <iostream>
#include <cmath>  // for sqrt in comp::abs()
#include <cassert>
#include "complex.hpp"
#include <string>

complex::complex()
    :a(1)
     ,b(4)
{
}

complex::complex(double a, double b)
    :a(a)
     ,b(b)
{
}

complex complex::operator + (complex tmp) {
        complex res;
        res.a = a + tmp.a;
        res.b = b + tmp.b;
        return res;
}

complex complex::operator - (complex tmp) {
        complex res;
        res.a = a - tmp.a;
        res.b = b - tmp.b;
        return res;
}

complex complex::operator * (complex tmp) {
        complex res;
        res.a = a * tmp.a - b * tmp.b;
        res.b = a * tmp.b + tmp.a * b;
        return res;
}

bool complex::operator < (complex tmp) {
    if(a < tmp.a) {
        return true;
    }
    if((int)a == (int)tmp.a && b  < tmp.b) {
        return true;
    }
    return false;
}

std::istream& operator >> (std::istream& in, complex &arg) {
    std::string s;
    in >> s;
    arg.a = 0;
    arg.b = 0;
    size_t i = 0;
    double sign = 1;
    if(s[i] < '0' || s[i] > '9') {
        if(s[i] == '-') {
            sign = -1;
        } else {
            assert(s[i] == '+');
        }
        ++i;
    }
    for( ; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i) {  //read symbols from string &
                                                                   //convert to decimal, until first non number symbol
        arg.a += arg.a * 10 + s[i] - '0';
    }
    arg.a *= sign;
    sign = 1;
    
    if(s[i] == '.') {// if it's real number,it also convert
        double tmp = 0;
        int cntr = 0;
        ++i;
        for( ; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i) {
            tmp += tmp * 10 + s[i] - '0';
            ++cntr;
        }
        tmp /= pow(10, cntr);
        arg.a += tmp;
    } else {
        assert(s[i] == '+' || s[i] == '-');//abort if ther'is a wrong symbol
    }

    if(s[i] == '-') {
        sign = -1;
    } else {
        assert(s[i] == '+');
    }
    ++i;
    for( ; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i) {
        arg.b += arg.b * 10 + s[i] - '0';
    }
    arg.b *= sign;

    if(s[i] == '.') {
        ++i;
        double tmp = 0;
        int cntr = 0;
        for( ; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i) {
            tmp += tmp * 10 + s[i] - '0';
            ++cntr;
        }   
        tmp /= pow(10, cntr); 
        arg.b += tmp;
    }

    assert(s[i] == 'i');
    return in;
}

std::ostream& operator << (std::ostream& out, const complex &arg) {
    if(arg.a) {                  // if a is 0, it becomes useless to print it
        printf("%.2lf ", arg.a);
    }
	if(arg.b) {                  // if b is 0, it becomes useless to print it
		if(arg.b > 0) {          // if b is positive, I need to print '+' symbol
			std::cout << "+";
		}
		printf("%.2lfi", arg.b);
	}
    return out;
}

complex complex::mulByConst(double value) {
	complex res;
	res.a = a * value;
	res.b = b * value;
	return res;
}

double complex::abs() {
	return sqrt(a*a + b*b);// the absolutlye value of complex numbers is always a real number
}



complexArray::complexArray(unsigned length = 4)
    :length(length)
{
    complex* arr = new complex[length];
    for(int i = 0; i < length; ++i) {
        int x = rand() % 100 + 1 - rand() % 100; // for the beauty I taked integer numbers
        arr[i].a = x / 4.0;                      // in this way they becomes to real numbers
        x = rand() % 100 + 1 - rand() % 100;
        arr[i].b = x / 4.0;
    }
    array = arr;
}


complexArray::~complexArray()
{
    delete[] array;
}

std::ostream& operator << (std::ostream& out, const complexArray &arr) {
    for(int i = 0; i < arr.length; ++i) {
        out << arr.array[i] << "   ";
	}
	out << '\n';
    return out;
}

int partSort(complex*, int, int);  //will be used in quickSort
void quickSort(complex*, int, int);// will be used in complexArray::sort

void complexArray::sort() {
	for(int i = 0; i < length; ++i) { // this loop will make all members of array in absolutely value
		array[i].a = array[i].abs();
		array[i].b = 0;
	}
	quickSort(array, -1, length - 1); // calling quickSort for the array
}

int partSort(complex* arr, int left, int right) {
        complex tmp = arr[right]; // pivot for sorting
        int index = left - 1; // current index for start
        for(int i = left; i < right; ++i) {
                if(arr[i] < tmp) {/// if the pivot is greater than current element, swap these 
                        ++index;
                        std::swap(arr[index], arr[i]);
                }
        }
        std::swap(arr[index + 1], arr[right]); //all elements in the left of current are less,
                                                   // than pivot, and others are greater than pivot
                                                   // so, I need swap these elements
        return index + 1;
}

void quickSort(complex* arr, int left, int right) {
        if(left < right) { // if left >= right it meens, that, all array is sorted
                int index = partSort(arr, left, right); // partsort will return the index of pivot
                                                        // with that index i will multiply array by
                                                        // two parts, and sort these apart
                quickSort(arr, left, index - 1);
                quickSort(arr, index + 1, right);
        }
}
