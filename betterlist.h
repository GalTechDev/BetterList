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
  Object *key;
};

typedef struct List List;
struct List {
  Element *premier;
};

typedef struct Dict Dict;
struct Dict {
  Element *premier;
};

typedef struct Float Float;
struct Float {
  double value;
};

typedef struct None None;
struct None {
  char *type;
};

extern List *list_init();

extern List *dict_init();

extern Object *list();

extern Object *dict();

extern Object *none();

extern Object *integer(int value);

extern Object *floating(double value);

extern Object *string(int value);

extern void clear(Object *);

extern int len(Object *);

extern void append(Object *, Object *value);

extern void insert(Object *, Object *key, Object *value);

extern void del(Object *, Object *key);

extern Element *pop(Object *, Object *key);

extern Object *get(Object *, Object *key);

extern void set(Object *, Object *key, Object *value);

extern Object *keys(Object *);

extern Object *values(Object *);

extern Object *items(Object *);

extern void update(Object *, Object *);

extern int existe(Object *, Object *);

extern char *toString(Object *object);

#endif
