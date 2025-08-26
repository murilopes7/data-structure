#include "darts.h"

int score (coordinate_t landing_position){
    float x = landing_position.x;
    float y = landing_position.y;
    
    float distance_squared = x*x + y*y;

    if (distance_squared > 100) return 0;
    else if (distance_squared <= 100 && distance_squared > 25) return 1;
    else if (distance_squared <= 25 && distance_squared > 1) return 5;
    else if (distance_squared <= 1 && distance_squared >= 0) return 10;
    else return -1;
}