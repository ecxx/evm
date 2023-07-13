#########################
# customise these
CFILES := fstack.cpp main.cpp vcb.cpp vm.cpp
PROG := prog
CFLAGS := -std=c++17 -Wall -Wextra -g 
LDFLAGS :=
########################

# -MMD generates dependencies while compiling
CFLAGS += -MMD
CC := g++

OBJFILES := $(CFILES:.cpp=.o)
DEPFILES := $(CFILES:.cpp=.d)

$(PROG) : $(OBJFILES)
	$(LINK.o) $(LDFLAGS) -o $@ $^

clean :
	rm -f $(PROG) $(OBJFILES) $(DEPFILES)

-include $(DEPFILES)