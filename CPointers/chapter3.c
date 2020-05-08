#include <stdio.h>


/*RETURNING A POINTER*/
int* allocateArrayRET(int size, int value) {
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i=0; i<size; i++) {
        arr[i] = value;
    }
    return arr; 
}

/*PASSING A POINTER TO A POINTER*/
void allocateArray(int **arr, int size, int value) {
    *arr = (int*)malloc(size * sizeof(int));
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            *(*arr+i) = value;
        }
    }
} 

//the following version of the function ilustrates why passing a simple pointer will not work
// printing vector as a pointer will return 0x00 and there will be a memory leak
void AllocateArray(int* arr, int size, int value ){

        arr = (int*) malloc(size * sizeof(int));
        if(arr != NULL){
            for(int i=0; i<size; i++){
                arr[i] = value;
            }
        }
    }

/*FREE FUNCTION*/
//It is a good practice to set a pointer to NULL after being freed
/*we get a warning if we do not explicitly cast the pointer type to void when we call the function. 
If we explicitly perform the cast, then the warning goes away. */
void saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) { 
        free(*pp);
        *pp = NULL;
    }
}

/* MACRO FOR SAFE FREE*/
#define safeFree(p) saferFree((void**)&(p))


int main()
{

    /*RETURNINGN A POINTER
    int* vector = allocateArrayRET(5,45);
    for(int i=0; i<5; i++) {
        printf("%d\n", vector[i]);
    }
    */

   /*PASSING A POINTER TO A POINTER
    Good one:
    int *vector = NULL;
    allocateArray(&vector,5,45);

    Bad one:
    int* vector = NULL;
    AllocateArray(&vector, 5, 45);
    printf("%p \n",vector);
    */
}