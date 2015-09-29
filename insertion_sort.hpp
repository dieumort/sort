/**
 * insertion sort
 */
#ifndef SORT_INSERTION_SORT_HPP_
#define SORT_INSERTION_SORT_HPP_

#include <functional>
#include <iterator>
#include <boost/concept_check.hpp>

namespace sort {

/**
 * insertion sort (std::less)
 */
template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end);

/**
 * insertion sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare);

/**
 * Impl of insertion sort (std::less)
 */
template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  insertion_sort(begin, end, std::less<value_type>());
}

/**
 * Impl of insertion sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  // [begin, i) is sorted
  for (RandomAccessIterator it_i = begin + 1; it_i != end; ++it_i) {
      // a[i]: value to be inserted
      value_type val_i(*it_i);

      // a[j]: a[i] -> a[begin]
      RandomAccessIterator it_j = it_i;
      while (it_j != begin) {
          // a[i] < a[j-1]
          if (compare(val_i, *(it_j-1))) {
              // a[j] = a[j-1]
              *it_j = *(it_j-1);
              --it_j;
          } else {
              // j is the index to insert
              break;
          }
      }

      // insert a[i]
      *it_j = val_i;
  }
}

} // namespace sort

#endif
