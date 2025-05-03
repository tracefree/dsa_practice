#include "fibonacci.hpp"

#include <print>


void test_fibonacci() {
    std::println("- Fibonacci");
    print_fibonacci_numbers_loop(20);
    print_fibonacci_numbers_recursion(20);
}

// --- Loop ---

void print_fibonacci_numbers_loop(uint max_index) {
    std::println("- Printing {} fibonacci numbers using loop", max_index);
    uint fibonacci_a = 1;
    uint fibonacci_b = 1;
    
    if (max_index == 0) {
        return;
    }

    std::println("Fibonacci number 1: {}", fibonacci_a);
    
    if (max_index == 1) {
        return;
    }

    std::println("Fibonacci number 2: {}", fibonacci_b);

    for (uint i = 2; i < max_index; i++) {
        uint tmp_a = fibonacci_a;
        fibonacci_a = fibonacci_b;
        fibonacci_b = fibonacci_b + tmp_a;
        std::println("Fibonacci number {}: {}", i + 1, fibonacci_b);
    }
}


// --- Recursion ---

void fibonacci(uint prev_a, uint prev_b, uint count, uint max_index) {
    uint next = prev_a + prev_b;
    std::println("Fibonacci number {}: {}", count + 1, next);
    count++;
    if (count < max_index) {
        fibonacci(prev_b, next, count, max_index);
    }
}

void print_fibonacci_numbers_recursion(uint max_index) {
    std::println("- Printing {} fibonacci numbers using recursion", max_index);
    if (max_index == 0) {
        return;
    }

    std::println("Fibonacci number 1: 1");
    
    if (max_index == 1) {
        return;
    }

    std::println("Fibonacci number 2: 1");

    if (max_index == 2) {
        return;
    }

    fibonacci(1, 1, 2, max_index);
}