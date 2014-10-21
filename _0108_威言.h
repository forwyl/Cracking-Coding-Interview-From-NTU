#ifndef CHECKROTATION_H_INCLUDED
#define CHECKROTATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
1.8 Assume you have a method isSubstring which checks if one word is a substring of another.
 Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
  call to isSubstring (i.e., ¡§waterbottle¡¨ is a rotation of ¡§erbottlewat¡¨).
**/

char firstInput[80];
char secondInput[80];
void inputString();

void inputString(){

    printf("Please insert a string shorter than 80 characters: ");
    scanf("%s", &firstInput);
    printf("The input string is : %s\n", firstInput);
    printf("Please insert another string shorter than 80 characters: ");
    scanf("%s", &secondInput);
    printf("The input string is : %s\n", secondInput);
    printf("---------------------------------------------------------------\n");

}

void checkRotation(){

    inputString();

    if(strlen(firstInput) != strlen(secondInput)){
        printf("[False]");
        return;
    }else{
        char combineChar[160];
        strcat(combineChar,firstInput);
        strcat(combineChar,firstInput);
        if(strstr(combineChar, secondInput)>0)
            printf("[True]");
        else
            printf("[False]");
    }

}

#endif // CHECKROTATION_H_INCLUDED
