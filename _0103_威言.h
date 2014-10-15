#ifndef REMOVEDUPLICATE_H_INCLUDED
#define REMOVEDUPLICATE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicate();

/*
** Time Complexity: O(N^2), N is the length of input string
*/
void removeDuplicate(){

    char input[80];
    int asciiBoolean[256] ={0};
    int i, j, codeNum, nextCodeNum;

    printf("Please insert a string shorter than 80 characters: ");
    scanf("%s", &input);
    printf("The input string is : %s\n", input);

    for(i=0; i<strlen(input); i++){

      codeNum = input[i]-0;
      if(asciiBoolean[codeNum]){
        input[i] = '\0';
        j = i+1;
        while(input[j] != '\0'){
            nextCodeNum = input[j]-0;
            if(asciiBoolean[nextCodeNum]){
                j++;
            }else{
                asciiBoolean[nextCodeNum] = 1;
                input[i] = input[j];
                break;
            }
        }
      }else{
        asciiBoolean[codeNum] = 1;
      }

    }

    printf("The output string, without duplicates, is : %s\n", input);

}

#endif // REMOVEDUPLICATE_H_INCLUDED
