/**
 * test performance
 */
#ifndef SORT_TEST_HPP_
#define SORT_TEST_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <functional>
#include <algorithm>
#include <boost/format.hpp>
#include <boost/concept_check.hpp>
#include "generator.hpp"

namespace sort {

/**
 * get size vec (1000,2000,5000,10000,...)
 */
std::vector<std::size_t> get_size_vec(std::size_t min_size, std::size_t max_size);

/**
 * test
 */
template <typename RandomAccessIterator>
void test(std::function<void (RandomAccessIterator, RandomAccessIterator)> & sorter, std::size_t min_size, std::size_t max_size, std::size_t count) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  // size array
  std::vector<std::size_t> size_vec = get_size_vec(min_size, max_size);
  for (auto size_it = size_vec.begin(); size_it != size_vec.end(); ++size_it) {
    // nanoseconds
    double elapsed_time = 0.0;
    for (std::size_t i = 0; i < count; ++i) {
      // prepare array
      auto array = generate_array<value_type>(*size_it);

      // measure time
      auto start = std::chrono::system_clock::now();
      sorter(array.get(), array.get() + *size_it);
      auto end = std::chrono::system_clock::now();

      // is sorted
      if (!std::is_sorted(array.get(), array.get() + *size_it)) {
        std::cout << "!!!not sorted!!!" << std::endl;
        return;
      }

      // sum time
      elapsed_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    elapsed_time *= 0.000000001 / count;
    std::cout << (boost::format("%8d %.9f") % *size_it % elapsed_time) << std::endl;
  }
}

}

#endif
