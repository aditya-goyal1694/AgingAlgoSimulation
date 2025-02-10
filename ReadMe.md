# Aging Algorithm Process Scheduler

## Overview
This project implements the **Aging Algorithm** to improve fairness in process scheduling in an operating system. The aging algorithm prevents **starvation** by gradually increasing the priority of waiting processes. The simulation is implemented in C and demonstrates how aging can be used to manage CPU scheduling efficiently.

## Features
- Reads a list of processes from a file (`processes.txt`).
- Implements the **Aging Algorithm** to prevent starvation.
- Simulates CPU scheduling with a time quantum.
- Tracks **Waiting Time (WT)** and **Turnaround Time (TAT)** for each process.
- Calculates **Average Waiting Time** and **Average Turnaround Time**.
- Displays a summary report of scheduling performance.

## File Structure
- `main.c` – Contains the implementation of the Aging Algorithm.
- `processes.txt` – Input file containing process details (Process ID, Burst Time).

## Input File Format (`processes.txt`)
Each line should contain:
```
<Process ID> <Burst Time>
```
Example:
```
1 5
2 8
3 3
4 6
```

## Compilation and Execution
### Compile the Code:
```bash
gcc main.c -o aging_scheduler
```
### Run the Program:
```bash
./aging_scheduler
```
### User Inputs:
- Number of processes.
- Time quantum for CPU scheduling.

## Output Format
```
Process ID   Burst Time   Waiting Time   Turnaround Time
1           5           0              5
2           8           5              13
3           3           13             16
4           6           16             22

Average Waiting Time: X.XX
Average Turnaround Time: X.XX
```

## Key Functions
- **`readProcesses()`** – Reads process data from a file.
- **`agingAlgo()`** – Implements the aging algorithm.
- **`main()`** – Manages user input, calls functions, and displays results.

## Future Improvements
- Implement a **priority queue** to dynamically adjust priorities.
- Add **graphical representation** of process execution.
- Support **multi-level queue scheduling**.

## License
This project is open-source and free to use.
