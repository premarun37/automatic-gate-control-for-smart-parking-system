# 🚗 Automatic Gate Control for Smart Parking System

## Using Circular Queue and Min Heap

This project presents an **Automated Smart Parking System** designed to improve parking management by automating **vehicle entry**, **parking slot allocation**, and **gate control** using embedded systems and efficient data structures.

The system is built using **Arduino UNO**, **HC-SR04 Ultrasonic Sensors**, and a **Servo Motor** to create a real-time smart parking solution.

To improve efficiency:

- **Circular Queue** is used for managing vehicle entry in FIFO order
- **Min Heap** is used to allocate the nearest available parking slot

---

# 📌 Project Objectives

- Automate parking gate control
- Reduce manual intervention in parking management
- Detect vehicle entry using ultrasonic sensors
- Allocate the nearest available parking slot efficiently
- Manage vehicle flow using FIFO logic
- Display real-time parking status through Serial Monitor

---

# ⚙️ System Overview

## 🔹 Vehicle Detection

Ultrasonic sensors detect vehicles approaching the entry gate and monitor parking slot occupancy.

## 🔹 Vehicle Queue Management

Incoming vehicles are managed using a **Circular Queue**, ensuring vehicles enter in **First-In-First-Out (FIFO)** order.

## 🔹 Smart Slot Allocation

Available parking slots are maintained using a **Min Heap** to assign the nearest available slot efficiently.

## 🔹 Automated Gate Control

A **Servo Motor** acts as the parking gate:

- Opens when parking is available
- Remains closed when all slots are occupied

## 🔹 Real-Time Monitoring

The system continuously updates parking slot status and displays results through the **Arduino Serial Monitor**.

---

# 🧠 Data Structures Used

## Circular Queue

Used for:

- Managing vehicle entry order
- Ensuring FIFO-based vehicle handling
- Preventing queue overflow efficiently

## Min Heap

Used for:

- Finding the nearest available parking slot
- Optimizing parking allocation time
- Improving system efficiency

---

# 🛠️ Hardware Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensors
- Servo Motor (SG90)
- Breadboard
- Jumper Wires
- USB Cable

---

# 💻 Software Requirements

- Arduino IDE
- Embedded C / Arduino Programming Language

---

# 📂 Project Directory Structure

```text
automatic-gate-control-for-smart-parking-system/
│
├── Code/
│   └── Arduino Source Code
│
├── Hardware-setup/
│   ├── Circuit-Setup/
│   └── Components-Used/
│
├── Serial-Monitor-Output/
│
└── README.md
```

---

# 🚀 Working Process

1. Vehicle arrives at the entry gate
2. Ultrasonic sensor detects the vehicle
3. System checks parking slot availability
4. Vehicle is added to the Circular Queue
5. Nearest available slot is assigned using Min Heap
6. Servo motor opens the gate
7. Slot occupancy status is updated in real time
8. Serial Monitor displays the current parking information

---

# 📸 Project Modules

## Code

Contains the Arduino source code implementing:

- Ultrasonic sensor control
- Servo motor operation
- Circular Queue logic
- Min Heap logic
- Serial Monitor output

## Hardware Setup

Contains:

- Circuit setup images
- Hardware component images
- Physical implementation details

## Serial Monitor Output

Contains screenshots showing:

- Slot availability status
- Occupied/free parking conditions
- Real-time monitoring output

---

# 🎯 Features

- Automated parking gate control
- Smart nearest-slot allocation
- Real-time occupancy monitoring
- Efficient vehicle queue management
- Low-cost embedded system implementation
- Scalable smart parking concept

---

# 👨‍💻 Team Members

- Mounidharan V
- Guna S
- Prem Arun P
- Thirulogasundar S

---
