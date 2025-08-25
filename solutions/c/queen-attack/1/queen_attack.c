#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    // Add this at the very beginning:
    if (queen_1.row > 7 || queen_1.column > 7 || queen_2.row > 7 || queen_2.column > 7) {
        return INVALID_POSITION;
    }
    
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
        return INVALID_POSITION;
    }

    else if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }

    else if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column)){
        return CAN_ATTACK;
    }

    else return CAN_NOT_ATTACK;
}

