## overview

The EMBB (Embedded Smart Baby Bed) project is designed to develop an intelligent embedded system for monitoring a baby’s condition using multiple sensors.

The system is built on the PSoC™ Edge E84 (Edgi-Talk development board), which serves as the main controller running RT-Thread OS. It collects real-time data from different sources, including the on-board AHT20 temperature and humidity sensor, audio input from a microphone, and external sensors such as a camera module and a pressure sensor.

The project focuses on combining sensor data to provide a more accurate understanding of the baby’s state. Visual data is used to analyze movement and posture, pressure data helps detect presence and activity, and environmental data (temperature and humidity) ensures a safe and comfortable surrounding.

All processing is performed locally on the embedded device using edge AI techniques developed with DeepCraft Studio. This allows the system to respond quickly without relying on cloud services.

The EMBB system can detect abnormal situations and generate alerts or notifications, helping caregivers respond in real time. Overall, the project demonstrates how embedded AI and multi-sensor integration can be applied to build a practical and reliable smart monitoring system.



  
## System Diagram  


```text
+--------------------------------------------------+
|        EMBB - Embedded Smart Baby Bed             |
+--------------------------------------------------+

+---------------------------+
|        Sensor Layer        |
|---------------------------|
| Visual Sensor             |
| humidity Sensor |
| Pressure Sensor           |
+-------------+-------------+
              |
              v
+---------------------------+
|  Embedded Control Layer    |
|---------------------------|
| PSoC™ Edge E84 + Edgi-Talk      |
| RT-Thread OS              |
| GPIO / I2C / SPI Drivers  |
| Sensor Data Collection    |
+-------------+-------------+
              |
              v
+---------------------------+
|        AI Engine           |
|---------------------------|
| Edge AI DeepCraft Models  |
| humidty Analysis            |
| Vision Analysis           |
| Pressure Analysis         |
| Sensor Fusion             |
+-------------+-------------+
              |
              v
+---------------------------+
|      Decision Layer        |
|---------------------------|
| Normal / Warning / Alert  |
| Safety Condition Check    |
+-------------+-------------+
              |
              v
+---------------------------+
|       Output Layer         |
|---------------------------|
| Alert Signal              |
| Status Result             |
| User Notification         |
+---------------------------+
```
### Containers  

The EMBB system is divided into several containers. Each container is responsible for a specific function to ensure modular and organized system design.

---

### 1. Sensor Container  
Responsible for collecting data from all sensors.

**Sensors Used:**
- Visual Sensor (camera / vision module)
- Pressure Sensor
- Humidity Sensor

**Functions:**
- Capture visual data for movement analysis  
- Read pressure values for presence detection  
- Measure humidity for environment monitoring  

**Interfaces:**
- GPIO  
- I2C  
- SPI  

---

### 2. Control Container  
Acts as the main system controller.

**Functions:**
- Manage communication with sensors  
- Handle RT-Thread tasks and scheduling  
- Process raw sensor data  

**Technology:**
- PSoC Edge  
- RT-Thread OS  

---

### 3. AI Engine Container  
Responsible for analyzing sensor data using embedded AI.

**Functions:**
- Analyze visual data (movement / posture)  
- Detect pressure changes (baby presence)  
- Evaluate environmental conditions (humidity)  
- Perform sensor fusion  

**Technology:**
- Edge AI DeepCraft Studio  
- On-device AI models  

---

### 4. Decision Container  
Responsible for determining system state.

**Functions:**
- Classify conditions (normal / warning / alert)  
- Apply safety rules  
- Trigger system responses  

---

### 5. Output Container  
Responsible for delivering results.

**Functions:**
- Generate alerts (LED / buzzer)  
- Provide system status  
- Notify user  

---
## Data Paths  
**Permalink: Data Paths**

### Visual Path

```text
Visual Sensor → Camera Interface → PSoC Edge → AI Engine → Vision Analysis → Decision → Output
```

### Pressure Path

```text
Pressure Sensor → ADC / I2C → PSoC Edge → Processing → Pressure Analysis → Decision → Output
```

### Humidity Path

```text
Humidity Sensor → I2C → PSoC Edge → Processing → Environment Analysis → Decision → Output
```

---

## AI Processing Flow  

```text
Sensor Inputs
(Visual + Pressure + Humidity)
        ↓
Data Preprocessing
        ↓
AI / Processing Layer
   ├── Vision Analysis
   ├── Pressure Analysis
   └── Humidity Monitoring
        ↓
Sensor Fusion
        ↓
Decision Making
(Normal / Warning / Alert)
        ↓
Output
(Alert Signal / Status Result / User Notification)
```

---

## Event Flow  

```text
AI / Processing Layer
        |
        | analyze sensor results
        v
Decision Layer
        |
        | trigger response
        v
Output Layer
        |
        v
User / Alert
```
## Network Architecture  


All system components communicate through the embedded communication interface of the EMBB system:

| Component            | Interface / Connection | Description                         |
|---------------------|----------------------|-------------------------------------|
| sensor_container    | GPIO / I2C / SPI     | Collects data from sensors           |
| control_container   | Internal Bus         | Manages system and data flow         |
| ai_engine           | Internal Processing  | Analyzes sensor data                 |
| decision_container  | Internal Logic       | Determines system state              |
| output_container    | GPIO / Signal Output | Sends alerts (LED / buzzer)          |
| communication       | Wi-Fi / UART / BLE   | Sends data to external system        |

---

### Data Communication Flow

```text
Sensors → Control → AI Engine → Decision → Output → User
```

---

### External Communication (Optional)

```text
EMBB Device → Wi-Fi / UART / BLE → Mobile App / Dashboard → User
```

## Hardware Requirements  

### Main Controller

- PSoC™ Edge E84 (Edgi-Talk Development Board)

---

### Sensors

- **Temperature & Humidity Sensor:**  
  - AHT20 (on-board)

- **Audio Input:**  
  - Microphone (via AUDIO interface)

- **Visual Sensor (External):**  
  - Camera Module (e.g., OV2640)

- **Pressure Sensor (External):**  
  - Force Sensitive Resistor (FSR)

---

### Interfaces

- GPIO  
- I2C  
- SPI  
- UART  
- AUDIO Interface  

---

### Output Devices

- On-board LEDs  
- Buzzer 

---

### Summary

```text
PSoC Edge + AHT20 + Microphone + Camera + Pressure Sensor
```
