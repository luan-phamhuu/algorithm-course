#include <iostream>
#include <cassert>
#include <vector>
#include <cassert>
#include <algorithm>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            return mid;
        }

        if (x > a[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

void test_solution() {
    assert( binary_search(vector<int> {}, 1) == -1 );

    assert( binary_search(vector<int> {1}, 1) == 0 );
    assert( binary_search(vector<int> {1}, 2) == -1 );

    assert( binary_search(vector<int> {1, 2}, 1) == 0 );
    assert( binary_search(vector<int> {1, 2}, 2) == 1 );
    assert( binary_search(vector<int> {1, 2}, 0) == -1 );

    // large dataset
    vector<int> *arr_1 = new vector<int>;
    for (int i = 0; i < 100000; i++) {
        arr_1->push_back(i);
    }
    assert( binary_search(*arr_1, 99999) == 99999 );
    delete(arr_1);

    // stress test
    while (true) {
        int n = rand() % 100000;
        vector<int> *arr = new vector<int>(n);


        for (size_t i = 0; i < arr->size(); i++) {
            (*arr)[i] = rand() % 1000000001;
        }

        std::sort(arr->begin(), arr->end());

        int random_searching_number;
        if (arr->size() > 0) {
            random_searching_number = (*arr)[rand() % arr->size()];
        } else {
            random_searching_number = rand() % 1000000001;
        }

        std::cout << "search: " << random_searching_number << '\n';
        for (size_t i = 0; i < arr->size(); i++) {
            std::cout << (*arr)[i] << ' ';
        }
        std::cout << '\n';
        std::cout << binary_search(*arr, random_searching_number) << "<=>" << linear_search(*arr, random_searching_number) << '\n';
        std::cout << "-------------------\n";

        assert( binary_search(*arr, random_searching_number) == linear_search(*arr, random_searching_number) );

        delete(arr);
    }

}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
      std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
      //replace with the call to binary_search when implemented
      std::cout << binary_search(a, b[i]) << ' ';
    }

    // test_solution();
}
