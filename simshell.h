#ifndef _SIMSHELL_H_
#define _SIMSHELL_H_

#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>




ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **fhstrtok(char *str)
void forkexe(char **arstr, char *envp[])
char *filecheck(char *str)
int pathcheck(char *str)
int _myexit(info_t *info)

