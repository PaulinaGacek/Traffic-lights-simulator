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
            std::cout << " <State 1> Cars: green, pedestrians: red\n";
            break;
        case LightState::yellow_red:
            std::cout << " <State 2> Cars: yellow, pedestrians: red\n";
            break;
        case LightState::red_green:
            std::cout << " <State 3> Cars: red, pedestrians: green\n";
            break;
        default:
            break;
    }
}

void TrafficLights::toggle() {
    auto start = std::chrono::high_resolution_clock::now();
    LightState nextState = transitions[currentState];
    unsigned long timeToWait = transitionTime[{currentState,nextState}];
    if(currentState==LightState::red_green){
        std::this_thread::sleep_until(start+std::chrono::milliseconds(timeToWait));
        timePassed += timeToWait;
    }
    else if(currentState==LightState::yellow_red){
        std::this_thread::sleep_until(start+std::chrono::milliseconds(timeToWait));
        timePassed += timeToWait;
        while(_kbhit()) _getch(); // clearing keyboard buffor
    }
    else if(currentState== LightState::green_red){
        unsigned long timePassedInLoop = 0;
        for(int i = 0; i < timeToWait/MAX_DELAY; ++i){
            if(isButtonPushed || _kbhit()){
                isButtonPushed = false;
                break;
            }
            timePassedInLoop += MAX_DELAY;
            std::this_thread::sleep_until(start+std::chrono::milliseconds(MAX_DELAY*i));
        }
        timePassed += timePassedInLoop;
        while(_kbhit()) _getch();
    }
    currentState = nextState;
}
