BLDDIR = build
SRCDIR = src
INCDIR = inc
BINDIR = bin

COMPLR = gcc
SRCEXT = c
SOURCES = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BLDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -ggdb
TARGET = $(BINDIR)/main

all: init $(TARGET)

init:
	mkdir -p $(BINDIR) $(BLDDIR)

$(TARGET): $(OBJECTS)
	$(COMPLR) $^ -o $@ -lm $(CFLAGS)

$(BLDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(COMPLR) -c -o $@ $< -lm $(CFLAGS)

clean:
	rm -r $(BLDDIR)
