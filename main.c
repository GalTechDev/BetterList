#include "betterlist.h"
#include <stdio.h>
#include <stdlib.h>

void list_demo() {
  // Create list objects
  Object *table = list();
  Object *line = list(); 

  // Create data objects
  Object *nb1 = integer(15);
  Object *nbtext = string("15");
  Object *nbfloat = floating(5.9);

  // Append elements to the end of a list
  append(line, nb1);     // append an integer
  append(line, nbfloat);  // append a float
  append(line, nbtext);   // append a string
  append(table, line);    // append a list

  // Clear a list
  //clear(line); not implemented !!

  /* Not implemented !!
  // Insert elements to the end of a list
  insert(line, 0, nb1);     // append an integer
  insert(line, 0, nbfloat);  // append a float
  insert(line, 0, nbtext);   // append a string
  insert(table, 0, line);    // append a list
  */

  // Access elements in the list
  Object *nb2 = get(line, 0); // get a Element

  // Access number of element
  len(line);

  // Print information
  printf("%d\n", len(line));  // print the number of elements in the list
  printf("%s\n", toString(nb2));      // print an object (<value>)
  printf("%s\n", toString(get(line, 0))); // print an element in the list [<value1>, <value2>, ...]
  printf("%s\n", toString(table));       // print a list of lists

  // Free memory
  Object *nb1_copy = pop(line, 0);
  del(line, 0);

  printf("%s\n", toString(nb1_copy));
  printf("%s\n", toString(table));
}

void dict_demo() {
  Object *line = list(); 
  append(line, integer(15));

  // Create dict objects
  Object *dico1 = dict();
  Object *dico2 = dict(); 

  // Create data objects
  Object *nb1 = integer(15);
  Object *nbtext = string("15");
  Object *nbfloat = floating(5.9);

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

  // Print information
  printf("%d\n", len(dico1));  // print the number of elements in the list
  printf("%s\n", toString(nb2));      // print an object <value>
  printf("%s\n", toString(get(dico1, string("line")))); // print an element in the dict
  printf("%s\n", toString(dico2));       // print a dict of dict

  // Free memory
  Object *nb1_copy = pop(dico1, string("nbtext"));
  del(dico1, string("nbfloat"));

  printf("%s\n", toString(nb1_copy));
  printf("%s\n", toString(dico1));
}

int main() {

  //list_demo();
  //dict_demo();

  return 0;
}
