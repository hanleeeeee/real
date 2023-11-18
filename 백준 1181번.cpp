#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
    const char* val1 = *(const char**)a;
    const char* val2 = *(const char**)b;
    if (strlen(val1) < strlen(val2))
    {
        return -1;
    }
    else if (strlen(val1) > strlen(val2))
    {
        return 1;
    }
   
    else return strcmp((char*)val1, (char*)val2);
}

int main() {
   
    int number;
    scanf("%d", &number);
    

    char** arr = (char**)malloc(number * sizeof(char*));
    for (int i = 0; i < number; i++) {
        arr[i] = (char*)malloc(50 * sizeof(char));
        scanf("%s", arr[i]);
    }

    qsort(arr, number, sizeof(char*), compare);
   
    
    int uniqueCount = 0;
    char** uniqueArr = (char**)malloc(number * sizeof(char*));

    for (int i = 0; i < number; i++) {
        if (i == 0 || strcmp(arr[i], arr[i - 1]) != 0) {
            uniqueArr[uniqueCount++] = arr[i];
        }
        /*else {
            free(arr[i]); // 중복된 문자열 메모리 해제
        }*/
    }
    
    for (int i = 0; i < uniqueCount; i++) {
        printf("%s\n", uniqueArr[i]);
       
    }
    /*qsort(arr, number, sizeof(char*), compare1);

    for (int i = 0; i < number; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }*/
    
}