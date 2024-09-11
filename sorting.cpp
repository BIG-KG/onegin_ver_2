#include "header.h"

void replace_str(char *str1, char *str2){
    char buffer[MAX_LEN_OF_STRING] = {};
    strcpy(buffer, str1);
    strcpy(str1, str2);
    strcpy(str2, buffer);
}

void myswap(char **stringArr, int el1, int el2){
    char *buffer_point = stringArr[el1];
    stringArr[el1] = stringArr[el2];
    stringArr[el2] = buffer_point;
}

int compare_strings(char *firstStr, char *secondStr){

    assert(firstStr);
    assert(secondStr);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;

    int toOneReg1 = 0;
    int toOneReg2 = 0;

    while(firstStr[currSimbStr1] != '\0' && secondStr[currSimbStr2] != '\0'){
        if( not(isalpha(firstStr[currSimbStr1]) )){
            currSimbStr1++;
            continue;
        }
        if( not(isalpha(secondStr[currSimbStr2]))){
            currSimbStr2++;
            continue;
        }

        toOneReg1 = tolower(firstStr[currSimbStr1]);
        toOneReg2 = tolower(secondStr[currSimbStr2]);

        if(toOneReg1 < toOneReg2){
            return 1;
        }
        else if(toOneReg1 > toOneReg2){
            return -1;
        }
        currSimbStr1 ++;
        currSimbStr2 ++;

    }

    if(firstStr[currSimbStr1] == '\0' && secondStr[currSimbStr2] == '\0'){
        if (currSimbStr1 < currSimbStr2){
            return 1;
        }
        if (currSimbStr1 < currSimbStr2){
            return -1;
        }
        else{
            return 0;
        }
    }
    if (firstStr[currSimbStr1] == '\0'){
        return 1;
    }
    if (secondStr[currSimbStr2]  == '\0'){
        return -1;
    }
    return 0;
}

void sort_strings_bubble(char **stringsArr, int numOfStrings){
    int currEl;
    for(int i = 1; i < numOfStrings; i ++){
        currEl = i;
        while(currEl > 0 && 0 < compare_strings(stringsArr[currEl],
                                                 stringsArr[currEl - 1])){
            myswap(stringsArr, currEl, currEl - 1);
            currEl--;
        }
    }
}