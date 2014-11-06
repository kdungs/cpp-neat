#include "object.h"

#include <stdio.h>
#include <stdlib.h>

object_t *object_new(const unsigned x) {
  object_t *obj = malloc(sizeof(object_t));
  if (!obj) {
    fprintf(stderr, "Could not allocate memory!");
    return NULL;
  }
  obj->x = x;
  fprintf(stdout, "object_t ctor\n");  // For demonstration
  return obj;
}

void object_free(object_t *obj) {
  if (obj) {
    free(obj);
    fprintf(stdout, "object_t dtor\n");  // For demonstration
  }
}
