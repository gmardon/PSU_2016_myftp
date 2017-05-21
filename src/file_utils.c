#include "myftp.h"

int	is_directory(char *path)
{
  if (opendir(path))
    {
      return (1);
    }
  return (0);
}

int	last_slash_index(char *path)
{
  int index;
  int last_index;

  index = last_index = 0;
  while (path[index])
    {
      if (path[index] == '/')
				last_index = index;
      index++;
    }
  return (last_index);
}

int	first_slash_index(char *path)
{
  int index;

  index = 0;
  while (path[index])
    {
      if (path[index] == '/')
				return (index + 1);
      index++;
    }
  return (index);
}

char *concat_path(char *base_path, char *to_add)
{
  char *path;

  if (*to_add == 0)
    return (strdup(base_path));

  if (*to_add == '/')
    return (strdup(to_add));

  if (strncmp(to_add, "./", 2) == 0 || strcmp(to_add, ".") == 0)
    return (concat_path(base_path, to_add + first_slash_index(to_add)));

  if (strncmp(to_add, "../", 3) == 0 || strcmp(to_add, "..") == 0)
    {
      path = (strdup(base_path));
      path[last_slash_index(path)] = 0;
      return (concat_path(path, to_add + first_slash_index(to_add)));
    }
  path = (strdup(to_add));
  path[first_slash_index(path)] = 0;
  return (concat_path(strcat(strcat(base_path, "/"), path),
		      to_add + first_slash_index(to_add)));
}
