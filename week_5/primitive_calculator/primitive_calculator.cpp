#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> calculate_consideration(int n) {
  vector<int> considerations;

  if (n % 3) {
    considerations.push_back(n / 3);
  }

  if (n % 2) {
    considerations.push_back(n / 2);
  }

  if (n > 1) {
    considerations.push_back(n - 1);
  }

  return considerations;
}

vector<int> dynamic_optimal_sequence(int n) {
  std::vector<int> sequence = {1};

  for (size_t i = 1; i < n; i++) {
    vector<int> considerations = calculate_consideration();
    

  }


  return sequence;
}

bool test_result(const vector<int> &a, const vector<int> &b) {
  return a == b;
}

void test() {
  // normal test
  vector<int> sequence {1, 2, 4, 5};
  assert(dynamic_optimal_sequence(5) == sequence);

  // edge case test
  // assert(old_result == new_result);

  // overflow test

  // random test
}

int main() {
  std::vector<int> sequence = {1, 2, 3};
  std::cout << "sequence size: " << sequence.size() << '\n';
  for (size_t i = 0; i < sequence.size(); i++) {
    std::cout << sequence[i] << ' ';
  }
  std::cout << '\n';

  // test();
  // int n;
  // std::cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }
}
