# Project name
NAME		= push_swap
CHECKER = checker

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
DEPFLAGS	= -MMD -MP
# I keep -g3 for debugging with LLDB 

# Directories
SRC_DIR		= src
INC_DIR		= includes
LIBFT_DIR	= lib/libft
PRINTF_DIR	= lib/ft_printf
DEP_DIR = .deps

# Source files
PS_DIR		= $(SRC_DIR)/push_swap
STACK_DIR	= $(SRC_DIR)/stack
CHECKER_DIR = $(SRC_DIR)/checker

# Push swap source files 
PS_SRCS		= $(PS_DIR)/UwU.c \
			  $(PS_DIR)/chunk_sort.c \
			  $(PS_DIR)/chunk_split.c \
			  $(PS_DIR)/chunk_utils.c \
			  $(PS_DIR)/move.c \
			  $(PS_DIR)/optimize_sort_three.c \
			  $(PS_DIR)/sort.c \
				$(PS_DIR)/optimize_post_sort.c \
			  $(PS_DIR)/optimize_post_sort_utils.c \
				$(PS_DIR)/optimize_easy_sort.c \
			  $(PS_DIR)/optimize_sort_asap.c \
			  $(PS_DIR)/optimize_to_the_top.c

# Stack source files
STACK_SRCS	= $(STACK_DIR)/data_management.c \
			  $(STACK_DIR)/operations_utils.c \
			  $(STACK_DIR)/opr_push.c \
			  $(STACK_DIR)/opr_reverse_rotate.c \
			  $(STACK_DIR)/opr_rotate.c \
			  $(STACK_DIR)/opr_swap.c \
			  $(STACK_DIR)/stack_initialization.c \
			  $(STACK_DIR)/stack_utils.c

# Checker source files 
CHECKER_SRCS = $(CHECKER_DIR)/checker_bonus.c \
			   $(CHECKER_DIR)/checker_utils_bonus.c

SRCS		= $(PS_SRCS) $(STACK_SRCS)
BONUS_SRCS	= $(STACK_SRCS) $(CHECKER_SRCS)

#Object files
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

# Dependency files
DEPS		= $(SRCS:%.c=$(DEP_DIR)/%.d)
BONUS_DEPS	= $(BONUS_SRCS:%.c=$(DEP_DIR)/%.d)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a
LIBS		= $(LIBFT) $(PRINTF)

# Include paths
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Library flags
LDFLAGS		= -L$(LIBFT_DIR) -L$(PRINTF_DIR)
LDLIBS		= -lft -lftprintf

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
RESET		= \033[0m

# ----------------------------- RULES ---------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

bonus: $(CHECKER) $(NAME)

$(CHECKER): $(BONUS_OBJS) $(LIBS)
	@echo "$(BLUE)Linking $(CHECKER)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) $(LDLIBS) -o $(CHECKER)
	@echo "$(GREEN)$(CHECKER) compiled successfully!$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(BLUE)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR)

# Create dependency directory
$(DEP_DIR):
	@mkdir -p $(DEP_DIR)/$(PS_DIR) $(DEP_DIR)/$(STACK_DIR) $(DEP_DIR)/$(CHECKER_DIR)

# Compile with dependency generation
%.o: %.c | $(DEP_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@mkdir -p $(DEP_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
	@mv $*.d $(DEP_DIR)/$*.d

# Include dependency files
-include $(DEPS)
-include $(BONUS_DEPS)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -rf $(DEP_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME) and $(CHECKER)...$(RESET)"
	@rm -f $(NAME) $(CHECKER)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
