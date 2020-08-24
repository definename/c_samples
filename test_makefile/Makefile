APP_NAME := test_app
APP_OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

.PHONY: all clean

all: $(APP_NAME)

$(APP_NAME): $(APP_OBJ)
	$(info target:$@ is being built)
	$(CC) -o $@ $^

$(APP_OBJ): %.o : %.c
	$(info object files:$(APP_OBJ) are being generated)
	$(CC) -c -o $@ $^

clean:
	$(RM) $(APP_OBJ) $(APP_NAME)


