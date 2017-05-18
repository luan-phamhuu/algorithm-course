#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <functional>
#include <algorithm>

using std::vector;

struct Item {
public:
    int weight, value;

    Item(int new_weight, int new_value) {
        weight = new_weight;
        value = new_value;
    }

    double value_per_weight() const {
        return (double)value / weight;
    }

    bool operator >(const Item& another_item) const {
        return value_per_weight() > another_item.value_per_weight();
    }
};

vector<Item> construct_sorted_items(vector<int> weights, vector<int> values) {
    vector<Item> items;

    for (size_t i = 0; i < weights.size(); i++) {
        items.push_back(Item(weights[i], values[i]));
    }

    std::sort(items.begin(), items.end(), std::greater<Item>());
    return items;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    vector<Item> items = construct_sorted_items(weights, values);
    int item_index = 0;

    while (capacity > 0) {
        Item current_item = items[item_index];

        int taken_weight = std::min(current_item.weight, capacity);
        capacity = capacity - taken_weight;
        value = value + taken_weight * current_item.value_per_weight();
        current_item.weight -= taken_weight;
        item_index++;
    }

    return value;
}

void test_solution() {
    std::cout << get_optimal_value(50, vector<int> {20, 50, 30}, vector<int> {60, 100, 120}) << '\n';
    std::cout << get_optimal_value(10, vector<int> {30}, vector<int> {500}) << '\n';
    assert(get_optimal_value(50, vector<int> {20, 50, 30}, vector<int> {60, 100, 120}) == 180.0000);
    assert(get_optimal_value(10, vector<int> {30}, vector<int> {500}) == 166.667);
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
      std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);
    std::cout << std::setprecision(4) << std::fixed << optimal_value << std::endl;

    // test_solution();
}
