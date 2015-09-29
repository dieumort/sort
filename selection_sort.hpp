/**
 * selection sort
 */
#ifndef SORT_SELECTION_SORT
#define SORT_SELECTION_SORT

#include <functional>
#include <iterator>
#include <boost/concept_check.hpp>

//-----------------------------------------------------------------------------

namespace sort {

//-----------------------------------------------------------------------------

/**
 * selection sort (std::less)
 */
template <typename RandomAccessIterator>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end);

/**
 * selection sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare);

//-----------------------------------------------------------------------------

/**
 * Impl of selection sort (std::less)
 */
template <typename RandomAccessIterator>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  // typedef
  typedef std::iterator_traits<RandomAccessIterator> traits;
  typedef typename traits::value_type value_type;

  selection_sort(begin, end, std::less<value_type>());
}

/**
 * Impl of selection sort (compare)
 */
template <typename RandomAccessIterator, typename Compare>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end, Compare compare) {
  // concept
  boost::function_requires<boost::RandomAccessIteratorConcept<RandomAccessIterator> >();

  // [begin, end)
  RandomAccessIterator it_min;
  for (RandomAccessIterator it_i = begin; it_i != end; ++it_i) {
    // min
    it_min = it_i;

    // find min
    for (RandomAccessIterator it_j = it_i + 1; it_j != end; ++it_j) {
      // a[j] < a[min] (if compare == less<T>)
      if (compare(*it_j, *it_min)) {
        it_min = it_j;
      }
    }

    // swap
    std::swap(*it_i, *it_min);
  }
}

//-----------------------------------------------------------------------------

} // namespace sort

//-----------------------------------------------------------------------------

#endif // SORT_SELECTION_SORT_HPP_

//-----------------------------------------------------------------------------
