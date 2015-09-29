/**
 * main file for sort
 */
#include <iostream>
#include <random>
#include "test.hpp"
#include "insertion_sort.hpp"
#include "selection_sort.hpp"
#include "bubble_sort.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"

using namespace std;

int main(int argc, char const * argv[]) {
  // settings
  const std::size_t min_size = 1000;
  const std::size_t max_size = 10000;
  const std::size_t min_size_qm = 1000;
  const std::size_t max_size_qm = 500000;
  const std::size_t trial_count = 10;

  // int
  std::function<void(int*, int*)> insertion_int_f = sort::insertion_sort<int*>;
  cout << "# insertion (int, avg of " << trial_count << " trials)" << endl;
  sort::test(insertion_int_f, min_size, max_size, trial_count);
  std::function<void(int*, int*)> selection_int_f = sort::selection_sort<int*>;
  cout << "# selection (int, avg of " << trial_count << " trials)" << endl;
  sort::test(selection_int_f, min_size, max_size, trial_count);
  std::function<void(int*, int*)> bubble_int_f = sort::bubble_sort<int*>;
  cout << "# bubble (int, avg of " << trial_count << " trials)" << endl;
  sort::test(bubble_int_f, min_size, max_size, trial_count);
  std::function<void(int*, int*)> quick_int_f = sort::quick_sort<int*>;
  cout << "# quick (int, avg of " << trial_count << " trials)" << endl;
  sort::test(quick_int_f, min_size_qm, max_size_qm, trial_count);
  std::function<void(int*, int*)> merge_int_f = sort::merge_sort<int*>;
  cout << "# merge (int, avg of " << trial_count << " trials)" << endl;
  sort::test(merge_int_f, min_size_qm, max_size_qm, trial_count);

  // real
  std::function<void(double*, double*)> insertion_real_f = sort::insertion_sort<double*>;
  cout << "# insertion (real, avg of " << trial_count << " trials)" << endl;
  sort::test(insertion_real_f, min_size, max_size, trial_count);
  std::function<void(double*, double*)> selection_real_f = sort::selection_sort<double*>;
  cout << "# selection (real, avg of " << trial_count << " trials)" << endl;
  sort::test(selection_real_f, min_size, max_size, trial_count);
  std::function<void(double*, double*)> bubble_real_f = sort::bubble_sort<double*>;
  cout << "# bubble (real, avg of " << trial_count << " trials)" << endl;
  sort::test(bubble_real_f, min_size, max_size, trial_count);
  std::function<void(double*, double*)> quick_real_f = sort::quick_sort<double*>;
  cout << "# quick (real, avg of " << trial_count << " trials)" << endl;
  sort::test(quick_real_f, min_size_qm, max_size_qm, trial_count);
  std::function<void(double*, double*)> merge_real_f = sort::merge_sort<double*>;
  cout << "# merge (real, avg of " << trial_count << " trials)" << endl;
  sort::test(merge_real_f, min_size_qm, max_size_qm, trial_count);

  // std::string
  std::function<void(string*, string*)> insertion_string_f = sort::insertion_sort<string*>;
  cout << "# insertion (string, avg of " << trial_count << " trials)" << endl;
  sort::test(insertion_string_f, min_size, max_size, trial_count);
  std::function<void(string*, string*)> selection_string_f = sort::selection_sort<string*>;
  cout << "# selection (string, avg of " << trial_count << " trials)" << endl;
  sort::test(selection_string_f, min_size, max_size, trial_count);
  std::function<void(string*, string*)> bubble_string_f = sort::bubble_sort<string*>;
  cout << "# bubble (string, avg of " << trial_count << " trials)" << endl;
  sort::test(bubble_string_f, min_size, max_size, trial_count);
  std::function<void(string*, string*)> quick_string_f = sort::quick_sort<string*>;
  cout << "# quick (string, avg of " << trial_count << " trials)" << endl;
  sort::test(quick_string_f, min_size_qm, max_size_qm, trial_count);
  std::function<void(string*, string*)> merge_string_f = sort::merge_sort<string*>;
  cout << "# merge (string, avg of " << trial_count << " trials)" << endl;
  sort::test(merge_string_f, min_size_qm, max_size_qm, trial_count);

  return 0;
}
