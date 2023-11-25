#include "betterlist.h"
#include <stdio.h>
#include <stdlib.h>

List *list_init() {
  List *list = malloc(sizeof(*list));
  Element *element = malloc(sizeof(*element));
  Element *last = malloc(sizeof(*last));

  if (list == NULL || element == NULL) {
    exit(EXIT_FAILURE);
  }
  int *first = malloc(sizeof(*first));

  last->value = first;
  last->next = NULL;
  element->value = first;
  element->next = last;
  list->premier = element;

  return list;
}

Float *float_init(double value) {
  Float *Float = malloc(sizeof(*Float));
  Float->value = value;
  return Float;
}

Object *list() {
  Object *object = malloc(sizeof(*object));
  object->type = "list";
  object->value = list_init();
  return object;
}

Object *integer(int value) {
  Object *object = malloc(sizeof(*object));
  object->type = "int";
  object->value = value;
  return object;
}

Object *floating(double value) {
  Object *object = malloc(sizeof(*object));
  object->type = "float";
  object->value = float_init(value);
  return object;
}

Object *string(int value) {
  Object *object = malloc(sizeof(*object));
  object->type = "str";
  object->value = value;
  return object;
}

int len(Object *list) {
  List *list_core = list->value;
  if (list_core == NULL) {
    return 0;
  } else {
    Element *actual = list_core->premier->next;
    int nb = 0;
    while (actual->next != NULL) {
      nb = nb + 1;
      actual = actual->next;
    }
    return nb;
  }
}

void add(Object *list, Object *value) {
  /* Création du nouvel élément */
  List *list_core = list->value;
  Element *actual = list_core->premier;
  Element *nouveau = malloc(sizeof(*nouveau));
  if (list_core == NULL || nouveau == NULL) {
    exit(EXIT_FAILURE);
  }
  nouveau->value = value;
  while (actual->next->next != NULL) {
    actual = actual->next;
  }

  /* Insertion de l'élément a la fin de la liste */
  nouveau->next = actual->next;
  actual->next = nouveau;
}

void pop(Object *list, int index) {
  List *list_core = list->value;
  Element *actual = list_core->premier->next;
  int i = 0;
  while (i < index) {
    actual = actual->next;
    i++;
  }
  Element *precedant = list_core->premier;
  int j = 0;
  while (j < index) {
    precedant = precedant->next;
    j++;
  }
  precedant->next = actual->next;
  free(actual);
}

Object *get(Object *list, int index) {
  List *list_core = list->value;

  Element *actual = list_core->premier->next;
  int i = 0;
  while (i != index) {
    actual = actual->next;
    i++;
  }
  return actual->value;
}

extern void printObject(Object *object, char *end) {
  if (object->type == "int") { // int
    printf("%s %d%s", object->type, object->value, end);

  } else if (object->type == "float") { // float
    Float *Float_object = object->value;
    double double_value = Float_object->value;
    printf("%s %f%s", object->type, Float_object->value, end);

  } else if (object->type == "str") { // str
    printf("%s '%s'%s", object->type, object->value, end);

  } else if (object->type == "list") { // list
    List *list = object->value;
    if (list == NULL) {
      printf("list []%s", end);

    } else {
      printf("list [");
      Element *actual = list->premier->next;
      int i = 0;
      while (i != len(object)) {
        printObject(actual->value, "");
        actual = actual->next;
        i++;
        if (i != len(object)) {
          printf(", ");
        }
      }
      printf("]%s", end);
    }
  } else {
    printf("<object at @%d>%s", object, end);
  }
}
