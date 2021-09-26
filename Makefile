# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 21:51:25 by tshimoda          #+#    #+#              #
#    Updated: 2021/09/26 12:56:26 by tshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

AR= ar rc
CC= gcc
CFLAGS= -Wall -Werror -Wextra -c
RM= rm -rf

SDIR= sources
ODIR= objects

SRCS= ft_printf.c \
		ft_scanners.c \
		ft_norm_utils.c \
		ft_libft_utils.c \
		ft_category_is.c \
		ft_category_is2.c \
		ft_putcollection_cs.c \
		ft_putcollection_p.c \
		ft_putcollection_di.c \
		ft_putcollection_u.c \
		ft_putcollection_xlower.c \
		ft_putcollection_xupper.c \
		ft_set_bytes_utils.c \
		ft_count_digit_utils.c \

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 	

all: $(NAME)
		@echo "\033[1;32mmake done!"

$(NAME): $(ODIR) $(OFIX)
		$(AR) $(NAME) $(OFIX)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

bonus: $(NAME)
		
clean:
		$(RM) $(OFIX) $(ODIR)

fclean: clean
				$(RM) $(NAME)
				@echo "\033[1;34mmake fclean done!"
	
re: fclean all

.PHONY: all bonus clean fclean re