.PHONY = all clean fclean re
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_isspace \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_printf_utils \
		ft_printf \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_base \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strreplace \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_lstadd \
		ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstget \
		ft_lstgetid \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstpop \
		ft_lstpush \
		ft_lstrevrotate \
		ft_lstrotate \
		ft_lstsize \
		ft_lstswap \
		ft_itoa_base_un \
		ft_itoa_base \
		ft_itoa_un \
		ft_exallocf \
		ft_get_next_line \
		ft_memncat \
		ft_memsuperclear \
		ft_memtostr \
		ft_nblowest \
		ft_nbabsolute \
		garbage_collector \

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

NAME = betterft.a

all: $(NAME)

%.o: %.c
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(OFILES)
	@printf "\t🤖 Compiling $(NAME)...\r"
	@ar -rc $(NAME) $(OFILES)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is compiled ✅"
	@echo "\t\033[0;33m[WARN]\t[$(NAME)]\tThis version of BETTERFT has been modified to help with specific tasks for pipex.\033[0m"

clean:
	@rm -f $(OFILES)
	@echo "\t[INFO]\t[$(NAME)]\t$(words $(OFILES)) object files deleted 🗑️"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean all
