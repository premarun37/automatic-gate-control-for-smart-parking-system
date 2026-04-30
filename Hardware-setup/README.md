# Hardware Setup

This directory contains all the **hardware components, circuit connections, and physical implementation details** of the *Automatic Gate Control for Smart Parking System*.

The hardware setup demonstrates how sensors, actuators, and the microcontroller work together to detect vehicles, allocate parking slots, and control the entry gate automatically.

---

## Hardware Components Used

- **Arduino UNO**
  - Acts as the central controller of the system
  - Processes sensor inputs and controls the servo motor
  - Implements Circular Queue and Min Heap logic

- **HC-SR04 Ultrasonic Sensors**
  - Used to detect vehicle presence
  - One sensor is placed at the entry gate
  - Sensors are placed at each parking slot to detect occupancy

- **Servo Motor (SG90)**
  - Simulates the automated parking gate
  - Rotates between 0° (closed) and 90° (open)

---

## Logic Used

- **Circular Queue**: Ensures FIFO vehicle entry handling
- **Min Heap**: Allocates nearest available parking slot efficiently

---

## Working Description

- Ultrasonic sensors continuously measure the distance to detect vehicles.

- When a vehicle is detected at the entry gate and a slot is available:
  - The servo motor opens the gate.
  - The vehicle is allowed to enter.

- Slot sensors monitor whether parking slots are occupied or free.

- Hardware status updates are sent to the Arduino Serial Monitor in real time.

---
