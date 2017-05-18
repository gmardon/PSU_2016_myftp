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
/*
char *get_ip()
{
  char s[128];
  struct hostent *host;
  struct in_addr **adr;
  char *ipaddr;

  ipaddr = NULL;
  if (!gethostname(s, 256))
    if ((host = gethostbyname(s)) != NULL)
      for (adr = (struct in_addr **)host->h_addr_list; *adr; adr++)
	ipaddr = strdup(inet_ntoa(**adr));
  return (ipaddr);
}
*/