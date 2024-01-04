#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Function pointer types for comparison and operations
typedef int (*CompareFunc)(const void *, const void *);
typedef void (*ForEachOpFunc)(void *);
typedef void (*TransformFunc)(void*);
typedef void (*ReduceFunc)(void*);
typedef void (*AccumulateOpFunc)(void *, const void *);
typedef bool (*BoolPredicateFunc)(const void *);
typedef uint32_t (*UniformRandomNumberGenerator)(void);

void algorithm_sort(void *base, size_t num, size_t size, CompareFunc comp);
void *algorithm_find(const void *base, size_t num, size_t size, const void *val, CompareFunc comp);
void *algorithm_find_if(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
void *algorithm_find_if_not(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
void *algorithm_find_end(const void *base1, size_t num1, size_t size1, const void *base2, size_t num2, size_t size2, CompareFunc comp);
void *algorithm_find_first_of(const void *base1, size_t num1, size_t size1, const void *base2, size_t num2, size_t size2, CompareFunc comp);
void algorithm_copy(const void *source, size_t num, size_t size, void *dest);
void *algorithm_accumulate(const void *base, size_t num, size_t size, void *init, AccumulateOpFunc op);
void algorithm_for_each(void *base, size_t num, size_t size, ForEachOpFunc op);
void *algorithm_max_element(const void *base, size_t num, size_t size, CompareFunc comp);
void *algorithm_min_element(const void *base, size_t num, size_t size, CompareFunc comp);
bool algorithm_all_of(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
bool algorithm_any_of(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
bool algorithm_none_of(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
void *algorithm_lower_bound(const void *base, size_t num, size_t size, const void *val, CompareFunc comp);
void *algorithm_upper_bound(const void *base, size_t num, size_t size, const void *val, CompareFunc comp);
bool algorithm_binary_search(const void *base, size_t num, size_t size, const void *val, CompareFunc comp);
void algorithm_transform(const void *base, size_t num, size_t size, void *result, TransformFunc op);
void *algorithm_reduce(const void *base, size_t num, size_t size, void *init, ReduceFunc op);
void *algorithm_partition(void *base, size_t num, size_t size, BoolPredicateFunc pred);
void algorithm_nth_element(void *base, size_t num, size_t size, size_t n, CompareFunc comp);
size_t algorithm_unique(void *base, size_t num, size_t size, CompareFunc comp);
void algorithm_merge(const void *base1, size_t num1, const void *base2, size_t num2, size_t size, void *result, CompareFunc comp);
void algorithm_inplace_merge(void *base, size_t middle, size_t num, size_t size, CompareFunc comp);
void *algorithm_adjacent_find(const void *base, size_t num, size_t size, CompareFunc comp);
size_t algorithm_count(const void *base, size_t num, size_t size, const void *val, CompareFunc comp);
size_t algorithm_count_if(const void *base, size_t num, size_t size, BoolPredicateFunc pred);
void *algorithm_mismatch(const void *base1, size_t num1, size_t size1, const void *base2, size_t num2, size_t size2, CompareFunc comp);
bool algorithm_equal(const void *base1, size_t num1, size_t size1, const void *base2, size_t num2, size_t size2, CompareFunc comp);
bool algorithm_is_permutation(const void *base1, size_t num1, size_t size1, const void *base2, size_t num2, size_t size2, CompareFunc comp);
void *algorithm_search(const void *base, size_t num, size_t size, const void *sub, size_t sub_num, size_t sub_size, CompareFunc comp);
void *algorithm_search_n(const void *base, size_t num, size_t size, size_t count, const void *val, CompareFunc comp);
void algorithm_fill(void *first, void *last, size_t size, const void *val);
void algorithm_fill_n(void *first, size_t n, size_t size, const void *val);
void algorithm_shuffle(void *base, size_t num, size_t size, UniformRandomNumberGenerator rng);

#endif // ALGORITHM_H_