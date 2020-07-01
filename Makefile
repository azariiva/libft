# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:07 by blinnea           #+#    #+#              #
#    Updated: 2020/07/01 20:16:12 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
GREENB = \033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #
CC = gcc
CF = -Wall -Wextra -Werror -ggdb

NAME = libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
FT_H =		include/$(NAME).h
LST_H =		include/$(NAME)_list.h
STR_H =		include/$(NAME)_string.h
CTP_H =		include/$(NAME)_ctype.h
IO_H =		include/$(NAME)_io.h
QUE_H =		include/$(NAME)_queue.h
MEM_H =		include/$(NAME)_memory.h
INT_H =		include/$(NAME)_integer.h

# **************************************************************************** #
#                           TEMPORARY DIRECTORIES                              #
# **************************************************************************** #
LSTDIR =	obj/list
STRDIR =	obj/string
CTPDIR =	obj/ctype
IODIR =		obj/io
QUEDIR =	obj/queue
MEMDIR =	obj/memory
INTDIR =	obj/integer

ALLDIR = $(LSTDIR) $(STRDIR) $(CTPDIR) $(IODIR) $(QUEDIR) $(MEMDIR) $(INTDIR)

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
LSTFILES =	ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
			ft_lstdelone_ic ft_lstdel_ic ft_lstswptop ft_lstpoptop ft_lsttrans \
			ft_lstshftup ft_lstpopbot ft_lstshftdown ft_lstnew_ic ft_lstsize
STRFILES =	ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strlen \
			ft_strdup ft_strcpy ft_strmap ft_strmapi ft_strequ ft_strnequ \
			ft_strsub ft_strjoin ft_strtrim ft_strncpy ft_strcat ft_strncat \
			ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp \
			ft_strncmp ft_strsplit ft_strsplit_plus ft_strchr_plus
CTPFILES =	ft_isalnum ft_isascii ft_isprint ft_islower ft_isupper ft_toupper \
			ft_tolower ft_isblank ft_iscntrl ft_isalpha ft_isgraph ft_isspace \
			ft_ispunct ft_isxdigit ft_isdigit
IOFILES =	ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
			ft_putstr_fd ft_putendl_fd ft_putnbr_fd
QUEFILES =	ft_quenew ft_queadd ft_quepop ft_quedel
MEMFILES =	ft_memset ft_memdel ft_memalloc ft_bzero ft_memcpy ft_memccpy \
			ft_memcmp ft_memmove ft_memchr
INTFILES =	ft_atoi ft_itoa ft_abs ft_labs ft_llabs

LSTOFILES =	$(patsubst %, $(LSTDIR)/%.o, $(LSTFILES))
STROFILES =	$(patsubst %, $(STRDIR)/%.o, $(STRFILES))
CTPOFILES =	$(patsubst %, $(CTPDIR)/%.o, $(CTPFILES))
IOOFILES =	$(patsubst %, $(IODIR)/%.o, $(IOFILES))
QUEOFILES =	$(patsubst %, $(QUEDIR)/%.o, $(QUEFILES))
MEMOFILES =	$(patsubst %, $(MEMDIR)/%.o, $(MEMFILES))
INTOFILES =	$(patsubst %, $(INTDIR)/%.o, $(INTFILES))

ALLOFILES =	$(LSTOFILES) $(STROFILES) $(CTPOFILES) $(IOOFILES) $(QUEOFILES) \
			$(MEMOFILES) $(INTOFILES)

.PHONY: clean fclean re all

all: dir $(NAME).a

$(NAME).a: $(ALLOFILES)
	@ar rc $@ $(ALLOFILES)
	@ranlib $@
	@echo "\n> $(GREEN)$(NAME) created$(DEFAULT)"

# create temporary directories
dir:
	@mkdir -p obj $(ALLDIR)

# create list object files
obj/list/%.o: src/list/%.c $(FT_H) $(LST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create string object files
obj/string/%.o: src/string/%.c $(CTP_H) $(MEM_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create ctype object files
obj/ctype/%.o: src/ctype/%.c $(CTP_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create io object files
obj/io/%.o: src/io/%.c $(FT_H) $(STR_H) $(IO_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create queue object files
obj/queue/%.o: src/queue/%.c $(MEM_H) $(LST_H) $(QUE_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create memory object files
obj/memory/%.o: src/memory/%.c $(MEM_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create integer object files
obj/integer/%.o: src/integer/%.c $(CTP_H) $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

clean:
	@rm -f $(ALLOFILES)
	@rm -fd $(ALLDIR) obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

fclean: clean
	@rm -f $(NAME).a
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
