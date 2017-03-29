//
//  main.cpp
//  HW3-7
//
//  Created by Wu Kang-Hua on 9/10/16.
//  Copyright © 2016 kanghuawu. All rights reserved.
//


#include <stdio.h>
#include <string.h>

void splice(const char s[], const char t[], char r[], int rlen);

int main()
{
    const char* a = "Hello";
    const char* b = "World";
    
//    printf("%f\n",sizeof(a));
//    for(int i=0; i<sizeof(a);i++) printf("%s\n",a[i]);
    char r[15];

    splice(a, b, r, sizeof(r));
    printf("%s\n", r);
    printf("Expected: HWeolrllod\n");

    
    a = "Goodbye";
//    printf("%d\n",sizeof(a));
    splice(a, b, r, sizeof(r));
//    printf("%d\n", sizeof(r));
    printf("%s\n", r);
    printf("Expected: GWooordlbdye\n");

    b = "cruel world";
    splice(a, b, r, sizeof(r));
    printf("%s\n", r);
    printf("Expected: Gcoroudebly ewo\n");
    return 0;
}

/**
 Compuute a string that interleaves the characters in strings s and t.
 If one string is longer than the other, append the suffix.
 For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
 Place the result into the character array r of size rlen.
 If the result does not fit, truncate it to rlen - 1 characters
 and a '\0' terminator.
 */
int max(int a, int b){
    if(a>=b) return a;
    return b;
}

int min(int a, int b){
    if (a<=b) return a;
    return b;
}

void splice(const char s[], const char t[], char r[], int rlen)
{
    
    int len = max(strlen(s), strlen(t));
//    printf("%d\n",rlen);
    int j = 0;
    for (int i=0; i<len; i++){
        if(i < strlen(s)) {
            r[j] = s[i];
            j++;
        }
        if(j == rlen){
            break;
        }
        if(i < strlen(t)){
            r[j] = t[i];
            j++;
        }
        if(j == rlen){
            break;
        }
    }
    int size = min(j, rlen);
//    printf("%d\n",size);
    r[size] = '\0';
    
}