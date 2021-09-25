#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "ins_sort.h"

/*
 * Swap array[key] and array[key-1] 
 * (array[key] to array[key-1] and array[key-1] to array[key])
 */
static void insertion_sort_int_swap(int array[], const unsigned int key) 
{
        int tmp;
       
        tmp = array[key];
        array[key] = array[key-1];
        array[key-1] = tmp;
}

static void insertion_sort_int_backward(int array[], unsigned int key)
{
        long int i = (long int) key - 1;

        for (; i>-1; i--, key--)
                if (array[key] < array[i])
                        insertion_sort_int_swap(array, key);
}

/*
 * I decided to enter the arguments type src[] and dst[] like
 * this and not *src and *dst to avoid confusion for the users
 */
void insertion_sort_int(int array[], const unsigned int size)
{
        unsigned int i, key;

        for (i=0, key=1; key<size; i++, key++)
                if (array[key] < array[i]) {
                        insertion_sort_int_swap(array, key);
                        /* 
                         * After the previous swap the current key is 
                         * equal to i since array[key] was moved t array[i] 
                         */
                        insertion_sort_int_backward(array, i);
                }
}

/*
 * Swap array[key] and array[key-1] 
 * (array[key] to array[key-1] and array[key-1] to array[key])
 */
static void insertion_sort_float_swap(float array[], const unsigned int key) 
{
        float tmp;
       
        tmp = array[key];
        array[key] = array[key-1];
        array[key-1] = tmp;
}

static void insertion_sort_float_backward(float array[], unsigned int key)
{
        long int i = (long int) key - 1;

        for (; i>-1; i--, key--)
                if (array[key] < array[i])
                        insertion_sort_float_swap(array, key);
}

/*
word_to_check[i] * I decided to enter the arguments type src[] and dst[] like
 * this and not *src and *dst to avoid confusion for the users
 */
void insertion_sort_float(float array[], const unsigned int size)
{
        unsigned int i, key;

        for (i=0, key=1; key<size; i++, key++)
                if (array[key] < array[i]) {
                        insertion_sort_float_swap(array, key);
                        /* 
                         * After the previous swap the current key is 
                         * equal to i since array[key] was moved t array[i] 
                         */
                        insertion_sort_float_backward(array, i);
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
			return (word_to_check[i] < assumed_smaller[i]);
                } else {
                        if (!isalpha(assumed_smaller[i]) 
                          && isalpha(word_to_check[i]))
                                return 1;
                        else if (isalpha(assumed_smaller[i])
                              && !isalpha(word_to_check[i]))
                                return 0;
                }
        }
	/* 
         * If haven't returned yet, return 1 if  
	 * check_len < assumed_len, otherwise return 0 
         */	
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
 * An alpha_cmp() wrapper that creates a lower case
 * copy of the assumed_smaller and word_to_check arguments
 */
static bool alpha_cmp_lower(const char *assumed_smaller, 
                            const char *word_to_check)
{
        const size_t assumed_smaller_len = strlen(assumed_smaller) + 1;
        const size_t word_to_check_len = strlen(word_to_check) + 1;
        char assumed_smaller_cp[assumed_smaller_len];
        char word_to_check_cp[word_to_check_len];

        memcpy(assumed_smaller_cp, assumed_smaller, assumed_smaller_len);
        memcpy(word_to_check_cp, word_to_check, word_to_check_len);
        convert_to_lower(assumed_smaller_cp);
        convert_to_lower(word_to_check_cp);

        return alpha_cmp(assumed_smaller_cp, word_to_check_cp);
}

/*
 * Swap array[key] and array[key-1] 
 * (array[key] to array[key-1] and array[key-1] to array[key])
 */
static void insertion_sort_str_swap(char *array[], const unsigned int key) 
{
        char *tmp;
       
        tmp = array[key];
        array[key] = array[key-1];
        array[key-1] = tmp;
}

static void insertion_sort_str_backward(char *array[], unsigned int key)
{
        long int i = (long int) key - 1;

        for (; i>-1; i--, key--)
                if (alpha_cmp_lower(array[i], array[key]))
                        insertion_sort_str_swap(array, key);
}

