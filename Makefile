# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 18:25:23 by msintas-          #+#    #+#              #
#    Updated: 2022/12/08 17:41:51 by msintas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c pipex-utils.c

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

LIBFT_PATH	=	./Libft

FT_PRINTF_PATH	=	./ft_printf

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIBFT_PATH)
				make -C $(FT_PRINTF_PATH)
				$(CC) $(OBJS) $(LIBFT_PATH)/libft.a $(FT_PRINTF_PATH)/libftprintf.a -o $(NAME)
				
clean:
				make -C $(LIBFT_PATH) clean
				make -C $(FT_PRINTF_PATH) clean
				$(RM) $(OBJS)

fclean:			
				make -C $(LIBFT_PATH) fclean
				make -C $(FT_PRINTF_PATH) fclean
				$(RM) $(OBJS) $(NAME)

re:				fclean all


.PHONY:			all clean fclean re bonus
