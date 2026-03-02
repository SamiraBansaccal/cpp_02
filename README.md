# CPP Module 02 (42 School)

## 📋 Description
This module introduces **Ad-hoc polymorphism**, **operator overloading**, and the **Orthodox Canonical Class Form**. The main objective is to create a functional class representing fixed-point numbers, offering a balance between performance and precision.

## 🧠 Implementation Logic (Score: 100/100)
The progression through the exercises builds a complete and robust numeric class:

- **Orthodox Canonical Class Form**: Implementation of the four essential member functions to ensure proper object lifecycle management:
  1. Default Constructor
  2. Copy Constructor
  3. Copy Assignment Operator (`operator=`)
  4. Destructor
- **Fixed-Point Arithmetic**: Instead of using standard `float` or `double`, I implemented a fixed-point representation with 8 fractional bits. This involved manual bit-shifting to handle conversions from integers and floats.
- **Operator Overloading**: 
  - **Comparison**: `>`, `<`, `>=`, `<=`, `==`, `!=`.
  - **Arithmetic**: `+`, `-`, `*`, `/`.
  - **Increment/Decrement**: Pre and post-increment/decrement (`++`, `--`).
- **Static Member Functions**: Implementation of `min` and `max` functions (and their `const` versions) to compare fixed-point objects.



## 📂 Project Structure
- `ex00/`: My First Class in Orthodox Canonical Form (Basic setup).
- `ex01/`: Towards a more useful fixed-point number class (Conversions from float/int).
- `ex02/`: Now we’re talking (Full operator overloading).
- `ex03/`: BSP (Binary Space Partitioning) - Optional logic using the Fixed class to check if a point is inside a triangle.

## 🛠️ Usage & Compilation

All exercises are compiled using `c++` with the `-std=c++98` flag.
```bash
make
```
