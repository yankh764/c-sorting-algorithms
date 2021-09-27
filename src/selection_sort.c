/*
---------------------------------------------------------
| License: MIT License                                  |
---------------------------------------------------------
| This source file contains all the necessary functions |
| for the selection sort algorithim                     |
---------------------------------------------------------
*/

#include "selection_sort.h"

/*
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_int_i(int array[], 
                                  unsigned int i, 
                                  const unsigned int size)
{
        unsigned int min;

        for (min=i; i<size;)
                if (array[++i] < array[min])
                        min = i;
        return min;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void selection_sort_int_swap(int array[], 
                                    const unsigned int src, 
                                    const unsigned int dst)
{
        int tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

void selection_sort_int(int array[], const unsigned int size)
{
       unsigned int i;

       for (i=0; i<size-1; i++)
               selection_sort_int_swap(array, get_min_int_i(array, i, size), i);
}

/*
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_float_i(float array[], 
                                    unsigned int i, 
                                    const unsigned int size)
{
        unsigned int min;

        for (min=i; i<size;)
                if (array[++i] < array[min])
                        min = i;
        return min;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void selection_sort_float_swap(float array[], 
                                      const unsigned int src, 
                                      const unsigned int dst)
{
        float tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

void selection_sort_float(float array[], const unsigned int size)
{
       unsigned int i;

       for (i=0; i<size-1; i++)
               selection_sort_float_swap(array, 
                                         get_min_float_i(array, i, size), 
                                         i);
}
