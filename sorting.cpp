#include "header.h"



const int START_ARRAY_SIZE = 5;
const int STEP_ARRAY = 2;

int int_cmp (void *num1, void *num2){

	assert (num1);
	assert (num2);

    for (int i = 0; i < sizeof(int); i ++){
        if (*((char *)num1 + i) - *((char *)num2 + i)){
            return ((int)(*((char *)num1 + i) - *((char *)num2 + i)));
        }
    }
    return 0;
}


void swapn(void* El1, void* El2, const int numOfBites){

	assert(El1);
	assert(El2);

    char buffer[numOfBites];
    memset(buffer, 0, numOfBites);

    memcpy(  buffer,    (char*)El1, numOfBites);
    memcpy( (char*)El1, (char*)El2, numOfBites);
    memcpy( (char*)El2,  buffer,    numOfBites);
}

void* more_less(void* varrayStart, void* varrayEnd, size_t dataSize, int (*comporator)(void*, void* )){

	assert (varrayStart);
	assert (varrayEnd);

	const int cDataSize = dataSize;
	char* arrayStart    = (char*)varrayStart;
	char* arrayEnd      = (char*)varrayEnd;
	int numbetlon       = rand() % ( (arrayEnd - arrayStart) / dataSize );
	char Etlon[cDataSize];

	memset (Etlon, 0, cDataSize);
	memcpy (Etlon, arrayStart + numbetlon * dataSize, dataSize);

	int  leftEl    = 0;
	int  rightEl   = (arrayEnd - arrayStart) / ( (dataSize) - 1 );
	bool findLeft  = false;
	bool findRight = false;
    while (leftEl + 1 < rightEl && rightEl > 0){

        findLeft = false;
        findRight = false;

        while (leftEl + 1 <= rightEl && (!findRight || !findLeft)){

            if (comporator (  (arrayStart + (rightEl*dataSize))  , Etlon) >= 0){
                rightEl  -= 1;
            }

            else{
                findRight = true;
            }

            if (comporator (Etlon , (arrayStart + (leftEl * dataSize))  )  > 0){
                leftEl   += 1;
            }

            else{
                findLeft  = true;
            }
        }

        if (leftEl + 1 >= rightEl){

            if (comporator (Etlon ,  (arrayStart + (leftEl * dataSize))  ) > 0){

                if (comporator ( (arrayStart + (rightEl * dataSize))  , Etlon) >= 0){
                    break;
                }

                else {
                    rightEl++;
                    break;
                }
            }

            else if (comporator (  (arrayStart + (rightEl * dataSize))  , Etlon) == 0){
                rightEl++;
                break;
            }
        }

        swapn(arrayStart + (leftEl  * dataSize),
              arrayStart + (rightEl * dataSize), dataSize);

    }

    return arrayStart + (rightEl) * dataSize;

}

