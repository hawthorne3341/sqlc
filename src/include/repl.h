#ifndef REPL_H
#define REPL_H

  typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
  } InputBuffer;

  void start_repl();

#endif
