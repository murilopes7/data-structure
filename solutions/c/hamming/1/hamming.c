#include "hamming.h"
#include <string.h>  // Need this for strlen()

int compute(const char *lhs, const char *rhs){
      // Edge Case 1: Check for null pointers
    if (lhs == NULL || rhs == NULL) {
        return -1;  // Error: null pointer passed
    }
    
    // Get string lengths
    int len1 = strlen(lhs);
    int len2 = strlen(rhs);
    
    // Edge Case 2: Check for different lengths
    if (len1 != len2) {
        return -1;  // Error: strings must be same length for Hamming distance
    }
    
    // Edge Case 3: Check for empty strings
    if (len1 == 0) {
        // Both strings are empty (since lengths are equal)
        return 0;  // Distance between two empty strings is 0
    }
    
    // Edge Case 4: Check for invalid DNA characters (optional - depends on requirements)
    for (int i = 0; i < len1; i++) {
        char c1 = lhs[i];
        char c2 = rhs[i];
        
        // Check if characters are valid DNA nucleotides (A, T, G, C)
        if ((c1 != 'A' && c1 != 'T' && c1 != 'G' && c1 != 'C') ||
            (c2 != 'A' && c2 != 'T' && c2 != 'G' && c2 != 'C')) {
            return -1;  // Error: invalid DNA character
        }
    }
    
    // Normal Case: Count differences (Hamming distance)
    int distance = 0;
    
    for (int i = 0; i < len1; i++) {
        if (lhs[i] != rhs[i]) {
            distance++;
        }
    }
    
    return distance;
}
