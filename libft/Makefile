 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josantos <josantos@42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:08:51 by josantos          #+#    #+#              #
#    Updated: 2021/06/09 15:08:03 by josantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
HEADER = libft.h
SRCS= ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memccpy.c \
      ft_memmove.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strlen.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strnstr.c \
      ft_strncmp.c \
      ft_atoi.c \
      ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_split.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
	  ft_putchar_bonus.c \
	  ft_putstr_bonus.c \
	  ft_putstr_len_bonus.c \
	  ft_itoa_base_bonus.c \
	  ft_litoa_base_bonus.c \
	  ft_litoa_bonus.c \
	  ft_llitoa_base_bonus.c \
	  ft_llitoa_bonus.c \
	  ft_atoll.c
OBJS= $(SRCS:.c=.o)
SRCS_STCK = lst_stacks/ft_dlstadd_back.c \
			lst_stacks/ft_dlstadd_front.c \
			lst_stacks/ft_dlst_clear.c \
			lst_stacks/ft_dlst_first.c \
			lst_stacks/ft_dlst_last.c \
			lst_stacks/ft_dlst_max.c \
			lst_stacks/ft_dlst_min.c \
			lst_stacks/ft_dlst_new.c \
			lst_stacks/ft_dlst_remove.c \
			lst_stacks/ft_dlst_size.c \
			lst_stacks/ft_dlstis_dup.c \
			lst_stacks/ft_dlstis_sorted.c \
			lst_stacks/ft_dlst_print.c
OBJS_STCK = $(SRCS_STCK:.c=.o)
SRCSB= ft_lstnew.c \
       ft_lstadd_front.c \
       ft_lstsize.c \
       ft_lstlast.c \
       ft_lstadd_back.c \
       ft_lstdelone.c \
       ft_lstclear.c \
       ft_lstiter.c \
       ft_lstmap.c
OBJSB = $(SRCSB:.c=.o)
FLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Ilst_stacks -I.

%.o: %.c 
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS) $(OBJSB) $(OBJS_STCK)
	ar -rs $(NAME) $(OBJS) $(OBJSB) $(OBJS_STCK)

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJSB) $(OBJS_STCK)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
