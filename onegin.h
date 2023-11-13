#ifndef ONEGIN
#define ONEGIN

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "source/str_input.h"
#include "source/str_output.h"
#include "../my_lib/str_func.h"
#include "source/func_sort.h"
#include "source/algoritm_sort.h"
#include "../my_lib/len_arr/len_array.h"
#undef LOG

#define LOG(mode, stream_out, args...)                                                        \
    do                                                                                        \
    {                                                                                       \
        if(mode)                                                                            \
        {                                                                                           \
            fprintf(stream_out, args);                                                      \
        }                                                                                   \
    } while(0)

len_arr *cpy_onegin_len_arr(len_arr *for_cpy);

CODE_ERRORS printf_onegin_txt(len_arr *onegin);

CODE_ERRORS free_cpy_onegin_struct(len_arr *for_free);

len_arr * split_file_on_str(FILE *stream_read, len_arr **buff_for_free);

#endif
