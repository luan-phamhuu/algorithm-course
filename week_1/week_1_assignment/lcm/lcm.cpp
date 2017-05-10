#include <iostream>
#include <cassert>

int gcd(int a, int b) {
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

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
    return (long long) a * b / gcd(a, b);
}

void test_solution() {
    int a, b;

    assert(lcm_fast(6, 8) == 24);
    assert(lcm_fast(28851538, 1183019) == 1933053046);
    assert(lcm_fast(0, 0) == 0);
    assert(lcm_fast(0, 1) == 0);
    assert(lcm_fast(1, 10000) == 10000);

    while (true) {
        a = rand() % 10000000;
        b = rand() % 10000000;
        std::cout << a << " " << b << '\n';
        assert(lcm_fast(a, b) == lcm_naive(a, b));
        std::cout << "OK" << '\n';
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  // test_solution();
  return 0;
}
