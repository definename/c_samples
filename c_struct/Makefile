TEST_TARGET := c_struct
TEST_APP_NAME := $(TEST_TARGET)_app
TEST_APP_OBJ := main.o test_struct_compound_literal.o

CFLAGS :=
CFLAGS += -g
CFLAGS += -I./..

PHONY :=

PHONY += all
all: $(TEST_APP_NAME)

$(TEST_APP_NAME): $(TEST_APP_OBJ)
	$(CC) -o $@  $(TEST_APP_OBJ)

PHONY += clean
clean:
	rm -vf $(TEST_APP_OBJ) $(TEST_APP_NAME)

.PHONY: $(PHONY)