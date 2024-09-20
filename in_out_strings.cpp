#include "header.h"

void print_all_strings(char **stringsArray, int numStrings){

	assert(stringsArray);

    for (int i = 0; i < numStrings; i ++){

        printf("%s\n", stringsArray[i]);
        free(stringsArray[i]);

    }
}

void print_struct_strings(string_start_end *string_struct, int numStrings){

	assert(string_struct);

    for (int i = 0; i < numStrings; i ++){

        printf("%s\n", string_struct[i].startl);

    }
}

