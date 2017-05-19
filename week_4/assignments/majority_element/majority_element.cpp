#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using std::vector;

int get_majority_element_moore(const vector<int> &a) {
    int maj_index = 0;
    int count = 1;

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == a[maj_index])
            count++;
        else
            count--;

        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }

    count = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == a[maj_index])
            count++;
    }

    if (count > a.size() / 2)
        return a[maj_index];
    else
        return -1;
}

int determine_majority(const vector<int> &a, int left, int right, int element_1, int element_2) {
    if (element_1 == element_2) {
        return element_1;
    }

    int element_1_count = 0;
    int element_2_count = 0;
    for (size_t i = left; i <= right; i++) {
        if (element_1 != -1 && a[i] == element_1)
            element_1_count++;
        if (element_2 != -1 && a[i] == element_2) {
            element_2_count++;
        }
    }

    if (element_1_count == element_2_count)
        return -1;

    return element_1_count > element_2_count ? element_1 : element_2;
}

int get_majority_element(const vector<int> &a, int left, int right) {
    if (left > right) {
        return -1;
    }

    if (left == right) {
        return a[left];
    }

    int mid = (left + right) / 2;
    int majority_left = get_majority_element(a, left, mid);
    int majority_right = get_majority_element(a, mid + 1, right);

    return determine_majority(a, left, right, majority_left, majority_right);
}

int get_majority_element(const vector<int> &a) {
    return get_majority_element(a, 0, a.size() - 1);
}

int get_majority_element_naive(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        int current_element = a[i];
        int count = 0;

        for (int j = 0; j < a.size(); j++)
            if (a[j] == current_element)
                count++;

        if (count > a.size() / 2)
            return current_element;
    }

    return -1;
}

void test_solution() {
    // edge case
    assert( get_majority_element_naive(vector<int> {}) == -1 );
    assert( get_majority_element_naive(vector<int> {1}) == 1 );
    assert( get_majority_element_naive(vector<int> {1, 2}) == -1 );
    assert( get_majority_element_naive(vector<int> {1, 1}) == 1 );

    assert( get_majority_element(vector<int> {}) == -1 );
    assert( get_majority_element(vector<int> {1}) == 1 );
    assert( get_majority_element(vector<int> {1, 2}) == -1 );
    assert( get_majority_element(vector<int> {1, 1}) == 1 );

    assert( get_majority_element_moore(vector<int> {}) == -1 );
    assert( get_majority_element_moore(vector<int> {1}) == 1 );
    assert( get_majority_element_moore(vector<int> {1, 2}) == -1 );
    assert( get_majority_element_moore(vector<int> {1, 1}) == 1 );

    // example case
    assert( get_majority_element_naive(vector<int> {2, 3, 9, 2, 2}) == 2 );
    assert( get_majority_element_naive(vector<int> {1, 2, 3, 4}) == -1 );
    assert( get_majority_element_naive(vector<int> {1, 2, 3, 1}) == -1 );

    assert( get_majority_element(vector<int> {2, 3, 9, 2, 2}) == 2 );
    assert( get_majority_element(vector<int> {1, 2, 3, 4}) == -1 );
    assert( get_majority_element(vector<int> {1, 2, 3, 1}) == -1 );

    assert( get_majority_element_moore(vector<int> {2, 3, 9, 2, 2}) == 2 );
    assert( get_majority_element_moore(vector<int> {1, 2, 3, 4}) == -1 );
    assert( get_majority_element_moore(vector<int> {1, 2, 3, 1}) == -1 );

    // big case
    long long n = 100000;
    vector<int> *array = new vector<int> (n);
    for (size_t i = 0; i < array->size(); i++) {
        (*array)[i] = rand() % 100000001;
    }

    clock_t begin, end;
    begin = clock();
    std::cout << get_majority_element_naive(*array) << '\n';
    end = clock();
    std::cout << "naive: " << double(end - begin) / CLOCKS_PER_SEC << '\n';

    begin = clock();
    std::cout << get_majority_element(*array) << "\n";
    end = clock();
    std::cout << "divide & conquer: " << double(end - begin) / CLOCKS_PER_SEC << '\n';

    begin = clock();
    std::cout << get_majority_element_moore(*array) << "\n";
    end = clock();
    std::cout << "moore: " << double(end - begin) / CLOCKS_PER_SEC << '\n';

    delete(array);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
      std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
    // test_solution();
}
