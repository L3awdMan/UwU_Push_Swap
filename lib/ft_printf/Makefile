# Rules 
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -gdwarf-3
AR      = ar rcs
NAME    = libftprintf.a

# Paths for test and source dir 
SRC_DIR			= .
MAIN_PATH   = /home/zotaj-di/Documents/ft_printf/main.c

# Source files
SRCS    = ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c \
          ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c
OBJS    = $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))

# Colors
GREEN   = \033[0;32m
RED     = \033[0;31m
CYAN    = \033[0;36m
BLUE    = \033[0;34m
NC      = \033[0m

# Main rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[SUCCESS](ദ്ദി˙ᗜ˙)$(NC) $(BLUE)$(NAME)$(NC) created successfully!"

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[CC] ▄︻デ══━一💥$(NC) $<"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)[CLEAN] 🧹🪣$(NC) ∘˙○˚.• Object files removed "

fclean: clean
	@rm -f $(NAME) printf_test
	@echo "$(RED)[FCLEAN] 🧹🪣$(NC) ∘˙○˚.• $(BLUE)$(NAME)$(NC) and test executable removed"

re: fclean all

# Compile the test main.c with the animation at the bigining 
test: re
	@clear
	@echo "$(CYAN)"
	@echo "██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗    ████████╗███████╗███████╗████████╗███████╗██████╗"
	@echo "██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗"
	@echo "██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗         ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝"
	@echo "██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝         ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗"
	@echo "██║     ██║  ██║██║██║ ╚████║   ██║   ██║            ██║   ███████╗███████║   ██║   ███████╗██║  ██║"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝            ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝"
	@echo "$(NC)"
	@sleep 1
	@echo "$(RED)Let's destroy this project together 💣...$(NC)"
	@sleep 1
	@echo "$(BLUE)Made by L3awd 🐴$(NC)"
	@sleep 2
	@bash -c '\
	frames=( \
	"          ( ◡̀_◡́)    " \
	"          ( ◡̀_◡́)▬   " \
	"          ( ◡̀_◡́)▬▬  " \
	"          ( ◡̀_◡́)▬▬█ " \
	"          ( ◡̀_◡́)▬▬💥" \
	); \
	for f in "$${frames[@]}"; do \
		clear; echo "$$f"; sleep 0.2; \
	done;'

	@$(CC) $(CFLAGS) $(MAIN_PATH) -L. -lftprintf -o printf_test
	@echo "$(CYAN)[TEST]$(NC) Running tests 🛠️"
	@sleep 1
	@echo "\n";
	@./printf_test

	@echo "$(RED)Finishing move...💀$(NC)"
	@bash -c '\
	frames=( \
	"          ( ◡̀_◡́)    " \
	"          ( ◡̀_◡́)▬   " \
	"          ( ◡̀_◡́)▬▬  " \
	"          ( ◡̀_◡́)▬▬█ " \
	"          ( ◡̀_◡́)▬▬💥" \
	"        (๑•̀ㅂ•́)ง🔥🔥 ✨ 🏆" \
	); \
	for f in "$${frames[@]}"; do \
		clear; echo "$$f"; sleep 0.2; \
	done;'
	@sleep 2
	@echo "$(GREEN)[TEST PASSED] ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧ $(NC) All tests completed successfully ــــــــــــــــﮩ٨ـ❤️️"


.PHONY: all clean fclean re test
