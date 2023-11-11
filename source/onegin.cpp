#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "str_input.h"
#include "str_output.h"
#include "../../my_lib/str_func.h"
#include "func_sort.h"
#include "algoritm_sort.h"
#include "../../my_lib/len_arr/len_array.h"
#include "../onegin.h"

len_arr *cpy_onegin_len_arr(len_arr *for_cpy)//хз как адкватнее сделать функцию копирования
{
    len_arr *for_write = (len_arr *)calloc(sizeof(len_arr), 1);

    for_write->arr = (void *)calloc(sizeof(len_arr), for_cpy->size_arr);
    for(int i = 0; i < for_cpy->size_arr; i++)
    {
        ((len_arr *)(for_write->arr))[i]->arr = (char *)calloc(sizeof(char *), ((len_arr *)(for_cpy->arr))[i]->size_arr);
        memcpy(((len_arr *)(for_write->arr))[i]->arr, ((len_arr *)(for_cpy->arr))[i]->arr,
                ((len_arr *)(for_cpy->arr))[i]->size_arr * sizeof(char *));
    }
    return for_write;
}

CODE_ERRORS free_cpy_onegin_struct(len_arr *for_free)
{
    for(int i = 0; i < for_free->size_arr; i++)
    {
        free(((len_arr *)(for_free->arr))[i]->arr);
    }
    free(for_free->arr);
    free(for_free);
    return ALL_GOOD;
}

len_arr * split_file_on_str(FILE *stream_read, len_arr **buff_for_free)
{
    len_arr *buff = read_from_file_to_buff(stream_read);
    *buff_for_free = buff;

    LOG(1, stderr,"\n main\n %s\n main\n", buff->arr);
    printf("main %p\n",  (buff->arr) );

    len_arr *ptr_all_str = find_all_str(buff);
    for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(ptr_all_str->arr) + i);
        LOG(1, stderr,"number %d, str %s\n point_mem %p\n", i, (char *)(may->arr), ((len_arr *)(ptr_all_str->arr) + i));
    }
    return ptr_all_str;

}
