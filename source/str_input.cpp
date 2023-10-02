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
    assert(ptr_new != nullptr);

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

    while(*(not_anal_buff + len_str) != '\n')
    {
        len_str += 1;
        if (*amount_characters + len_str == buff->size_arr) break;   // todo 1 earlier
    }

    *(not_anal_buff + len_str) = '\0';
    len_str += 1;

    LOG("\n     not_anal_buff s, %s\n", not_anal_buff);
    LOG("len_str, %d\n", len_str);

    *amount_characters += len_str;

    if (len_str != 1)
    {
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
    const size_t FACTOR_SIZE = 2;
    int amount_characters = 0;

    do
    {
        LOG("str %p\n",  (buffer->arr) );
        LOG("str %s\n",  (buffer->arr) );

        len_arr *s = find_one_str(buffer, &amount_characters);

        if (size_arr == counter)
        {
            size_arr = size_arr * FACTOR_SIZE;
            arr_str = (len_arr *)increase_size_array((void *)arr_str, size_arr);
        }
        *(arr_str + counter) = *s;
        counter++;

    }while(amount_characters < buffer->size_arr);

    return gen_struct_len_arr((void *)arr_str, counter);
}

FILE *open_file(const char *text_const, char *mode)
{
    FILE *stream_read = NULL;

    const size_t size_mode = 10;
    char new_mode[size_mode] = {};
    const char DEFAULT_READ_MODE = 'r';
    char file_name[MAX_SIZE_FILE] = {};

    if(!(strlen(text_const) < MAX_SIZE_FILE))
    {
            file_name[0] = POISON_VAL_FOR_CHAR;
    }

    else
    {
        strcpy(file_name, text_const);
    }


    do{
        if (file_name[0] == POISON_VAL_FOR_CHAR)
        {
            int res = fscanf(stdin, "%.*s", MAX_SIZE_FILE, file_name);
        }
        if ((mode[0] != 'w') and (mode[0] != 'r'))
        {

            new_mode[0] = DEFAULT_READ_MODE;
        }
        else
        {
            stream_read = fopen(file_name, mode);
            file_name[0] = POISON_VAL_FOR_CHAR;
        }

    }while(stream_read == NULL);

    return stream_read;
}


len_arr *read_from_file_to_buff(FILE *stream_read)
{
    struct stat info = {};
    fstat(fileno (stream_read), &info);
    int size_buff = 0;

    char *buffer = (char *) calloc((size_t)(info.st_size) + 1, sizeof(char));
    if (buffer == nullptr)
    {
        printf("too big file");
        exit(1);
    }
    size_t res = fread((void *)buffer, sizeof(char), info.st_size, stream_read);

    size_buff = res;
    buffer[size_buff] = '\0';

    fclose(stream_read);

    LOG("res %d\n", res);

    return gen_struct_len_arr((void *)buffer, res);

}
