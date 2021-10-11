/*
---------------------------------------------------------
| License: MIT License                                  |
---------------------------------------------------------
| This source file contains all the necessary functions |
| for the merge sort algorithim                         |
---------------------------------------------------------
*/

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
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

static void merge_int(int array[], const unsigned int l, 
                      const unsigned int m, const unsigned int r)
{
        const unsigned int l_len = m - l + 1;
        const unsigned int r_len = r - m;
        unsigned int il, ir, ia;
        int right[r_len];
        int left[l_len]; 

        copy_partition_int(array, l, m, left, 0);
        copy_partition_int(array, m+1, r, right, 0);
        
        for (il=0, ir=0, ia=l; (il<l_len && ir<r_len) ; ia++) {
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

void merge_sort_int(int array[], const unsigned int l, const unsigned int r)
{
        const unsigned int m = (l + r) / 2;

        if (l < r) {
                merge_sort_int(array, l, m);
                merge_sort_int(array, m+1, r);
                merge_int(array, l, m, r);
        }
}

/*
 * Copy a partition from the main array "from" to a subarray "to"
 * from the index from[begin] to the index from[end]. Start copying to "to[i]".
 * Assume "to" is big enough.
 */
static void copy_partition_float(const float from[], unsigned int begin, 
                                 unsigned int end, float to[], unsigned int i)
{
        for (; begin<=end; begin++, i++)
                to[i] = from[begin];
}

static void merge_float(float array[], const unsigned int l, 
                        const unsigned int m, const unsigned int r)
{
        const unsigned int l_len = m - l + 1;
        const unsigned int r_len = r - m;
        unsigned int il, ir, ia;
        float right[r_len];
        float left[l_len]; 

        copy_partition_float(array, l, m, left, 0);
        copy_partition_float(array, m+1, r, right, 0);
        
        for (il=0, ir=0, ia=l; (il<l_len && ir<r_len) ; ia++) {
                if (left[il] < right[ir])
                        array[ia] = left[il++];
                else
                        array[ia] = right[ir++];
        }
        /* left[] is empty */
        if (il == l_len)
                copy_partition_float(right, ir, r_len-1, array, ia);
        /* right[] is empty */
        else
                copy_partition_float(left, il, l_len-1, array, ia);
}

void merge_sort_float(float array[], const unsigned int l, const unsigned int r)
{
        const unsigned int m = (l + r) / 2;

        if (l < r) {
                merge_sort_float(array, l, m);
                merge_sort_float(array, m+1, r);
                merge_float(array, l, m, r);
        }
}

/*
 * Copy a partition from the main array "from" to a subarray "to"
 * from the index from[begin] to the index from[end]. Start copying to "to[i]".
 * Assume "to" is big enough.
 */
static void copy_partition_uint(const unsigned int from[], unsigned int begin, 
                                unsigned int end, unsigned int to[], unsigned int i)
{
        for (; begin<=end; begin++, i++)
                to[i] = from[begin];
}

static void merge_uint(unsigned int array[], const unsigned int l, 
                       const unsigned int m, const unsigned int r)
{
        const unsigned int l_len = m - l + 1;
        const unsigned int r_len = r - m;
        unsigned int il, ir, ia;
        unsigned int right[r_len];
        unsigned int left[l_len];

        copy_partition_uint(array, l, m, left, 0);
        copy_partition_uint(array, m+1, r, right, 0);
        
        for (il=0, ir=0, ia=l; (il<l_len && ir<r_len) ; ia++) {
                if (left[il] < right[ir])
                        array[ia] = left[il++];
                else
                        array[ia] = right[ir++];
        }
        /* left[] is empty */
        if (il == l_len)
                copy_partition_uint(right, ir, r_len-1, array, ia);
        /* right[] is empty */
        else
                copy_partition_uint(left, il, l_len-1, array, ia);
}

void merge_sort_uint(unsigned int array[], 
                     const unsigned int l, 
                     const unsigned int r)
{
        const unsigned int m = (l + r) / 2;

        if (l < r) {
                merge_sort_uint(array, l, m);
                merge_sort_uint(array, m+1, r);
                merge_uint(array, l, m, r);
        }
}

/*
 * Copy a partition from the main array "from" to a subarray "to"
 * from the index from[begin] to the index from[end]. Start copying to "to[i]".
 * Assume "to" is big enough.
 */
static void copy_partition_lint(const long int from[], unsigned int begin, 
                                unsigned int end, long int to[], unsigned int i)
{
        for (; begin<=end; begin++, i++)
                to[i] = from[begin];
}

static void merge_lint(long int array[], const unsigned int l, 
                       const unsigned int m, const unsigned int r)
{
        const unsigned int l_len = m - l + 1;
        const unsigned int r_len = r - m;
        unsigned int il, ir, ia;
        long int right[r_len];
        long int left[l_len]; 

        copy_partition_lint(array, l, m, left, 0);
        copy_partition_lint(array, m+1, r, right, 0);
        
        for (il=0, ir=0, ia=l; (il<l_len && ir<r_len) ; ia++) {
                if (left[il] < right[ir])
                        array[ia] = left[il++];
                else
                        array[ia] = right[ir++];
        }
        /* left[] is empty */
        if (il == l_len)
                copy_partition_lint(right, ir, r_len-1, array, ia);
        /* right[] is empty */
        else
                copy_partition_lint(left, il, l_len-1, array, ia);
}

void merge_sort_lint(long int array[], 
                     const unsigned int l, 
                     const unsigned int r)
{
        const unsigned int m = (l + r) / 2;

        if (l < r) {
                merge_sort_lint(array, l, m);
                merge_sort_lint(array, m+1, r);
                merge_lint(array, l, m, r);
        }
}

/*
 * Return 1 if word_to_check should come before assumed_smaller
 * alphabetically, otherwise return 0.
 */
static bool alpha_cmp(const char *assumed_smaller, 
                      const char *word_to_check) 
{
	const size_t assumed_len = strlen(assumed_smaller);
	const size_t check_len = strlen(word_to_check);
	size_t min_len, i;

	min_len = (assumed_len < check_len) ? assumed_len : check_len; 
	
	for (i=0; i<min_len; i++) {
                if (isalpha(word_to_check[i]) 
	          && isalpha(assumed_smaller[i])) {
                        if (word_to_check[i] < assumed_smaller[i])
                                return 1;
                        else if (assumed_smaller[i] < word_to_check[i])
                                return 0;
                } else {
                        if (!isalpha(assumed_smaller[i]) 
                          && isalpha(word_to_check[i]))
                                return 1;
                        else if (isalpha(assumed_smaller[i])
                              && !isalpha(word_to_check[i]))
                                return 0;
                }
        }
        return (check_len < assumed_len);
}

static void convert_to_lower(char *str)
{
        unsigned int i;

        for (i=0; str[i]!='\0'; i++)
                if (isupper(str[i]))
                        str[i] = tolower(str[i]);
}

/*
 * Make a small letter copy of src to dst. Make sure that 
 * dst has enough space to hold src
 */
static void make_small_copy(const char *src, char *dst)
{
        const size_t size = strlen(src) + 1;

        memcpy(dst, src, size);
        convert_to_lower(dst);
}

/*
 * An alpha_cmp() wrapper that creates a lower case
 * copy of the assumed_smaller and word_to_check arguments,
 * then returns the alpha_cmp() value.
 */
static bool alpha_cmp_lower(const char *assumed_smaller, 
                            const char *word_to_check)
{
        const size_t assumed_smaller_len = strlen(assumed_smaller) + 1;
        const size_t word_to_check_len = strlen(word_to_check) + 1;
        char assumed_smaller_cp[assumed_smaller_len];
        char word_to_check_cp[word_to_check_len];

        make_small_copy(assumed_smaller, assumed_smaller_cp);
        make_small_copy(word_to_check, word_to_check_cp);

        return alpha_cmp(assumed_smaller_cp, word_to_check_cp);
}

/*
 * Copy a partition from the main array "from" to a subarray "to"
 * from the index from[begin] to the index from[end]. Start copying to "to[i]".
 * Assume "to" is big enough.
 */
static void copy_partition_str(char *const from[], unsigned int begin, 
                               unsigned int end, char *to[], unsigned int i)
{
        for (; begin<=end; begin++, i++)
                to[i] = from[begin];
}

static void merge_str(char *array[], const unsigned int l, 
                      const unsigned int m, const unsigned int r)
{
        const unsigned int l_len = m - l + 1;
        const unsigned int r_len = r - m;
        unsigned int il, ir, ia;
        char *right[r_len];
        char *left[l_len]; 

        copy_partition_str(array, l, m, left, 0);
        copy_partition_str(array, m+1, r, right, 0);
        
        for (il=0, ir=0, ia=l; (il<l_len && ir<r_len) ; ia++) {
                if (alpha_cmp_lower(right[ir], left[il]))
                        array[ia] = left[il++];
                else
                        array[ia] = right[ir++];
        }
        /* left[] is empty */
        if (il == l_len)
                copy_partition_str(right, ir, r_len-1, array, ia);
        /* right[] is empty */
        else
                copy_partition_str(left, il, l_len-1, array, ia);
}

void merge_sort_str(char *array[], const unsigned int l, const unsigned int r)
{
        const unsigned int m = (l + r) / 2;

        if (l < r) {
                merge_sort_str(array, l, m);
                merge_sort_str(array, m+1, r);
                merge_str(array, l, m, r);
        }
}

