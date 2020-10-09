#include <iostream>
#include "complex.hpp" //for complex objects and f-s

int main() {
    std::cout << "Type two complex numbers like \"a(+/-)bi\"\nType x : ";
	complex x, y;
    std::cin >> x;
    std::cout << "Type y : ";
    std::cin >> y;
	std::cout << "x + y == " << x + y << '\n';
	
	std::cout << "Type the length of the array : ";
	unsigned length;
	std::cin >> length;
	complexArray arr = complexArray(length);
	std::cout << "\nArray is:\n";
    std::cout << arr;
	std::cout << "\nThe sorted array is:\n";
	arr.sort();
    std::cout << arr;
}

