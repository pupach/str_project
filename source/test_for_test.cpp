#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>


#define LOG(stream_out, args...)                                                      \
    do                                                                                      \
    {                                                                                       \                                                                               \
            fprintf(stream_out, args);                                                      \                                                                                  \
    } while(0)


FILE *stream_out = stdin;


const int MAX_SIZE = 10;


const int EXTRA_SIZE = 10;

char str_for_scanf[] = "%s";

int MAX_SIZE_STR = 100;

int Index_to_insert = 2;


enum CODE_ERRORS
{
    ALL_GOOD   = 0,
    VAL_NAN    = 1,
    VAL_INF    = 2,
    VAL_POISON = 3,
    VAL_ZERO   = 4,
    BAD_RETURN = 5
};




int main()
{
    char **text = {};
    text = (char **)calloc(10, sizeof(char *));
    printf("%s", *(text + 9));
    text[2] = "fffff";
    char **ptr_new = (char **)realloc((void **)text, 20);
    printf("%s", *(ptr_new + 9));
}
