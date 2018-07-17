#Build/Rebuild: make build
#Compile: make all
#Run: make test

UDP_PATH = ./udp
TCP_PATH = ./tcp

.PHONY: all clean build test

all:
	make all -C $(UDP_PATH)
	make all -C $(TCP_PATH)

build:
	make build -C $(UDP_PATH)
	make build -C $(TCP_PATH)

clean:
	make clean -C $(UDP_PATH)
	make clean -C $(TCP_PATH)

test:
	make test -C $(UDP_PATH) & make test -C $(TCP_PATH)