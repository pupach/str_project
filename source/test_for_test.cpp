#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[10] = "fd fds k";
    while(str != nullptr)
    {
        str = strtok(str, "");
        fprintf(stderr, "%s\n", str);
    }
}
