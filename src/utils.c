#include "myftp.h"

void print_error(char *msg, int exit_code)
{
	printf("%s\n", msg);
	if (exit_code != 0)
		exit(exit_code);
}

char **strsplit(const char* str, const char* delim) 
{
    char *s = strdup(str);
    size_t tokens_alloc = 1;
    size_t tokens_used = 0;
    char **tokens = calloc(tokens_alloc, sizeof(char*));
    char *token, *rest = s;
    while ((token = strsep(&rest, delim)) != NULL) {
        if (tokens_used == tokens_alloc) {
            tokens_alloc *= 2;
            tokens = realloc(tokens, tokens_alloc * sizeof(char*));
        }
        tokens[tokens_used++] = strdup(token);
    }
    if (tokens_used == 0) {
        free(tokens);
        tokens = NULL;
    } else {
        tokens = realloc(tokens, tokens_used * sizeof(char*));
    }
    free(s);
    return tokens;
}

char *execute(char *path)
{
    int process_id;
    int fork_id;
    int status;
    char *output;
    int cp[2];
    char      *newargv[] = { NULL };
    char      *newenviron[] = { NULL };
 

    if (pipe(cp) == -1)
        exit(84);
    status = 0;
    output = my_malloc(BUFFER_SIZE * 4 * sizeof(char));
    if ((fork_id = fork()) == 0)
    {
        close(1);
        dup(cp[1]);
        close(0);
        close(cp[0]);
        process_id = execve(path, newargv, newenviron);
    }
    close(cp[1]);
    read(cp[0], output, BUFFER_SIZE * 4);
    waitpid(fork_id, &status, 0);
    return (output);
}