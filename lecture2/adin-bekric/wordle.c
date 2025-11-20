#include <stdio.h>
#include <paroot.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


#define WORD_LEN 5
#define MAX_TRIES 6

static const string WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA", 
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY",
};
static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));

int main(void){

    srand((unsigned int)time(NULL));
    const char *secret = WORDS[rand() % WORD_COUNT];
    char *guess;
    int won = 0;

for(int attempt = 1; attempt <= MAX_TRIES; attempt++){
    do{
        guess = get_string("Type your guess: ");
    }while(strlen(guess) != WORD_LEN);

    for(int i = 0; i < WORD_LEN; i++) {
    if(guess[i] < 65 || guess[i] > 90 ){
        guess[i] = toupper(guess[i]);
    }
}
char feedback[WORD_LEN + 1];
feedback[WORD_LEN] = '\0';
int counts[26] = {0};

    for(int i = 0; i < WORD_LEN; i++) {
    if(guess[i] == secret[i]) {
        feedback[i] = 'G';
    }else{
        feedback[i] = '.';
        counts[secret[i] - 'A']++;
    }/*Here we temporarely mark letters that arent in the correct position
 with . instead of Y which well do in the next pass */
}
for(int i = 0; i < WORD_LEN; i++) {
    if(feedback[i] == '.') {
        int Ypos = guess[i] - 'A';
        if(counts[Ypos] > 0) {
            feedback[i] = 'Y';
            counts[Ypos]--;
        }        
    }
}

printf("%s\n", feedback);

    if(strcmp(feedback, "GGGGG") == 0) {
        printf("You won in %i attempt(s)!\n", attempt);
        won = 1;
        break;
    }
}
    if (!won){
    printf("You ran out of attempts, the word was: %s\n", secret);
    }
}    