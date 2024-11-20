
# Set Operations Project

## Overview
This project focuses on implementing a set data structure and supporting various operations on sets, such as union, intersection, difference, and symmetric difference. The program allows users to perform set operations on a range of elements from 0 to 127 and outputs the results in a specified format.

### Key Features:
- Supports basic set operations like union, intersection, subtraction, and symmetric difference.
- Handles multiple sets (SET-A, SET-B, SET-C, etc.), and allows users to interact with them through commands.
- Provides functionality to read and print sets, as well as display the results of set operations.

## Requirements
- The set elements are integers in the range from 0 to 127.
- Operations are performed on predefined sets (e.g., `SET-A`, `SET-B`, etc.).
- The program should handle invalid inputs gracefully and display appropriate error messages.

## Available Commands:
1. **Read a Set**
   - Command: `read_set SET, n1, n2, ..., -1`
   - Example: `read_set SETA, 5, 6, 23, 44, 76, 98, -1`
   - This command defines a set with specified elements.
   
2. **Print a Set**
   - Command: `print_set SET`
   - Example: `print_set SETA`
   - This command prints the current elements of the set.
   
3. **Union of Two Sets**
   - Command: `union_set SET1, SET2, SET3`
   - Example: `union_set SETA, SETB, SETC`
   - This command performs the union of the specified sets.
   
4. **Intersection of Two Sets**
   - Command: `intersect_set SET1, SET2`
   - Example: `intersect_set SETA, SETB`
   - This command performs the intersection of the specified sets.
   
5. **Subtraction of Two Sets**
   - Command: `sub_set SET1, SET2`
   - Example: `sub_set SETA, SETB`
   - This command performs the difference of the first set minus the second set.
   
6. **Symmetric Difference of Two Sets**
   - Command: `symdiff_set SET1, SET2`
   - Example: `symdiff_set SETA, SETB`
   - This command computes the symmetric difference of the two sets.

7. **Stop**
   - Command: `stop`
   - Example: `stop`
   - This command stops the execution of the program.

## Example Usage:

```bash
# Define sets
read_set SETA, 5, 6, 23, 44, 76, 98, -1
read_set SETB, 3, 6, 5, 4, 4, -1

# Print sets
print_set SETA
print_set SETB

# Perform operations
union_set SETA, SETB
intersect_set SETA, SETB
sub_set SETA, SETB
symdiff_set SETA, SETB
```

## Error Handling
- **Invalid Set Name**: If the set name is undefined, an error message will be displayed.
- **Invalid Set Member**: If a set member is out of range or not an integer, an error message will be displayed.
- **Missing Parameters**: If a required parameter is missing, an error message will be displayed.
- **Extraneous Text**: If there is extra text after the command, an error message will be displayed.
