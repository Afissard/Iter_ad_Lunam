/* Resources : 
    ANSI Escape for Color :
    - https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
    - https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
    Malloc stuff :
    - https://stackoverflow.com/questions/14416759/return-char-string-from-a-function
    Structure stuff :
    - https://stackoverflow.com/questions/228684/how-to-declare-a-structure-in-a-header-that-is-to-be-used-by-multiple-files-in-c
    - https://stackoverflow.com/questions/2060974/how-to-include-a-dynamic-array-inside-a-struct-in-c

*/

// Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Other dependencies
#include "bless_tui.c"

char screen[HEIGHT][WIDTH][STR_SIZE] = {}; // TODO need to move it to bless_tui (struct?) 


int main(){
    init_screen(screen);
    
    draw(screen, 0, 0, "#", B_RED, BG_B_WHITE);
    display(screen);

    // END
    char test[64] = "Eamus ad Lunam!";
    color_str(B_BLUE, BG_B_WHITE, test, sizeof(test));
    printf("%s\n", test);
    return 0;
}