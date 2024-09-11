#include "header.h"

int enter_text(char *** pointToStringArr, FILE *inputfile, int maxNumbStrings){

    char **stringsArray = *pointToStringArr;
    assert(stringsArray);
    assert(inputfile);

    int currString = 0;
    char buffer_string[MAX_LEN_OF_STRING] = {};
    int a;
    while((a = fscanf(inputfile, "%[^\n]%*[\n]", buffer_string)) > 0){

        stringsArray[currString] = (char*)calloc(sizeof(char), 60);

        strcpy(stringsArray[currString], buffer_string);

        currString ++;

        if (currString >= maxNumbStrings){

            *pointToStringArr = (char**)realloc( stringsArray,
                                                    sizeof(char*) * (maxNumbStrings + STEP_ADDING_STRING));
            stringsArray = *pointToStringArr;
            assert(stringsArray);
            maxNumbStrings += STEP_ADDING_STRING;
        }
    }

    return --currString;
}

void print_all_strings(char **stringsArray, int numStrings){
    for(int i = 0; i < numStrings; i ++){
        printf("%s\n", stringsArray[i]);
        free(stringsArray[i]);
    }
}

