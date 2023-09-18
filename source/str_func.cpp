#include "str_func.h"



int Myputs(const char *str)
{
    while(*str)
    {
        putc((int)*str, stdout);
        str++;
    }
    return 1;

}

char *Mystrchr(const char *str, int ch)
{
    int i = 0;
    while(str[i])
    {
        if ((int)(str[i]) == ch)
        {
            return ((char*)str + i);
        }
        i++;
    }
    return nullptr;
}

int Mystrlen(const char *str)
{
    if (str == nullptr) return 0;
    int i = 0;
    while(*(str + i))
    {
        i++;
    }
    return i;
}

char *Mystrcpy(char *destptr, const char *srcptr)
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return nullptr;
    int counter = 0;
    int len_dest = Mystrlen(destptr);

    while(*(srcptr + counter))
    {
        *(destptr + counter) = *(srcptr + counter);
        counter++;
    }

    *(destptr + counter) = '\0';
    counter++;

    while (counter<len_dest)
    {
        *(destptr + counter) = '\0';
        counter++;
    }


    return destptr;
}

char *Mystrncpy(char *destptr, const char *srcptr, size_t n)
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return nullptr;

    int counter = 0;

    while (*(srcptr + counter) && (counter < n))
    {
        *(destptr + counter) = *(srcptr + counter);
        counter++;
    }
    while(counter < n)
    {
        *(destptr + counter) = '0';
        counter++;
    }
    return destptr;
}

char * Mystrcat(char * destptr, const char * srcptr )
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return nullptr;

    printf("\n%c, %s ssss", *(destptr + strlen(destptr)), srcptr);

    Mystrcpy(destptr + strlen(destptr), srcptr);

    return destptr;
}

char *Mystrncat(char *destptr, const char *srsrcptr, size_t n)
{
    if ((destptr == nullptr) or (srsrcptr == nullptr)) return nullptr;
    int counter = 0;

    while (*(destptr + counter))
    {
        counter++;
    }
    Mystrncpy((destptr + counter), srsrcptr, n);

    return destptr;
}


char *Myfgets(char *str, int num, FILE *stream)
{
    if ((str == nullptr)) return nullptr;
    int counter = 0;

    while(counter<num)
    {
        char res = getc(stream);
        if ((int) res == EOF)
        {
            break;
        }
        *(str + counter) = res;
        counter++;
    }
    return str;
}

char *Mystrdup(const char *str)
{
    int len = Mystrlen(str) + 1;
    char * ptr = (char *) calloc(len, sizeof(char));

    return Mystrcpy(ptr, str);
}

char *Mystrstr(const char *str, const char *strSearch)
{
    int counter = 0;
    while (*(str + counter))
    {
        int counter_2 = 0;
        int res = 1;
        while(*(strSearch + counter_2))
        {
            if (*(str + counter + counter_2) != *(strSearch + counter_2))
            {
                res = 0;
                break;
            }
            counter_2++;
        }
        if (res)
        {
            return (char *)str + counter;
        }
        counter++;
    }
    return nullptr;
}

char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert)
{
    int len_all_str = strlen(str1) + strlen(str2);
    char *ptr_new_str = (char *)calloc(len_all_str, sizeof(char));

    ptr_new_str = strncpy(ptr_new_str, str1, index_of_insert - 1);
    strncpy(ptr_new_str + index_of_insert-1, str2, strlen(str2));
    strcpy(ptr_new_str + index_of_insert-1+strlen(str2), str1+index_of_insert-1);

    return ptr_new_str;
}

bool is_letter_rus(char characters)
{
    if (((characters >= 'a') and (characters <= 'z')) or ((characters >= 'A') and (characters <= 'Z')))
    {
        return true;
    }
    return false;
}
