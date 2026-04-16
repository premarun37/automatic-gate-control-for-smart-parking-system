# Automatic Gate Control for Smart Parking System

### Using Circular Queue and Min Heap

This project presents an **automated smart parking system** that controls vehicle entry and parking slot allocation using **Arduino Uno**, **ultrasonic sensors**, and a **servo motor**.  

Efficient data structures such as **Circular Queue** and **Min Heap** are used to manage vehicle flow and allocate the nearest available parking slot.

---

## Objectives

- Automate gate control based on parking slot availability  
- Assign the nearest available slot using Min Heap  
- Manage vehicle entry using Circular Queue (FIFO)  
- Reduce congestion and human intervention  

---

## System Overview

- Vehicles are detected at the entry using ultrasonic sensors  
- If a slot is available, the vehicle is added to a circular queue  
- The nearest free slot is selected using a min heap  
- A servo motor opens/closes the gate automatically  
- Slot status is updated in real time and displayed via Serial Monitor  

---

## Technologies & Components

- Arduino UNO  
- HC-SR04 Ultrasonic Sensors  
- Servo Motor (SG90)  
- Breadboard & Jumper Wires  
- Arduino IDE (Embedded C)  

---

## Directory Structure

```
automatic-gate-control-for-smart-parking-system/
│
├── Code/
├── Hardware-setup/
│   ├── Circuit-Setup/
│   └── Components-Used/
└── Serial-Monitor-Output/
```

---

## Team Members

- Mounidharan V  
- Guna S  
- Prem Arun P  
- Thirulogasundar S  
