#include <stdint.h>
#include "cursor.h"
#include "pager.h"
#include "row.h"
#include "table.h"
#ifndef REPL_H
#define REPL_H

  typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
  } MetaCommandResult;

  typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
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
    StatementType type;
    Row row_to_insert; // only used by insert statement
  } Statement;

  void start_repl();

#endif
