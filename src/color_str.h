

// Reset
#define RESET_ALL       "\x1b[0m"
// Background color
#define BG_BLACK        "\x1b[40m"
#define BG_RED          "\x1b[41m"
#define BG_GREEN        "\x1b[42m"
#define BG_YELLOW       "\x1b[43m"
#define BG_BLUE         "\x1b[44m"
#define BG_MAGENTA      "\x1b[45m"
#define BG_CYAN         "\x1b[46m"
#define BG_WHITE        "\x1b[47m"
//Bright background color
#define BG_B_BLACK      "\x1b[100m"
#define BG_B_RED        "\x1b[101m"
#define BG_B_GREEN      "\x1b[102m"
#define BG_B_YELLOW     "\x1b[103m"
#define BG_B_BLUE       "\x1b[104m"
#define BG_B_MAGENTA    "\x1b[105m"
#define BG_B_CYAN       "\x1b[106m"
#define BG_B_WHITE      "\x1b[107m"
// String color
#define BLACK           "\x1b[30m"
#define RED             "\x1b[31m"
#define GREEN           "\x1b[32m"
#define YELLOW          "\x1b[33m"
#define BLUE            "\x1b[34m"
#define MAGENTA         "\x1b[35m"
#define CYAN            "\x1b[36m"
#define WHITE           "\x1b[37m"
//Bright string color
#define B_BLACK         "\x1b[90m"
#define B_RED           "\x1b[91m"
#define B_GREEN         "\x1b[92m"
#define B_YELLOW        "\x1b[93m"
#define B_BLUE          "\x1b[94m"
#define B_MAGENTA       "\x1b[95m"
#define B_CYAN          "\x1b[96m"
#define B_WHITE         "\x1b[97m"
// Custom color print for easy use of Ansi escape code
//#define COLOR_STR(color, background, string)   color background string "\x1b[0m" // old and decayed

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