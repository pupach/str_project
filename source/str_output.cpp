#include "str_output.h"
#include "str_input.h"

int write_in_file(len_arr * arr_to_write, char *filename)
{
    printf("write_in_file");
    FILE *stream_to_write = open_file(filename);
    len_arr *arr = (len_arr *)arr_to_write->arr;

    for(int i = 0; i < arr_to_write->size_arr; i++)
    {
        char * str = (char *) arr->arr;

        char symb = str[arr->size_arr - 1];
        str[arr->size_arr - 1] = '\0';

        fputs(str, stream_to_write);

        str[arr->size_arr - 1] = symb;

    }
    return 1;
}