int compare_strings(void *vfirstStr, void *vsecondStr){

	assert(vfirstStr);
	assert(vsecondStr);

    char *firstStr  = *((char**)vfirstStr );
    char *secondStr = *((char**)vsecondStr);
    assert(firstStr);
    assert(secondStr);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;

    int toOneReg1 = 0;
    int toOneReg2 = 0;

    while ( firstStr[currSimbStr1] != '\0'  &&  secondStr[currSimbStr2] != '\0' ){

        if ( !(isalpha (firstStr[currSimbStr1]) ) ){
            currSimbStr1++;
            continue;
        }

        if ( !(isalpha (secondStr[currSimbStr2])) ){
            currSimbStr2++;
            continue;
        }

        toOneReg1 = tolower (firstStr[currSimbStr1]);
        toOneReg2 = tolower (secondStr[currSimbStr2]);

        if     (toOneReg1 < toOneReg2){
            printf("111");
            return -1;
        }

        else if(toOneReg1 > toOneReg2){
            printf("222");
            return 1;
        }

        currSimbStr1 ++;
        currSimbStr2 ++;

    }

    if ( firstStr[currSimbStr1] == '\0'  &&  secondStr[currSimbStr2] == '\0' ){
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

    if (firstStr[currSimbStr1] == '\0'){
        return -1;
    }

    if (secondStr[currSimbStr2]  == '\0'){
        return 1;
    }

    return 0;

}

void quick_sort(void* vArrayStart, int numElem, size_t dataSize, int (*comporator)(void*, void* )){

	assert (vArrayStart);
	assert (comporator != 0);

    start_end_arr *StEndPointers = (start_end_arr *)calloc ( sizeof (start_end_arr) , START_ARRAY_SIZE );
    StEndPointers[0].startch     = vArrayStart;
    StEndPointers[0].endch       = (char *)vArrayStart + (numElem * dataSize);

    int arraySize  = START_ARRAY_SIZE;
    int numOfEl    = 1;
    int currEl     = 0;
    int currElSize = 0;
    char *middleEl = NULL;
    char **start   =(char **)vArrayStart;

    do{

        currElSize = (  ((char *)StEndPointers[currEl].endch)  - ((char *)StEndPointers[currEl].startch)  )
                                                    / (dataSize);

        if (currElSize == 2){
            if ( comporator (   ((char *)StEndPointers[currEl].endch - dataSize),
                                ((char *)StEndPointers[currEl].startch         )   ) < 0 ){
                                                                                                //как нормально оформить
                swapn (  ((char *)StEndPointers[currEl].endch  - dataSize),
                         ((char *)StEndPointers[currEl].startch          ),  dataSize  );
            }
        }
        else{
            middleEl = (char *)more_less (  (StEndPointers[currEl].startch),
                                            (StEndPointers[currEl].endch  ), dataSize, comporator );

            if (   ((char *)StEndPointers[currEl].endch -  middleEl)  >= (2 * dataSize) ){

                StEndPointers[numOfEl].endch   = StEndPointers[currEl].endch;
                StEndPointers[numOfEl].startch = middleEl;
                numOfEl ++;
            }

            if(   (middleEl - (char *)StEndPointers[currEl].startch)  >= (2 * dataSize) ){

                StEndPointers[numOfEl].endch   = middleEl;
                StEndPointers[numOfEl].startch = StEndPointers[currEl].startch;
                numOfEl ++;
            }
        }

        currEl ++;

        if(numOfEl + 2 >= arraySize){
            arraySize    *= STEP_ARRAY;
            StEndPointers = (start_end_arr *)realloc (StEndPointers ,  (sizeof(start_end_arr) * arraySize)  );
            assert(StEndPointers);
        }

    }while(numOfEl > currEl);

    free(StEndPointers);

}

int struct_compare_strings(void *vfirstStr, void *vsecondStr){

	assert(vfirstStr);
	assert(vsecondStr);

    char *firstStr  = ( ((string_start_end *)vfirstStr ) ->startl);
    char *secondStr = ( ((string_start_end *)vsecondStr) ->startl);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;
    int toOneReg1    = 0;
    int toOneReg2    = 0;

    while(firstStr[currSimbStr1] != '\0' && secondStr[currSimbStr2] != '\0'){

        if( not(isalpha(firstStr[currSimbStr1]) )){

            if (  !(isalpha (secondStr[currSimbStr2]))  ){
                currSimbStr2++;
            }

            currSimbStr1++;
            continue;
        }

        if(  !(isalpha (secondStr[currSimbStr2]))  ){
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

    //printf("\nstr1 _%s_ str2 _%s_, num1 = %d, num2 = %d\n",
                      //  firstStr, secondStr, currSimbStr1, currSimbStr2);

    if (  (firstStr[currSimbStr1] == '\0')  &&  (secondStr[currSimbStr2] == '\0')  ){
        if (currSimbStr1 < currSimbStr2){
           // printf("222\n");
            return -1;
        }

        if (currSimbStr1 > currSimbStr2){
            //printf("333\n");
            return  1;
        }

        else{
            //printf("444\n");
            return  0;
        }
    }

    if (firstStr [currSimbStr1]  == '\0'){
        //printf("555\n");
        return -1;
    }

    if (secondStr[currSimbStr2]  == '\0'){
        //printf("666\n");
        return 1;
    }
    //printf("777\n");
    return 0;

}

int struct_compare_strings_rev(void *vfirstStr, void *vsecondStr){

	assert(vfirstStr );
	assert(vsecondStr);

    char *firstStr  = ( ((string_start_end *)vfirstStr )->endl);
    char *secondStr = ( ((string_start_end *)vsecondStr)->endl);

    int currSimbStr1 = 0;
    int currSimbStr2 = 0;
    int toOneReg1    = 0;
    int toOneReg2    = 0;

    while(  (firstStr[currSimbStr1] != '\0')  &&  (secondStr[currSimbStr2] != '\0')  ){
        if ( !(isalpha(firstStr[currSimbStr1])) ){

            if ( !(isalpha(secondStr[currSimbStr2])) ){
                currSimbStr2--;
            }

            currSimbStr1--;
            continue;
        }

        if ( !(isalpha(secondStr[currSimbStr2])) ){
            currSimbStr2--;
            continue;
        }

        toOneReg1 = tolower(firstStr[currSimbStr1]);
        toOneReg2 = tolower(secondStr[currSimbStr2]);

        if(toOneReg1 < toOneReg2){//���� ����� ������
            //printf("000\n");
            return -1;
        }
        else if(toOneReg1 > toOneReg2){
            //printf("111\n");
            return 1;
        }
        currSimbStr1 --;
        currSimbStr2 --;

    }

    //printf("\nstr1 _%s_ str2 _%s_, num1 = %d, num2 = %d\n",
                      //  firstStr, secondStr, currSimbStr1, currSimbStr2);

    if(firstStr[currSimbStr1] == '\0' && secondStr[currSimbStr2] == '\0'){
        if (currSimbStr1 > currSimbStr2){
           // printf("222\n");
            return -1;
        }
        if (currSimbStr1 < currSimbStr2){
            //printf("333\n");
            return 1;
        }
        else{
            //printf("444\n");
            return 0;
        }
    }

    if (firstStr[currSimbStr1] == '\0'){
        //printf("555\n");
        return -1;
    }

    if (secondStr[currSimbStr2]  == '\0'){
        //printf("666\n");
        return 1;
    }
    //printf("777\n");
    return 0;
}
