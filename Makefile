# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

# Makefile for ft_printf project
NAME = push_swap.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/include

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Colors
GREEN = \033[0;32m
BLUE  = \033[0;34m
RESET = \033[0m

# ---------------- RULES ---------------- #

all: $(LIBFT) $(NAME)

# Build libft (If it's needed))
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Link final program
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BLUE)[ALL] push_swap ready!   (˵ •̀ ᴗ - ˵ ) ✧$(RESET)"

# Rule to compile source files into object files.
# Creates the object directory if it doesn't exist.
# Compiles .c files into .o files, including the necessary header directories.
# $< is the first prerequisite (the source file), and $@ is the target (the object file).
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_INC) -c $< -o $@

# Clean up object files and libft.a
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

# Same as clean but also removes test
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

# Rebuild everything from scratch
re: fclean all

# **************************************************************************** #
#                                     TEST                                     #
# **************************************************************************** #

# Test program name
NAME_TEST = test

# Rule to compile and run the test program from main.c
test: $(OBJ) $(LIBFT)
	@echo "$(MAGENTA)[TEST] Generating test!  ♪♪ ヽ(ˇ∀ˇ )ゞ $(RESET)"
	@$(CC) $(CFLAGS) main.c $(NAME) -I$(INC_DIR) -I$(LIBFT_INC) -g -o $(NAME_TEST)
	@./$(NAME_TEST)

.PHONY: all clean fclean re test