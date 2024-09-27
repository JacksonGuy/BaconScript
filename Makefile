cc = g++

CFLAGS = -g

BUILD_DIR = bin

SOURCES = $(wildcard src/*.cpp src/**/*.cpp)
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

EXE = bsc.exe

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(cc) $(CFLAGS) -c -o $@ $<

all: $(OBJS)
	$(cc) -o $(EXE) $^ $(CLFAGS)

clean:
	rm -rf ./bin
	rm *.exe