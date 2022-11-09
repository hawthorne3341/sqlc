#include <stdint.h>
#ifndef TABLE_H
#define TABLE_H

#define TABLE_MAX_PAGES 100

  typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
  } Pager;

  typedef struct {
    Pager* pager;
    uint32_t num_rows;
  } Table;

  Pager* pager_open (const char* filename);
  void* get_page(Pager* pager, uint32_t page_num);
  Table* db_open();
  void db_close(Table* table);

#endif
