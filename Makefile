# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboris <eboris@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 14:38:05 by eboris            #+#    #+#              #
#    Updated: 2020/03/08 17:25:52 by eboris           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
FLAGS = -Wall -Wextra -Werror
TERM_FLAGS = -lncurses -ltermcap
HEADERS = ./includes
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(HEADERS)/libft
LIBFT_OBJS_FILES = $(patsubst %.c, %.o, $(LIBFT_SRCS_FILES))
LIBFT_OBJS_DIR = $(OBJS_DIR)libft/
LIBFT_OBJS = $(addprefix $(LIBFT_OBJS_DIR), $(LIBFT_OBJS_FILES))
LIBFT_SRCS_FILES =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c           \
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c         \
					ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c      \
					ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c       \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c          \
					ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c    \
					ft_putendl.c ft_putendl_fd.c ft_puterror.c               \
					ft_puterrornbr.c ft_puterrorstr.c ft_putnbr.c            \
					ft_putnbr_fd.c ft_putnstr.c ft_putstr.c ft_putstr_fd.c   \
					ft_straddchr.c ft_strcat.c ft_strchr.c ft_strclr.c       \
					ft_strcmp.c ft_strcpy.c ft_strdel.c	ft_strdup.c          \
					ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c      \
					ft_strjoinfree.c ft_strlcat.c ft_strlen.c ft_strmap.c    \
					ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c      \
					ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c       \
					ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c       \
					ft_tolower.c ft_toupper.c get_next_line.c
FT_PRINTF_NAME = libprintf.a
FT_PRINTF_DIR = $(LIBFT_DIR)/printf/
FT_PRINTF_HEADERS = $(HEADERS)/printf
FT_PRINTF_OBJS_FILES = $(patsubst %.c, %.o, $(FT_PRINTF_SRCS_FILES))
FT_PRINTF_OBJS_DIR = $(LIBFT_OBJS_DIR)ft_printf/
FT_PRINTF_OBJS = $(addprefix $(FT_PRINTF_OBJS_DIR), $(FT_PRINTF_OBJS_FILES))
FT_PRINTF_SRCS_FILES =  ft_lists.c ft_putstr.c ft_strcpys.c ft_strdups.c     \
						ft_strs.c ft_parsing.c ft_strpercent.c ft_atoi.c     \
						ft_itoa.c ft_null.c ft_remparam.c ft_flags.c         \
						ft_width.c ft_precision.c ft_length.c ft_type.c      \
						ft_typefun.c ft_strings.c ft_stringwidth.c ft_char.c \
						ft_charwidth.c ft_integer.c ft_num2char.c            \
						ft_num2charhhh.c ft_num2charjtzl.c ft_intwidth.c     \
						ft_integeru.c ft_numu2char.c ft_numu2charhhh.c       \
						ft_numu2charjtzl.c ft_float.c ft_float_floor.c 		 \
						ft_fixmanissa.c ft_ld_arr.c ft_ld_refix.c            \
						ft_ld_rounding.c ft_ldouble_ceiling.c                \
						ft_ldouble_floor.c ft_float_naninf.c                 \
						ft_float_refix.c ft_float_arr.c ft_float_ceiling.c   \
						ft_float_rounding.c ft_octal.c ft_hexadec.c          \
						ft_binary.c ft_printf.c

OBJS_FILES = $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
SRCS_FILES = 	ft_select.c fts_errors.c fts_args.c fts_structs_func.c		\
				fts_term.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: clean fclean re

all: $(NAME)

$(LIBFT_NAME): $(LIBFT_OBJS_DIR) $(LIBFT_OBJS)
			@ar rc $(LIBFT_NAME) $(LIBFT_OBJS)
			@ranlib $(LIBFT_NAME)
			@echo "\n$(LIBFT_NAME): $(GREEN)объектные файлы созданы.$(RESET)"
			@echo "$(LIBFT_NAME): $(GREEN)Библиотека $(LIBFT_NAME) создана.$(RESET)"


