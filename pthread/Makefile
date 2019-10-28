CWD = $(shell pwd)
TEST_TARGET := pthread
TEST_APP_NAME := $(TEST_TARGET)_app
TEST_APP_OBJ := main.o
TEST_APP_LINK_LIB :=pthread

PHONY :=

PHONY += all
all: $(TEST_APP_NAME)

$(TEST_APP_NAME): $(TEST_APP_OBJ)
	$(CC) -o $@  $(TEST_APP_OBJ) -l$(TEST_APP_LINK_LIB)

PHONY += clean
clean:
	rm -vf $(TEST_APP_OBJ) $(TEST_APP_NAME)

.PHONY: $(PHONY)