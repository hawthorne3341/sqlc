#include <stdint.h>
#include "constants.h"
#include "pager.h"
#ifndef TABLE_H
#define TABLE_H

  typedef struct {
    Pager* pager;
    uint32_t num_rows;
  } Table;

  Table* db_open();
  void db_close(Table* table);

#endif
