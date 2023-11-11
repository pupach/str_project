#ifndef STR_INPUT
#define STR_INPUT

#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../../my_lib/work_with_file.h"
#include "../../my_lib/len_arr/len_array.h"


extern int MAX_SIZE_STR;

extern FILE *stream_out;


/*

enum CODE_ERRORS
{
    ALL_GOOD   = 0,
    VAL_NAN    = 1,
    VAL_INF    = 2,
    VAL_POISON = 3,
    VAL_ZERO   = 4,
    BAD_RETURN = 5
};*/


const size_t EXTRA_SIZE = 1000;

void **increase_size_array(void **ptr_arr, size_t new_size);

len_arr *find_one_str(len_arr *buff, int *amount_characters);

CODE_ERRORS free_all_dinamic_ptr(len_arr *arr);

len_arr *read_from_file_to_buff(FILE *stream_read);

bool is_number(char characters);

bool check_empty_char(char symbol);

CODE_ERRORS free_mem_buf(len_arr *buff);

CODE_ERRORS print_str(char **text, const int size_arr);

len_arr *find_all_str(len_arr *buff);

#endif
