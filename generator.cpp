/**
 * generator
 */

 #include <string>
 #include <limits>
 #include <random>
 #include "generator.hpp"

 namespace sort {

 /**
  * Impl of generate int array
  */
 template <>
 std::shared_ptr<int> generate_array(std::size_t size) {
  // typedef
  typedef std::mt19937 engine_type;
  typedef std::uniform_int_distribution<int> distribution_type;

  // min, max
  const int min = std::numeric_limits<int>::min();
  const int max = std::numeric_limits<int>::max();

  // generator
  std::random_device rnd;
  engine_type engine(rnd());
  distribution_type distribution(min, max);

  // array
  std::shared_ptr<int> array(new int[size], std::default_delete<int[]>());
  for (std::size_t i = 0; i < size; ++i) {
    array.get()[i] = distribution(engine);
  }

  return array;
 }

 /**
  * Impl of generate double array
  */
 template <>
 std::shared_ptr<double> generate_array(std::size_t size) {
  // typedef
  typedef std::mt19937 engine_type;
  typedef std::uniform_real_distribution<double> distribution_type;

  // generator
  std::random_device rnd;
  engine_type engine(rnd());
  distribution_type distribution(0, 1);

  // array
  std::shared_ptr<double> array(new double[size], std::default_delete<double[]>());
  for (std::size_t i = 0; i < size; ++i) {
    array.get()[i] = distribution(engine);
  }

  return array;
 }

 // Impl of generate std::string array
 template <>
 std::shared_ptr<std::string> generate_array(std::size_t size) {
  // typedef
  typedef std::mt19937 engine_type;
  typedef std::uniform_int_distribution<std::size_t> distribution_type;

  // min, max
  const std::size_t min = std::numeric_limits<std::size_t>::min();
  const std::size_t max = std::numeric_limits<std::size_t>::max();

  // generator
  std::random_device rnd;
  engine_type engine(rnd());
  distribution_type distribution(min, max);

  // graphic characters
  const char min_char = static_cast<char>(0x21);
  const char max_char = static_cast<char>(0x7E);
  const std::size_t len = 8;

  // array
  std::shared_ptr<std::string> array(new std::string[size], std::default_delete<std::string[]>());
  for (std::size_t i = 0; i < size; ++i) {
    // generate
    array.get()[i].reserve(len);
    for (std::size_t j = 0; j < len; ++j) {
      array.get()[i] += (min_char + (distribution(engine) % (max_char - min_char)));
    }
  }

  return array;
 }

 }
