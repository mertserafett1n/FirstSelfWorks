#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    int ab = 1;
    int a = 0,b = 0, c = 0, d = 0, e = 0, f = 0, g =0,h = 0;
    while(ab == 1){
        printf("Enter number of letters for  message: ");
        int num;
        scanf("%d", &num);
        int i;
        int binary,decnum;
        for(i = 0; i < num; i++){
            decnum = 0;
            scanf("%d", &binary);
            decnum += (binary % 10) * 1;
            binary /= 10;
            decnum += (binary % 10) * 2;
            binary /= 10;
            decnum += (binary % 10) * 4;
            srand(time(NULL));
            int randomnum = rand()%8;
            switch(decnum){
                case 0:
                    printf("%d. encrypted letter is A and random number is %d\n", i+1, randomnum);
                    a++;
                    break;
                case 1:
                    printf("%d. encrypted letter is B and random number is %d\n", i+1, randomnum);
                    b++;
                    break;
                case 2:
                    printf("%d. encrypted letter is C and random number is %d\n", i+1, randomnum);
                    c++;
                    break;
                case 3:
                    printf("%d. encrypted letter is D and random number is %d\n", i+1, randomnum);
                    d++;
                    break;      
                case 4:
                    printf("%d. encrypted letter is E and random number is %d\n", i+1, randomnum);
                    e++;
                    break;
                case 5:
                    printf("%d. encrypted letter is F and random number is %d\n", i+1, randomnum);
                    f++;
                    break; 
                case 6:
                    printf("%d. encrypted letter is G and random number is %d\n", i+1, randomnum);
                    g++;
                    break;
                case 7:
                    printf("%d. encrypted letter is H and random number is %d\n", i+1, randomnum);
                    h++;
                    break;
            }
        }
            printf("Message has just taken...");
            printf("Enter 1 to continue and 0 to exit: ");
            scanf("%d", &ab);
        }
        printf("\n\nNumber of letters after coding-> A: %d, B: %d, C %d, D: %d, E: %d, F: %d, G: %d, H: %d\n",a,b,c,d,e,f,g,h);
    return 0;
}