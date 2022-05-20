#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM "\t\r\n\a"

/*Points to an array of pointers to strings called the "environment"*/
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator:;| &
 * @next: next node
 * Description: single linked list to store separators
 */

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

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
void free_data(data_shell *datash)
void set_data(data_shell *datash, char **av)
int main(int ac, char **av)
int exec_line(data_shell *datash) 

#endif
