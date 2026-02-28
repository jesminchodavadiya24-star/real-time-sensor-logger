# real-time-sensor-logger

#  Project Overview
The Real-Time Sensor Data Logger is a deterministic embedded-style C project designed to simulate a real-time sensor logging system.    

## The system demonstrates:
- Circular buffer implementation
- Finite State Machine (FSM) control
- Bit flag–based control signals
- Deterministic behavior (no dynamic memory in runtime loop)
- Zero memory leaks (verified using Valgrind)
- Modular architecture with clean build system

This project is structured to reflect embedded robotics system design principles used in real-world control systems.

---
# System Architecture
            +------------------+
            |  Sensor Input    |
            +------------------+
                      |
                      v
            +------------------+
            |  Logger Module   |
            |  (Bit Flags)     |
            +------------------+
                      |
                      v
            +------------------+
            |  FSM Controller  |
            | (IDLE/LOG/ERROR) |
            +------------------+
                      |
                      v
            +------------------+
            | Circular Buffer  |
            +------------------+


## Module Breakdown
- Circular Buffer    
  - Fixed-size, no dynamic allocation
  - O(1) push and pop
  - Deterministic memory usage
- FSM (Finite State Machine)
  - STATE_IDLE
  - STATE_LOGGING
  - STATE_ERROR
  - Explicit transition handling
- Logger
  - Uses bit flags to control system state
  - Ensures no data logging during error state
 
---

# Why Deterministic?
Robotics and embedded systems require predictable timing behavior.

## My project avoids:
- Dynamic memory allocation in control loops
- Unbounded recursion
- Blocking operations
- Undefined behavior
All memory is statically allocated.

## This ensures:
- Stable execution time
- No heap fragmentation
- Real-time safety principles    
Deterministic systems are critical in robotics for maintaining control loop stability and avoiding jitter.

---

# Memory Safety
## My project:
- Uses no malloc / free
- Contains no global unsafe memory access
- Uses bounded circular buffer
- Includes input validation
- Avoids buffer overflows

## Memory correctness verified using:
    valgrind --leak-check=full ./sensor_logger
## Expected output:
    All heap blocks were freed -- no leaks are possible
    0 errors from 0 contexts
    
This confirms zero memory leaks and safe memory handling.

---


