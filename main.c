#include "init.h"

int	main(int argc, const char **argv)
{
	char	*path;
	char	*pname;

	path = NULL;
	pname = NULL;
	if (argc < 2)
		pname = "my_project";
	else
		pname = (char *)argv[1];
	if (!ft_create_dir("..", pname))
	{
		perror("Create project error\n");
		return (0);
	}
	path = ft_join_path(2, "..", pname);
	ft_create_project(path, pname);
	free(path);
	return (0);
}
