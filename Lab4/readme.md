
# LAB4

## Traffic Light Controller in C

This exercise covers the implementation of a traffic light controller in C. The task allows you to practice the following:

- **State machines:** A traffic light controller is a typical example of a system implemented with a state machine model.
- **Function calls:** The program's functionality is divided into logical parts using functions.
- **Program structure with multiple files:** Different parts of the program are placed in separate files.

### Task Description

Implement a program in C that simulates the operation of a traffic light controller. The program should work as follows:

Phase 1:

- The program has three states: red, yellow, and green.
- The red light stays on for 10 seconds.
- The yellow light stays on for 2 seconds.
- The green light stays on for 15 seconds.
- The states change automatically.
- The program has a function that prints the color of the light to the screen.

Phase 2:
- Add new states: RED+YELLOW, BLINKING YELLOW and OFF
- Add Pedestrian light control
- Add Button to request a green light

You can decide yourself how the logic of the traffic lights works, but in general, according to Finnish law. The button can be a suitable command, which is read from  stdin. 

**State machines**

For a more info about the finite state machines (FSM), have a look at:

[State machine design in C](
https://www.codeproject.com/Articles/1275479/State-Machine-Design-in-C)

[Traffic light FSM](https://tahull.github.io/projects/pic/traffic-light-fsm)

### Implementation

**Implementation Instructions:**

1. Create a new empty project for your C compiler.
2. Create two source code files: `main.c` and `traffic_light.c`. Create one header file: `traffic_light.h`, remember include guards!
3. **main.c**:
    - Contains the main function (`main`), which calls the traffic light controller functions.
    - Define constants for the light durations.
4. **traffic_light.c**:
    - Contains functions that implement the functionality of the traffic light controller:
        - `init_traffic_light`: Initializes the traffic light controller.
        - `run_traffic_light`: Simulates the operation of the traffic light controller.
        - `get_light_color`: Returns the light color as a string.
    - Use a state machine model to manage the states of the traffic lights.
    - Use the `sleep` function to implement the light delays.

**Some coding guidelines:**

Avoid using magic numbers. That is, for example, do not call sleep(15) - instead, call sleep(GREEN_DURATION), where GREEN_DURATION is a macro you have defined in some meaningful place ( like a related .h-file).

Use enumerated states.
