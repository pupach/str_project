#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


struct STR_CODE_COMMANDS
{
    const char comment[12] = "comment";
    const char var[12] = "var";
    const char numb_var[12] = "numb_var";
    const char POISON_VAL[12] = "POISON_VAL";

const char push[12] = "push";

const char HLT[12] = "HLT";

const char add[12] = "add";

const char sub[12] = "sub";

const char mul[12] = "mul";

const char divis[12] = "divis";

const char pop[12] = "pop";

const char jump[12] = "jump";

const char out[12] = "out";
};


STR_CODE_COMMANDS may = {};

const char *NUMB_COM[256*2] = {};

NUMB_COM[1] = nullptr;

NUMB_COM[23] = may.HLT;

NUMB_COM[8] = may.add;

NUMB_COM[3] = may.sub;

NUMB_COM[5] = may.mul;

NUMB_COM[6] = may.divis;

NUMB_COM[89] = may.pop;

NUMB_COM[76] = may.jump;

NUMB_COM[2] = may.out;
int main()
{
}
