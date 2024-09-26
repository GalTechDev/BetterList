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
  set(dico1, string("nb1"), nb1);     // append an integer
  set(dico1, string("nbfloat"), nbfloat);  // append a float
  
  printf("before dict clear : %s\n", toString(dico1)); 
  clear(dico1);
  printf("after dict clear : %s\n", toString(dico1)); 

  // Insert elements to the end of a dict
  set(dico1, string("nb1"), nb1);     // append an integer
  set(dico1, string("nbfloat"), nbfloat);  // append a float
  set(dico1, string("nbtext"), nbtext);   // append a string
  set(dico1, string("line"), line);   // append a list
  set(dico2, string("dico1"), dico1);    // append a dict

  // Access elements in the list
  Object *nb2 = get(line, 0); // get a Element

  // Access number of element (key, value)
  len(dico1);

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

  // Free memory
  Object *nb1_copy = pop(dico1, string("nbtext"));
  del(dico1, string("nbfloat"));

  printf("'nb1_copy' result of pop 'nbtext' : %s\n", toString(nb1_copy));
  printf("dict 'dico1' : %s\n", toString(dico1));
}

int main() {

  //list_demo();
  //dict_demo();

  return 0;
}
