#ifndef DETERMINEANAGRAMS_H_INCLUDED
#define DETERMINEANAGRAMS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determineAnagrams();

/*
** Time Complexity: O(N1+N2), N1 and N2 are the length of the two input strings
*/
void determineAnagrams(){

    char firstInput[80];
    char secondInput[80];
    int asciiBoolean[256] ={0};
    int i = 0;
    int codeNum = 0;

    printf("Please insert a string shorter than 80 characters: ");
    scanf("%s", &firstInput);
    printf("The input string is : %s\n", firstInput);
    printf("Please insert another string shorter than 80 characters: ");
    scanf("%s", &secondInput);
    printf("The input string is : %s\n", secondInput);
    printf("---------------------------------------------------------------\n");

    for(i=0; i<strlen(firstInput); i++){
        codeNum = firstInput[i]-0;
        asciiBoolean[codeNum]++;
    }
    for(i=0; i<strlen(secondInput); i++){
        codeNum = secondInput[i]-0;
        if(asciiBoolean[codeNum]==0){
            printf("[False] %s and %s are not anagrams!", firstInput, secondInput);
            return;
        }else{
            asciiBoolean[codeNum]--;
        }
    }

    for(i=0; i<sizeof(asciiBoolean)/sizeof(asciiBoolean[0]); i++){
        if(asciiBoolean[i]!=0){
            printf("[False] %s and %s are not anagrams!", firstInput, secondInput);
            return;
        }
    }

    printf("[True] %s and %s are anagrams!", firstInput, secondInput);

}

#endif // DETERMINEANAGRAMS_H_INCLUDED
