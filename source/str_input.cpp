#include "str_input.h"
#include "str_func.h"


FILE *stream_out = stdin;

int MAX_SIZE_STR = 100;


void *increase_size_array(void *ptr_arr, size_t new_size)
{
    if (ptr_arr == nullptr)
    {
        return nullptr;
    }
    LOG("new_size, %d", new_size);
    LOG("ptr_arr %s", *(((char **) ptr_arr) + 1));

    void *ptr_new = (void *)realloc(ptr_arr, new_size * sizeof(len_arr *));

    LOG("ptr_new %s", *(((char *) ptr_new) + 1));

    return ptr_new;
}

len_arr *find_one_str(len_arr *buff, int *amount_characters)
{
    int len_str = 0;
    char *not_anal_buff = (char *)(buff->arr + *amount_characters);

    LOG("\namount_characters, %d\n", *amount_characters);

    LOG("\nnot_anal_buff c, %c\n", *not_anal_buff);
    LOG("\nnot_anal_buff n, %d\n", *not_anal_buff);

    char n = '\n';
    LOG("\nn %d\n", n);

    while(*(not_anal_buff + len_str) != n)
    {
        if (*(amount_characters) + len_str == buff->size_arr) break;
        len_str += 1;
    }

    *(not_anal_buff + len_str) = '\0';
    len_str += 1;

    LOG("\n     not_anal_buff s, %s\n", not_anal_buff);
    LOG("len_str, %d\n", len_str);

    *amount_characters += len_str;

    if (len_str != 1)
    {
/*        len_arr str_struct;
        str_struct.arr = not_anal_buff;
        str_struct.size_arr = len_str;*/

        return gen_struct_len_arr((void *)not_anal_buff, len_str);

    }
    else
    {
        return find_one_str(buff, amount_characters);
    }
}

CODE_ERRORS free_all_dinamic_ptr(char *text[], const int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        if (text[i] != nullptr)
        {
            free(text[i]);
        }
    }
    return ALL_GOOD;
}


CODE_ERRORS print_str(char **text, const int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        if (text[i] != nullptr)
        {
            LOG("%p\n",   (text+i));
            char *s = *(text+i);
            LOG("str %d\n",   i);
        }
    }
}


len_arr *find_all_str(len_arr *buffer)
{
    bool flag = true;
    int counter = 0;
    len_arr *arr_str = (len_arr *)calloc(EXTRA_SIZE, sizeof(len_arr));
    size_t size_arr = EXTRA_SIZE;
    int amount_characters = 0;

    do
    {
        LOG("str %p\n",  (buffer->arr) );
        LOG("str %s\n",  (buffer->arr) );

        len_arr *s = find_one_str(buffer, &amount_characters);

        if (size_arr == counter)
        {
            size_arr += EXTRA_SIZE;
            arr_str = (len_arr *)increase_size_array((void *)arr_str, size_arr);
        }
        *(arr_str + counter) = *s;
        counter++;

    }while(amount_characters < buffer->size_arr);

/*    len_arr *all_ptr_str = (len_arr *)calloc(sizeof(struct len_arr), 1);
    all_ptr_str->size_arr = counter;
    all_ptr_str->arr = (void *)arr_str; */

    return gen_struct_len_arr((void *)arr_str, counter);
}


FILE *open_file(char *text, char *mode)
{
    char file_name[MAX_SIZE_FILE] = {};
    if (text[0]=='_')
    {
        printf("������� ��� �����, ��� ����� ����� ������� �������");
        char shablon_format_str_fscanf[] = "%s";
        char MAX_SIZE_NAME_FILE[10] = {};

        itoa(MAX_SIZE_FILE, ((char *)(MAX_SIZE_NAME_FILE)), 10);

        char *format_str_fscanf = Myinsert_str_to_str((char *)shablon_format_str_fscanf, (char *)MAX_SIZE_NAME_FILE, 2);
        LOG("%s", format_str_fscanf);
        int res = fscanf(stdin, "%s", file_name);
    }
    else if(strlen(text) < MAX_SIZE_FILE)
    {
        strcpy(file_name, text);
    }
    else
    {
        printf("����������� ����");
        char *text_default = "_";
        return open_file(text_default, mode);
    }
    if ((mode[0] != 'w') and (mode[0] != 'r'))
    {
        printf("����������� mode" );
        return open_file(text);
    }

    FILE *stream_read = fopen(file_name, mode);

    if (stream_read == NULL)
    {
        printf("����������� ����");
        char *text_default = "_";
        return open_file(text_default, mode);
    }
    return stream_read;
}

len_arr *read_from_file_to_buff(FILE *stream_read)
{
    struct stat info = {};
    fstat(fileno (stream_read), &info);
    int size_buff = 0;

    char *buffer = (char *) calloc((size_t)(info.st_size), sizeof(char));

    size_t res = fread((void *)buffer, sizeof(char), info.st_size, stream_read);
    size_buff = res;

    fclose(stream_read);

    LOG("res %d\n", res);

/*    len_arr *buff = (len_arr *)calloc(sizeof(len_arr), 1);
    buff->arr =  (void *)buffer;
    buff->size_arr = res;*/

    return gen_struct_len_arr((void *)buffer, res);

}

int gen_arr_ptr_on_beg_str(char *buffer)
{

}

