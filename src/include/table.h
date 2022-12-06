#include <stdint.h>
#include "constants.h"
#include "pager.h"
#ifndef TABLE_H
#define TABLE_H

  typedef struct {
    Pager* pager;
    uint32_t root_page_num;
  } Table;

  Table* db_open();
  void db_close(Table* table);

#endif
