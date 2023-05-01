#include "color_str.h"

// TODO : make variables for WIDTH and HEIGHT
#define WIDTH 128
#define HEIGHT 32
#define STR_SIZE 32 // Max size to encode the char + ANSI escape codes

void color_str(char color[8], char background[8], char *str_target, int str_target_size);
void draw(char screen[HEIGHT][WIDTH][STR_SIZE], int x, int y, char ascii_char[1], char color[8], char background[8]);
void init_screen(char screen[HEIGHT][WIDTH][STR_SIZE]);
void display(char screen[HEIGHT][WIDTH][STR_SIZE]);