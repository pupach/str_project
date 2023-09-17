#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>

const int DEBUG_MODE = 1;

#include "str_input.h"
#include "str_func.h"
#include "func_sort.h"


int main()
{
    char *text = {};
    text = (char *)calloc(MAX_SIZE, sizeof(char *));
    FILE *str_in = open_file("d.txt");

    len_arr *buff = read_from_file_to_buff(str_in);

    LOG("\n main\n %s\n main\n", buff->arr);
    LOG("main %p\n",  (buff->arr) );

    len_arr *ptr_all_str = find_all_str(buff);
    for (int i = 0; i < (ptr_all_str->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(ptr_all_str->arr) + i);
        LOG("number %d, str %s\n", i, (char *)(may->arr));
    }
    len_arr *sort_bub_arr_ptr = sort_bubble(ptr_all_str, &compare_str_len_arr);

    for (int i = 0; i < (sort_bub_arr_ptr->size_arr); i++)
    {
        LOG("number %d, str %s\n", i, (*(((char **)sort_bub_arr_ptr->arr + i)) ));
    }
}
