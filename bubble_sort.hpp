/**
 * bubble sort
 */
#ifndef SORT_BUBBLE_SORT
#define SORT_BUBBLE_SORT

#include <functional>
#include <iterator>
#include <boost/concept_check.hpp>

//-----------------------------------------------------------------------------

namespace sort {

//-----------------------------------------------------------------------------

/**
 * bubble sort (std::less)
 */
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end);

/**
 * bubble sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare);

//-----------------------------------------------------------------------------

/**
 * Impl of bubble sort (std::less)
 */
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  bubble_sort(begin, end, std::less<value_type>());
}

/**
 * Impl of bubble sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // [begin, end - 1)
  for (RandomAccessIterator it_i = begin; it_i != end - 1; ++it_i) {
    // j: end - 1 -> i
    for (RandomAccessIterator it_j = end - 1; it_j != it_i; --it_j) {
      // a[j] < a[j-1] (if compare == less<T>)
      if (compare(*it_j, *(it_j - 1))) {
        std::swap(*it_j, *(it_j - 1));
      }
    }
  }
}

//-----------------------------------------------------------------------------

} // namespace sort

//-----------------------------------------------------------------------------

#endif // SORT_BUBBLE_SORT_HPP_

//-----------------------------------------------------------------------------
