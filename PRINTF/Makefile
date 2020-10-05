NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g

SOURCES = 	ft_printf.c \
			conversions.c \
			its_char.c \
			its_str.c \
			its_ptr.c \
			its_ptr2.c \
			its_int.c \
			its_int2.c \
			its_uint.c \
			its_oct.c \
			its_oct2.c \
			its_hex.c \
			its_hex2.c \
			its_float.c \
			its_float_2.c \
			modifiers.c \
			extra.c \
			extra_2.c \
			its_nonprint.c \
			its_binary.c

HEADER = includes

LIBFT = libft

DIR_S = srcs

DIR_O = obj

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

all: $(NAME)

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(SRCS)/

clean:
	rm -f $(OBJS)
	@rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean