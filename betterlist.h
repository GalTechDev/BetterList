#ifndef BETTERLIST_H
#define BETTERLIST_H

typedef struct Object Object;
struct Object {
  char *type;
  int *value;
};

typedef struct Element Element;
struct Element {
  Object *value;
  Element *next;
};

typedef struct List List;
struct List {
  Element *premier;
};

typedef struct Float Float;
struct Float {
  double value;
};

extern List *list_init();

Float *float_init(double value);

extern Object *list();

extern Object *integer(int value);

extern Object *floating(double value);

extern Object *string(int value);

extern int len(Object *);

extern void add(Object *, Object *value);

extern void pop(Object *, int);

extern Object *get(Object *, int);

extern void printObject(Object *object, char *end);

#endif