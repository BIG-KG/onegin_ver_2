#include "header.h"

const int START_ARRAY_SIZE = 5;
const int STEP_ARRAY = 2;

void* more_less(void* varrayStart, void* varrayEnd, size_t dataSize, int (*comporator)(void*, void* )){

	assert (varrayStart);
	assert (varrayEnd);

	const int cDataSize = dataSize;
	char* arrayStart    = (char*)varrayStart;
	char* arrayEnd      = (char*)varrayEnd;
	int numbetlon       = rand() % ( (arrayEnd - arrayStart) / dataSize );

	char Etlon[cDataSize];
	memset(Etlon, 0, cDataSize);
	memcpy(Etlon, arrayStart + numbetlon * dataSize, dataSize);

	int leftEl     = 0;
	int rightEl    = (arrayEnd - arrayStart) / (dataSize) - 1;
	bool findLeft  = 0;
	bool findRight = 0;

    while(leftEl + 1 < rightEl && rightEl > 0){

        findLeft = 0;
        findRight = 0;

        while (leftEl + 1 <= rightEl && (!findRight || !findLeft)){
            if (comporator (  (arrayStart + (rightEl*dataSize))  , Etlon) >= 0){
                rightEl  -= 1;
            }
            else{
                findRight = 1;
            }
            if (comporator (Etlon , (arrayStart + (leftEl * dataSize))  )  > 0){
                leftEl   += 1;
            }
            else{
                findLeft =  1;
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
                         ((char *)StEndPointers[currEl].startch          ),    dataSize);
            }
        }

        else if(currElSize == 3){

            if (comporator (   ((char *)StEndPointers[currEl].startch           ),
                               ((char *)StEndPointers[currEl].startch + dataSize)   )   > 0 ){

                if (comporator (   ((char *)StEndPointers[currEl].startch +dataSize),
                                   ((char *)StEndPointers[currEl].endch - dataSize )   ) > 0){

                    swapn (   ((char *)StEndPointers[currEl].startch         ),
                              ((char *)StEndPointers[currEl].endch - dataSize),  dataSize);

                }

                else if (comporator (   ((char *)StEndPointers[currEl].startch),
                                        ((char *)StEndPointers[currEl].endch - dataSize )   ) < 0){

                    swapn (   ((char *)StEndPointers[currEl].startch           ),
                              ((char *)StEndPointers[currEl].startch + dataSize),  dataSize);
                }

                else{
                    swapn (   ((char *)StEndPointers[currEl].startch           ),
                              ((char *)StEndPointers[currEl].startch + dataSize),  dataSize);

                    swapn (   ((char *)StEndPointers[currEl].endch - dataSize  ),
                              ((char *)StEndPointers[currEl].startch + dataSize),  dataSize);
                }
            }

            else if (comporator (   ((char *)StEndPointers[currEl].endch   - dataSize),
                                    ((char *)StEndPointers[currEl].startch + dataSize)   ) < 0){
                printf("\nd\n");

                if (comporator (   ((char *)StEndPointers[currEl].endch - dataSize),
                                  ((char *)StEndPointers[currEl].startch         )   ) < 0){

                    swapn (   ((char *)StEndPointers[currEl].startch           ),
                              ((char *)StEndPointers[currEl].startch + dataSize),  dataSize);

                    swapn (   ((char *)StEndPointers[currEl].endch - dataSize  ),
                              ((char *)StEndPointers[currEl].startch           ),  dataSize);
                }

                else{
                    swapn (   ((char *)StEndPointers[currEl].endch - dataSize  ),
                              ((char *)StEndPointers[currEl].startch + dataSize),  dataSize);
                }

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

