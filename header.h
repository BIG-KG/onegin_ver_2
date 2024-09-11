#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

const int MAX_LEN_OF_STRING = 50;
const int MAX_NUM_OF_STRINGS = 3;
const int STEP_ADDING_STRING = 5;

void print_all_strings(char **dinamic_mass_strings, int num_of_strings);

void replace_str(char *str1, char *str2);

void myswap(char **dinamic_mass, int el1, int el2);

int enter_text(char *** P_dinamic_mass_strings, FILE *inputfile, int maxNumberStrings);

int compare_strings(char *first_str, char *second_str);

void sort_strings_bubble(char **dinamic_mass_strings, int num_of_strings);

#endif // HEADER_H_INCLUDED
