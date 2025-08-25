#include "resistor_color.h"
#include <stdio.h>
#include <string.h>

// Note: Only implementing the functions required by the tests

// Function to get the numerical value of a color band
int color_code(resistor_band_t color) {
    return (int)color;
}

// Function to return the list of all colors (note: function name is "colors" not "colors_list")
const resistor_band_t* colors(void) {
    static const resistor_band_t color_sequence[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return color_sequence;
}