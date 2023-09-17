#ifndef STR_FUNC
#define STR_FUNC


#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>


#define LOG(args...)                                                            \
    do                                                                                      \
    {                                                                                       \
        if (1 > 0)                                                                 \
        {                                                                                   \
            fprintf(stdout, args);                                                      \
        }                                                                                   \
    } while(0)

const int default_val_flag_comp = 100;

int Myputs(const char *str);

char *Mystrchr(const char *str, int ch);

int Mystrlen(const char *str);

char *Mystrcpy(char *destptr, const char *srcptr);

char *Mystrncpy(char *destptr, const char *srcptr, size_t n);

char * Mystrcat(char * destptr, const char * srcptr );

char *Mystrncat(char *destptr, const char *srsrcptr, size_t n);

char *Myfgets(char *str, int num, FILE *stream);

char *Mystrdup(const char *str);

char *Mystrstr(const char *str, const char *strSearch);

char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert);

int compare_str(char * str_1, char * str_2);

bool is_letter_rus(char characters);
#endif
