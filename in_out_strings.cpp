#include "header.h"

// cringenaming
int enter_text_struct(string_start_end ** pointToStringArr, int inputfile, char ** start){

    assert(pointToStringArr);

    string_start_end *stringsArray = NULL;
    int maxNumbStrings = MAX_LEN_OF_STRING;
    int numstring = 0;
	int file_size = 0;
    int currElement = 1;

	stringsArray = (string_start_end *)calloc(sizeof(string_start_end), maxNumbStrings);

	lseek(inputfile, 0, SEEK_END);
    file_size = tell(inputfile);
	lseek(inputfile, 0, 0);

    char *bufferString = (char *)calloc(file_size + 4, sizeof(char));

    int reatedElements = read(inputfile, bufferString + 1, file_size);
    while( currElement < file_size){
        while(!isalpha(bufferString[currElement]) && currElement < file_size){
            currElement++;
        }
        if(currElement >= file_size){
            break;
        }
        bufferString[currElement - 1] = '\0';
        stringsArray[numstring].startl = &bufferString[currElement];
        while(bufferString[currElement] != '\n' && currElement < file_size){
            currElement++;
        }
        bufferString[currElement] = '\0';
        stringsArray[numstring].endl = &bufferString[currElement - 1];
        currElement ++;

        numstring ++;
        if (numstring >= maxNumbStrings){
            stringsArray = (string_start_end *)realloc(stringsArray,
                                sizeof(string_start_end) * maxNumbStrings * STEP_ADDING_STRING);

            maxNumbStrings *= STEP_ADDING_STRING;
        }
    }

    *start = bufferString;
    *pointToStringArr = stringsArray;
    return numstring;
}

void print_all_strings(char **stringsArray, int numStrings){

	assert(stringsArray);

    for(int i = 0; i < numStrings; i ++){
        printf("%s\n", stringsArray[i]);
        free(stringsArray[i]);
    }
}

void print_struct_strings(string_start_end *string_struct, int numStrings){

	assert(string_struct);

    for(int i = 0; i < numStrings; i ++){
        printf("%s\n", string_struct[i].startl);
    }
}

