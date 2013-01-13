CCWARNINGS=-Wall -Wextra
CCOPTIMIZATION=
CCOTHER=-std=gnu99
LIBS=
PATHS=

EXECUTABLE=battleships

SOURCES=$(shell echo source/*.c)

CC=gcc
CFLAGS=$(CCOTHER) $(CCWARNINGS) $(CCOPTIMIZATION)

OBJECTS=$(SOURCES:.c=.o)

REMOVE=rm -f

all: info compile
	
exec: info compile
	./$(EXECUTABLE)

info:
	@echo "Building: $(EXECUTABLE)"
	@echo "	CC: $(CC)"
	@echo "	CFLAGS: $(CFLAGS)"
	@echo "	LIBS: $(LIBS)"
	@echo ""

compile: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(PATHS) $(LIBS) $(OBJECTS) -o $@


#c.o: %.c  Stichwort: Pattern in Regeln
# Jede o-Datei hänt von der entsprechenden c-Datei ab.
# $< --> die erste Building
# $@ Name des targets

# Suffix-Regeln
.c.o:
	@echo "CC $<"
	@$(CC) $(PATHS) $(CFLAGS) -c $< -o $@


clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(EXECUTABLE)
	
