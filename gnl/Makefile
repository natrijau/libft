# **************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2026/09/30 01:48:00 by natrijau          #+#    #+#             #
#   Updated: 2026/09/30 01:48:00 by natrijau         ###   ########.fr       #
#                                                                            #
# **************************************************************************** #

NAME            := get_next_line.a
BONUS_NAME      := get_next_line_bonus.a
CC              := gcc
CFLAGS          := -Wall -Wextra -Werror
AR              := ar rcs
RM              := rm -rf
GREEN           := \033[0;32m
CYAN            := \033[0;36m
YELLOW          := \033[0;33m
RESET           := \033[0m

SRC_DIR         := src
OBJ_DIR         := obj
CORE_DIR        := $(SRC_DIR)/core
UTILS_DIR       := $(SRC_DIR)/utils

SRC             := $(CORE_DIR)/get_next_line.c \
                   $(UTILS_DIR)/get_next_line_utils.c
BONUS_SRC       := $(CORE_DIR)/get_next_line_bonus.c \
                   $(UTILS_DIR)/get_next_line_utils_bonus.c
OBJ             := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ       := $(BONUS_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: header directories $(NAME) footer

header:
	@printf "$(CYAN)╔══════════════════════════════════════════════════════════════╗$(RESET)\n"
	@printf "$(CYAN)║                     GET_NEXT_LINE                           ║$(RESET)\n"
	@printf "$(CYAN)╚══════════════════════════════════════════════════════════════╝$(RESET)\n"

directories:
	@mkdir -p $(OBJ_DIR)/core $(OBJ_DIR)/utils

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@printf "$(GREEN)[OK] $@ created$(RESET)\n"

$(BONUS_NAME): $(BONUS_OBJ)
	@$(AR) $@ $^
	@printf "$(GREEN)[OK] $@ created$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "$(YELLOW)Compiling %s$(RESET)\n" $<
	@$(CC) $(CFLAGS) -I. -c $< -o $@

bonus: header directories $(BONUS_NAME) footer

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(GREEN)[OK] objects removed$(RESET)\n"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@printf "$(GREEN)[OK] archives removed$(RESET)\n"

re: fclean all

help:
	@printf "Targets: all, bonus, clean, fclean, re, help\n"

footer:
	@printf "$(CYAN)──────────────────────── build complete ───────────────────────$(RESET)\n"

.PHONY: all bonus clean fclean re help directories header footer
