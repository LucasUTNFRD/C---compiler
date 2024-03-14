#ifndef COMPILERPROJECT_H
#define COMPILERPROJECT_H

#include <stdio.h>
#include <stdbool.h>

struct pos
{
  int line;
  int col;
  const char * filename;
};

enum
{
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYPE_OPERATOR,
  TOKEN_TYPE_SYMBOL,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE
};

struct token
{
  int type;
  int flags;

  union
  {
    char charValue;
    char *stringValue;
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void * any;
  };

  bool whitespace;

  const char* between_brackets;
};


enum
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};

struct compile_process
{
    // The flags in regards to how this file should be compiled
    int flags;

    struct compile_process_input_file
    {
        FILE* fp;
        const char* abs_path;
    } cfile;

    FILE* ofile;

};

int compile_file(const char* filename, const char* out_filename, int flags);
struct compile_process *compile_process_create(const char *filename, const char *filename_out, int flags);

#endif
