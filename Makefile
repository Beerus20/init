NAME		= init_project
FILES		= main.c
SRC			= create_project.c utils.c
SRC_PATH	= $(SRC:%.c=src/%.c)
FUNC		= create_makefile.c create_include.c create_main.c create_cfile.c
FUNC_PATH	= $(FUNC:%.c=functions/%.c)

OBJS		= $(FILES:%.c=output/%.o)
SRC_OBJS	= $(SRC_PATH:src/%.c=output/%.o)
FUNC_OBJS	= $(FUNC_PATH:functions/%.c=output/%.o)

CC			= clang -g
CFLAGS		= -Wall -Wextra -Werror -Iincludes

define create_objs
	@$(CC) $(CFLAGS) -c $(1) -o $(2);
endef

define create_exe
	@$(CC) $(CFLAGS) $(1) -o $(2);
endef

all			: $(NAME)

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call create_objs,$<,$@)

output/%.o	: */%.c | output
				$(call create_objs,$<,$@)

$(NAME)		: $(FUNC_OBJS) $(SRC_OBJS) $(OBJS)
				$(call create_exe,$^,$@)

init		: $(NAME)
				@./$(NAME)
				cd ../my_project

init\:%		: $(NAME)
				@./$(NAME) $(subst init:,,$@)
				cd ../$(subst init:,,$@)

rm\:%		:
				@rm -rf ../$(subst rm:,,$@)

clean		:
				@rm -rf $(FUNC_OBJS) $(SRC_OBJS) $(OBJS)

fclean		: clean
				@rm -rf $(NAME)

re			: fclean all
.PHONY		: all clean fclean re