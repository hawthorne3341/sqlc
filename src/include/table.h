#include <stdint.h>
#ifndef TABLE_H
#define TABLE_H

#define TABLE_MAX_PAGES 100

  typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
  } Table;

  Table* new_table();
  void free_table(Table* table);

#endif
