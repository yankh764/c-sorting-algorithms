/*
---------------------------------------------------------
| License: MIT License                                  |
---------------------------------------------------------
| This source file contains all the necessary functions |
| for the heap sort algorithim                          |
---------------------------------------------------------
*/

#include "heap_sort.h"

/*
 * Find the largest value among root, left child and right child 
 * and return it's index in the array.
 */
static unsigned int get_largest_int(int array[], 
                                    const unsigned int size,
                                    const unsigned int root_i,
                                    const unsigned int li_child,
                                    const unsigned int ri_child)
{
        if ((li_child < size) && (array[li_child] > array[root_i]))
                return li_child;
        else if ((ri_child < size) && (array[ri_child] > array[root_i]))
                return ri_child;
        else
                return root_i;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void heap_sort_int_swap(int array[], 
                               const unsigned int src, 
                               const unsigned int dst)
{
        int tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

static void heapify_int(int array[], 
                        const unsigned int i, 
                        const unsigned int size)
{
        const unsigned int li_child = 2 * i + 1;
        const unsigned int ri_child = 2 * i + 2;
        unsigned int largest;

        largest = get_largest_int(array, size, i, li_child, ri_child);

        if (largest != i) {
                heap_sort_int_swap(array, largest, i);
                heapify_int(array, largest, size);
        }
}

static void build_max_heap_int(int array[], const unsigned int size)
{
        long int i;

        for (i=(size/2)-1; i>-1; i--)
                heapify_int(array, i, size);
}

void heap_sort_int(int array[], const unsigned int size)
{
        long int i;

        build_max_heap_int(array, size);

        for (i=size-1; i>-1; i--)
                heap_sort_int_swap(array, i, 0);

        heapify_int(array, 0, i);
}
