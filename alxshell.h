#ifndef _ALXSHELL_H_
#define _ALXSHELL_H_

/**  env variable */

extern char **environ;

/**  MACROS */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(a) (write(STDOUT_FILENO, a, _strlen(a)))

/**  LIB FUNCTIONS USED */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/** STRING FUNCTION */

char *str_tok(char *st, const char *to);
unsigned int checkDelim(char a, const char *st);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *st);
int _strcmp(char *ss, char *ss1);
int _isalpha(int d);
void arrayRet(char *arr, int len);
int int_len(int num);
char *_itoa(unsigned int t);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *ss, const char *ss1, size_t n);
char *_strdup(char *st);

/**  MEMORIES ALLOCATION AND MANAGEMENT */

void freeEnv(char **en);
void *fill_an_array(void *ab, int ad, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *calloc_(unsigned int size);
void *realloc_(void *p, unsigned int oldSize, unsigned int newSize);
void freeAll(char **input, char *ln);

/** INPUT Function */

void shell_prompt(void);
void signa(int sign);
char *getline_(void);

/**  Command parser and extractor */

int path_cmd(char **ln);
char *getenv_(char *name);
char **parse_cmd(char *cmd);
int handleBuiltin(char **cmd, int h);
void readFile(char *fname, char **argv);
char *build(char *token, char *value);
int checkBuiltin(char **cmd);
void creatEnvi(char **envi);
int check_cmd(char **tokens, char *ln, int co, char **argv);
void treatFile(char *ln, int counter, FILE *fd, char **argv);
void exit_bull(char **cmd, char *ln, FILE *fd);

/** BUILTIN  FUNCtions */

void hash(char *buff);
int history(char *input);
int histoDis(char **cmd, int h);
int disEnv(char **cmd, int h);
int changeDir(char **cmd, int h);
int displayHelp(char **cmd, int h);
int echoBuiltin(char **cmd, int h);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** Error handle and Printer */
void printNumber(unsigned int num);
void printNumberIn(int num);
void printError(char *ln, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bull - contain bultin to handle and functions to excute
 * @command:pointer to char
 * @func:func to excute when bultin true
 */

typedef struct  bull
{
	char *command;
	int (*func)(char **ln, int h);
} bul_t;

#endif