$(LIBFT_OBJS_DIR):
			@mkdir -p $(LIBFT_OBJS_DIR)
			@echo "$(LIBFT_NAME): $(GREEN)каталог $(LIBFT_OBJS_DIR) создан.$(RESET)"

$(LIBFT_OBJS_DIR)%.o : $(LIBFT_DIR)%.c $(LIBFT_HEADERS)
			@$(CC) $(FLAGS) -I$(LIBFT_HEADERS) -c $< -o $@
			@echo "$(GREEN).$(RESET)\c"

libclean:
			@rm -rf $(LIBFT_OBJS_DIR)
			@echo "$(LIBFT_NAME): $(RED)каталог $(LIBFT_OBJS_DIR) удален.$(RESET)"
			@echo "$(LIBFT_NAME): $(RED)объектные файлы удалены.$(RESET)"

libfclean: libclean
			@rm -f $(LIBFT_NAME)
			@echo "$(LIBFT_NAME): $(RED)библиотека $(LIBFT_NAME) удалена.$(RESET)"

$(FT_PRINTF_NAME): $(FT_PRINTF_OBJS_DIR) $(FT_PRINTF_OBJS)
			@ar rc $(FT_PRINTF_NAME) $(FT_PRINTF_OBJS)
			@ranlib $(FT_PRINTF_NAME)
			@echo "\n$(FT_PRINTF_NAME): $(GREEN)объектные файлы созданы.$(RESET)"
			@echo "$(FT_PRINTF_NAME): $(GREEN)Библиотека $(FT_PRINTF_NAME) создана.$(RESET)"


$(FT_PRINTF_OBJS_DIR):
			@mkdir -p $(FT_PRINTF_OBJS_DIR)
			@echo "$(FT_PRINTF_NAME): $(GREEN)каталог $(FT_PRINTF_OBJS_DIR) создан.$(RESET)"

$(FT_PRINTF_OBJS_DIR)%.o : $(FT_PRINTF_DIR)%.c $(FT_PRINTF_HEADERS)
			@$(CC) $(FLAGS) -I$(FT_PRINTF_HEADERS) -c $< -o $@
			@echo "$(GREEN).$(RESET)\c"

printfclean:
			@rm -rf $(FT_PRINTF_OBJS_DIR)
			@echo "$(FT_PRINTF_NAME): $(RED)каталог $(FT_PRINTF_OBJS_DIR) удален.$(RESET)"
			@echo "$(FT_PRINTF_NAME): $(RED)объектные файлы удалены.$(RESET)"

printffclean: printfclean
			@rm -f $(FT_PRINTF_NAME)
			@echo "$(FT_PRINTF_NAME): $(RED)библиотека $(FT_PRINTF_NAME) удалена.$(RESET)"

$(NAME): $(LIBFT_NAME) $(FT_PRINTF_NAME) $(OBJS_DIR) $(OBJS)
			@echo "\n$(NAME): $(GREEN)объектные файлы созданы.$(RESET)"
			@$(CC) $(SRCS) $(TERM_FLAGS) -I $(HEADERS) -I $(LIBFT_HEADERS) -I $(FT_PRINTF_HEADERS) -L. -lprintf -lft -o $(NAME) $<
			@echo "$(NAME): $(GREEN)программа $(NAME) создана.$(RESET)"

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)
			@echo "$(NAME): $(GREEN)каталог $(OBJS_DIR) создан.$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
			@$(CC) $(FLAGS) -I $(HEADERS) -I $(LIBFT_HEADERS) -I $(FT_PRINTF_HEADERS) -c $< -o $@
			@echo "$(GREEN).$(RESET)\c"

clean:
			@rm -rf $(OBJS_DIR)
			@echo "$(NAME): $(RED)каталог $(OBJS_DIR) удален.$(RESET)"
			@echo "$(NAME): $(RED)объектные файлы удалены.$(RESET)"

fclean: libfclean printffclean clean
			@rm -f $(NAME)
			@echo "$(NAME): $(RED)программа $(NAME) удалена.$(RESET)"

re: fclean $(NAME)
