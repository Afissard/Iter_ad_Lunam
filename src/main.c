/* Resources : 
    ANSI Escape for Color :
    - https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
    - https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
    Malloc stuff :
    - https://stackoverflow.com/questions/14416759/return-char-string-from-a-function
*/

// Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Other dependencies
#include "color_str.h"

// Variables & constantes
#define WIDTH 128
#define HEIGHT 32
#define STR_SIZE 32 // Max size to encode the char + ANSI escape codes
char screen[HEIGHT][WIDTH][STR_SIZE] = {};
//char *p_screen = &screen;

void draw(char screen[HEIGHT][WIDTH][STR_SIZE], int x, int y, char ascii_char[1], char color[8], char background[8]){
    /* 
    Fonction to draw on the screen what have been given in parameter
    */
    char str_final[STR_SIZE] = {*ascii_char};
    color_str(color, background, str_final, sizeof(str_final));
    strcpy(screen[y][x], str_final);
}

void display(char screen[HEIGHT][WIDTH][STR_SIZE]){
    /*
    Fonction to "write" the full screen on the terminal
    */
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            printf("%s", screen[y][x]);
        }
        printf("\n");
    }
}

int main(){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            draw(screen, x, y, "c", B_RED, BG_B_WHITE);
        }
    } // fill the full screen
    
    display(screen);

    // END
    char test[64] = "Eamus ad Lunam!";
    color_str(B_BLUE, BG_B_WHITE, test, sizeof(test));
    printf("%s\n", test);
    return 0;
}