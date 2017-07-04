#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;

int get_number_of_inversions(const vector<int> &a, size_t left, size_t right);
int get_number_of_inversions(const vector<int> &a);
int get_number_of_inversions_naive(const vector<int> &a);
int merge_sort(vector<int> &a);
int merge();


int get_number_of_inversions(const vector<int> &a) {
    return -1;
}

int get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  int number_of_inversions = 0;
  // if (right <= left + 1) return number_of_inversions;
  // size_t ave = left + (right - left) / 2;
  // number_of_inversions += get_number_of_inversions(a, b, left, ave);
  // number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int get_number_of_inversions_naive(const vector<int> &a) {
    int inversion_count = 0;

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = i; j < a.size(); j++) {
            if (a[i] > a[j])
                inversion_count++;
        }
    }

    return inversion_count;
}

void test_solution() {

    std::cout << get_number_of_inversions_naive(vector<int> {4, 3, 6, 4, 2, 5}) << '\n';
    assert( get_number_of_inversions_naive(vector<int> {4, 3, 6, 4, 2, 5}) == 5 );
}

int main() {
    // int n;
    // std::cin >> n;
    // vector<int> a(n);
    // for (size_t i = 0; i < a.size(); i++) {
    //   std::cin >> a[i];
    // }
    // vector<int> b(a.size());
    // std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

    // test_solution();
    int a;
    float f;
    double d;
    std::cout << sizeof(a) << '\n';
    std::cout << sizeof(f) << '\n';
    std::cout << sizeof(d) << '\n';
}
