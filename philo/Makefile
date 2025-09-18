#------------------------------------------------#
#					STRUCTURE					 #
#------------------------------------------------#
# minishell
# ├── Makefile
# ├── minishell
# ├── src/
# |	  ├── main.c
# │   ├── module1/
# │   └── module2/
# ├── .build/
# │	  ├── main.o
# │	  └── main.d
# ├── include/
# │   ├── philo.h
# │   └── module1/
# └── lib/
#     └── libft/
#	      ├── libft.a
#	      ├── src/
#	      └── include/
#	          └── libft.h

vpath %.c src
vpath %.i include

-include mk_files/philo.mk
#------------------------------------------------#
#					NOTES						 #
#------------------------------------------------#
# run				:	make run ARGS="arg1 arg2"
# run with valgrind :	make valgrind ARGS="arg1 arg2"

#------------------------------------------------#
#					FILES						 #
#------------------------------------------------#
NAME		= philo
INCLUDES	= $(PHILO_INC)
SRC_FILES	= $(PHILO_SRC)

#------------------------------------------------#
#					DIRECTORY					 #
#------------------------------------------------#
OBJ_DIR		= .build/
INC_DIR		= include/

#------------------------------------------------#
#					PATHS						 #
#------------------------------------------------#
SRC			= $(addsuffix .c, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEP 		= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INC			= $(addprefix $(INC_DIR), $(INCLUDES))

#------------------------------------------------#
#					COMMANDS					 #
#------------------------------------------------#
CC			= gcc
RM			= rm -rf

#------------------------------------------------#
#					FLAGS						 #
#------------------------------------------------#
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= -MMD -MP $(IFLAGS)
IFLAGS		= -Iinclude 
MAKEFLAGS	+= --no-print-directory

#------------------------------------------------#
#					RULES						 #
#------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	@echo "\n$(MAGENTA)$(BOLD)💻 Compiling executable...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(BOLD)\n✅ Compilation successful!$(RESET)"
	@echo "$(CYAN)    └─ Ready to run: ./$(NAME)\n$(RESET)"

$(OBJ_DIR)%.o: %.c $(INC) Makefile | $(OBJ_DIR)
	@echo "  → Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

-include $(DEP)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(MAGENTA)$(BOLD)🧹 Cleaning up project files...$(RESET)"
	@echo "$(CYAN)    ├─ Removed object files, and dependencies$(RESET)"
	@echo "$(CYAN)    └─ Cleaned build directory: $(OBJ_DIR)$(RESET)"

fclean: clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)$(BOLD)\n🗑️  Full clean-up completed:$(RESET)"
	@echo "$(CYAN)    └─ Executable removed: ./$(NAME)\n$(RESET)"

re: fclean all

fclean-all: fclean

clean-all: clean

run: all
	@echo "$(BOLD)🚀 Running:$(RESET) ./$(NAME) $(ARGS)"
	@./$(NAME) $(ARGS)

.PHONY: all clean fclean re run

#------------------------------------------------#
#					COLORS						 #
#------------------------------------------------#
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[0;34m
CYAN	= \033[0;36m
MAGENTA	= \033[0;35m
WHITE	= \033[1;37m
BOLD    = \033[1m
RESET   = \033[0m


