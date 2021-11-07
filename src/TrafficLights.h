#ifndef STATEMACHINE_TRAFFICLIGHTS_H
#define STATEMACHINE_TRAFFICLIGHTS_H

#include <iostream>
#include <map>
#include "LightState.h"

class TrafficLights {
public:
    explicit TrafficLights(LightState state = LightState::red_green);
private:
    const std::map<LightState,LightState> lightsTransitions = {
            {LightState::red_green,LightState::green_red},
            {LightState::green_red,LightState::yellow_red},
            {LightState::yellow_red,LightState::red_green},
    };
    const std::map<std::pair<LightState,LightState>,size_t> transitionTime = {
            {{LightState::red_green,LightState::green_red},10},
            {{LightState::green_red,LightState::yellow_red},20},
            {{LightState::yellow_red,LightState::red_green},2}
    };
    LightState currentState;
    bool isButtonPushed = false;
};


#endif //STATEMACHINE_TRAFFICLIGHTS_H
