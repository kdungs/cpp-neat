#ifndef _OBJECT_H
#define _OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  unsigned x;  // Struct can't be empty.
} object_t;
object_t *object_new(const unsigned);
void object_free(object_t*);

#ifdef __cplusplus
}
#endif

#endif /* _OBJECT_H */
