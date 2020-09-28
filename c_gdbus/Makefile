# The following package should be installed
# sudo apt install libglib2.0-dev

GDBUS_SERVICE_NAME := gdbus_service_app
GDBUS_SERVICE_SRC := $(wildcard *_service.c)
GDBUS_SERVICE_OBJ := $(GDBUS_SERVICE_SRC:%.c=%.o)

GDBUS_CLIENT_NAME := gdbus_client_app
GDBUS_CLIENT_SRC := $(wildcard *_client.c)
GDBUS_CLIENT_OBJ := $(GDBUS_CLIENT_SRC:%.c=%.o)

CODEGEN_NAME := mygenerated
CODEGEN_SRC := $(CODEGEN_NAME).c
CODEGEN_OBJ := $(CODEGEN_NAME).o
CODEGEN_HEADER := $(CODEGEN_NAME).h
CODEGEN_NAMESPACE := MYNAMESPACE
CODEGEN_PREFIX := com.my.gdbus.

APP_LIBLIST := glib-2.0 gio-2.0 gio-unix-2.0
APP_CFLAGS := $(shell pkg-config --cflags $(APP_LIBLIST))
APP_LDLIBS := $(shell pkg-config --libs $(APP_LIBLIST))

CFLAGS += $(APP_CFLAGS)
LDLIBS += $(APP_LDLIBS)

.PHONY: all clean codegen

all: codegen $(GDBUS_SERVICE_NAME) $(GDBUS_CLIENT_NAME)

# gdbus service
$(GDBUS_SERVICE_NAME): $(GDBUS_SERVICE_OBJ) $(CODEGEN_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(GDBUS_SERVICE_OBJ): $(GDBUS_SERVICE_SRC)
	$(CC) -c $^ $(CFLAGS)

# gdbus client
$(GDBUS_CLIENT_NAME): $(GDBUS_CLIENT_OBJ) $(CODEGEN_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(GDBUS_CLIENT_OBJ): $(GDBUS_CLIENT_SRC)
	$(CC) -c $^ $(CFLAGS)

# gdbus generate
$(CODEGEN_OBJ): $(CODEGEN_SRC)
	$(CC) -c $^ $(CFLAGS)

codegen:
	gdbus-codegen --generate-c-code $(CODEGEN_NAME) \
				  --c-namespace $(CODEGEN_NAMESPACE) \
				  --interface-prefix $(CODEGEN_PREFIX) \
				  com.my.gdbus.xml \

clean:
	$(RM) $(GDBUS_SERVICE_OBJ) $(GDBUS_SERVICE_NAME)
	$(RM) $(GDBUS_CLIENT_OBJ) $(GDBUS_CLIENT_NAME)
	$(RM) $(CODEGEN_SRC) $(CODEGEN_OBJ) $(CODEGEN_HEADER)
