/*
---------------------------------------------------------
| License: MIT License                                  |
---------------------------------------------------------
| This source file contains all the necessary functions |
| for the selection sort algorithim                     |
---------------------------------------------------------
*/

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "selection_sort.h"

/*
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_int_i(const int array[], 
                                  unsigned int i, 
                                  const unsigned int size)
{
        unsigned int min;

        for (min=i++; i<size; i++)
                if (array[i] < array[min])
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
static unsigned int get_min_float_i(const float array[], 
                                    unsigned int i, 
                                    const unsigned int size)
{
        unsigned int min;

        for (min=i++; i<size; i++)
                if (array[i] < array[min])
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

/*
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_uint_i(const unsigned int array[], 
                                   unsigned int i, 
                                   const unsigned int size)
{
        unsigned int min;

        for (min=i++; i<size; i++)
                if (array[i] < array[min])
                        min = i;
        return min;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void selection_sort_uint_swap(unsigned int array[], 
                                     const unsigned int src, 
                                     const unsigned int dst)
{
        unsigned int tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

void selection_sort_uint(unsigned int array[], const unsigned int size)
{
       unsigned int i;

       for (i=0; i<size-1; i++)
               selection_sort_uint_swap(array, get_min_uint_i(array, i, size), i);
}

/*
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_long_int_i(const long int array[], 
                                       unsigned int i, 
                                       const unsigned int size)
{
        unsigned int min;

        for (min=i++; i<size; i++)
                if (array[i] < array[min])
                        min = i;
        return min;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void selection_sort_long_int_swap(long int array[], 
                                         const unsigned int src, 
                                         const unsigned int dst)
{
        long int tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

void selection_sort_long_int(long int array[], const unsigned int size)
{
       unsigned int i;

       for (i=0; i<size-1; i++)
               selection_sort_long_int_swap(array, 
                                            get_min_long_int_i(array, i, size), 
                                            i);
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
 * Get the index of the element with the smaller value from
 * array[i] to array[size-1]
 */
static unsigned int get_min_str_i(char *const array[], 
                                  unsigned int i, 
                                  const unsigned int size)
{
        unsigned int min;

        for (min=i++; i<size; i++)
                if (alpha_cmp_lower(array[min], array[i]))
                        min = i;
        return min;
}

/*
 * Swap array[src] and array[dst]
 * (array[src] to array[dst] and array[dst] to array[src])
 */
static void selection_sort_str_swap(char *array[], 
                                    const unsigned int src, 
                                    const unsigned int dst)
{
        char *tmp;

        tmp = array[dst];
        array[dst] = array[src];
        array[src] = tmp;
}

void selection_sort_str(char *array[], const unsigned int size)
{
       unsigned int i;

       for (i=0; i<size-1; i++)
               selection_sort_str_swap(array, get_min_str_i(array, i, size), i);
}
