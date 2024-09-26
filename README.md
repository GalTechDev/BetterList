
---

# BetterList C Library

BetterList is a C library that allows you to create list and dictionary with multiple data types. This library provides a flexible and easy-to-use interface for managing Object in your C programs.

## Getting Started

### Prerequisites

Before using BetterList, make sure you have the following prerequisites installed:

- C compiler (e.g., GCC)

### Usage of List

1. Include the "betterlist.h" header file in your C program.

    ```c
    #include "betterlist.h"
    ```

2. Create objects for your list and variable.

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

3. Perform operations on the list and variable.

    ```c
      // Append elements to the end of a list
      append(line, nb1);     // append an integer
      append(line, nbfloat);  // append a float
      append(line, nbtext);   // append a string
      append(table, line);    // append a list

      // Clear a list
      printf("before list clear : %s\n", toString(line)); 
      clear(line);
      printf("after list clear : %s\n", toString(line)); 
      
      set(line, 0, nb1);     // append an integer
      set(line, 1, nbfloat);  // append a float
      //set(line, 2, nbtext);   // append a string
      set(table, 0, line);    // append a list
    
      printf("after list set : %s\n", toString(line)); 
    
      insert(line, 1, nbtext);     // insert a string
    
      printf("after list insert : %s\n", toString(line)); 
    
      // Access elements in the list
      Object *nb2 = get(line, 0); // get a Element

      // Access number of element
      len(line);
    ```

4. Get information on list and variable.

    ```c
      // Print information
      printf("len of list %d\n", len(line));  // print the number of elements in the list
      printf("element nb2 : %s\n", toString(nb2));      // print an object (<value>)
      printf("element of line[0] : %s\n", toString(get(line, 0))); // print an element in the list [<value1>, <value2>, ...]
      printf("liste 'table' : %s\n", toString(table));       // print a list of lists
    
      // Free memory
      Object *nb1_copy = pop(line, 0);
      del(line, 0);
    
      printf("'nb1_copy' the result of pop 0: %s\n", toString(nb1_copy));
      printf("liste 'table' : %s\n", toString(table));
      printf("index 0 existe ? %d\n", existe(line, 0));
      clear(line);
      printf("index 0 existe ? (after clear) %d\n", existe(line, 0));
    ```

5. Remove element

### Examples

Check the provided example in the `main.c` file for a quick demonstration of BetterList in action.

This is the output of the provided example :

![Capture d’écran_2024-09-26_08-38-48](https://github.com/user-attachments/assets/8f81972a-b1d7-41e5-a6e0-65225ebf6301)

### Usage of Dictionary

1. Include the "betterlist.h" header file in your C program.

    ```c
    #include "betterlist.h"
    ```

2. Create objects for your dict and variable.

    ```c
    int main() {
      // Create dict objects
      Object *dico1 = dict();
      Object *dico2 = dict(); 
      
      // Create data objects
      Object *nb1 = integer(15);
      Object *nbtext = string("15");
      Object *nbfloat = floating(5.9);
    ```

3. Perform operations on dict and variable.

    ```c
      // Clear a dict
      //clear(dico1); not implemented !!

      // Insert elements to the end of a dict
      insert(dico1, string("nb1"), nb1);     // append an integer
      insert(dico1, string("nbfloat"), nbfloat);  // append a float
      insert(dico1, string("nbtext"), nbtext);   // append a string
      insert(dico1, string("line"), line);   // append a list
      insert(dico2, string("dico1"), dico1);    // append a dict
    
      // Access elements in the list
      Object *nb2 = get(line, 0); // get a Element

      // Access number of element (key, value)
      len(dico1);
    ```
    
4. Get information on dict and variable.
   
   ```c
      // Print information
      printf("len of dict : %d\n", len(dico1));  // print the number of elements in the list
      printf("element nb2 : %s\n", toString(nb2));      // print an object <value>
      printf("element of dico1['line'] : %s\n", toString(get(dico1, string("line")))); // print an element in the dict
      printf("dict 'dico2' : %s\n", toString(dico2));       // print a dict of dict
   
      printf("nb1 existe ? %d\n", existe(dico1, string("nb1")));
      printf("nb2 existe ? %d\n", existe(dico1, string("nb2")));
    
      printf("keys of 'dico1' %s\n", toString(keys(dico1)));
      printf("values of 'dico1' %s\n", toString(values(dico1)));
      printf("items of 'dico1' %s\n", toString(items(dico1)));
    ```

5. Remove element
   ```c
       // Free memory
      Object *nb1_copy = pop(dico1, string("nbtext"));
      del(dico1, string("nbfloat"));
    
      printf("%s\n", toString(nb1_copy));
      printf("%s\n", toString(dico1));
   ``

### Examples

Check the provided example in the `main.c` file for a quick demonstration of BetterList in action.

This is the output of the provided example :

![Capture d’écran_2024-09-26_08-38-11](https://github.com/user-attachments/assets/5e0d997f-6418-484d-8de5-ea5b739d2246)

## Contributing

If you'd like to contribute to BetterList, please fork the repository and create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

---
