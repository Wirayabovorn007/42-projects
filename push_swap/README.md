*This project has been created as part of the 42 curriculum by wiboonpr.*

# Push_swap

## Description
**Push_swap** is a 42 School algorithm project that challenges students to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one must manipulate various types of algorithms and choose the most appropriate solution for optimized data sorting.

This project implements a **Greedy Algorithm** (often referred to as the "Turk Algorithm"). Instead of simply moving the top numbers, the program calculates the "push cost" for every node in stack A—determining exactly how many rotations are needed to place it correctly in stack B. It then executes the move for the node with the absolute cheapest cost, prioritizing simultaneous rotations (`rr` and `rrr`) to minimize operations.

## Instructions

### Compilation
The project uses a `Makefile` for compilation. To compile the executable, run the following command at the root of the repository:

```bash
make
```
This will generate the push_swap executable. Other available commands:
```bash
make clean: Removes object files.
```
```bash
make fclean: Removes object files and the executable.
```
```bash
make re: Recompiles the project from scratch.
```
### Execution
To run the program, pass a list of integers as arguments. The program will output the list of operations required to sort them.

```Bash
./push_swap 2 1 3 6 5 8
```
You can also pass the numbers as a single string, which is handled by the project's input parser:
```Bash
./push_swap "2 1 3 6 5 8"
```
To verify the output or visualize the sorting process, you can pipe the output to a checker (if available) or simply count the lines to see the efficiency:
```Bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
## Resources

### References
- [Push Swap Tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk) - This video provides a visual explanation of the "Turk Algorithm" (Greedy Sort) used in this project.

- [The "Turk Algorithm"](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) - The logic used in this project is based on greedy cost calculation strategies.

- [42 Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

## AI Usage
Artificial Intelligence was used in this project for the following tasks:

- Concept Explanation: To gain a deep understanding of the "Greedy/Turk" algorithm and how cost calculation logic handles simultaneous rotations.

- Debugging: To help identify potential memory leaks (e.g., ensuring stack b is freed).