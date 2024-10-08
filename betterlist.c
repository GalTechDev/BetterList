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
  if (object->type == "list") {
    while (len(object)>0) {
      pop(object, 0);
    }
  } else if (object->type == "dict") {
    while (len(object)>0) {
      Object *list_keys = keys(object);
      Object *key = get(list_keys, 0);
      pop(object, key);
    }
  }
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

void insert(Object *list, Object *key, Object *value) {
  if (list->type == "list") {
    List *list_core = list->value;
    Element *actual = list_core->premier;
    int i = 0;

    if (key > len(list)) {
      key = len(list);
    }

    // Find the position to insert
    while (actual->next != NULL && i < key) {
      actual = actual->next;
      i++;
    }

    // Create the new element
    Element *nouveau = malloc(sizeof(*nouveau));
    if (list_core == NULL || nouveau == NULL) {
      exit(EXIT_FAILURE);
    }
    nouveau->value = value;

    // Insert the new element
    nouveau->next = actual->next; 
    actual->next = nouveau; 
  }
}

Element *pop(Object *object, Object *key) {
  if (object->type == "list") {
    List *list_core = object->value;
    Element *actual = list_core->premier->next;
    int i = 0;
    while (i < key) {
      actual = actual->next;
      i++;
    }
    Element *precedant = list_core->premier;
    int j = 0;
    while (j < key) {
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

void set(Object *object, Object *key, Object *value) {
  if (object->type == "list") {
    List *list_core = object->value;
    if (key >= len(object) || len(object)==0) {
      // If the index is out of bounds, append the value
      append(object, value);
    } else {
      // If the index is within bounds, replace the existing value
      Element *actual = list_core->premier->next;
      int i = 0;
      while (actual->next != NULL) {
        if (i == key) {
          actual->value = value;
          break;
        } else {
          actual = actual->next;
          i++;
        }
      }
    }
  } else if (object->type == "dict") {
    Dict *dict_core = object->value;
    Element *actual = dict_core->premier->next;

    // Check if the key already exists
    while (actual->next != NULL) {
      if (actual->key->type == key->type && actual->key->value == key->value) {
        // Update the value if the key exists
        actual->value = value;
        return; // Exit the function after updating
      }
      actual = actual->next;
    }

    // If the key doesn't exist, add a new key-value pair
    Element *nouveau = malloc(sizeof(*nouveau));
    if (dict_core == NULL || nouveau == NULL) {
      exit(EXIT_FAILURE);
    }
    nouveau->key = key;
    nouveau->value = value;
    nouveau->next = dict_core->premier->next;
    dict_core->premier->next = nouveau; 
  }
}

Object *keys(Object *object) {
  if (object->type == "dict") {
    Dict *dict_core = object->value;
    Element *actual = dict_core->premier->next;
    Object *keys_list = list();
    while (actual->next != NULL) {
      append(keys_list, actual->key);
      actual = actual->next;
    }
    return keys_list;
  }
}

Object *values(Object *object) {
  if (object->type == "dict") {
    Dict *dict_core = object->value;
    Element *actual = dict_core->premier->next;
    Object *values_list = list();
    while (actual->next != NULL) {
      append(values_list, actual->value);
      actual = actual->next;
    }
    return values_list;
  }
}

Object *items(Object *object) {
  if (object->type == "dict") {
    Dict *dict_core = object->value;
    Element *actual = dict_core->premier->next;
    Object *items_list = list();
    while (actual->next != NULL) {
      Object *item = list();
      append(item, actual->key);
      append(item, actual->value);
      append(items_list, item);
      actual = actual->next;
    }
    return items_list;
  }
}

void update(Object *object_a, Object *object_b) {
  if (object_a->type == "dict" && object_b->type == "dict") {
    Object *keys_b = keys(object_b);
    for (int i = 0; i < len(keys_b); i++) {
      Object *key = get(keys_b, i);
      Object *value = get(object_b, key);
      set(object_a, key, value);
    }
  }
}

int existe(Object *object, Object *key) {
  if (object->type == "list") {
    List *list_core = object->value;
    Element *actual = list_core->premier->next;
    int i = 0;
    while (actual->next != NULL) {
      if (i == key) {
        return 1;
      } else {
        actual = actual->next;
        i++;
      }
    }
    return 0;

  } else if (object->type == "dict") {
    List *dict_core = object->value;
    Element *actual = dict_core->premier->next;

    while (actual->next != NULL) {
      if (actual->key->type == key->type) {
        if (actual->key->value == key->value) {
          return 1;
        }
      }
      actual = actual->next;
    }
  }
  return 0;
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
