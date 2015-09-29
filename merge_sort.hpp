/**
 * merge sort
 */
#ifndef SORT_MERGE_SORT_HPP_
#define SORT_MERGE_SORT_HPP_

#include <functional>
#include <iterator>
#include <memory>
#include <boost/concept_check.hpp>
#include "insertion_sort.hpp"

//-----------------------------------------------------------------------------

namespace sort {

//-----------------------------------------------------------------------------

/**
 * merge sort (std::less)
 */
template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end);

/**
 * merge sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare);

//-----------------------------------------------------------------------------

/**
 * Impl of merge sort (body)
 */
template <typename RandomAccessIterator, typename Compare, typename T>
void merge_sort_body(RandomAccessIterator begin, RandomAccessIterator end, Compare compare, T * work_begin, T * work_end);

/**
 * Impl of merge sort (std::less)
 */
template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  merge_sort(begin, end, std::less<value_type>());
}

/**
 * Impl of merge sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  // workspace
  const std::size_t size = std::distance(begin, end);
  std::shared_ptr<value_type> work_array(new value_type[size],  std::default_delete<value_type[]>());

  merge_sort_body(begin, end, compare, work_array.get(), work_array.get() + size);
}

/**
 * Impl of merge sort (body)
 */
template <typename RandomAccessIterator, typename Compare, typename T>
void merge(RandomAccessIterator begin, RandomAccessIterator mid, RandomAccessIterator end, Compare compare, T * work_begin, T * work_mid) {
  RandomAccessIterator i, j;
  T * work_i;

  // copy half
  for (i = begin, work_i = work_begin; i != mid; ++i, ++work_i) {
    *work_i = *i;
  }

  // merge
  for (j = begin, work_i = work_begin; i != end && work_i != work_mid; ++j) {
    if (compare(*i, *work_i)) {
      *j = *i;
      ++i;
    } else {
      *j = *work_i;
      ++work_i;
    }
  }

  // rest
  for ( ; i != end; ++i, ++j) {
    *j = *i;
  }

  for ( ; work_i != work_mid; ++work_i, ++j) {
    *j = *work_i;
  }
}

/**
 * Impl of merge sort (body)
 */
template <typename RandomAccessIterator, typename Compare, typename T>
void merge_sort_body(RandomAccessIterator begin, RandomAccessIterator end, Compare compare, T * work_begin, T * work_end) {
  // small range
  const std::size_t th = 16;
  const std::size_t distance = std::distance(begin, end);
  if (th >= distance) {
    // insertion sort
    insertion_sort(begin, end);
    return;
  }

  // recursive
  RandomAccessIterator mid = begin + (distance / 2);
  T * work_mid = work_begin + (distance / 2);
  merge_sort_body(begin, mid, compare, work_begin, work_mid);
  merge_sort_body(mid, end, compare, work_mid, work_end);

  // merge
  merge(begin, mid, end, compare, work_begin, work_mid);
}

//-----------------------------------------------------------------------------

} // namespace sort

//-----------------------------------------------------------------------------

#endif // SORT_MERGE_SORT_HPP_

//-----------------------------------------------------------------------------
