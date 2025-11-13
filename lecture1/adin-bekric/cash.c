#include <paroot.h>
#include <stdio.h>
#include <math.h>

void coin_counter(int *coin_total, int change_cents){

    *coin_total += change_cents/25;
    change_cents %= 25;
    *coin_total += change_cents/10;
    change_cents %= 10;
    *coin_total += change_cents/5;
    change_cents %= 5;
    *coin_total += change_cents;
}

int main(void){
    float change = 0;
    int change_cents = 0;
    int coin_total = 0;
do{
   change = get_float("Input the change to return to the customer:");
}
while(change<0 );
   change_cents = (int) round(change * 100);
  
coin_counter(&coin_total, change_cents);
    
    printf("%i", coin_total);
}