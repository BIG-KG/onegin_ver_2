#include "header.h"

void swapn(void* El1, void* El2, const int numOfBites){

	assert(El1);
	assert(El2);

    char buffer[numOfBites];
    memset(buffer, 0, numOfBites);

    memcpy(  buffer,    (char*)El1, numOfBites);
    memcpy( (char*)El1, (char*)El2, numOfBites);
    memcpy( (char*)El2,  buffer,    numOfBites);
}

int struct_compare_strings(void *vfirstStr, void *vsecondStr){

	assert(vfirstStr );
	assert(vsecondStr);

    char *firstStr  = ( ((string_start_end *)vfirstStr ) ->startl);
    char *secondStr = ( ((string_start_end *)vsecondStr) ->startl);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;
    int toOneReg1    = 0;
    int toOneReg2    = 0;



    while(firstStr[currSimbStr1] != '\0' && secondStr[currSimbStr2] != '\0'){

        if (  not(isalpha(firstStr[currSimbStr1]))  ){

            if (  not(isalpha(secondStr[currSimbStr2]))  ){
                currSimbStr2++;
            }

            currSimbStr1++;
            continue;
        }

        if ( not(isalpha(secondStr[currSimbStr2])) ){
            currSimbStr2++;
            continue;
        }

        toOneReg1 = tolower(firstStr [currSimbStr1]);
        toOneReg2 = tolower(secondStr[currSimbStr2]);

        if     (toOneReg1 < toOneReg2){//���� ����� ������
            return -1;
        }

        else if(toOneReg1 > toOneReg2){
            return  1;
        }

        currSimbStr1 ++;
        currSimbStr2 ++;

    }

    if (  (firstStr[currSimbStr1] == '\0')  &&  (secondStr[currSimbStr2] == '\0')  ){
        if (currSimbStr1 < currSimbStr2){
            return -1;
        }
        if (currSimbStr1 > currSimbStr2){
            return 1;
        }

        else{
            return 0;
        }
    }

    if (firstStr [currSimbStr1]  == '\0'){
        return -1;
    }

    if (secondStr[currSimbStr2]  == '\0'){
        return 1;
    }

    return 0;

}

int struct_compare_strings_rev(void *vfirstStr, void *vsecondStr){

	assert(vfirstStr);
	assert(vsecondStr);

    char *firstStr  = ( ((string_start_end *)vfirstStr )->endl);
    char *secondStr = ( ((string_start_end *)vsecondStr)->endl);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;
    int toOneReg1 = 0;
    int toOneReg2 = 0;

    while (  (firstStr[currSimbStr1] != '\0')  &&  (secondStr[currSimbStr2] != '\0')  ){

        if ( not(isalpha(firstStr[currSimbStr1]) )){
            if ( not(isalpha(secondStr[currSimbStr2]))){
                currSimbStr2--;
            }
            currSimbStr1--;
            continue;
        }
        if ( not(isalpha(secondStr[currSimbStr2]))){
            currSimbStr2--;
            continue;
        }

        toOneReg1 = tolower(firstStr[currSimbStr1]);
        toOneReg2 = tolower(secondStr[currSimbStr2]);

        if (toOneReg1 < toOneReg2){//���� ����� ������
            return -1;
        }
        else if (toOneReg1 > toOneReg2){
            return 1;
        }

        currSimbStr1 --;
        currSimbStr2 --;

    }

    if (  (firstStr[currSimbStr1] == '\0')  &&  (secondStr[currSimbStr2] == '\0')  ){

        if (currSimbStr1 > currSimbStr2){
            return -1;
        }

        if (currSimbStr1 < currSimbStr2){
            return  1;
        }

        else{
            return  0;
        }
    }

    if (firstStr [currSimbStr1] == '\0'){
        return -1;
    }

    if (secondStr[currSimbStr2] == '\0'){
        return 1;
    }

    return 0;
}
