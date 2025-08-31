// resistor_color_duo.h
#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Enum definition for resistor band colors
typedef enum {
    BLACK = 0,
    BROWN = 1,
    RED = 2,
    ORANGE = 3,
    YELLOW = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    GREY = 8,
    WHITE = 9
} resistor_band_t;

// Function declarations
void run_tests(void);
void print_color_list(void);
void to_lowercase(char* str);
int color_code(resistor_band_t colors[]);
const resistor_band_t* colors(void);
resistor_band_t string_to_color(const char* color_name);
int color_code_from_string(const char* color_name);
int resistor_value(const char* colors[], int num_colors);

#endif