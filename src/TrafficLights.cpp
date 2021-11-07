#include <thread>
#include <conio.h>
#include "TrafficLights.h"

TrafficLights::TrafficLights(LightState state) {
    currentState = state;
}

void TrafficLights::run() {
    std::cout << "Press enter to run the traffic lights";
    char c = _getch();
    while(true){
        if(_kbhit() && _getch()=='e')
            break;
        if(_kbhit())
            isButtonPushed = true;
        displayState();
        toggle();
    }
}

 void TrafficLights::displayState() {
    std::cout <<"[ "<< timePassed<< " ] ";
    switch (currentState) {
        case LightState::green_red:
            std::cout << "Cars: green, pedestrians: red\n";
            break;
        case LightState::yellow_red:
            std::cout << "Cars: yellow, pedestrians: red\n";
            break;
        case LightState::red_green:
            std::cout << "Cars: red, pedestrians: green\n";
            break;
        default:
            break;
    }
}

void TrafficLights::toggle() {
    LightState nextState = transitions[currentState];
    unsigned long timeToWait = transitionTime[{currentState,nextState}];
    if(currentState==LightState::red_green || currentState==LightState::yellow_red){
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
        timePassed += timeToWait;
    }
    else if(currentState== LightState::green_red){
        unsigned long timePassedInLoop = 0;
        for(int i = 0; i < timeToWait/MAX_DELAY; ++i){
            if(isButtonPushed || _kbhit()){
                isButtonPushed = false;
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(MAX_DELAY));
            timePassedInLoop += MAX_DELAY;
        }
        timePassed += timePassedInLoop;
    }
    currentState = nextState;
}
