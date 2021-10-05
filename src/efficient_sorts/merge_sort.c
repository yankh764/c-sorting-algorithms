/*
---------------------------------------------------------
| License: MIT License                                  |
---------------------------------------------------------
| This source file contains all the necessary functions |
| for the merge sort algorithim                         |
---------------------------------------------------------
*/

#include <stdio.h>
#include "merge_sort.h"

/*
 * Copy a partition from the main array "from" to a subarray "to"
 * from the index from[begin] to the index from[end]. Start copying to "to[i]".
 * Assume "to" is big enough.
 */
static void copy_partition_int(const int from[], unsigned int begin, 
                               unsigned int end, int to[], unsigned int i)
{
        for (; begin<=end; begin++, i++)
                to[i] = from[begin];
}

static void merge_int(const int left[], const unsigned int l_len, 
                      const int right[], const unsigned int r_len, 
                      int array[])
{
        unsigned int il, ir, ia;

        for (il=0, ir=0, ia=0; (il<l_len && ir<r_len) ; ia++) {
                if (left[il] < right[ir])
                        array[ia] = left[il++];
                else
                        array[ia] = right[ir++];
        }
        /* left[] is empty */
        if (il == l_len)
                copy_partition_int(right, ir, r_len-1, array, ia);
        /* right[] is empty */
        else
                copy_partition_int(left, il, l_len-1, array, ia);
}

void merge_sort_int(int array[], const unsigned int len)
{
        const unsigned int middle = len / 2;
        const unsigned int l_len = middle;
        const unsigned int r_len = len - l_len;
        int right[r_len];
        int left[l_len]; 

        if (middle) {
                copy_partition_int(array, 0, middle-1, left, 0);
                copy_partition_int(array, middle, len-1, right, 0);
                merge_sort_int(left, l_len);
                merge_sort_int(right, r_len);
                merge_int(left, l_len, right, r_len, array);
        }
}

