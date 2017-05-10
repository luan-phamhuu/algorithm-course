#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
  int n = numbers.size();

  int max_index_1 = -1;
  for (size_t i = 0; i < n; i++) {
    if ((max_index_1 == -1) || (numbers[i] > numbers[max_index_1])) {
      max_index_1 = i;
    }
  }

  int max_index_2 = -1;
  for (size_t i = 0; i < n; i++) {
    if ((i!= max_index_1) && ((max_index_2 == -1) || numbers[i] > numbers[max_index_2])) {
      max_index_2 = i;
    }
  }

  return (long long) numbers[max_index_1] * numbers[max_index_2];
}

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((long long)numbers[i] * numbers[j] > result) {
        result = (long long)numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
      cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);

    cout << result << "\n";
    return 0;
}
