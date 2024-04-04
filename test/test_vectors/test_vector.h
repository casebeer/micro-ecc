
#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

typedef struct tv {
  const char* private_key;
  const char* public_key;
  const char* k;
  const char* hash;
  const char* r;
  const char* s;
} Test;

#endif
