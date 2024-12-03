CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCFILES = libft.c ft_split.c main.c parser.c parser_checker.c ft_list.c ft_list_utils.c ft_list_utils2.c instructions.c solver.c solver_calculator.c solver_utils.c
SRCDIR = ./
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))

BONUS_SRCFILES = libft.c ft_split.c bonus_main.c parser.c parser_checker.c ft_list.c ft_list_utils.c ft_list_utils2.c bonus_instructions.c checker.c
BONUS_OBJS = $(addprefix $(OBJDIR), $(BONUS_SRCFILES:.c=.o))

HEADERFILES = push_swap.h parser_checker.h ft_list.h instructions.h
HEADERDIR = ./
HEADERS = $(addprefix $(HEADERDIR), $(HEADERFILES))
INCLUDES = -I $(HEADERDIR)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS_NAME): $(OBJDIR) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
