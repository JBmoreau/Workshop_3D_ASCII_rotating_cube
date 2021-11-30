##
## EPITECH PROJECT, 2021
## Workshop 3D ASCII Rotating cube
## File description:
## Makefile
##

BLUE		=	/bin/echo -e "\x1b[34;01m$1\x1b[0m"
BEGIN_GREEN	= 	/bin/echo -e "\x1b[32;01m"
END_COLOR	=	/bin/echo -e "\x1b[0m"

CC			= 	gcc
CFLAGS		= 	-W -Wall -Werror -Wextra
MATH		=	-lm

DEBUG		=	-g3
SEG			=	-g3 -fsanitize=address

SRC 		=	main.c \
				math.c

OBJ 		= 	main.o \
				math.o

TARGET		= 	cube \

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(MATH)
	@$(call BLUE,"Build OK")

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)

clean :
	@rm -rf $(OBJ)
	@$(call BLUE,"Clean OK")

fclean :
	@rm -rf $(OBJ)
	@rm -rf $(TARGET)
	@$(call BLUE,"Fclean OK")

re : fclean all

g3 :
	@$(CC) $(DEBUG) $(CFLAGS) -c $(SRC)
	@$(CC) $(DEBUG) $(CFLAGS) -o $(TARGET) $(OBJ) $(MATH)
	@$(call BLUE,"Build -g3 OK")

seg :
	@$(CC) $(SEG) $(CFLAGS) -c $(SRC)
	@$(CC) $(SEG) $(CFLAGS) -o $(TARGET) $(OBJ) $(MATH)
	@$(call BLUE,"Build seg OK")

my : re
	@$(call BEGIN_GREEN)
	@./$(TARGET)
	@$(call END_COLOR)
