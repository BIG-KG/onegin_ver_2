#include "header.h"

int main(){
    char mass_strings[MAX_NUM_OF_STRINGS][MAX_LEN_OF_STRING] = {};
    char file_name[50] = {};
    int maxNumberStrings = MAX_NUM_OF_STRINGS;

    char **stringsArray = (char**)calloc(sizeof(char*), maxNumberStrings);

    FILE *inputFile = fopen("input.txt", "r");

    int numStrings = enter_text(&stringsArray, inputFile, maxNumberStrings) + 1;

    //sort_strings_bubble(stringsArray, numStrings);
	
	quick_sort(stringsArray, numStrings, sizeof(char *), compare_strings);
	
    print_all_strings(stringsArray, numStrings);

    fclose(inputFile);
    free(stringsArray);
    return 0;
}
