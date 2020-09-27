APP_NAME := c_glib_app
APP_SRC := $(wildcard *.c)
APP_OBJ := $(APP_SRC:%.c=%.o)

APP_FLAGS := $(shell pkg-config --cflags glib-2.0)
APP_LDLIBS := $(shell pkg-config --libs glib-2.0)

CFLAGS += $(APP_FLAGS)
LDLIBS += $(APP_LDLIBS)

.PHONY: all clean

all: $(APP_NAME)

$(APP_NAME): $(APP_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(APP_OBJ): $(APP_SRC)
	$(CC) -c $^ $(CFLAGS)

clean:
	$(RM) $(APP_OBJ) $(APP_NAME)
