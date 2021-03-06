#ifndef STATEMACHINE_TRAFFICLIGHTS_H
#define STATEMACHINE_TRAFFICLIGHTS_H

#include <iostream>
#include <map>
#include "LightState.h"

class TrafficLights {
public:
    explicit TrafficLights(LightState state = LightState::red_green);
    void run();
private:
    void displayState();
    void toggle();
    inline void clearBuffer();

    std::map<LightState,LightState> transitions = {
            {LightState::red_green,LightState::green_red},
            {LightState::green_red,LightState::yellow_red},
            {LightState::yellow_red,LightState::red_green},
    };
    std::map<std::pair<LightState,LightState>,size_t> transitionTime = {
            {{LightState::red_green,LightState::green_red},10000},
            {{LightState::green_red,LightState::yellow_red},20000},
            {{LightState::yellow_red,LightState::red_green},2000}
    };
    LightState currentState;
    bool isButtonPushed = false;
    bool isForcedToStop = false;
    const unsigned int MAX_DELAY = 1000; //in milliseconds
    long long timePassed = 0; // in milliseconds
};

#endif //STATEMACHINE_TRAFFICLIGHTS_H
