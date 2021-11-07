#ifndef STATEMACHINE_LIGHTSTATE_H
#define STATEMACHINE_LIGHTSTATE_H

/**
 * LightState is a representation of all possible states, where
 * first color is a traffic light color for cars and
 * the second one for pedestrians
 */

enum class LightState {
    red_green , green_red, yellow_red
};


#endif //STATEMACHINE_LIGHTSTATE_H
