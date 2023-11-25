#include "betterlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Object *table = list();
  Object *line = list(); 
  Object *nb1 = integer(15);
  Object *nbtext = string("15");
  Object *nbfloat = floating(5.9);
  
  printObject(nb1, "\n");
  printf("%d\n", nb1->value);
  printObject(nbtext, "\n");
  printObject(nbfloat, "\n");
  add(line, nb1);     // add a integer
  add(line, nbfloat);  // add a float
  add(line, nbtext);  // add a string
  add(line, nbtext);  // add a other string
  add(table, line); // add a list

  Object *nb2 = get(line, 0); // get a saved value
  printf("%d\n", len(line));  // get number of element in list

  printObject(nb2, "\n");           // print an object <type> <value>
  printObject(get(line, 0), "\n"); // print an element in list
  printObject(table, "\n");       // print a list of list

  pop(get(table, 0), 0); // like pop(ligne, 0)
  printObject(table, "\n"); // print a list of list (without the first element line)
  printf("%d\n", len(get(table, 0))); // print number of element in list
  return 0;
}
