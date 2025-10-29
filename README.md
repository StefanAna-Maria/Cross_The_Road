# Cross The Road

### Description
**Cross The Road** is a console-based **C++ game** inspired by the classic *Frogger*.  
The player controls a frog that must cross a busy road filled with moving cars. The objective is to guide the frog safely across the road multiple times, earning as many points as possible without getting hit by an obstacle.

The game provides a simplified yet engaging experience:
- Features a single obstacle type — **cars**.
- All obstacles move in the same direction.
- Each obstacle lane has **cars moving at different speeds**.
- The score increases for every successful road crossing.
- Includes an **interactive menu** that allows players to start a new game or exit.
- Game elements are represented by different symbols: **Player** (`V`), **Car** (`#`).
- Player controls: **W (up)**, **A (left)**, **S (down)**, **D (right)**.
- Runs entirely in the **console**.

---

### Functionality and Rules
- There are two *safe zones*: one at the top and one at the bottom of the map. Between them are multiple lanes filled with moving obstacles.  
- The player must move from one safe zone to the other while avoiding the cars.  
- Each time the frog successfully crosses the road (without hitting an obstacle), the score increases.  
- If the frog collides with an obstacle, it's **GAME OVER**, and the score resets.  
- The player can also quit the game manually by pressing **'Q'**.  
- After the game ends, the player receives a **game summary message** showing their final score and an **interactive menu** to either start a new game or exit the application.

---

### Technologies and Design
This project demonstrates clean **object-oriented design** principles and makes use of advanced **C++ programming concepts**, including:

- **Design Patterns**:
  - **Observer Pattern** — used for communication between game entities (e.g., player and obstacles).  
  - **Command Pattern** — encapsulates player actions and input handling.
  
- **Templates**:
  - A **template class** (`Player`) demonstrating type generalization.
  - A **template function** for displaying coordinates dynamically.

- **Programming Concepts**:
  - Encapsulation and inheritance to structure entities (`Player`, `Obstacle`, `Lane`, etc.).
  - Polymorphism for flexible behavior across objects.
  - File management for maintaining clean code and modularity.
  - Built using **CMake** and compiled in **Visual Studio 2022**.

---

### Project Summary
University project developed as part of the *Object-Oriented Programming — Year II, Semester II* course.  
Successfully implemented both fundamental and advanced OOP concepts suitable for an introductory OOP project.  
Received an evaluation grade of **9.20 / 10**. 

