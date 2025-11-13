#include <stdio.h>
#include <paroot.h>

int main(void){
    int number = 0;

    do{
    number = get_int("Input the height:");
    } while(number < 1 || number > 8);

    int h=number;
    
    for(int i = 1; i<=number; i++){
    for(int j = h-1; j>0; j--){
        printf(" ");
    }
    for(int k = 1; k<=i; k++){
        printf("#");
    }
    printf("\n");
    h--;
}
}