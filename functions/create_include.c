#include "init.h"

void	ft_create_includes(char *path, char *pname)
{
	int		fd;
	char	*file;

	file = ft_strjoins(2, pname, ".h");
	path = ft_join_path(2, path, file);
	pname = ft_capitalize(pname);
	fd = open(path, O_RDWR | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	if (fd == -1)
	{
		perror("ERROR to create include file\n");
		return ;
	}
	dprintf(fd, "#ifndef %s_H\n", pname);
	dprintf(fd, "# define %s_H\n\n", pname);
	dprintf(fd, "# include <stdio.h>\n\n");
	dprintf(fd, "#endif");
	free(pname);
	free(file);
	free(path);
	close(fd);
}

