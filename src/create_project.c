#include "init.h"

int	ft_create_dir(char *path, char *pname)
{
	char	*dir;

	dir = ft_join_path(2, path, pname);
	if (mkdir(dir, 0755) == -1)
	{
		perror("ERROR to create directory");
		perror(pname);
		perror("\n");
		return (0);
	}
	return (1);
}

void	ft_create_project(char *path, char *pname)
{
	char	*tmp_path;

	tmp_path = NULL;
	if (ft_create_dir(path, "src"))
	{
		tmp_path = ft_join_path(2, path, "src");
		ft_create_cfile(tmp_path, pname, NULL);
		free(tmp_path);
	}
	if (ft_create_dir(path, "functions"))
	{
		tmp_path = ft_join_path(2, path, "functions");
		ft_create_cfile(tmp_path, pname, "utils");
		free(tmp_path);
	}
	if (ft_create_dir(path, "includes"))
	{
		tmp_path = ft_join_path(2, path, "includes");
		ft_create_includes(tmp_path, pname);
		free(tmp_path);
	}
	ft_create_main(path, pname);
	ft_create_makefile(path, pname);
}
