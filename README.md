# not_std

### Reinventing the standard library

This project was initiated to learn more about data structures by implementing them from scratch. Building them independently also provides flexibility for modifications based on specific requirements.

After completing the initial implementations, the next objective will be to improve performance. The aim is to make the not_std containers faster than the std counterparts, even if it requires sacrificing some safety measures.

### Data structures:

**vector:**
A dynamic array that automatically manages its size. It reallocates memory when elements are added or removed, ensuring efficient use of memory.

**unordered_map:**
A hash table implementation, which provides ![O(n)](https://latex.codecogs.com/svg.image?O(1)) average-time complexity for lookups. It utilizes linear indexing to handle hash collisions.

**pair:**
A simple container comprising two elements, commonly used in data structures to store two related pieces of data.

**string:**
A dynamic character array with null-termination. Provides several utility functions for string manipulations.

**priority_queue:**
A heap-based data structure ensuring the highest (or lowest, based on comparator) priority element remains at the front.

**list:**
A doubly linked list that allows efficient insertion and removal from both ends of the sequence.

**set:**
An associative container that contains unique elements. Implemented as a red-black binary search tree.

**bitset:**
A class that represents a fixed-size sequence of N bits. Bitsets can be manipulated by standard logic operators and converted to and from strings and integers.

### Testing

#### Unit Tests:

For each data structure, I've added unit tests in the **test/unit_test** directory. Whenever I introduce new functionality, I make it a point to update these tests to ensure everything's working as expected.

#### Benchmark Tests:

Beyond just correctness, performance is a critical aspect of data structures. Benchmark tests have been set up to compare the performance of not_std data structures against their standard library counterparts. This serves as an empirical measure of the efficiency of the custom implementations.
