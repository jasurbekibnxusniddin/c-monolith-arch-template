# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Iinclude/external
LDFLAGS = -Llib -lpq

# Source files and target
SRC = src/main.c src/server/server.c src/db/db.c 
OBJ = $(SRC:.c=.o)
TARGET = app

# Directories
INCLUDE_DIR = include/external
LIB_DIR = lib

# Default target
all: $(TARGET)

# Build the application
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Darwin. PostgreSQL 16.1 
DARWIN_LIBPQ_INCLUDE = /opt/homebrew/opt/libpq/include
DARWIN_LIBPQ_LIB = /opt/homebrew/opt/libpq/lib

# Darwin. libmicrohttpd
LIBMICROHTTPD_INCLUDE = /opt/homebrew/include
LIBMICROHTTPD_LIB = /opt/homebrew/lib


# Install libpq headers and libraries into the project for Darwin
lib-install-darwin:
	@echo "Installing libpq headers and libraries..."
	# brew install libpq
	mkdir -p $(INCLUDE_DIR) $(LIB_DIR)
	cp $(DARWIN_LIBPQ_INCLUDE)/libpq-fe.h $(INCLUDE_DIR)
	cp $(DARWIN_LIBPQ_INCLUDE)/postgres_ext.h $(INCLUDE_DIR)
	cp $(DARWIN_LIBPQ_INCLUDE)/pg_config_ext.h $(INCLUDE_DIR)
	cp $(DARWIN_LIBPQ_LIB)/libpq.a $(LIB_DIR)
	cp $(DARWIN_LIBPQ_LIB)/libpq.dylib $(LIB_DIR)
	@echo "libpq installation completed."

	@echo "Installing libmicrohttpd headers and libraries..."
	# brew install libmicrohttpd
	cp $(LIBMICROHTTPD_INCLUDE)/microhttpd.h $(INCLUDE_DIR)
	cp $(LIBMICROHTTPD_LIB)/libmicrohttpd.dylib $(LIB_DIR)
	@echo "libpq and libmicrohttpd installation completed."	

# Linux. PostgreSQL 16.1
LINUX_LIBPQ_INCLUDE = /usr/include/postgresql
LINUX_LIBPQ_LIB = /usr/lib/x86_64-linux-gnu

# Install libpq headers and libraries into the project for Linux
lib-install-linux:
	@echo "Installing libpq headers and libraries..."
	mkdir -p $(INCLUDE_DIR) $(LIB_DIR)
	cp $(LINUX_LIBPQ_INCLUDE)/libpq-fe.h $(INCLUDE_DIR)
	cp $(LINUX_LIBPQ_INCLUDE)/postgres_ext.h $(INCLUDE_DIR)
	cp $(LINUX_LIBPQ_INCLUDE)/pg_config_ext.h $(INCLUDE_DIR)
	cp $(LINUX_LIBPQ_LIB)/libpq.a $(LIB_DIR)
	cp $(LINUX_LIBPQ_LIB)/libpq.so $(LIB_DIR)
	@echo "libpq installation completed."


	
# Rebuild the app
rebuild: clean all

# Test the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean lib-install rebuild run

gbuild:
	gcc -o $(TARGET) \
	src/main.c \
	src/db/postgres.c \
	src/router/router.c \
	src/router/handlers/handlers.c \
	-Iinclude/external -Llib -lpq -lmicrohttpd

cbuild:
	clang -v -o $(TARGET) \
	src/main.c \
	src/db/postgres.c \
	src/router/router.c \
	src/handlers/handlers.c \
	-Iinclude/external -Llib -lpq -lmicrohttpd

gclean:
	rm -f $(OBJ) $(TARGET)
