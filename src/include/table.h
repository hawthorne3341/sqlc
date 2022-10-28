#include <stdint.h>
#ifndef TABLE_H
#define TABLE_H

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#define TABLE_MAX_PAGES 100

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

  typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
  } Table;

  typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
  } Row;

  Table* new_table();
  void free_table(Table* table);
  void serialize_row(Row* source, void* destination); 
  void deserialize_row(void* source, Row* destination); 
  void* row_slot(Table* table, uint32_t row_num);
  void print_row(Row* row); 

  static const uint32_t ID_SIZE = size_of_attribute(Row, id);
  static const uint32_t USERNAME_SIZE = size_of_attribute(Row, username);
  static const uint32_t EMAIL_SIZE = size_of_attribute(Row, email);

  static const uint32_t ID_OFFSET = 0;
  static const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
  static const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
  static const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

  static const uint32_t PAGE_SIZE = 4096;
  static const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
  static const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

#endif
