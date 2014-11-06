#ifndef __OBJECT_H__
#define __OBJECT_H__

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

#endif /* __OBJECT_H__ */
