## Traffic lights simulator :vertical_traffic_light: ##
This programme simulates behavior of traffic lights by use of state machine.

Possible states:

- <State 1> Cars: green, pedestrians: red
- <State 2> Cars: yellow, pedestrians: red
- <State 3> Cars: red, pedestrians: green

Possible transitions:
- <State 1> :arrow_right: <State 2> after 10 seconds
- <State 2> :arrow_right: <State 3> after 20 seconds or after pushing button*
- <State 3> :arrow_right: <State 1> after 2 seconds


:warning: *button pushed during period when pedestrians have green light does not count
    pushing button is simulated by not empty input from keyboard*
