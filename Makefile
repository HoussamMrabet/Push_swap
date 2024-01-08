NAME = push_swap

EXTRA = checker

all : $(NAME)

bonus : $(EXTRA)

$(NAME) :
	@make -C mandatory
	@mv mandatory/push_swap push_swap

$(EXTRA) :
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