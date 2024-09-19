#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

const int MAX_LEN_OF_STRING = 50;
const int MAX_NUM_OF_STRINGS = 3;
const int STEP_ADDING_STRING = 5;

struct string_start_end{
    char *startl = NULL;
    char *endl = NULL;
};

struct start_end_arr{
    void *startch = NULL;
    void *endch = NULL;
};

void print_all_strings(char **dinamic_mass_strings, int num_of_strings);

void myswap(char **dinamic_mass, int el1, int el2);

int enter_text(char *** P_dinamic_mass_strings, int inputfile);

void quick_sort(void* vArrayStart, int numElem, size_t dataSize, int (*comporator)(void*, void* ));

int compare_strings(void *vfirstStr, void *vsecondStr);

void* more_less(void* varrayStart, void* varrayEnd, size_t dataSize, int (*comporator)(void*, void* ));

void swapn(void* El1, void* El2, const int numOfBites);

int enter_text_struct(string_start_end ** pointToStringArr, int inputfile, char ** start);

int struct_compare_strings(void *vfirstStr, void *vsecondStr);
void print_struct_strings(string_start_end *string_struct, int numStrings);


#endif // HEADER_H_INCLUDED
