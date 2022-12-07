#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

t_format    *setup(char *file, int  *fd);
char        *unset(int fd, char *file);
void        free_shape(t_format **shape, char *str);
#endif