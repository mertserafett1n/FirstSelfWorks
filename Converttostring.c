#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int i;
    //char array_birler[10][5] ile aynı şey bu alltaki.
    char **array_birler =(char**)malloc(10*sizeof(char));
    for(i = 0; i < 9;i++){
        array_birler[i] = malloc(5*sizeof(char));
    }
    // ilk index de hiç bir şey yazmıyor çünkü sayıda herhangi bir yerde 0 varsa o basamağı atlarız yazarken/okurken.
    array_birler[0] = "";
    array_birler[1] = "bir";
    array_birler[2] = "iki";
    array_birler[3] = "uc";
    array_birler[4] = "dort";
    array_birler[5] = "bes";
    array_birler[6] = "alti";
    array_birler[7] = "yedi";
    array_birler[7] = "sekiz";
    array_birler[9] = "dokuz";
    //char array_onlar[10][6] ile aynı şey. İKİNCİNİN 6 OLMASININ SEBEBİ ONLAR BASAMAĞINDA KARAKTER OLARAK MAKSİMUM 6 KARAKTERLİ ŞEYLER VAR DOKSAN SEKSEN.
    char **array_onlar = (char**)malloc(10 * sizeof(char));
    for(i = 0; i < 10;i++){
        array_onlar[i] = (char*)malloc(6 * sizeof(char));
    }
    array_onlar[0] = "";
    array_onlar[1] = "on";
    array_onlar[2] = "yirmi";
    array_onlar[3] = "otuz";
    array_onlar[4] = "kirk";
    array_onlar[5] = "elli";
    array_onlar[6] = "altmis";
    array_onlar[7] = "yetmis";
    array_onlar[8] = "seksen";
    array_onlar[9] = "doksan";
    int number, digit_num = 0, *digit_array = (int*)malloc(4*sizeof(int));
    printf("Enter a integer: ");
    scanf("%d", &number);    
    i = 0;
    while(number > 0){
        digit_array[i++] = number % 10;
        number /= 10;
        digit_num++;
    }
    switch(digit_num){
        case 4:
            if(digit_array[3] != 1)
                printf("%sbin",array_birler[digit_array[3]]);
            else
                printf("bin");
        case 3:
            if(digit_array[2] != 1 || digit_array[2] != 0)
                printf("%syuz",array_birler[digit_array[2]]);
            else if(digit_array[2] == 1)
                printf("yuz");
        case 2:
            printf("%s",array_onlar[digit_array[1]]);
        case 1:
            printf("%s",array_birler[digit_array[0]]);
            break;
    }
    free(array_birler);
    free(array_onlar);
printf("\n");
return 0;
}