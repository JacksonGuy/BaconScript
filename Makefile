cc = gcc

CFLAGS = -g

BUILD_DIR = bin

SOURCES = $(wildcard src/*.c src/**/*.c)
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SOURCES))

EXE = bsc.exe

$(BUILD_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(cc) $(CFLAGS) -c -o $@ $<

all: $(OBJS)
	$(cc) -o $(EXE) $^ $(CLFAGS)

clean:
	rm -rf ./bin
	rm *.exe