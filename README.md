# Automotive ECU Simulator

## About the Project

I created this project to understand the basic working of an Automotive Electronic Control Unit (ECU).

In a real vehicle, an ECU receives inputs from different sensors or switches, processes the input conditions, and controls different outputs. In this project, I tried to simulate a simple version of that process using Wokwi.

The project uses two push buttons as inputs, an OLED display to show the ECU status, and a buzzer to indicate an alert condition.

## Components Used

* ESP32
* 2 Push Buttons
* OLED Display
* Buzzer
* Wokwi Simulator

## Working

The two push buttons are used to provide different input conditions to the ECU.

The ESP32 reads the button inputs and checks the programmed conditions.

Based on the input:

* The ECU changes its current status.
* The OLED displays the corresponding status.
* The buzzer is activated when an alert condition occurs.

This helped me understand how input processing and output control work in an embedded system.



## Control Flow

```text
Push Button Input
       ↓
    ESP32
       ↓
Check Input Condition
       ↓
ECU Control Logic
       ↓
 ┌───────────────┐
 ↓               ↓
OLED Display    Buzzer
Status           Alert
```

## Technologies Used

* Embedded C / C++
* ESP32
* Wokwi
* OLED Display
* Digital Input / Output

## Project Screenshot

![Automotive ECU Simulator](ecu-simulator.png)

## What I Learned

Through this project, I practiced:

* Reading digital inputs
* Controlling output devices
* Using an OLED display
* Writing embedded control logic
* Working with ESP32
* Testing an embedded system using Wokwi

## Future Improvements

I want to improve this simulator by adding more automotive-related features such as:

* CAN communication
* FreeRTOS tasks
* Watchdog timer
* Sensor fault detection
* ECU diagnostic functions
* More vehicle sensor inputs

## Source Code

The complete source code used for the simulator is available in this repository.

## Author

**Akilan S**

Electronics and Communication Engineering
