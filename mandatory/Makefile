NAME = push_swap

SRCS = push_swap.c parser.c sort-0.c sort-1.c sort-2.c sort-3.c utils-0.c utils-1.c utils-2.c actions-0.c actions-1.c

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
	@echo "$(GREEN)push_swap generated ✅$(RESET)"

$(OBJS): %.o: %.c $(RELINK)
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT) --no-print-directory

clean:
	@make clean -C $(LIBFT) --no-print-directory
	@rm -f $(OBJS)
	@echo "$(YELLOW)cleaning push_swap objects! 🧹✨$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT) --no-print-directory
	@rm -f $(NAME)
	@echo "$(RED)remove push_swap ❌$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
