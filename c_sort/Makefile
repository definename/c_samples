.RECIPEPREFIX = >
CWD = $(shell pwd)
TEST_TARGET := c_sort
TEST_APP_NAME := $(TEST_TARGET)_app
TEST_APP_OBJ := main.o

PHONY :=

PHONY += all
all: $(TEST_APP_NAME)

$(TEST_APP_NAME): $(TEST_APP_OBJ)
>$(CC) -o $@  $(TEST_APP_OBJ)

PHONY += clean
clean:
>rm -vf $(TEST_APP_OBJ) $(TEST_APP_NAME)

.PHONY: $(PHONY)
