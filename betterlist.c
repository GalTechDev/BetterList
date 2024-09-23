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

Object *list() {
  Object *object = malloc(sizeof(*object));
  object->type = "list";
  object->value = list_init();
  return object;
}

Object *dict() {
  Object *object = malloc(sizeof(*object));
  object->type = "dict";
  object->value = dict_init();
  return object;
}

List *dict_init() {
  List *dict = malloc(sizeof(*list));
  Element *element = malloc(sizeof(*element));
  Element *last = malloc(sizeof(*last));

  if (dict == NULL || element == NULL) {
    exit(EXIT_FAILURE);
  }
  int *first = malloc(sizeof(*first));

  last->value = first;
  last->next = NULL;
  element->value = first;
  element->next = last;
  dict->premier = element;

  return dict;
}

Object *none() {
  Object *object = malloc(sizeof(*object));
  object->type = "None";
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
  Float *Float = malloc(sizeof(*Float));
  Float->value = value;
  object->value = Float;
  return object;
}

Object *string(int value) {
  Object *object = malloc(sizeof(*object));
  object->type = "str";
  object->value = value;
  return object;
}

void clear(Object *object) {
  
}

int len(Object *object) {
  if (object->type == "list") {
    List *object_core = object->value;
    if (object_core == NULL) {
      return 0;
    } else {
      Element *actual = object_core->premier->next;
      int nb = 0;
      while (actual->next != NULL) {
        nb = nb + 1;
        actual = actual->next;
      }
      return nb;
    }
  } else if (object->type == "dict") {
    Dict *object_core = object->value;
    if (object_core == NULL) {
      return 0;
    } else {
      Element *actual = object_core->premier->next;
      int nb = 0;
      while (actual->next != NULL) {
        nb = nb + 1;
        actual = actual->next;
      }
      return nb;
    }
  } else {
    return -1;
  }
}

void append(Object *list, Object *value) {
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

void insert(Object *object, Object *key, Object *value) {
  if (object->type == "list") {
   // TODO
  } else if (object->type == "dict") {
    Dict *dict_core = object->value;
    Element *actual = dict_core->premier;
    Element *nouveau = malloc(sizeof(*nouveau));
    if (dict_core == NULL || nouveau == NULL) {
      exit(EXIT_FAILURE);
    }
    nouveau->key = key;
    nouveau->value = value;
    while (actual->next->next != NULL) {
      actual = actual->next;
    }

    /* Insertion de l'élément a la fin du dico */
    nouveau->next = actual->next;
    actual->next = nouveau;
  }
}

Element *pop(Object *object, Object *key) {
  if (object->type == "list") {
    List *list_core = object->value;
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
    return actual->value;
    
  } else if (object->type == "dict") {
    List *dict_core = object->value;
    Element *actual = dict_core->premier->next;
    int i = 0;
    while (actual->next != NULL) {
      if (actual->key->type == key->type) {
        if (actual->key->value == key->value) {
          break;
        }
      }
      actual = actual->next;
      i++;
    }

    Element *precedant = dict_core->premier;
    int j = 0;
    while (actual->next != NULL) {
      if (j == i) {
        precedant->next = actual->next;
        return actual->value;
      } else {
        precedant = precedant->next;
        j++;
      }
    }
  }
  return none();
}

void del(Object *object, Object *key) { free(pop(object, key)); }

Object *get(Object *object, Object *key) {
  if (object->type == "list") {
    List *list_core = object->value;

    Element *actual = list_core->premier->next;
    int i = 0;
    while (actual->next != NULL) {
      if (i == key) {
        return actual->value;
      } else {
        actual = actual->next;
        i++;
      }
    }

  } else if (object->type == "dict") {
    List *dict_core = object->value;
    Element *actual = dict_core->premier->next;

    while (actual->next != NULL) {
      if (actual->key->type == key->type) {
        if (actual->key->value == key->value) {
          return actual->value;
        }
      }
      actual = actual->next;
    }
  }
  return none();
}

extern char *toString(Object *object) {
  char *str = malloc(100); // Allocate memory for the string
  if (str == NULL) {
    exit(EXIT_FAILURE); // Handle memory allocation failure
  }
  str[0] = '\0'; // Initialize the string as empty
  if (object == NULL || object->type == "None") {
    strcat(str, "None");

  } else if (object->type == "int") { // int
    char int_str[50];
    sprintf(int_str, "%d", object->value);
    strcat(str, int_str);

  } else if (object->type == "float") { // float
    Float *Float_object = object->value;
    char float_str[50];
    sprintf(float_str, "%f", Float_object->value);
    strcat(str, float_str);

  } else if (object->type == "str") { // str
    char string_str[50];
    sprintf(string_str, "'%s'", object->value);
    strcat(str, string_str);

  } else if (object->type == "list") { // list
    List *list = object->value;
    if (list == NULL) {
      strcat(str, "[]");

    } else {
      strcat(str, "[");
      Element *actual = list->premier->next;
      int i = 0;
      while (i != len(object)) {

        char *element_str = toString(actual->value);
        strcat(str, element_str);
        free(element_str); // Free the temporary string

        actual = actual->next;
        i++;
        if (i != len(object)) {
          strcat(str, ", ");
        }
      }
      strcat(str, "]");
    }
  } else if (object->type == "dict") { // list
    Dict *dict = object->value;
    if (dict == NULL) {
      strcat(str, "{}");

    } else {
      strcat(str, "{");
      Element *actual = dict->premier->next;
      int i = 0;
      while (i != len(object)) {
        char *key_str = toString(actual->key);
        char *value_str = toString(actual->value);

        strcat(str, key_str);
        strcat(str, " : ");
        strcat(str, value_str);

        free(key_str);
        free(value_str);

        actual = actual->next;
        i++;
        if (i != len(object)) {
          strcat(str, ", ");
        }
      }
      strcat(str, "}");
    }
  } else {
    char object_str[50];
    sprintf(object_str, "<object at @%d>", object);
    strcat(str, object_str);
  }
  return str;
}
