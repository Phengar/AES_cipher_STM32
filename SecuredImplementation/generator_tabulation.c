#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static unsigned char multGalois0x01[256];
static unsigned char multGalois0x02[256];
static unsigned char multGalois0x03[256];
static unsigned char multGalois0x0e[256];
static unsigned char multGalois0x0b[256];
static unsigned char multGalois0x0d[256];
static unsigned char multGalois0x09[256];




unsigned char multGalois(unsigned char a, unsigned char b){ //The full implementation of multGalois is needed here as long as there isn't an array with all the values for 0x0e, 0x0b, 0x0d and 0x09
    unsigned char p=0;
    for (int i=0; i<8; i++){
        if ((b & 0x01) == 0x01){
            p^=a;
        }
        if ((a & 0x80) == 0x80){
            a<<=1;
            a^=0x1b;
        }else{
            a<<=1;
        }
        b>>=1;
    }
    return p;
}

void print_values(unsigned char *a){
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            printf("0x%x, ", a[i*16+j]);
        }
        printf("\n");
    }
    printf("};\n\n");
}

void main(){
    for(int i=0; i<256; i++){
        multGalois0x01[i]=multGalois(i, 0x01);
    }
    printf("static const unsiged char multGalois0x01[256] = {\n");
    print_values(multGalois0x01);
    for(int i=0; i<256; i++){
        multGalois0x02[i]=multGalois(i, 0x02);
    }
    printf("static const unsiged char multGalois0x02[256] = {\n");
    print_values(multGalois0x02);
    for(int i=0; i<256; i++){
        multGalois0x03[i]=multGalois(i, 0x03);
    }
    printf("static const unsiged char multGalois0x03[256] = {\n");
    print_values(multGalois0x03);
    for(int i=0; i<256; i++){
        multGalois0x09[i]=multGalois(i, 0x09);
    }
    printf("static const unsiged char multGalois0x09[256] = {\n");
    print_values(multGalois0x09);
    for(int i=0; i<256; i++){
        multGalois0x0b[i]=multGalois(i, 0x0b);
    }
    printf("static const unsiged char multGalois0x0b[256] = {\n");
    print_values(multGalois0x0b);
    for(int i=0; i<256; i++){
        multGalois0x0d[i]=multGalois(i, 0x0d);
    }
    printf("static const unsiged char multGalois0x0d[256] = {\n");
    print_values(multGalois0x0d);
    for(int i=0; i<256; i++){
        multGalois0x0e[i]=multGalois(i, 0x0e);
    }
    printf("static const unsiged char multGalois0x0e[256] = {\n");
    print_values(multGalois0x0e);
}