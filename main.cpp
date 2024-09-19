
#include "header.h"

int main(){
    char *allStr = NULL;
    string_start_end *stringsArray = NULL;
    int in_file = open("input.txt", /*_O_BINARY |*/ O_RDONLY );

    int numStrings = enter_text_struct(&stringsArray, in_file, &allStr);



    //int numStrings = enter_text(&stringsArray, in_file) + 1;
    //sort_strings_bubble(stringsArray, numStrings);
    //printf("num_of_elem = %d\n", numStrings);
	quick_sort(stringsArray, numStrings, sizeof(string_start_end), struct_compare_strings);
    print_struct_strings(stringsArray, numStrings);
    free(allStr);
    free(stringsArray);
    return 0;
}

