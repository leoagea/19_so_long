# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagea <lagea@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 01:08:23 by lagea             #+#    #+#              #
#    Updated: 2024/05/31 15:54:14 by lagea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME		= so_long
BONUS		= so_long_bonus

SRC_DIR		= src/
BONUS_DIR	= bonus/
OBJ_DIR		= obj/
OBJB_DIR	= obj_bonus/
INC_DIR		= inc/
#EXIT_DIR	= src/exit/
#PARSER_DIR	= src/parser/
#RENDER_DIR	= src/render

#EXIT		= $(wildcard $(EXIT_DIR)*.c)
#MAP			= $(wildcard $(PARSER_DIR)*.c)  
#RENDER		= $(wildcard $(RENDER_DIR)*.c)
SRC 		= $(wildcard $(SRC_DIR)*.c)  #$(MAP) $(EXIT) $(RENDER)
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
SRCB		= bonus/main_bonus.c bonus/anim_bonus.c bonus/render_bonus.c bonus/check_bonus.c \
			 bonus/events_bonus.c bonus/exit_bonus.c  bonus/map_bonus.c  bonus/xpm_bonus.c
OBJB		= $(SRCB:$(BONUS_DIR)%.c=$(OBJB_DIR)%.o)

LIBFT 		= lib/libft.a
LIBFT_PATH 	= libft/

CC			= gcc
RM			= rm -f
C_FLAGS		= -Wall -Wextra -Werror
INCS 		= -I$(INC_DIR) -I.
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_push_swap
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling Push Swap... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCS) -Imlx -c $< -g -o $@
	$(call progress_bar_push_swap)

$(OBJB_DIR)%.o: $(BONUS_DIR)%.c
	mkdir -p $(OBJB_DIR)
	$(CC) $(C_FLAGS) $(INCS) -Imlx -c $< -g -o $@
	$(call progress_bar_push_swap)

all: $(LIBFT) $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) -Llib/ -lft $(MLX) -g -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

$(BONUS):$(LIBFT) $(OBJB)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	$(CC) $(OBJB) -Llib/ -lft $(MLX) -g -o $(BONUS)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"
	
$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(NC)"
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "$(ORANGE)Cleaning objects for Libft...$(NC)"
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(GREEN)Cleaned objects Libft!$(NC)"
	@echo "$(ORANGE)Cleaning objects for Push Swap...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@$(RM) $(OBJB_DIR)*.o
	@echo "$(GREEN)Cleaned Push Swap objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Libft...$(NC)"
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
	@echo "$(BLUE)Fully cleaned Libft!$(NC)"
	@echo "$(ORANGE)Fully cleaning library for Push Swap...$(NC)"
	@$(RM) $(NAME) $(BONUS)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)
	@echo "$(BLUE)Fully cleaned Push Swap!$(NC)"

re: fclean all

.PHONY: all clean fclean re