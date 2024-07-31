// Part I/demo_print.cpp
// example for "C++17 In Detail"
// by Bartlomiej Filipek
// 2018/2019

#include <iostream>

template<typename T> void linePrinter(const T& x)  {
    // `if constexpr` is a compile-time conditional statement. It allows the compiler 
    // to evaluate the condition during compilation and optimize the code accordingly.
    if constexpr (std::is_integral_v<T>)
        // If `T` is an integral type (like int), this block will be compiled, printing "num: " followed by the value of `x`.
        std::cout << "num: " << x << '\n';
    else if constexpr (std::is_floating_point_v<T>) {
        const auto frac = x - static_cast<long>(x);
        std::cout << "flt: " << x << ", frac " << frac << '\n';
    }
    else if constexpr(std::is_pointer_v<T>) {
        std::cout << "ptr, ";
        linePrinter(*x);
    }
    else
        std::cout << x << '\n'; 
}

template<typename ... Args> void printWithInfo(Args ... args) {
    (linePrinter(args), ...); // fold expression over the comma operator
}

int main () {
    int i = 10;
    float f = 2.56f;
    printWithInfo(&i, &f, 30);
}