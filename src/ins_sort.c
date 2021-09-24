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
int *insertion_sort_int(int array[], const unsigned int size)
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
