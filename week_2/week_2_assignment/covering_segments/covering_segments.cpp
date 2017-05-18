#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cassert>


using std::vector;

class Segment {

public:
  int start, end;

  Segment(int start, int end) {
    this->start = start;
    this->end = end;
  }

  Segment() {
    this->start = 0;
    this->end = 0;
  }

  bool operator == (const Segment &another_segment) const {
    return this->start == another_segment.start && this->end == another_segment.end;
  }

  bool operator < (const Segment &another_segment) const {
    std::cout << "HERE" << '\n';
    return this-> end < another_segment.end;
  }
};

vector<int> optimal_points(const vector<Segment> &segments) {
  vector<int> points;
  int current_segment = 0;

  // create another non const version of segments and sort on it
  vector<Segment> sorted_segments = segments;
  std::sort(sorted_segments.begin(), sorted_segments.end(), [](const Segment &segment_1, const Segment &segment_2) {
    return segment_1.end < segment_2.end;
  });

  while (current_segment < sorted_segments.size()) {
    int point = sorted_segments[current_segment].end;
    points.push_back(point);
    current_segment++;

    while (current_segment < sorted_segments.size() && sorted_segments[current_segment].start <= point) {
      current_segment++;
    }
  }

  return points;
}

void assert_array(const vector<int> &array_1, const vector<int> &array_2) {
  std::cout << "checking array: ------" << '\n';
  for (size_t i = 0; i < array_1.size(); i++) {
    std::cout << array_1[i] << ' ';
  }

  std::cout << '\n';
  for (size_t i = 0; i < array_2.size(); i++) {
    std::cout << array_2[i] << ' ';
  }
  std::cout << '\n';

  if (array_1.size() != array_2.size()) {
    assert(false);
  }

  for (size_t i = 0; i < array_1.size(); i++) {
    if (array_1[i] != array_2[i]) {
      assert(false);
    }
  }

}

void test_solution() {
  // example test
  assert_array( optimal_points( vector<Segment> { Segment(1, 3), Segment(2, 5), Segment(3, 6) } ), vector<int> { 3 } );
  assert_array( optimal_points( vector<Segment> { Segment(4, 7), Segment(1, 3), Segment(2, 5), Segment(5, 6) } ), vector<int> { 3, 6 });

  // edge case test
  assert_array( optimal_points( vector<Segment> { } ), vector<int> { });
  assert_array( optimal_points( vector<Segment> { Segment(0, 1)} ), vector<int> { 1 });
  assert_array( optimal_points( vector<Segment> { Segment(0, 3), Segment(1, 2)} ), vector<int> { 2 });
  assert_array( optimal_points( vector<Segment> { Segment(0, 1), Segment(1, 2)} ), vector<int> { 1 });
  assert_array( optimal_points( vector<Segment> { Segment(0, 1), Segment(2, 3)} ), vector<int> { 1, 3 });

  // Time test
  int n = 100;
  vector<Segment> segments(n, Segment(0, 1000000000));
  assert_array( optimal_points( segments ), vector<int> { 1000000000 });
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }

  // test_solution();

}
