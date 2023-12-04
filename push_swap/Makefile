NAME = push_swap
CC = cc -g -Wall -Wextra -Werror
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = array_to_list.c commands_utils.c input_checker.c list_utils_two.c list_utils.c main.c \
		print_error.c sort_utils_2.c sort_utils_3.c sort_utils.c sorting_center.c sorting_phase_2.c \
			commands.c
OBJS = *.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc -o $(NAME) $(OBJS) $(LIBFT) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) 

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)