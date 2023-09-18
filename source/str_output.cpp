#include "str_output.h"
#include "str_input.h"
#include "str_func.h"

int write_in_file(len_arr * arr_to_write, char *filename)
{
    printf("write_in_file");
    FILE *stream_to_write = open_file(filename);
    len_arr *arr = (len_arr *)arr_to_write->arr;

    for(int i = 0; i < arr_to_write->size_arr; i++)
    {
        char * str = (char *) (arr + i)->arr;

        char symb = str[(arr + i)->size_arr - 1];
        str[(arr + i)->size_arr - 1] = '\0';

        LOG("string %s\n", str);

        fputs(str, stream_to_write);

        str[(arr + i)->size_arr - 1] = symb;

    }
    fclose(stream_to_write);
    return 1;
}
