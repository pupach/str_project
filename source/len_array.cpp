#include "len_array.h"

len_arr * gen_struct_len_arr(void *arr, int size_arr)
{
    len_arr *sorted_str = (len_arr *)calloc(sizeof(len_arr *), 1);
    sorted_str->arr = arr;
    sorted_str->size_arr = size_arr;
    return sorted_str;
}
