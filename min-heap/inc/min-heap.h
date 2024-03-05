/**
 * @file min-heap.h
 * @brief Library that implements a minimum heap with a static array without
 * dinamic memory allocation
 *
 * @date 29 Feb 2024
 * @author Antonio Gelain [antonio.gelain@studenti.unitn.it]
 */

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Type definition for the min heap structure
 * @details As an example you can declare and initialize a new heap structure
 * that can contain 10 integers as follows:
 *      int8_t min_heap_compare(int a, int b) {
 *          if (a < b) return -1;
 *          return a == b ? 0 : 1;
 *      }
 *      MinHeap(int, 10) heap = min_heap_init(int, 10, min_heap_compare);
 *
 * @details The last item in the data array is used as swap storage when two items
 * in the array needs to be swapped
 *
 * @param TYPE The data type
 * @param CAPACITY The maximum number of elements of the heap
 *
 * @param data_size The size a single element in bytes
 * @param size The number of elements currently inside the heap
 * @param capacity The maximum number of elements that heap can contain
 * @param data The heap data
 * @param compare A pointer to a function that compares two items an returns:
 *     - -1: if the first item is less than the second
 *     -  0: if the items are equal
 *     -  1: if the first item is greater than the second
 */
#define MinHeap(TYPE, CAPACITY) \
struct { \
    uint16_t data_size; \
    size_t size; \
    size_t capacity; \
    int8_t (* compare)(void *, void *); \
    TYPE data[CAPACITY + 1]; \
}

/**
 * @brief Min heap structure initialization
 * @attention The TYPE and CAPACITY variables must be the same as the ones
 * in the structure declaration above
 * @details As an example you can declare and initialize a new heap structure
 * that can contain 10 integers as follows:
 *      int8_t min_heap_compare(int a, int b) {
 *          if (a < b) return -1;
 *          return a == b ? 0 : 1;
 *      }
 *      MinHeap(int, 10) heap = min_heap_init(int, 10, min_heap_compare);
 *
 * @param TYPE The data type
 * @param CAPACITY The maximum number of elements of the heap
 * @param CMP_CALLBACK The callback function used to compare items in the heap
 */
#define min_heap_init(TYPE, CAPACITY, CMP_CALLBACK) \
{ \
    .data_size = sizeof(TYPE), \
    .size = 0, \
    .capacity = CAPACITY, \
    .compare = CMP_CALLBACK, \
    .data = { 0 } \
}

/**
 * @brief Structure definition used to pass the heap handler as a function parameter
 * @attention This structure should not be used directly
 */
typedef struct {
    uint16_t data_size;
    size_t size;
    size_t capacity;
    int8_t (* compare)(void *, void *);
    void * data;
} MinHeapInterface;

/**
 * @brief Get the number of elements inside the heap
 *
 * @param heap The heap handler structure
 * @return size_t The current size
 */
#define min_heap_size(heap) _min_heap_size((MinHeapInterface *)(heap))

/**
 * @brief Check if the heap is empty
 * @details If heap is NULL it is considered as empty
 *
 * @param heap The heap handler structure
 * @return bool True if the heap is empty, false otherwise
 */
#define min_heap_is_empty(heap) _min_heap_is_empty((MinHeapInterface *)(heap))

/**
 * @brief Check if the heap is full
 * @details If heap is NULL it is considered as full
 *
 * @param heap The heap handler structure
 * @return bool True if the heap is full, false otherwise
 */
#define min_heap_is_full(heap) _min_heap_is_full((MinHeapInterface *)(heap))

/**
 * @brief Get the first element in the heap (the minimum)
 * @attention The return value can be NULL
 * @attention The returned item is treated as an array of bytes and has to be converted
 *
 * @param heap The heap handler structure
 * @return uint8_t ** A pointer to the minimum element
 */
#define min_heap_top(heap) _min_heap_top((MinHeapInterface *)(heap))

/**
 * @brief Clear the heap removing all elements
 *
 * @param heap The heap handler structure
 */
#define min_heap_clear(heap) _min_heap_clear((MinHeapInterface *)(heap))

/**
 * @brief Insert an element in the heap
 *
 * @param heap The heap handler structure
 * @param item The item to insert
 * @return bool True if the item is inserted correctly, false otherwise
 */
#define min_heap_insert(heap, item) _min_heap_insert((MinHeapInterface *)(heap), (void *)(item))

/**
 * @brief Remove an element from the heap
 * @attention 'out' can be NULL
 * @details If 'out' is not NULL the item data is copied into it
 *
 * @param heap The heap handler structure
 * @param index The index of the item to remove in the heap
 * @param out The removed item (has to be an address)
 * @return bool True if the item is removed correctly, false otherwise
 */
#define min_heap_remove(heap, index, out) _min_heap_remove((MinHeapInterface *)(heap), index, (void *)(out))


/******************************************/
/*   DO NOT USE THE FOLLOWING FUNCTIONS   */
/*         USE THE MACRO INSTEAD          */
/******************************************/

size_t _min_heap_size(MinHeapInterface * heap);
bool _min_heap_is_empty(MinHeapInterface * heap);
bool _min_heap_is_full(MinHeapInterface * heap);
void * _min_heap_top(MinHeapInterface * heap);
void _min_heap_clear(MinHeapInterface * heap);
bool _min_heap_insert(MinHeapInterface * heap, void * item);
bool _min_heap_remove(MinHeapInterface * heap, size_t index, void * out);

#endif  // MIN_HEAP_H

