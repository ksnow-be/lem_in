# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 12:37:56 by vferry            #+#    #+#              #
#    Updated: 2019/04/10 19:48:35 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= $(wildcard srcs/*.c)
OBJS	= $(patsubst srcs/%.c,%.o,$(SRCS))
INC		= includes/


$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJS): $(SRCS)
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I$(INC)
