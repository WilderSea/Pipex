# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:20:50 by msintas-          #+#    #+#              #
#    Updated: 2022/11/29 14:20:51 by msintas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

# todos los .c, max 5 funciones por linea "\"

SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_hexa.c
			

OBJS	=	$(SRCS:.c=.o)

#BONUS	=	

#BONUS_OBJS		= $(BONUS:.c=.o)

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

#bonus:			$(OBJS) $(BONUS_OBJS)
#				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)


.PHONY:			all clean fclean re bonus