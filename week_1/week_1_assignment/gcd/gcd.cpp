#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
        current_gcd = d;
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
    if (a == 0 || b == 0) {
        return 1;
    }

    while (b > 0) {
        int tmp_a = a;
        a = b;
        b = tmp_a % b;
    }

    return a;
}

void test_solution() {
    int a;
    int b;

    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(28851538, 1183019) == 17657);

    while (true) {
        a = rand() % 1000000000;
        b = rand() % 1000000000;

        std::cout << a << ' ' << b << '\n';
        assert(gcd_fast(a, b) == gcd_naive(a, b));
        std::cout << "OK" << '\n';
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
  // test_solution();
}
