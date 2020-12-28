NAME = libmx.a

TMP_DIR = ./obj

OBJ = ./*.o
TMP_OBJ = ./obj/*.o

SRC = ./src/*.c
TMP_SRC = ./obj/*.c

INC = ./inc/*.h
TMP_INC = ./obj/*.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@mkdir $(TMP_DIR)
	@cp $(SRC) $(TMP_DIR)
	@cp $(INC) $(TMP_DIR)
	@clang $(CFLAGS) -c $(TMP_SRC) -I $(TMP_INC)
	@mv $(OBJ) $(TMP_DIR)
	@ar -rc $(NAME) $(TMP_OBJ)

uninstall: clean
	@rm $(NAME)

clean:
	@rm -rf $(TMP_DIR)

reinstall: uninstall all
