#include <iostream>
#include <cassert>
#include <array>

using std::array;

int get_change(int m) {
    array<int, 3> denominations { 10, 5, 1 };
    int current_demomination_index = 0;
    int change_count = 0;

    while (m > 0 && current_demomination_index < denominations.size()) {
        if (m >= denominations[current_demomination_index]) {
            m = m - denominations[current_demomination_index];
            change_count++;
        } else {
            current_demomination_index++;
        }
    }
    return change_count;
}

void test_solution() {
    assert(get_change(1) == 1);
    assert(get_change(2) == 2);
    assert(get_change(3) == 3);
    assert(get_change(5) == 1);
    assert(get_change(28) == 6);
    assert(get_change(49) == 9);
    assert(get_change(50) == 5);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  // test_solution();
}
