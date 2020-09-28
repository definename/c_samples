GDBUS_SERVICE_NAME := gdbus_service_app
GDBUS_SERVICE_SRC := $(wildcard *_service.c)
GDBUS_SERVICE_OBJ := $(GDBUS_SERVICE_SRC:%.c=%.o)

GDBUS_CLIENT_NAME := gdbus_client_app
GDBUS_CLIENT_SRC := $(wildcard *_client.c)
GDBUS_CLIENT_OBJ := $(GDBUS_CLIENT_SRC:%.c=%.o)

APP_LIBLIST := glib-2.0 gio-2.0
APP_CFLAGS := $(shell pkg-config --cflags $(APP_LIBLIST))
APP_LDLIBS := $(shell pkg-config --libs $(APP_LIBLIST))

CFLAGS += $(APP_CFLAGS)
LDLIBS += $(APP_LDLIBS)

.PHONY: all clean gen

all: $(GDBUS_SERVICE_NAME) $(GDBUS_CLIENT_NAME)

# gdbus service
$(GDBUS_SERVICE_NAME): $(GDBUS_SERVICE_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(GDBUS_SERVICE_OBJ): $(GDBUS_SERVICE_SRC)
	$(CC) -c $^ $(CFLAGS)

# gdbus client
$(GDBUS_CLIENT_NAME): $(GDBUS_CLIENT_OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

$(GDBUS_CLIENT_OBJ): $(GDBUS_CLIENT_SRC)
	$(CC) -c $^ $(CFLAGS)

gen:
	gdbus-codegen --generate-c-code minminbus \
				  --c-namespace MinMinBus \
				  --interface-prefix com.fatminmin. \
				  com.fatminmin.gdbus.xml \

clean:
	$(RM) $(GDBUS_SERVICE_OBJ) $(GDBUS_SERVICE_NAME)
	$(RM) $(GDBUS_CLIENT_OBJ) $(GDBUS_CLIENT_NAME)
	$(RM) minminbus.c minminbus.h
