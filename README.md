
---

# BetterList C Library

BetterList is a C library that allows you to create lists with multiple data types. This library provides a flexible and easy-to-use interface for managing lists in your C programs.

## Getting Started

### Prerequisites

Before using BetterList, make sure you have the following prerequisites installed:

- C compiler (e.g., GCC)

### Usage

1. Include the "betterlist.h" header file in your C program.

    ```c
    #include "betterlist.h"
    ```

2. Create objects for your list and data types.

    ```c
    int main() {
      // Create list objects
      Object *table = list();
      Object *line = list(); 
      
      // Create data objects
      Object *nb1 = integer(15);
      Object *nbtext = string("15");
      Object *nbfloat = floating(5.9);
    ```

3. Perform operations on the lists and data types.

    ```c
      // Add elements to the list
      add(line, nb1);     // add an integer
      add(line, nbfloat);  // add a float
      add(line, nbtext);   // add a string
      add(table, line);    // add a list
    
      // Access elements in the list
      Object *nb2 = get(line, 0); // get a saved value

      // Access number of element
      len(line);

      // Print information
      printf("%d\n", len(line));  // print the number of elements in the list
      printObject(nb2, "\n");      // print an object (<type> <value>)
      printObject(get(line, 0), "\n"); // print an element in the list [<type> <value>, ...]
      printObject(table, "\n");       // print a list of lists
    ```

### Examples

Check the provided example in the `main.c` file for a quick demonstration of BetterList in action.

This is the output of the provided example :

![image](https://github.com/GalTechDev/BetterList/assets/81401725/128912da-ac33-47d1-9db6-9c7196460abc)


## Contributing

If you'd like to contribute to BetterList, please fork the repository and create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

---
