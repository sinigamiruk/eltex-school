#Build/Rebuild: make build
#Compile: make all
#Run: make test

CC = gcc
CFLAGS = -std=c99
SRC = $(SERV).c $(CLNT).c
OBJ = $(SRC:.c=.o)
SERV = server
CLNT = client

.PHONY: all clean build test

all: $(CLNT) $(SERV)

build: clean all

%.o: %.c
	$(CC) $(CFLAGS) -c $^

$(SERV): $(SERV).o
	$(CC) $^ -o $@
$(CLNT): $(CLNT).o
	$(CC) $^ -o $@

clean:
	rm -rf *.o $(SERV) $(CLNT)

test: $(CLNT) $(SERV)
	@echo "* Clients must be running in other terminals *\n"
	./$(SERV)