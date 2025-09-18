# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

# Libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# MLX
CMLXFLAG = -lmlx -X11 -Xext -lm
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

# Source files
SRCS =

# Object files
OBJS = $(SRCS:.c=.o)


# Default target
all: $(NAME)

# Build pipex binary (regular)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft -L $(MLX_PATH) $(CMLXFLAG) -o $(NAME)

# Build libft library if needed
$(LIBFT):
	make -C $(LIBFT_PATH) all
# Build MLX library
$(MLX)
	make -C $(MLX_PATH) all

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f $(OBJS)

# Full clean: remove objects and binary
fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
