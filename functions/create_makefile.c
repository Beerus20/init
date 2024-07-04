#include "init.h"

void	ft_makefile_func(int fd, char *func_name, char *script)
{
	dprintf(fd, "\ndefine %s\n\t%s\nendef\n", func_name, script);
}

void	ft_target_script(int fd, char *script)
{
	dprintf(fd, "				");
	dprintf(fd, "%s\n\n", script);
}

void	ft_init_target(int fd)
{
	dprintf(fd, "\nall			: $(NAME)\n\n");
	dprintf(fd, "output		:\n");
	ft_target_script(fd, "@if [ ! -d output ]; then mkdir output; fi");
	dprintf(fd, "output/%%.o	: %%.c | output\n");
	ft_target_script(fd, "$(call create_objs,$<,$@)");
	dprintf(fd, "output/%%.o	: */%%.c | output\n");
	ft_target_script(fd, "$(call create_objs,$<,$@)");
	dprintf(fd, "$(NAME)		: $(FUNCT_OBJS) $(SRC_OBJS) $(OBJS)\n");
	ft_target_script(fd, "$(call create_exe,$^,$@)");
	dprintf(fd, "clean		:\n");
	ft_target_script(fd, "rm -rf $(FUNCT_OBJS) $(SRC_OBJS) $(OBJS)");
	dprintf(fd, "fclean		: clean\n");
	ft_target_script(fd, "rm -rf $(NAME)");
	dprintf(fd, "re			: fclean all\n");
	dprintf(fd, ".PHONY		: all clean fclean re");
}

void	ft_create_makefile(char *path, char *pname)
{
	int		fd;
	char	*file;

	file = ft_join_path(2, path, "Makefile");
	fd = open(file, O_RDWR | O_CREAT);
	free(file);
	if (fd == -1)
	{
		perror("ERROR to create Makefile\n");
		return ;
	}
	dprintf(fd, "NAME		= %s\n", pname);
	dprintf(fd, "FILES		= main.c\n\n");
	dprintf(fd, "SRC			= %s.c\n", pname);
	dprintf(fd, "FUNC		= utils.c\n");
	dprintf(fd, "OBJS		= $(FILES:%%.c=output/%%.o)\n");
	dprintf(fd, "SRC_OBJS	= $(SRC:%%.c=output/%%.o)\n");
	dprintf(fd, "FUNC_OBJS	= $(FUNC:%%.c=output/%%.o)\n");
	dprintf(fd, "CC			= cc\n");
	dprintf(fd, "CFLAGS		= -Wall -Wextra -Werror -Iincludes\n");
	ft_makefile_func(fd, "create_objs", "$(CC) $(CFLAGS) -c $(1) -o $(2);");
	ft_makefile_func(fd, "create_exe", "$(CC) $(CFLAGS) $(1) -o $(2);");
	ft_init_target(fd);
	close(fd);
}
