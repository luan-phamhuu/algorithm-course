#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    // naive solution will cause overflow no matter how big our type is
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int new_current;

    for (int i = 2; i <= n; ++i) {
        new_current = previous + current;
        previous = current;
        current = new_current;
    }

    return new_current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current = 1;
    int new_current;

    for (size_t i = 2; i <= n; i++) {
        new_current = (previous + current) % 10;
        previous = current;
        current = new_current;
    }

    return new_current;
}

void test_solution() {
    // with int type, naive solution works fine with n < 47
    for (size_t i = 0; i < 47; i++) {
        assert(get_fibonacci_last_digit_fast(i) == get_fibonacci_last_digit_naive(i));
    }

    assert(get_fibonacci_last_digit_fast(331) == 9);
    assert(get_fibonacci_last_digit_fast(327305) == 5);
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    // test_solution();
}
