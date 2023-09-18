#include "str_input.h"
#include "func_sort.h"
#include "str_func.h"

int compare_str_len_arr(len_arr * str1, len_arr * str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    int index_1 = 0;
    int index_2 = 0;
    int res_comp = 0;
    char *str_1 = (char *)(str1->arr);
    char *str_2 = (char *)(str2->arr);

    LOG("compare_str1 %s\n", str_1);
    LOG("compare_str2 %s\n", str_2);

    while(((*(str_1 + index_1) != '\0') and (*(str_2 + index_2)) != '\0')
            and res_comp == 0)
    {
        if (!is_letter_rus(*(str_1 + index_1)))
        {
            index_1++;
            continue;
        }

        if (!is_letter_rus(*(str_2 + index_2)))
        {
            index_2++;
            continue;
        }

        if (*(str_1 + index_1) > *(str_2 + index_2)) res_comp = 1;

        else if (*(str_1 + index_1) < *(str_2 + index_2)) res_comp = -1;

        index_1++;
        index_2++;
    }

    if (res_comp == 0)
    {
        if ((*(str_1 + index_1) != '\0') and (*(str_2 + index_2) == '\0')) res_comp = -1;

        else if ((*(str_1 + index_1) == '\0') and (*(str_2 + index_2) != '\0')) res_comp = 1;

    }
    return res_comp;
}


len_arr *sort_bubble(len_arr *arr_ptr, int (*f_sort) (len_arr *, len_arr *))
{

    for  (int i = 0; i < (arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_ptr->arr) + i);
        LOG("sort_bubble 1 %d, str %s\n", i, (char *)(may->arr));
    }

    LOG("size %d", arr_ptr->size_arr);

    len_arr *arr_to_sort = (len_arr *)calloc(arr_ptr->size_arr, sizeof(len_arr *));
    for (int i = 0; i < (arr_ptr->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_ptr->arr) + i);
        LOG("sort_bubble 2 number %d, str %s\n", i, (char *)(may->arr));
    }
    memcpy(arr_to_sort, (len_arr *)(arr_ptr->arr), sizeof(len_arr *)*(arr_ptr->size_arr)*1);// why 2 ???????


    for (int i = 0; i < (   arr_to_sort->size_arr); i++)
    {
        len_arr *may = ((len_arr *)(arr_to_sort) + i);
        LOG("sort_bubble 3 number %d, str %s\n", i, (char *)(may->arr));
    }

    bool flag_is_sorted = false;

    do
    {
        flag_is_sorted = true;

        for(size_t i = 0; i < (arr_ptr->size_arr - 1); i++)
        {
            LOG("sort_bubble i = %d, size = %d\n", i, arr_ptr->size_arr);
            LOG("str1-%d, str2-%d", i, i+1);

            int res = f_sort((len_arr *)(arr_to_sort)  + i, (len_arr *)(arr_to_sort)  + i+1);
            if (res == -1)
            {
                len_arr promejutok = *(arr_to_sort  + i);

                *(arr_to_sort  + i) = *(arr_to_sort  + i+1);
                *(arr_to_sort  + i+1) = promejutok;

                flag_is_sorted = false;
            }
        }
    }while(!flag_is_sorted);

    len_arr *sorted_str = (len_arr *)calloc(sizeof(len_arr *), 1);
    sorted_str->arr = (char *)arr_to_sort;
    sorted_str->size_arr = arr_ptr->size_arr;

    return sorted_str;
}
