#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <limits>

using std::vector;

long long max_dot_product_naive(vector<int> a, vector<int> b) {
    long long result = std::numeric_limits<long long>::min();

    std::sort(a.begin(), a.end());

    do {
        long long tmp_result = 0;

        // print vectors
        // for (size_t i = 0; i < a.size(); i++) {
        //   std::cout << a[i] << " " << b[i] << '\n';
        // }

        for (size_t i = 0; i < a.size(); i++)  {
            tmp_result += (long long)a[i] * b[i];
        }

        // std::cout << "current result: " << result << '\n';
        // std::cout << "new result: " << tmp_result << '\n';

        if (tmp_result > result) {
            // std::cout << "new result taken!" << '\n';
            result = tmp_result;
        }
    } while( std::next_permutation(a.begin(), a.end()) );

    return result;
}

long long max_dot_product(vector<int> a, vector<int> b) {
    long long result = 0;

    // sort a
    std::sort(a.begin(), a.end());
    // sort b
    std::sort(b.begin(), b.end());

    for (size_t i = 0; i < a.size(); i++) {
        result += (long long)a[i] * b[i];
    }
    return result;
}

void test_solution() {
    // example test
    assert(max_dot_product(vector<int> {23}, vector<int> {39}) == 897);
    assert(max_dot_product(vector<int> {1, 3, -5}, vector<int> {-2, 4, 1}) == 23);
    assert(max_dot_product(vector<int> {1, 3, 5}, vector<int> {-2, 4, 1}) == 21);

    // edge cases
    assert( max_dot_product(vector<int> {}, vector<int> {}) == 0 );

    assert( max_dot_product(vector<int> {1}, vector<int> {-1}) == -1 );
    assert( max_dot_product(vector<int> {-1}, vector<int> {1}) == -1 );
    assert( max_dot_product(vector<int> {-1}, vector<int> {-1}) == 1 );

    assert( max_dot_product(vector<int> {-1}, vector<int> {0}) == 0 );

    // overflow test
    std::vector<int> a;
    std::vector<int> b;
    for (size_t i = 0; i < 1000; i++) {
        a.push_back(100000);
        b.push_back(100000);
    }
    assert( max_dot_product(a, b) == 10000000000000 );

    std::vector<int> a1;
    std::vector<int> b1;
    for (size_t i = 0; i < 1000; i++) {
        a1.push_back(-100000);
        b1.push_back(-100000);
    }
    assert( max_dot_product(a1, b1) == 10000000000000 );

     std::cout << max_dot_product(vector<int> {-4, -5}, vector<int> {1, 8}) << '\n';
     std::cout << max_dot_product_naive(vector<int> {-4, -5}, vector<int> {1, 8}) << '\n';

//   stress test
     while (true) {
       int n = rand() % 10 + 1;
       vector<int> a;
       vector<int> b;

       std::cout << "size of n: " << n << '\n';
       for (size_t i = 0; i < n; i++) {
         int random_number = (rand() % 100001) * ( pow(-1, rand() % 2) );
         a.push_back( random_number );
         random_number = (rand() % 100001) * ( pow(-1, rand() % 2) );
         b.push_back( random_number );
       }

       for (size_t i = 0; i < a.size(); i++) {
         std::cout << a[i] << " " << b[i] << '\n';
       }

       assert(max_dot_product(a,  b) == max_dot_product_naive(a, b));
       std::cout << "OK" << "\n\n";
     }
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
      std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
    // test_solution();

    return 0;
}
