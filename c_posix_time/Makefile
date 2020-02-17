.RECIPEPREFIX = >
TEST_TARGET := c_posix_time
TEST_APP_NAME := $(TEST_TARGET)_app
TEST_APP_OBJ := main.o

CFLAGS :=
CFLAGS += -g
CFLAGS += -I./..

LIBS :=
LIBS += -lm

PHONY :=
PHONY += all
all: $(TEST_APP_NAME)

$(TEST_APP_NAME): $(TEST_APP_OBJ)
>$(CC) -o $@  $(TEST_APP_OBJ) $(LIBS)

PHONY += clean
clean:
>rm -vf $(TEST_APP_OBJ) $(TEST_APP_NAME)

.PHONY: $(PHONY)