#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern int errno;

/**
 * struct selectfunction - a struct array of functions
 * @command: a pointer to the caharacter of the command string
 * @funcptr: a pointer to a function
 */

typedef struct selectfunction
{
char *command;
int (*funcptr)(char **line);
} selecte;

void sigintHandler(int sig_num __attribute__((unused)));
void printprompt(int i);
int exitor(char *line[]);
int cater(char *line[]);
int getstr(char *str);
int shellprocessor(char **line, char **argv);
char **strbrk(char *line, char c);
int _getline(char **line, size_t *len);
void farewell(void);
void description(void);
void printstar(void);
void printstr(char *s);
int strleng(char *s);
void strcopy(char *src, char *dest);
int strcomp(char *str, char *equ);
void strmix(char *src, char *dest);
int lister(char **line);
int (*getfunc(char *str))(char **line);
int echorr(char *line[]);
int builtincom(char **line);
int changedire(char **line);
int pwder(char *line[]);
int envir(char *line[]);
int maker(char *line[]);
char _getchar(void);
char *stringer(char *line, int i, char *str, char c);
char *read_line(int *i_eof)
int get_help(data_shell *datash)
int get_error(data_shell *datash, int eval)
void get_sigint(int sig)
int (*get_builtin(char *cmd))(data_shell *)
char *swap_char(char *input, int bool)
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
int split_commands(data_shell *datash, char *input)
char **split_line(char *input)
void check_env(r_var **h, char *in, data_shell *data)
int check_vars(r_var **h, char *in, char *st, data_shell *data)
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
char *rep_var(char *input, data_shell *datash)
char *without_comment(char *in)
void shell_loop(data_shell *datash)
int cd_shell(data_shell *datash)
void cd_dot(data_shell *datash)
void cd_to(data_shell *datash)
void cd_previous(data_shell *datash)
void cd_to_home(data_shell *datash)

#endif
