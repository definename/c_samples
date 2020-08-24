APP_NAME := test_app
APP_SRC := $(wildcard *.c)
APP_OBJ := $(patsubst %.c, %.o, $(APP_SRC))

.PHONY: all clean

all: $(APP_NAME)

$(APP_NAME): $(APP_OBJ)
	$(info target:$@ is being built)
	$(CC) -o $@ $^

$(APP_OBJ): $(APP_SRC)
	$(info object files:$(APP_OBJ) are being generated)
	$(CC) -c $^

clean:
	$(RM) $(APP_OBJ) $(APP_NAME)


