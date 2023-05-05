#include <stdlib.h>
#include "bless_tui.h"

typedef struct Screen{
    /*
    Struct for storing the width and height of the displayed screen in "charactere-unit"
    and the actual char array containing the screen
    */
    int height;
    int width;
    char screen[][][]; // the last [] is a string (array of char)
} Screen;

void init_struct_Screen(){
    int **array = malloc(sizeof(int *) * HEIGHT);
    for(int y; y < HEIGHT; y++){
        array[y] = malloc(sizeof(int *) * WIDTH);
        for(int x; x < WHITE; x++){
            array[y][x] = malloc(sizeof(char *) * STR_SIZE);
        } 
    }
}
void free_struct_Screen(int **array){
    for(int y; y < HEIGHT; y++){
        for(int x; x < WHITE; x++){
            free (array[y][x]);
        }    
        free (array[y]);
    }
    free (array);
}

void color_str(char color[8], char background[8], char *str_target, int str_target_size){
    /*
    Fonction to add color and backround color to the string given (this one have to be bigger than 24)
    */
    if(str_target_size > 24){ // security
        char *str_buff = malloc(str_target_size); // local temporary string
        snprintf(str_buff, str_target_size, "%s%s%s\x1b[0m", color, background, str_target); // concatenation of all str
        strcpy(str_target, str_buff);
        free(str_buff); // prevent memory leak
    }
}

void draw(char screen[HEIGHT][WIDTH][STR_SIZE], int x, int y, char ascii_char[1], char color[8], char background[8]){
    /* 
    Fonction to draw on the screen what have been given in parameter
    */
    char str_final[STR_SIZE] = {*ascii_char};
    color_str(color, background, str_final, sizeof(str_final));
    strcpy(screen[y][x], str_final);
}

void init_screen(char screen[HEIGHT][WIDTH][STR_SIZE]){
    // fill the full screen
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            draw(screen, x, y, " ", DEFAULT, DEFAULT);
        }
    } 
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