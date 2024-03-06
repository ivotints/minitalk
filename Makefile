# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:49:56 by ivotints          #+#    #+#              #
#    Updated: 2024/02/27 16:37:25 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = minitalk.h
NAMESV = server
NAMECL = client
FLAGS = -Wall -Wextra -Werror
CC = cc

RESET	= \033[0m
BLUE	= \033[0;94m
YELLOW	= \033[0;93m
GRAY	= \033[0;90m

all: $(NAMECL) $(NAMESV)


$(NAMECL): client.c
	@$(CC) $(FLAGS) client.c -o $(NAMECL)
	@echo "$(BLUE)Client is ready!$(RESET)"

$(NAMESV): server.c
	@$(CC) $(FLAGS) server.c -o $(NAMESV)
	@echo "$(BLUE)Server is ready!$(RESET)"


clean:

fclean: clean
	@echo "$(GRAY)Removing minitalk...$(RESET)"
	@$(RM) $(NAMECL) $(NAMESV)

re: fclean all

.PHONY: all bonus clean fclean re
