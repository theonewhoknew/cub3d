MAKEFLAGS += --no-print-directory

NAME = libft.a

SRCS =  $(addprefix $(SRC_DIR)/,ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_splitchr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putunbr.c ft_puthexnbr.c ft_contains_digit.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_dlstnew.c ft_dlstadd_back.c ft_dlstlast.c ft_dlstadd_front.c ft_reverse_tab.c \
		ft_printarr.c ft_strcmp.c ft_strcat.c ft_check_malloc_error.c ft_free_matrix.c ft_print_m.c \
		ft_count_arr.c)
		
OBJ_DIR = obj

SRC_DIR = src

PRINT_DIR = printf

GET_DIR = get_next_line

PRINT_SRCS = $(addprefix $(PRINT_DIR)/,ft_isprint.c ft_printadd.c ft_printchar.c ft_printf.c ft_printhex.c ft_printnbr.c ft_printstr.c ft_printunbr.c)

GET_SRCS = $(addprefix $(GET_DIR)/,get_next_line_utils.c get_next_line.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
PRINT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(PRINT_SRCS:.c=.o)))
GET_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(GET_SRCS:.c=.o)))

CFLAGS = -Wall -Werror -Wextra -I .

all: $(NAME)

$(NAME) : $(OBJS) $(PRINT_OBJS) $(GET_OBJS)
	ar rcs $(NAME) $(OBJS) $(PRINT_OBJS)  $(GET_OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c ./libft.h Makefile | $(OBJ_DIR)
	gcc -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o : $(PRINT_DIR)/%.c ./libft.h Makefile | $(OBJ_DIR)
	gcc -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o : $(GET_DIR)/%.c ./libft.h Makefile | $(OBJ_DIR)
	gcc -c $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all bonus clean fclean re
