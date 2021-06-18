LIBFT = libft/libft.a
NAME = push_swap
SRCS = ft_push_swap.c \
	   srcs/ft_swap.c \
	   srcs/ft_rotate.c \
	   srcs/ft_rrotate.c \
	   srcs/ft_push.c \
	   srcs/ft_error_check.c \
	   srcs/ft_sort.c \
	   srcs/ft_median.c \
	   srcs/ft_rotate_choice_1.c \
	   srcs/ft_rotate_choice_2.c \
	   srcs/ft_rotate_choice_3.c \
	   srcs/ft_sort_large_100_utils.c \
	   srcs/ft_sort_large_500_utils.c \
		srcs/ft_sort_large_500_utils_2.c

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
INCS = -Iincludes -Llibft -lft
CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Iincludes -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./LIBFT
	$(CC) $(FLAGS) $(INCS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: clean all fclean re

