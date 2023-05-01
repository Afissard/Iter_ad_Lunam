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
#include "bless_tui.c"

// Variables & constantes
#define WIDTH 128
#define HEIGHT 32
#define STR_SIZE 32 // Max size to encode the char + ANSI escape codes
char screen[HEIGHT][WIDTH][STR_SIZE] = {};
//char *p_screen = &screen;


int main(){
    init_screen(screen);
    
    draw(screen, 0, 0, "@", B_RED, BG_B_WHITE);
    display(screen);

    // END
    char test[64] = "Eamus ad Lunam!";
    color_str(B_BLUE, BG_B_WHITE, test, sizeof(test));
    printf("%s\n", test);
    return 0;
}