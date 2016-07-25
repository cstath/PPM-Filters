# ########################   Makefile.1   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

# Declaration of variables
SRCDIR = .
INCLDIR = .
OUTDIR = ../bin
CC = g++
CC_FLAGS = -std=c++11 -g -O2 -ggdb3 -Wall -Wextra -pedantic
LIBS   = -lgtest -lgtest_main


# File names
PROGRAM = filter
#SRCFILES := $(shell ls $(SRCDIR))
SRCFILES := $(wildcard *.cpp)
TMPFILES = $(SRCFILES:.cpp=.o)
OBJFILES = $(addprefix $(OUTDIR)/, $(TMPFILES))
HEADERFILES = := $(wildcard *.h)

# Main target
$(OUTDIR)/$(PROGRAM): $(OBJFILES)
	$(CC) $(OBJFILES) -o $@ 

# To obtain object files
$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) -I$(INCLDIR) $< -o $@ 

# To remove generated files
clean:
	rm -f $(OUTDIR)/$(PROGRAM) $(OBJFILES)
