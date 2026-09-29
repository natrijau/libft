# ╔═══════════════════════════════════════════════════════════════════════════╗
# ║                                                                           ║
# ║                          LIBFT MAKEFILE                                   ║
# ║                                                                           ║
# ║  A complete C library with memory manipulation, string processing,        ║
# ║  conversion and tokenization functions.                                   ║
# ║                                                                           ║
# ║  By: natrijau                                                             ║
# ║  Created: 2026/09/29                                                      ║
# ║                                                                           ║
# ╚═══════════════════════════════════════════════════════════════════════════╝

# ═════════════════════════════════════════════════════════════════════════════
#                            COLORS & FORMATTING
# ═════════════════════════════════════════════════════════════════════════════

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
BOLD		= \033[1m
DIM			= \033[2m
RESET		= \033[0m

# ═════════════════════════════════════════════════════════════════════════════
#                           CONFIGURATION
# ═════════════════════════════════════════════════════════════════════════════

NAME		= libft.a
HEADER		= libft.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I.
AR			= ar
ARFLAGS		= rcs
RM			= rm -f
MKDIR		= mkdir -p

# ═════════════════════════════════════════════════════════════════════════════
#                        DIRECTORIES STRUCTURE
# ═════════════════════════════════════════════════════════════════════════════

SRC_DIR		= src
OBJ_DIR		= obj

SUBDIRS		= memory character string convert split output

SRC_SUBDIRS	= $(addprefix $(SRC_DIR)/,$(SUBDIRS))
OBJ_SUBDIRS	= $(addprefix $(OBJ_DIR)/,$(SUBDIRS))

# ═════════════════════════════════════════════════════════════════════════════
#                        SOURCE FILES ORGANIZATION
# ═════════════════════════════════════════════════════════════════════════════

# Memory management functions (allocation, deallocation, copy, etc.)
SRC_MEMORY		=	ft_bzero.c \
					ft_memchr.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_calloc.c \
					ft_memcmp.c

# Character classification and conversion (isalpha, tolower, etc.)
SRC_CHAR		=	ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_tolower.c \
					ft_toupper.c

# String manipulation (strlen, strchr, strjoin, etc.)
SRC_STRING		=	ft_strlen.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strncmp.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strnstr.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strmapi.c \
					ft_striteri.c

# Type conversion (atoi, itoa)
SRC_CONVERT		=	ft_atoi.c \
					ft_itoa.c \
					ft_count_digits.c \
					ft_check_int_overflow.c

# String splitting and tokenization (generic, reusable)
SRC_SPLIT		=	ft_split.c \
					ft_alloc_str_array.c \
					ft_extract_tokens.c \
					ft_free_str_array.c \
					ft_count_tokens.c \
					ft_token_len.c \
					ft_is_separator.c

# Output functions (file descriptor based)
SRC_OUTPUT		=	ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c

# ═════════════════════════════════════════════════════════════════════════════
#                        SOURCES WITH PATHS
# ═════════════════════════════════════════════════════════════════════════════

SOURCES_FULL	=	$(addprefix $(SRC_DIR)/memory/,$(SRC_MEMORY)) \
					$(addprefix $(SRC_DIR)/character/,$(SRC_CHAR)) \
					$(addprefix $(SRC_DIR)/string/,$(SRC_STRING)) \
					$(addprefix $(SRC_DIR)/convert/,$(SRC_CONVERT)) \
					$(addprefix $(SRC_DIR)/split/,$(SRC_SPLIT)) \
					$(addprefix $(SRC_DIR)/output/,$(SRC_OUTPUT))

OBJECTS_FULL	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES_FULL))

# ═════════════════════════════════════════════════════════════════════════════
#                              BUILD RULES
# ═════════════════════════════════════════════════════════════════════════════

.PHONY: all clean fclean re help directories

# Default target
all: header directories $(NAME) footer

# Create necessary directories
directories:
	@$(MKDIR) $(OBJ_SUBDIRS)

# Build the static library
$(NAME): $(OBJECTS_FULL)
	@echo "$(BOLD)$(MAGENTA)[Linking]$(RESET) $(CYAN)$(NAME)$(RESET)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS_FULL)
	@echo "$(GREEN)[OK] Library created successfully$(RESET)"

# Compile each .c file into .o object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@echo "$(YELLOW)[Compiling]$(RESET) $(CYAN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	@echo "$(BOLD)$(RED)[Cleaning]$(RESET) Object files..."
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)[OK] Object files removed$(RESET)"

# Remove everything (objects + library)
fclean: clean
	@echo "$(BOLD)$(RED)[Deep Cleaning]$(RESET) Library and objects..."
	@$(RM) $(NAME)
	@echo "$(GREEN)[OK] Library removed$(RESET)"

# Rebuild everything from scratch
re: fclean all

# Display help
help:
	@echo ""
	@echo "$(BOLD)$(CYAN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║              LIBFT BUILD SYSTEM - HELP                     ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(BOLD)Available targets:$(RESET)"
	@echo "  $(GREEN)make$(RESET)          Build the library (default target)"
	@echo "  $(GREEN)make all$(RESET)      Same as 'make'"
	@echo "  $(GREEN)make clean$(RESET)    Remove object files (.o)"
	@echo "  $(GREEN)make fclean$(RESET)   Remove object files and library"
	@echo "  $(GREEN)make re$(RESET)       Rebuild everything from scratch"
	@echo "  $(GREEN)make help$(RESET)     Display this help message"
	@echo ""
	@echo "$(BOLD)Project Structure:$(RESET)"
	@echo "  $(MAGENTA)Memory functions$(RESET)          : 7 functions"
	@echo "  $(MAGENTA)Character functions$(RESET)       : 7 functions"
	@echo "  $(MAGENTA)String functions$(RESET)         : 13 functions"
	@echo "  $(MAGENTA)Conversion functions$(RESET)      : 2 functions"
	@echo "  $(MAGENTA)Tokenization functions$(RESET)    : 7 functions"
	@echo "  $(MAGENTA)Output functions$(RESET)         : 4 functions"
	@echo "  $(DIM)────────────────────────────$(RESET)"
	@echo "  $(BOLD)Total: 40 functions$(RESET)"
	@echo ""
	@echo "$(BOLD)Directory Layout:$(RESET)"
	@echo "  $(CYAN)src/$(RESET)               Source files organized by category"
	@echo "  $(CYAN)obj/$(RESET)               Compiled object files (generated)"
	@echo "  $(CYAN)libft.a$(RESET)            Final static library"
	@echo ""
	@echo "$(BOLD)Compilation flags:$(RESET)"
	@echo "  $(CYAN)$(CFLAGS)$(RESET)"
	@echo ""

# Display header during build
header:
	@echo ""
	@echo "$(BOLD)$(CYAN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║                   Building LIBFT                           ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""

# Display footer after successful build
footer:
	@echo ""
	@echo "$(BOLD)$(GREEN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(GREEN)║            BUILD COMPLETE - ALL READY!                     ║$(RESET)"
	@echo "$(BOLD)$(GREEN)╚════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""