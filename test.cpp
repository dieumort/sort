/**
 * test performance
 */

#include "test.hpp"

namespace sort {

/**
 * get size vec (1000,2000,5000,10000,...)
 */
std::vector<std::size_t> get_size_vec(std::size_t min_size, std::size_t max_size) {
  // unit
  const std::size_t factorial = static_cast<std::size_t>(log10(min_size));
  std::size_t unit = static_cast<std::size_t>(pow(10, factorial));

  // vector
  std::vector<std::size_t> vec;
  std::size_t size = min_size;
  while (size <= max_size) {
    // add
    vec.push_back(size);

    // next
    if (size < 2 * unit) {
      size = 2 * unit;
    } else if (size < 5 * unit) {
      size = 5 * unit;
    } else {
      size = 10 * unit;
      unit *= 10;
    }
  }

  return vec;
}

}
