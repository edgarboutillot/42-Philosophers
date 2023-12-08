# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edgarboutillot <edgarboutillot@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:45:27 by edgarboutil       #+#    #+#              #
#    Updated: 2023/10/16 18:19:34 by edgarboutil      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	srcs/init.c srcs/threads.c\
					srcs/philo_routine.c \
					utils/number.c utils/utils.c\
					main.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	philo
HEAD_DIR		=	INCLUDES/

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3
FLAGS			+=	-MMD -MP


# RULES -------------------------------------------------------------
all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.c | dir
					$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/srcs
					@mkdir -p $(OBJS_DIR)/utils

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BON)

re:					fclean all

.PHONY:				all dir clean fclean re
