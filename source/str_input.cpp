#include "str_input.h"
#include "../../my_lib/str_func.h"
#include "../../my_lib/work_with_file.h"


FILE *stream_out = stdin;

int MAX_SIZE_STR = 100;

// TODO: add type name in func name
void *increase_size_array(void *ptr_arr, size_t new_size)
{
    if (ptr_arr == nullptr)
    {
        return nullptr;
    }
    LOG(1, stderr, "new_size, %d", new_size);
    LOG(1, stderr, "ptr_arr %s", *(((char **) ptr_arr) + 1));

    void *ptr_new = (void *)realloc(ptr_arr, new_size * sizeof(len_arr *));
    // TODO: replace assert with something better
    assert(ptr_new != nullptr);

    LOG(1, stderr, "ptr_new %s", *(((char *) ptr_new) + 1));

    return ptr_new;
}

// TODO: look at strtok
len_arr *find_one_str(len_arr *buff, int *amount_characters)
{
    int len_str = 0;
    char *not_anal_buff = (char *)(buff->arr + *amount_characters);
    do
    {
        not_anal_buff = (char *)(buff->arr + *amount_characters);
        len_str = 0;
        LOG(1, stderr, "\namount_characters, %d\n", *amount_characters);

        LOG(1, stderr, "\nnot_anal_buff c, %c\n", *not_anal_buff);
        LOG(1, stderr, "\nnot_anal_buff n, %d\n", *not_anal_buff);

        while(*(not_anal_buff + len_str) != '\n')
        {
            len_str += 1;
            if (*amount_characters + len_str == buff->size_arr) break;
        }

        *(not_anal_buff + len_str) = '\0';
        len_str += 1;

        LOG(1, stderr, "\n     not_anal_buff s, %s\n", not_anal_buff);
        LOG(1, stderr, "len_str, %d\n", len_str);

        *amount_characters += len_str;
    }while(len_str == 1);

    return gen_struct_len_arr((void *)not_anal_buff, len_str);
}

CODE_ERRORS free_all_dinamic_ptr(len_arr *arr)
{
    LOG(1, stderr, "free_all_dinamic_ptr begin size %zu\n", arr->size_arr);

    free(((len_arr *)arr->arr));
    free(arr);

    LOG(1, stderr, "free_all_dinamic_ptr end\n");

    return ALL_GOOD;
}


CODE_ERRORS free_mem_buf(len_arr *buff)
{
    free(buff->arr);
    free(buff);
}


CODE_ERRORS print_str(char **text, const int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        if (text[i] != nullptr)
        {
            LOG(1, stderr, "%p\n",   (text+i));
            char *s = *(text+i);
            LOG(1, stderr, "str %d\n",   i);
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
    int size_arr = EXTRA_SIZE;

    do
    {
        LOG(1, stderr, "str %s\n",  (buffer->arr) );

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

    LOG(1, stderr, "res %d\n", res);

    return gen_struct_len_arr((void *)buffer, res);

}
