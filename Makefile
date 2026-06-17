# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

# Libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# MLX
MLX_DIR = /tmp/mlx_linux
CMLXFLAG = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Include
INCLUDE = -I./include -I$(MLX_DIR)

# Source files
SRCS =  src/so_long.c \
		src/exit.c \
		src/flood_fill.c \
		src/hook.c \
		src/move.c \
		src/init_map.c \
		src/validate_map.c \
		src/load_img.c

# Object files
OBJ_DIR = obj
OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(NAME)

# Build pipex binary (regular)
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft $(CMLXFLAG) -o $(NAME)


# Build libft library if needed
$(LIBFT):
	make -C $(LIBFT_PATH) all

# Compile .c to .o
$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean object files
clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

# Full clean: remove objects and binary
fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
