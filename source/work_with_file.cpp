#include "work_with_file.h"
#include <stdlib.h>



char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert)
{
    int len_all_str = strlen(str1) + strlen(str2);
    char *ptr_new_str = (char *)calloc(len_all_str, sizeof(char));

    ptr_new_str = strncpy(ptr_new_str, str1, index_of_insert - 1);
    strncpy(ptr_new_str + index_of_insert-1, str2, strlen(str2));
    strcpy(ptr_new_str + index_of_insert-1+strlen(str2), str1+index_of_insert-1);

    return ptr_new_str;
}

FILE *open_file(const char *text_const, char *mode)
{
    FILE *stream_read = NULL;

    char file_name[MAX_SIZE_FILE] = {};

    strcpy(file_name, text_const);


    do{
        LOG(1, stderr, "%s\n", file_name);
        if (file_name[0] == POISON_VAL_FOR_CHAR)
        {
            printf("������� ��� �����, ��� ����� ����� ������� �������\n");


            int res = fscanf(stdin, "%.*s", MAX_SIZE_FILE, file_name);
        }
        else if(!(strlen(text_const) < MAX_SIZE_FILE))
        {
            printf("����������� ����: ������� ������� ���");
            file_name[0] = POISON_VAL_FOR_CHAR;
        }
        if ((mode[0] != 'w') and (mode[0] != 'r'))
        {
            printf("����������� mode" );
            printf("������� mode" );

            size_t size_mode = 10;
            char new_mode[size_mode] = {};
            int res = scanf("%.*s", size_mode, new_mode);

            strcpy(new_mode, mode);
        }
        else
        {
            stream_read = fopen(file_name, mode);
            file_name[0] = POISON_VAL_FOR_CHAR;
        }

    }while(stream_read == NULL);

    return stream_read;
}

void close_file_for_debug(FILE *stream_out)
{
    if (!((stream_out == stdout) or (stream_out == stderr)))
    {
        fclose(stream_out);
    }
}
