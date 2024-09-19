
#include "header.h"

int main(){
    char *allStr = NULL;
    string_start_end *stringsArray = NULL;
    int in_file = open("input.txt", _O_BINARY | O_RDONLY );

    int numStrings = enter_text_struct(&stringsArray, in_file, &allStr);
	//quick_sort(stringsArray, numStrings, sizeof(string_start_end), struct_compare_strings);
	quick_sort(stringsArray, numStrings, sizeof(string_start_end),
               struct_compare_strings_rev);
    print_struct_strings(stringsArray, numStrings);
    close(in_file);
    free(allStr);
    free(stringsArray);
    return 0;
}

