#include <stdint.h>
#ifndef REPL_H
#define REPL_H

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#define TABLE_MAX_PAGES 100

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

  typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
  } MetaCommandResult;

  typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
  } PrepareResult;

  typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_TABLE_FULL
  } ExecuteResult;

  typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
  } StatementType;

  typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
  } InputBuffer;

  typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
  } Row;

  typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
  } Table;

  typedef struct {
    StatementType type;
    Row row_to_insert; // only used by insert statement
  } Statement;

  void start_repl();

#endif
