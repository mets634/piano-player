CC=msp430-gcc
CFLAGS=-mmcu=msp430g2553 -g
LDFLAGS=

SRCDIR=source
HDRDIR=header
BINDIR=bin
OBJDIR=obj

SRCS=$(wildcard $(SRCDIR)/*.c)
HDRS=$(wildcard $(HDRDIR)/*.h)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TARGET=$(BINDIR)/main.elf


.PHONY: all
all: $(TARGET)
	echo "prog $<\n exit" | mspdebug rf2500

.PHONY: clean
clean:
	rm -r $(BINDIR) $(OBJDIR) 2>/dev/null; true

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) -I$(HDRDIR) -o $@ $<

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) -mmcu=msp430g2553 -o $@ $< $(LDFLAGS)
