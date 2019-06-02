COMP := g++
CFLAGS := -Iinclude -MD
LDFLAGS := 
SRC := $(wildcard src/*.cc)
OBJ := $(addprefix bin/, $(notdir $(SRC:%.cc=%.o)))
HDR := $(wildcard include/*.h)
FILENAME := bin/out

bin/%.o: src/%.cc
	$(COMP) -o$@ -c $< $(CFLAGS)
	
all: $(OBJ)
	$(COMP) -O3 $^ $(LDFLAGS) -o $(FILENAME)

debug: $(OBJ)
	$(COMP) -g $^ $(LDFLAGS) -o $(FILENAME)

-include $(OBJ:.o=.d)

.PHONY: clean

clean:
	rm -r bin/*.o
