default: build

build:
	@gcc src/*.c -Isrc -o main.exe $(shell pkg-config json-c gtk+-3.0 --libs --cflags)

run: build
	@./main.exe testfile.txt