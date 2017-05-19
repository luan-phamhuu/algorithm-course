#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

vector<int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int i = l;
    int j = l;
    int m = l;

    for (int i = l + 1; i <= r; i++) {
        if (a[i] == x) {
            m++;
            swap(a[m], a[i]);
        } else if (a[i] < x) {
            j++;
            m++;
            swap(a[m], a[j]);
            swap(a[j], a[i]);
        }
    }
    swap(a[l], a[j]);

    vector<int> result = { j, m };
    return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> segment;
    segment = partition3(a, l, r);

    randomized_quick_sort(a, l, segment[0] - 1);
    randomized_quick_sort(a, segment[1] + 1, r);
}

void test_solution() {
    vector<int> *a = new vector<int> {4, 3, 6, 4, 2, 5};
    randomized_quick_sort(*a, 0, a->size() - 1);

    for (size_t i = 0; i < a->size(); i++) {
        std::cout << (*a)[i] << '\n';
    }
    delete(a);
}

int main() {
    // int n;
    // std::cin >> n;
    // vector<int> a(n);
    // for (size_t i = 0; i < a.size(); ++i) {
    //   std::cin >> a[i];
    // }
    // randomized_quick_sort(a, 0, a.size() - 1);
    // for (size_t i = 0; i < a.size(); ++i) {
    //   std::cout << a[i] << ' ';
    // }

    test_solution();
}
