APP_NAME := c_macro_app
APP_SRC := $(wildcard *.c)
APP_OBJ := $(APP_SRC:%.c=%.o)

.PHONY: all clean

all: $(APP_NAME)

ifeq ($(origin CFLAGS), undefined)
 CFLAGS := -Og -g -ggdb
endif

$(APP_NAME): $(APP_OBJ)
	$(CC) -o $@ $^

$(APP_OBJ): $(APP_SRC)
	$(CC) -c $^ $(CFLAGS)

clean:
	$(RM) $(APP_OBJ) $(APP_NAME)
