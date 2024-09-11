#include "header.h"

int enter_text(char *** P_dinamic_mass_strings, FILE *inputfile, int max_number_of_strings){

    char **dinamic_mass_strings = *P_dinamic_mass_strings;
    assert(dinamic_mass_strings);
    assert(inputfile);

    int current_string = 0;
    char buffer_string[MAX_LEN_OF_STRING] = {};
    int a;
    while((a = fscanf(inputfile, "%[^\n]%*[\n]", buffer_string)) > 0){

        dinamic_mass_strings[current_string] = (char*)calloc(sizeof(char), 60);

        strcpy(dinamic_mass_strings[current_string], buffer_string);

        current_string ++;

        if (current_string >= max_number_of_strings){

            *P_dinamic_mass_strings = (char**)realloc( dinamic_mass_strings,
                                                    sizeof(char*) * (max_number_of_strings + STEP_ADDING_STRING));
            dinamic_mass_strings = *P_dinamic_mass_strings;
            assert(dinamic_mass_strings);
            max_number_of_strings += STEP_ADDING_STRING;
        }
    }

    return --current_string;

}
