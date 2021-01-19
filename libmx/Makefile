NAME = libmx.a

TMP_DIR = ./obj

OBJ = ./*.o
TMP_OBJ = ./obj/*.o

SRC = ./src/*.c
INC = ./inc/*.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@mkdir $(TMP_DIR)
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mv $(OBJ) $(TMP_DIR)
	@ar -rc $(NAME) $(TMP_OBJ)

uninstall: clean
	@rm $(NAME)

clean:
	@rm -rf $(TMP_DIR)

reinstall: uninstall all
