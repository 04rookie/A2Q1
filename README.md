# Distributed Sorting with MPI - README

This project implements and analyzes an efficient **MPI (Message Passing Interface)** program to sort small integers in distributed memory. The program is designed to handle an array of signed 16-bit integers distributed across multiple processors, ensuring efficient sorting with minimal all-to-all data exchange.

## Key Features
- **Distributed Array**: The input array $$ X = [x_0, x_1, \dots, x_{n-1}] $$ is divided into $$ p $$ partitions ($$ X_0, X_1, \dots, X_{p-1} $$), where each partition resides in the memory of a processor.
- **Sorting Guarantee**: Ensures that for $$ i < j $$, all keys assigned to processor $$ i $$ are less than or equal to those assigned to processor $$ j $$.
- **Efficient Communication**: Avoids large-scale all-to-all data exchanges for better performance in distributed environments.
- **Key Assignment**: Guarantees that duplicate keys ($$ x_i = x_j $$) are assigned to the same processor.

## Implementation Highlights
- The program leverages MPI for inter-process communication and distributed memory management.
- It assumes no specific initial distribution of the input array across processors, ensuring flexibility.
- The algorithm ensures that the number of distinct keys is always greater than the number of processors ($$ p $$).

## Use Case
This implementation is ideal for scenarios requiring distributed sorting of small integer datasets while minimizing communication overhead. It is particularly suited for high-performance computing environments where processing efficiency and scalability are critical.

## Requirements
- MPI library (e.g., MPICH or OpenMPI)
- C/C++ compiler with MPI support

## How to Run
1. Compile the code using an MPI-compatible compiler:
   ```bash
   mpicc -o mpi_sort mpi_sort.c
   ```
2. Run the program with $$ p $$ processors:
   ```bash
   mpirun -np <number_of_processors> ./mpi_sort
   ```

## Output
The sorted array is distributed among the processors, respecting the guarantees outlined above. Each processor stores its respective partition of the sorted array.

---

Feel free to explore and adapt this implementation for your distributed sorting needs!
