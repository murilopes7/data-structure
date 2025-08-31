#include "resistor_color_duo.h"
#include <stdio.h>
#include <stdlib.h>

// Function to get the numerical value of a color band
// Updated to accept array parameter to match header declaration
int color_code(resistor_band_t colors[]) {
    // For the duo resistor, we need the first two colors
    // Calculate: first_digit * 10 + second_digit
    return colors[0] * 10 + colors[1];
}

// Function to return the list of all colors
const resistor_band_t* colors(void) {
    static const resistor_band_t color_sequence[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return color_sequence;
}

// Convert a color name string to lowercase for comparison
void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to convert color string to resistor_band_t enum
resistor_band_t string_to_color(const char* color_name) {
    // Create a copy of the input string to convert to lowercase
    char color_copy[20];
    strncpy(color_copy, color_name, sizeof(color_copy) - 1);
    color_copy[sizeof(color_copy) - 1] = '\0';
    to_lowercase(color_copy);
    
    // Fixed: Use strcmp() == 0 for string comparison, not numeric values
    if (strcmp(color_copy, "black") == 0) return BLACK;
    if (strcmp(color_copy, "brown") == 0) return BROWN;
    if (strcmp(color_copy, "red") == 0) return RED;
    if (strcmp(color_copy, "orange") == 0) return ORANGE;
    if (strcmp(color_copy, "yellow") == 0) return YELLOW;
    if (strcmp(color_copy, "green") == 0) return GREEN;
    if (strcmp(color_copy, "blue") == 0) return BLUE;
    if (strcmp(color_copy, "violet") == 0) return VIOLET;
    if (strcmp(color_copy, "grey") == 0 || strcmp(color_copy, "gray") == 0) return GREY;
    if (strcmp(color_copy, "white") == 0) return WHITE;
    
    // Return -1 for invalid color (we'll handle this in the calling function)
    return (resistor_band_t)-1;
}

// Function to get color code directly from string
int color_code_from_string(const char* color_name) {
    resistor_band_t color = string_to_color(color_name);
    if (color == (resistor_band_t)-1) {
        return -1; // Invalid color
    }
    return (int)color; // Return the numerical value of the single color
}

// Function to calculate the resistor value from an array of color strings
// This uses only the first two colors and returns a two-digit number
int resistor_value(const char* colors[], int num_colors) {
    if (num_colors < 2) {
        printf("Error: At least two colors are required\n");
        return -1;
    }
    
    // Get the values of the first two colors
    int first_digit = color_code_from_string(colors[0]);
    int second_digit = color_code_from_string(colors[1]);
    
    // Check for invalid colors
    if (first_digit == -1) {
        printf("Error: Invalid first color '%s'\n", colors[0]);
        return -1;
    }
    if (second_digit == -1) {
        printf("Error: Invalid second color '%s'\n", colors[1]);
        return -1;
    }
    
    // Calculate two-digit value
    int result = first_digit * 10 + second_digit;
    
    // Print info about ignored colors if there are more than 2
    if (num_colors > 2) {
        printf("Note: Only first two colors used. Ignored: ");
        for (int i = 2; i < num_colors; i++) {
            printf("%s", colors[i]);
            if (i < num_colors - 1) printf(", ");
        }
        printf("\n");
    }
    
    return result;
}

// Test function to demonstrate the functionality
void run_tests(void) {
    printf("Testing Resistor Color Duo Decoder:\n");
    printf("-----------------------------------\n");
    
    // Test case 1: brown-green
    const char* test1[] = {"brown", "green"};
    int result1 = resistor_value(test1, 2);
    printf("brown-green: %d (expected 15) %s\n", result1, (result1 == 15) ? "✓" : "✗");
    
    // Test case 2: brown-green-violet (should ignore violet)
    const char* test2[] = {"brown", "green", "violet"};
    int result2 = resistor_value(test2, 3);
    printf("brown-green-violet: %d (expected 15) %s\n", result2, (result2 == 15) ? "✓" : "✗");
    
    // Test case 3: red-blue
    const char* test3[] = {"red", "blue"};
    int result3 = resistor_value(test3, 2);
    printf("red-blue: %d (expected 26) %s\n", result3, (result3 == 26) ? "✓" : "✗");
    
    // Test case 4: orange-orange
    const char* test4[] = {"orange", "orange"};
    int result4 = resistor_value(test4, 2);
    printf("orange-orange: %d (expected 33) %s\n", result4, (result4 == 33) ? "✓" : "✗");
    
    // Test case 5: black-black
    const char* test5[] = {"black", "black"};
    int result5 = resistor_value(test5, 2);
    printf("black-black: %d (expected 0) %s\n", result5, (result5 == 0) ? "✓" : "✗");
    
    // Test case 6: white-white
    const char* test6[] = {"white", "white"};
    int result6 = resistor_value(test6, 2);
    printf("white-white: %d (expected 99) %s\n", result6, (result6 == 99) ? "✓" : "✗");
    
    // Test case 7: yellow-violet with extra colors
    const char* test7[] = {"yellow", "violet", "red", "gold"};
    int result7 = resistor_value(test7, 4);
    printf("yellow-violet-red-gold: %d (expected 47) %s\n", result7, (result7 == 47) ? "✓" : "✗");
    
    printf("\n");
}

// Print available colors
void print_color_list(void) {
    printf("Available colors and their values:\n");
    printf("---------------------------------\n");
    const char* color_names[] = {
        "black", "brown", "red", "orange", "yellow",
        "green", "blue", "violet", "grey", "white"
    };
    
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", color_names[i], i);
    }
    printf("\n");
}