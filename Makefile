NAME	:= philo

CC		:= gcc
INCLUDE	:= ./includes
CFLAGS	:= -Wall -Wextra -Werror -I $(INCLUDE)
#CFLAGS	:= -ggdb -I $(INCLUDE)

BONUS	:= bonus/*.c
SRC		:= src/*.c
CYAN		= \033[0;96m
BLUE		= \033[0;94m
WHITE		= \033[0;97m

all: $(NAME)

$(NAME): norm
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(BLUE)philo$(CYAN) is ready to use"

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@echo "$(BLUE)philo executibles$(CYAN) are cleaned"

bonus: normb
	@$(CC) $(CFLAGS) $(BONUS) -o $(NAME)_bonus
	@echo "$(BLUE)philo_bonus$(CYAN) is ready to use"

clean:
	@rm -rf $(OBJDIR)

rebonus: fclean bonus

norm:
	@norminette $(SRC) $(INCLUDE)/ft_philosophers.h

normb:
	@norminette $(BONUS) $(INCLUDE)/bonus.h

re:	fclean all

.PHONY: all clean fclean re bonus rebonus