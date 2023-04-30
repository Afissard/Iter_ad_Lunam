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


void color_str(char color[8], char background[8], char str_target[STR_SIZE]){
    /*
    Fonction to add color and backround color to the string given (this one have to be bigger than 24)
    TODO: Add a way to get the size of the str_target for easier usage
    */
    // TODO : the solution is with malloc ? : https://stackoverflow.com/questions/14416759/return-char-string-from-a-function
    char str_buff[STR_SIZE] = {}; // local temporary string
    snprintf(str_buff, STR_SIZE, "%s%s%s\x1b[0m", color, background, str_target); // concatenation of all str
    strcpy(str_target, str_buff);
}

void draw(char screen[HEIGHT][WIDTH][STR_SIZE], int x, int y, char ascii_char[1], char color[8], char background[8]){
    /* 
    Fonction to draw on the screen what have been given in parameter
    */
    char str_final[STR_SIZE] = {*ascii_char};
    color_str(color, background, str_final);
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
    color_str(B_BLUE, BG_B_WHITE, test);
    printf("%s\n", test);
    return 0;
}