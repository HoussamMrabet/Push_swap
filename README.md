# Push_swap Project

## Introduction
The **Push_swap** project is a sorting algorithm project that challenges developers to efficiently sort a set of integers using two stacks and a limited set of instructions. The objective is to create a program named `push_swap` that calculates and displays the smallest list of instructions to sort the given stack.

## Algorithms Used
### Radix Sort
For larger sets, I implemented a radix sort algorithm that operates on individual bits rather than digits. This allows for efficient sorting of heavy sets.

### Insertion Sort
For smaller sets, I utilized the insertion sort algorithm by splitting the set into chunks and sorting them individually.

### My Own Algorithm
To validate the project with full score, I implemented a custom algorithm. This algorithm uses two pivots that helps migrating from stack to another and identifies the best move to efficiently sort the stack.

## Implementation
### Mandatory Part
To run the mandatory part, execute:
```bash
make
./push_swap <list_of_integers>
```

### Bonus Part
To run the bonus part, execute:
```bash
make bonus
./checker <list_of_integers>
```

## Testing
I have included a checker program for testing the correctness of the sorting instructions generated by `push_swap`. It compares the output with the expected sorted stack.

### Example Usage
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

## Grading Criteria
### Mandatory
- The project successfully handles sorting with the lowest number of operations.
- The `push_swap` program produces the correct output and handles errors appropriately.

### Bonus
- The bonus part is only evaluated if the mandatory part is perfect.
- The bonus program `checker` correctly validates the sorting instructions.

### SCORE : 100/100 (+25 Bonus)

## Grade Breakdown
### Middle Version
- Successfully passed test for 100 random values.
- Score: 5/5

### Advanced Version
- Successfully passed test for 500 random values.
- Score: 5/5

## Conclusion
The project demonstrates a deep understanding of sorting algorithms and their complexity. The implemented solutions efficiently handle various scenarios, resulting in a high grade. The provided checker program ensures the correctness of the sorting instructions.
