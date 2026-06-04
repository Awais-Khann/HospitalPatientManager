# Hospital Patient Manager

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![Structure](https://img.shields.io/badge/Architecture-Modular-orange.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A lightweight, modular command-line application in C++ for managing hospital patient queues and records. The project implements core data structures (priority queue, BST, merge sort) without using the STL to demonstrate fundamental algorithms and system design.

## Features

- Priority-based triage: Critical patients (priority 1) are served before normal patients (priority 2).
- Call next patient: Instantly serve the highest-priority waiting patient.
- Fast lookups: Search patient records by unique ID using a BST.
- Sort views: Display patients sorted by Age (merge sort) or by ID (in-order BST traversal).
- Modular design: Code separated into headers and source files for maintainability.

## Architecture & Data Structures

1. Linked List (Priority Queue) — manages the waiting line.
2. Binary Search Tree (BST) — stores patient records keyed by ID.
3. Merge Sort — sorts arrays of patient pointers by age.

## Prerequisites

- C++ compiler supporting C++11 or later (g++, clang++).

## Installation & Compilation

```bash
git clone https://github.com/Awais-Khann/HospitalPatientManager.git
cd HospitalPatientManager
g++ *.cpp -o hospital_system
```

Run the program:

- macOS / Linux:
```bash
./hospital_system
```

- Windows (from Command Prompt / PowerShell):
```powershell
hospital_system.exe
```

## Usage

On launch the menu displays:

```
===== HOSPITAL PATIENT SYSTEM =====
1. Add Patient(s)
2. Call Next Patient
3. Display Patient Queue
4. Search Patient by ID
5. Display Patients Sorted by Age
6. Display Patients Sorted by ID (BST)
0. Exit
```

When adding a patient, provide:
- ID (unique)
- Name
- Age
- Priority (1 = Critical, 2 = Normal)

## Contributing

Contributions, issues, and feature requests are welcome. Please open issues or pull requests on the repository.

## License

This project is open-source under the MIT License.
