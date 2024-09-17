#include "header.h"

int main(){
    char file_name[50] = {};

    char **stringsArray = NULL;

    int in_file = open("input.txt", O_TRUNC );

    int numStrings = enter_text(&stringsArray, in_file) + 1;

    //sort_strings_bubble(stringsArray, numStrings);
	
	quick_sort(stringsArray, numStrings, sizeof(char *), compare_strings);
	
    print_all_strings(stringsArray, numStrings);

    fclose(inputFile);
    free(stringsArray);
    return 0;
}
