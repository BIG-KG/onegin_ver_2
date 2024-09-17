#include "header.h"

int enter_text(char *** pointToStringArr, 	int inputfile){
	
    assert(stringsArray);
    
    char **stringsArray = *pointToStringArr;
    int num_ofString = 0;
	file_size = 0;
	
	lseek(inputfile, 0, SEEK_END);
    printf("%l", tell(lseek));
	
    while( (fscanf(inputfile, "%[^\n]%*[\n]", buffer_string)) > 0){

        stringsArray[currString] = (char*)calloc(sizeof(char), strlen(buffer_string));

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
	
	assert(stringsArray);
	
    for(int i = 0; i < numStrings; i ++){
        printf("%s\n", stringsArray[i]);
        free(stringsArray[i]);
    }
}

