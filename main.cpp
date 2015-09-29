/**
 * main file for sort
 */
#include <iostream>
#include <random>
#include "test.hpp"
#include "insertion_sort.hpp"

using namespace std;

int main(int argc, char const * argv[]) {
  std::function<void(int*,int*)> f = sort::insertion_sort<int*>;
  sort::test(f, 1000, 10000, 10);

  return 0;
}
