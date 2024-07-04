#ifndef INIT_H
# define INIT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdarg.h>

int		ft_create_dir(char *path, char *pname);
char	*ft_capitalize(char *str);
char	*ft_join_path(int nb, ...);
void	ft_create_project(char *path, char *pname);
char	*ft_strjoins(int nb, ...);

/* --------------------- CREATE CFILE ------------------------ */
void	ft_create_cfile(char *path, char *pname, char *fname);

/* --------------------- CREATE MAIN ------------------------- */
void	ft_create_main(char *path, char *pname);

/* --------------------- CREATE INCLUDE ---------------------- */
void	ft_create_includes(char *path, char *pname);

/* --------------------- CREATE MAKEFILE --------------------- */
void	ft_create_makefile(char *path, char *pname);

#endif