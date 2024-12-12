SRCS_DIR = ./srcs/

SRC = al_map_convert.c al_map_optimize.c al_map_solver.c al_print_map.c ft_assign_map.c ft_check_argnum.c ft_map_check.c ft_read_file.c ft_split.c ft_string.c main.c ft_assign_row_col.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

SRCS_OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./includes/

CC = cc

CFLAGS = -Wall -Wextra -Werror

OUTPUT = bsq

all : $(OUTPUT)

.c.o:
	${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

$(OUTPUT) : $(SRCS_OBJ)
	${CC} ${CFLAGS} -o ${OUTPUT} ${SRCS_OBJ}

clean :
	rm -f $(SRCS_OBJ)

fclean : clean
	rm -f $(OUTPUT)

re : fclean all

.PHONY : all clean fclean re
