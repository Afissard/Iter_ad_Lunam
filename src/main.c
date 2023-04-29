// Libraries
#include <stdlib.h>
#include <stdio.h>
// Other dependencies
#include "color_str.h"

// Variables & constantes
#define screen_size 4096
int width = 128;
int height = 32;
char screen[screen_size][32] = {};
//char *p_screen = &screen;

// Fonctions
void display(int width, int height, char *screen){
    /*
    Fonction to "write" the full screen on the terminal
    */
    int screen_pos = 0; // position of the current selected chararactere of the screen
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            printf("%c", screen[screen_pos]);
            screen_pos ++;
        }
        printf("\n");
    }
}

int main(){
    for(int i; i < screen_size; i++){
        screen[i] = 'x'; // COLOR_STR('x', B_MAGENTA, BG_B_WHITE);
    } // fill the screen
    
    display(width, height, screen);

    // END
    printf(COLOR_STR("Eamus ad Lunam!", B_BLUE, BG_B_WHITE) "\n");
    return 0;
}