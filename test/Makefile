# ########################   Makefile for Test   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

# Declaration of variables
SRCDIR = ../filter
TESTDIR = .
INCLDIR = -I. -I../filter
OUTDIR = ../bin
CC = g++
CC_FLAGS = -std=c++11 -g -ggdb3 -Wall -Wextra -pedantic
LIBS   = -lgtest -lgtest_main


# File names
PROGRAM = filter
SRCFILES := $(shell find $(SRCDIR)/ -name '*.cpp' -exec basename {} \;)
TMPFILES = $(SRCFILES:.cpp=.o)
OBJFILES = $(addprefix $(OUTDIR)/, $(TMPFILES))

# Do the same for the test program but don't link main.c or .check files
# Check framework provides it's own main() function.
SRCFILES-TEST := $(shell find $(TESTDIR)/ -name '*.cpp' -exec basename {} \;)
TMPFILES-TEST  = $(SRCFILES-TEST:.cpp=.o)
OBJFILES-TEST  = $(addprefix $(OUTDIR)/, $(TMPFILES-TEST))
OBJFILES-TEST += $(OBJFILES)
OBJFILES-TEST := $(filter-out %/main.o, $(OBJFILES-TEST))

# @echo $(OBJFILES-TEST)

# all:
# 	@echo "OBJFILES="
# 	@echo
# 	@echo $(OBJFILES)
# 	@echo
# 	@echo "OBJFILES-TEST="
# 	@echo
# 	@echo $(OBJFILES-TEST)

# Build test program
$(OUTDIR)/$(PROGRAM)-test: $(OBJFILES-TEST)
	$(CC) $(CC_FLAGS) $^ -o $@ $(LIBS)

# Generic rules to build all source files needed for test
$(OUTDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $(INCLDIR) $< -o $@ $(LIBS)

$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $(INCLDIR) $< -o $@ $(LIBS)

# To remove generated files
clean:
	rm -f $(OUTDIR)/$(PROGRAM)-test $(OBJFILES-TEST)
