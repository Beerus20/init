#include "init.h"

void	ft_create_main(char *path, char *pname)
{
	int		fd;
	char	*file;

	file = ft_join_path(2, path, "main.c");
	fd = open(file, O_RDWR | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	if (fd == -1)
	{
		perror("ERROR to create main function\n");
		return ;
	}
	dprintf(fd, "#include \"%s.h\"\n\n", pname);
	dprintf(fd, "int	main(int argc, const char **argv)\n");
	dprintf(fd, "{\n");
	dprintf(fd, "\t(void)argc;\n");
	dprintf(fd, "\t(void)argv;\n");
	dprintf(fd, "\tprintf(\"Project %s was created succefuly\");\n", pname);
	dprintf(fd, "\treturn (0);\n");
	dprintf(fd, "}\n");
	free(file);
	close(fd);
}
