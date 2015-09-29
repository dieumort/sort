/**
 * generator
 */
#ifndef SORT_GENERATOR_HPP_
#define SORT_GENERATOR_HPP_

#include <memory>

namespace sort {

/**
 * generate array
 */
template <typename T>
std::shared_ptr<T> generate_array(std::size_t size);

}

#endif
