#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define key "123456789"


void main(){
    unsigned char key1[32], key2[32], key3[32], key4[32];
    for (int i=0; i<32; i++){
        key1[i]=key[i];
        key2[i]=key[32+i];
        key3[i]=key[64+i];
        key4[i]=key[96+i];
    }
    
    printf("Hello world!"); 
}