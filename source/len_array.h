#ifndef LEN_ARRAY
#define LEN_ARRAY



#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>


struct len_arr
{
    int size_arr = -1;
    void *arr;
};

len_arr * gen_struct_len_arr(void *arr, int size_arr);
#endif
