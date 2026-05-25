# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

# Makefile for ft_printf project
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
RED     = \033[0;31m
GREEN = \033[0;32m
YELLOW  = \033[0;33m
BLUE  = \033[0;34m
MAGENTA = \033[0;35m
RESET = \033[0m

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# **************************************************************************** #
#                             SOURCES & OBJECTS                                #
# **************************************************************************** #

# List of source files
SRC = $(shell find $(SRC_DIR) -name "*.c")
# Generate object file names from source file names
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

# Create the library
all: $(NAME)

# Rule to build the libft library from object files
# Copies the libftprintf.a to libft.a and then archives the object files into libft.a.
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BLUE)[ALL] libft ready!   (˵ •̀ ᴗ - ˵ ) ✧$(RESET)"

# Rule to compile source files into object files.
# Creates the object directory if it doesn't exist.
# Compiles .c files into .o files, including the necessary header directories.
# $< is the first prerequisite (the source file), and $@ is the target (the object file).
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean up object files and libft.a
clean:
	@rm -rf $(OBJ_DIR)

# Same as clean but also removes test
fclean: clean
	@rm -f $(NAME)
	@rm -rf ./$(NAME_TEST)
	@echo "$(YELLOW)[FCLEAN] Removed all generated files   ᕙ(  •̀ ᗜ •́  )ᕗ$(RESET)"

# Rebuild everything from scratch
re: fclean all

# **************************************************************************** #
#                                     TEST                                     #
# **************************************************************************** #

# Test program name
NAME_TEST = test

# Rule to compile and run the test program from main.c
test: $(NAME)
	@echo "$(MAGENTA)[TEST] Generating test!  ♪♪ ヽ(ˇ∀ˇ )ゞ $(RESET)"
	@$(CC) $(CFLAGS) main.c $(NAME) -I$(INC_DIR) -g -o $(NAME_TEST)
	@./$(NAME_TEST)

# Declare phony targets to avoid conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re test