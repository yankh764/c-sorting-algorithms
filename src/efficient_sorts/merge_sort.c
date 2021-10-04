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
 * from the index from[begin] to the index from[end]. Assume "to"
 * is big enough.
 */
static void copy_partition(const int from[], int to[],
                           const unsigned int begin, 
                           const unsigned int end)
{
        unsigned int i;
        
        for (i=begin; i<=end; i++)
                to[i] = from[i];
}

static void merge_int(const int left[], const unsigned int l_len, 
                      const int right[], const unsigned int r_len, 
                      int array[])
{
        unsigned int i_l, i_r, i;

        for (i_l=i_r=i=0; ; i++) {
                if (i_l<l_len && i_r<r_len) {
                        if (left[i_l] < right[i_r])
                                array[i] = left[i_l++];
                        else
                                array[i] = right[i_r++];
                } else {
                        if (i_l == l_len)
                                copy_partition(right, array, i_r, r_len-1);
                        else
                                copy_partition(left, array, i_l, l_len-1);
                        break;
                }
        }
}

void merge_sort_int(int array[], const unsigned int len)
{
        const unsigned int middle = len / 2;
        const unsigned int l_len = middle;
        const unsigned int r_len = len - l_len;
        int right[r_len];
        int left[l_len]; 

        if (middle) {
                copy_partition(array, left, 0, middle-1);
                copy_partition(array, right, middle, len-1);
                merge_sort_int(left, l_len);
                merge_sort_int(right, r_len);
                merge_int(left, l_len, right, r_len, array);
        }
}

/*
                        1 4 3 2
                   1 4           3 2
                 1     4       3     2
                   1 4           2 3
                        1 2 3 4        

*/
