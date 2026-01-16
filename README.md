# *This project has been created as part of the 42 curriculum by tlamit.*

## Description

The goal of this project is to sort a stack of integers using a limited set of instructions and the smallest number of moves. You are given two stacks, `a` and `b`. At the beginning, stack `b` is empty and stack `a` contains a random set of unique integers. The objective is to sort stack `a` in ascending order.

## Instructions

### Compilation

```bash
make        # Compiles push_swap
make bonus  # Compiles checker
```

This will create the `push_swap` executable.

To compile the bonus part, which includes a `checker` program, run:

```bash
make bonus
```

### Execution

The `push_swap` program takes a list of integers as arguments.

```bash
./push_swap 4 2 1 3
```

The program will output a series of instructions to sort the given list.

The `checker` program (from the bonus part) can be used to verify the output of `push_swap`.

```bash
./push_swap 4 2 1 3 | ./checker 4 2 1 3
```

If the output is `OK`, the list is sorted correctly. Otherwise, it will show `KO`.

## Resources

- **42 Project Subject:** The official project description from 42.
- **Medium Articles:** Many articles on Medium explain the logic and algorithms for Push_swap.

### AI Usage

AI was used for the following tasks in this project:

- **Generating this README.md file:** An AI agent was prompted to create a README file that meets the 42 curriculum requirements.
- **Debugging:** AI was used to help debug parts of the sorting algorithm.
- **Code explanation:** AI helped in understanding and explaining certain parts of the code.
