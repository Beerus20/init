#include "init.h"

void	ft_create_cfile(char *path, char *pname, char *fname)
{
	int		fd;
	char	*file;
	char	*tmp_pname;

	if (!fname)
		tmp_pname = ft_strjoins(2, pname, ".c");
	else
		tmp_pname = ft_strjoins(2, fname, ".c");
	file = ft_join_path(2, path, tmp_pname);
	fd = open(file, O_RDWR | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	free(tmp_pname);
	if (fd == -1)
	{
		printf("ERROR to create %s\n", pname);
		perror("file error\n");
		return ;
	}
	dprintf(fd, "#include \"%s.h\"\n", pname);
	free(file);
	close(fd);
}
