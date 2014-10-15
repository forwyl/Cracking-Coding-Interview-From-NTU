#ifndef REPLACESPACE_H_INCLUDED
#define REPLACESPACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSpace();

void replaceSpace(){

    char input[30];
    int len, space, newLen, inputIndex, outputIndex;

    printf("Please insert a string shorter than 30 characters: ");
    fgets(input, sizeof(input), stdin);
    printf("The input string is : %s\n", input);
    printf("---------------------------------------------------------------\n");

    len = 0;
    space = 0;
    while(input[len]){
        if(input[len]==' '){
            space++;
        }
        len++;
    }

    newLen = len+2*space+1;
    char *output = malloc(newLen);
    inputIndex = 0;
    outputIndex = 0;
    for(inputIndex=0; inputIndex<len; inputIndex++){
        if(input[inputIndex]==' '){
            output[outputIndex++] = '%';
            output[outputIndex++] = '2';
            output[outputIndex++] = '0';
        }else{
            output[outputIndex++] = input[inputIndex];
        }
    }
    output[outputIndex] = '\0';

    printf("The output string is : %s\n", output);
    free(output);

}

#endif // REPLACESPACE_H_INCLUDED
