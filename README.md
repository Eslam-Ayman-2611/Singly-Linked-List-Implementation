# Singly Linked List Implementation in C++

A console-based C++ project developed as part of my **Data Structures and Algorithms** coursework at the Faculty of Engineering, Menoufia University.

The project focuses on understanding and implementing the **Singly Linked List** data structure using pointers and dynamic memory allocation.

## Project Overview

This application provides an interactive menu that allows users to create, manipulate, analyze, and visualize a singly linked list.

It demonstrates how linked lists work internally through node connections, pointer manipulation, and memory addresses.

## Features

### 1. Linked List Operations

- Create a linked list.
- Insert nodes at the beginning or end.
- Insert at a specific index.
- Insert after a specific value.
- Delete nodes from the beginning or end.
- Delete nodes by index or value.
- Delete the entire linked list.

### 2. Searching

- Search for a specific value.
- Find the smallest element.
- Find the largest element.

### 3. Sorting

- Sort elements in ascending order.
- Sort elements in descending order.

### 4. Movement & Reversing

- Move the largest element to the end.
- Move the smallest element to the beginning.
- Reverse the linked list.

### 5. Calculations

- Calculate the sum and average of all nodes.
- Calculate the sum and average of even values.
- Calculate the sum and average of odd values.
- Perform calculations on values divisible by a specified number.

### 6. Visualization

- Display the linked list node by node.
- Show node values and memory addresses.
- Visualize the `next` pointer connections.
- Display the head pointer and its address.

## Technologies Used

- **Language:** C++
- **Standard:** C++14
- **Core Concepts:** Data Structures, Pointers, Dynamic Memory Allocation, Structs, Functions, and Linked List Traversal.
- **Libraries:** Standard C++ Libraries.
- **Terminal Interface:** ANSI Escape Codes for colored output.

## Project Structure

```text
Singly-Linked-List-Implementation/
│
├── Main.cpp
├── Header.h
├── Colors.h
│
├── main_Functions.cpp
├── Inserting_Functions.cpp
├── Deleting_Functions.cpp
├── Searching_functions.cpp
├── Sorting_Functions.cpp
├── Movement_Functions_Reverse.cpp
├── Calculations_Functions.cpp
├── Displaying_Functions.cpp
└── Extra_functions.cpp
```

## How to Run

### Prerequisites

- A C++ compiler supporting C++14 or later (GCC or Clang).
- A terminal environment.

### Compilation

Navigate to the project directory and run:

```bash
g++ -std=c++14 Main.cpp -o Main
```

### Execution

On macOS or Linux:

```bash
./Main
```

On Windows:

```bash
Main.exe
```

## Learning Objectives

This project was developed to strengthen my understanding of:

- Singly Linked List implementation.
- Pointer operations and memory management.
- Dynamic memory allocation using `new` and `delete`.
- Insertion, deletion, and traversal algorithms.
- Searching and sorting techniques.
- Working with multiple C++ source files.
- Understanding how data structures are represented in memory.

## Academic Background

Developed as a practical application following the study of **Data Structures and Algorithms** during my Computer Engineering studies.

**Author:** Eslam Ayman

---

_This project represents an academic learning experience and a practical implementation of fundamental linked list operations in C++._
