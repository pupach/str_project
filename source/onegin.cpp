#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

#include "str_input.h"
#include "str_output.h"
#include "str_func.h"
#include "func_sort.h"
#include "algoritm_sort.h"
#include "len_array.h"


int main()
{
    char *text = {};
    text = (char *)calloc(MAX_SIZE, sizeof(char *));
    FILE *str_in = open_file("d.txt");

    len_arr *buff = read_from_file_to_buff(str_in);

    LOG("\n main\n %s\n main\n", buff->arr);
    printf("main %p\n",  (buff->arr) );

    fclose(str_in);

    len_arr *ptr_all_str = find_all_str(buff);
    for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(ptr_all_str->arr) + i);
        LOG("number %d, str %s\n", i, (char *)(may->arr));
    }
    len_arr *sort_bub_arr_ptr = sort_bubble(ptr_all_str, &compare_str_len_arr);

    printf("\nsort_bub_arr_ptr end\n");

    for (int i = 0; i < (sort_bub_arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(sort_bub_arr_ptr->arr) + i);
        LOG("sort_bubble number %d, str %s\n", i, (char *)(may->arr));
    }

    write_in_file(sort_bub_arr_ptr, "res.txt");



}
