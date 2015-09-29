/**
 * quick sort
 */
#ifndef SORT_QUICK_SORT_HPP_
#define SORT_QUICK_SORT_HPP_

#include <functional>
#include <iterator>
#include <boost/concept_check.hpp>
#include "insertion_sort.hpp"

//-----------------------------------------------------------------------------

namespace sort {

//-----------------------------------------------------------------------------

/**
 * quick sort (std::less)
 */
template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator begin, RandomAccessIterator end);

/**
 * quick sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void quick_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare);

//-----------------------------------------------------------------------------

/**
 * Impl of quick sort (std::less)
 */
template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  quick_sort(begin, end, std::less<value_type>());
}

/**
 * Impl of quick sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void quick_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  // small range
  const std::size_t th = 16;
  const std::size_t distance = std::distance(begin, end);
  if (th >= distance) {
    // insertion sort
    insertion_sort(begin, end);
    return;
  }

  // find pivot
  RandomAccessIterator mid = begin + (distance / 2);

  // begin > mid
  if (!compare(*begin, *mid)) {
    std::swap(*begin, *mid);
  }
  // begin > end-1
  if (!compare(*begin, *(end-1))) {
    std::swap(*begin, *(end-1));
  }
  // mid > end-1
  if (!compare(*mid, *(end-1))) {
    std::swap(*mid, *(end-1));
  }

  value_type pivot = *mid;
  RandomAccessIterator left = begin;
  RandomAccessIterator right = end-1;
  while (left <= right) {
    // left
    while (left < end-1 && compare(*left, pivot)) {
      ++left;
    }

    // right
    while (begin < right && !compare(*right, pivot)) {
      --right;
    }

    if (left > right) {
      break;
    }

    std::swap(*left, *right);
    ++left;
    --right;
  }

  // recursive
  quick_sort(begin, left, compare);
  quick_sort(left, end, compare);
}

//-----------------------------------------------------------------------------

} // namespace sort

//-----------------------------------------------------------------------------

#endif // SORT_QUICK_SORT_HPP_

//-----------------------------------------------------------------------------
