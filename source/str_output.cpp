#include "str_output.h"
#include "str_input.h"
#include "str_func.h"

int write_in_file(len_arr * arr_to_write, char *filename)
{
    printf("write_in_file");

    FILE *stream_to_write = open_file(filename, "w");

    len_arr *arr = (len_arr *)arr_to_write->arr;

    for(int i = 2; i < arr_to_write->size_arr; i++)
    {
        printf("%d %d", i, arr_to_write->size_arr);
        char * str = (char *) (arr + i)->arr;

        char symb = str[(arr + i)->size_arr - 1];
        str[(arr + i)->size_arr - 1] = '\0';

        LOG("number %d string %s\n", i, str);

        char s = fputs(str, stream_to_write);
        printf("%c\n", s);
        char *enter = "\n";
        fputs(enter, stream_to_write);

        LOG("fddffd");
        str[(arr + i)->size_arr - 1] = symb;
        printf("%d %d", i, arr_to_write->size_arr);

    }
    fclose(stream_to_write);
    return 1;
}
