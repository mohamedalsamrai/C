#include <stdio.h>
#define IN 1
#define OUT 0
int main(){

    int c, state, word_count, char_count, line_count;
    state = OUT;
    word_count = 0;
    char_count = 0;
    line_count = 0;
    
    printf("\n\n");
    while ((c = getchar()) != EOF) {
        char_count++;
        if (c == '\n') {
            line_count++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
             word_count++; 
             state = IN;
          
        }
    }
    
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
    printf("Lines: %d\n", line_count);
    
    return 0;


}