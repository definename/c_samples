APP_NAME := c_pthread_app
APP_SRC := $(wildcard *.c)
APP_OBJ := $(APP_SRC:%.c=%.o)

APP_CFLAGS := 
APP_LDLIBS := -lpthread

CFLAGS += $(APP_CFLAGS)
LDLIBS += $(APP_LDLIBS)

.PHONY: all clean

all: $(APP_NAME)

$(APP_NAME): $(APP_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(APP_OBJ): $(APP_SRC)
	$(CC) -c $^ $(CFLAGS)

clean:
	$(RM) $(APP_OBJ) $(APP_NAME)
