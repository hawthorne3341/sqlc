#ifndef REPL_H
#define REPL_H

  typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
  } MetaCommandResult;

  typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
  } PrepareResult;

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
  } Statement;

  void start_repl();

#endif
