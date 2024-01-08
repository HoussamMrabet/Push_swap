NAME = checker

SRCS = checker_bonus.c parser_bonus.c utils_bonus.c actions-0_bonus.c actions-1_bonus.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
RELINK = libft/libft.h

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT) -lft -o $@
	@echo "$(GREEN)checker generated ✅$(RESET)"

$(OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT) --no-print-directory

clean:
	@make clean -C $(LIBFT) --no-print-directory
	@rm -f $(OBJS)
	@echo "$(YELLOW)cleaning bonus objects! 🧹✨$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT) --no-print-directory
	@rm -f $(NAME)
	@echo "$(RED)remove checker ❌$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
