# ================================== #
#  			   LIBFT MAKEFILE 		       #
# ================================== #

# Color Definitions
GREEN	= \033[0;32m
RED		= \033[0;31m
BLUE	= \033[0;34m
RESET	= \033[0m
BOLD	= \033[1m

# Compiler Configuration
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
LIBC	= ar rcs
RM		= rm -f

# Library Name
NAME	= libft.a

# Source Files
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
		  ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		  ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Bonus Files
SRCSB = ft_lstnew.c ft_lstdelone.c ft_lstclear.c \
				ft_lstlast.c ft_lstadd_back.c  ft_lstadd_front.c \
				ft_lstiter.c
BONUS_OBJS = $(SRCSB:.c=.o)

# Object Files
OBJS	= $(SRCS:.c=.o)

# ================================== #
#						 BUILD RULES             #
# ================================== #

# Main rule - builds the library
all: $(NAME)
	@echo "$(GREEN)$(BOLD)✔ libft compiled successfully!$(RESET)"

# Library compilation
$(NAME): $(OBJS)
	@echo "$(BLUE)$(BOLD)🛠  Building $(NAME)...$(RESET)"
	@$(LIBC) $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)✔ Library created: $(NAME)$(RESET)"

# Bonus rule 
bonus: $(BONUS_OBJS)
	@echo "$(BLUE)$(BOLD)🛠  Building bonus objects...$(RESET)"
	@$(LIBC) $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)$(BOLD)✔ Bonus added to $(NAME)$(RESET)"

# Pattern rule for .c to .o compilation
%.o: %.c
	@echo "$(BLUE)🔧 Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(BONUS_OBJS)

# Full clean (objects + library)
fclean: clean
	@echo "$(RED)🧹 Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

# Rebuild
re: fclean all

# Phony targets (targets that aren't files)
.PHONY: all bonus clean fclean re
