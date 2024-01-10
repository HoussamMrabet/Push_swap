NAME = push_swap

EXTRA = checker

M_RELINK = mandatory/actions-0.c mandatory/actions-1.c mandatory/parser.c mandatory/push_swap.c mandatory/push_swap.h mandatory/sort-0.c mandatory/sort-1.c mandatory/sort-2.c mandatory/sort-3.c mandatory/utils-0.c mandatory/utils-1.c mandatory/utils-2.c

B_RELINK = bonus/actions-0_bonus.c bonus/actions-1_bonus.c bonus/checker_bonus.c bonus/get_next_line.c bonus/get_next_line.h bonus/get_next_line_utils.c bonus/parser_bonus.c bonus/push_swap_bonus.h bonus/utils_bonus.c

LM_RELINK = mandatory/libft/ft_isalpha.c mandatory/libft/ft_lstadd_back_bonus.c mandatory/libft/ft_lstlast_bonus.c mandatory/libft/ft_memcmp.c mandatory/libft/ft_printf.h mandatory/libft/ft_putstr_fd.c mandatory/libft/ft_strjoin.c mandatory/libft/ft_strncmp.c mandatory/libft/ft_tolower.c mandatory/libft/ft_atoi.c mandatory/libft/ft_isascii.c mandatory/libft/ft_lstadd_front_bonus.c mandatory/libft/ft_lstmap_bonus.c mandatory/libft/ft_memcpy.c mandatory/libft/ft_printf_utils.c mandatory/libft/ft_split.c mandatory/libft/ft_strlcat.c mandatory/libft/ft_strnstr.c mandatory/libft/ft_toupper.c mandatory/libft/ft_bzero.c mandatory/libft/ft_isdigit.c mandatory/libft/ft_lstclear_bonus.c mandatory/libft/ft_lstnew_bonus.c mandatory/libft/ft_memmove.c mandatory/libft/ft_putchar_fd.c mandatory/libft/ft_strchr.c mandatory/libft/ft_strlcpy.c mandatory/libft/ft_strrchr.c mandatory/libft/ft_calloc.c mandatory/libft/ft_isprint.c mandatory/libft/ft_lstdelone_bonus.c mandatory/libft/ft_lstsize_bonus.c mandatory/libft/ft_memset.c mandatory/libft/ft_putendl_fd.c mandatory/libft/ft_strdup.c mandatory/libft/ft_strlen.c mandatory/libft/ft_strtrim.c mandatory/libft/libft.h mandatory/libft/ft_isalnum.c mandatory/libft/ft_itoa.c mandatory/libft/ft_lstiter_bonus.c mandatory/libft/ft_memchr.c mandatory/libft/ft_printf.c mandatory/libft/ft_putnbr_fd.c mandatory/libft/ft_striteri.c mandatory/libft/ft_strmapi.c mandatory/libft/ft_substr.c

LB_RELINK = bonus/libft/ft_isalpha.c bonus/libft/ft_lstadd_back_bonus.c bonus/libft/ft_lstlast_bonus.c bonus/libft/ft_memcmp.c bonus/libft/ft_printf.h bonus/libft/ft_putstr_fd.c bonus/libft/ft_strjoin.c bonus/libft/ft_strncmp.c bonus/libft/ft_tolower.c bonus/libft/ft_atoi.c bonus/libft/ft_isascii.c bonus/libft/ft_lstadd_front_bonus.c bonus/libft/ft_lstmap_bonus.c bonus/libft/ft_memcpy.c bonus/libft/ft_printf_utils.c bonus/libft/ft_split.c bonus/libft/ft_strlcat.c bonus/libft/ft_strnstr.c bonus/libft/ft_toupper.c bonus/libft/ft_bzero.c bonus/libft/ft_isdigit.c bonus/libft/ft_lstclear_bonus.c bonus/libft/ft_lstnew_bonus.c bonus/libft/ft_memmove.c bonus/libft/ft_putchar_fd.c bonus/libft/ft_strchr.c bonus/libft/ft_strlcpy.c bonus/libft/ft_strrchr.c bonus/libft/ft_calloc.c bonus/libft/ft_isprint.c bonus/libft/ft_lstdelone_bonus.c bonus/libft/ft_lstsize_bonus.c bonus/libft/ft_memset.c bonus/libft/ft_putendl_fd.c bonus/libft/ft_strdup.c bonus/libft/ft_strlen.c bonus/libft/ft_strtrim.c bonus/libft/libft.h bonus/libft/ft_isalnum.c bonus/libft/ft_itoa.c bonus/libft/ft_lstiter_bonus.c bonus/libft/ft_memchr.c bonus/libft/ft_printf.c bonus/libft/ft_putnbr_fd.c bonus/libft/ft_striteri.c bonus/libft/ft_strmapi.c bonus/libft/ft_substr.c

all : $(NAME)

bonus : $(EXTRA)

$(NAME) : $(M_RELINK) $(LM_RELINK)
	@make -C mandatory
	@mv mandatory/push_swap push_swap

$(EXTRA) : $(B_RELINK) $(LB_RELINK)
	@make -C bonus
	@mv bonus/checker checker

clean :
	@make clean -C mandatory
	@make clean -C bonus

fclean :
	@rm -rf $(NAME) $(EXTRA)
	@make fclean -C mandatory
	@make fclean -C bonus

re : fclean all

.PHONY: all clean fclean re
