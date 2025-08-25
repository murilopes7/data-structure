#include "leap.h"
#include <stdio.h>

bool leap_year (int year){
      
    if (year % 4 != 0) {
        return false;  // Not divisible by 4 = not leap year
    }
    
    if (year % 100 != 0) {
        return true;   // Divisible by 4 but not 100 = leap year
    }
    
    if (year % 400 == 0) {
        return true;   // Divisible by 400 = leap year
    }

    return false;
}