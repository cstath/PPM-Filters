# ########################   Makefile for filter   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

# Declaration of variables
SRCDIR = .
INCLDIR = .
OUTDIR = ../bin
$(shell mkdir -p $(OUTDIR) >/dev/null)
OBJDIR = $(OUTDIR)/objs
$(shell mkdir -p $(OBJDIR) >/dev/null)
DEPDIR = $(OUTDIR)/deps
$(shell mkdir -p $(DEPDIR) >/dev/null)

CC = g++
CC_FLAGS = -std=c++11 -g -Wall -Wextra -pedantic -fopenmp
LIBS   = -lgtest -lgtest_main


# File names
PROGRAM = filter
#SRCFILES := $(shell ls $(SRCDIR))
SRCFILES := $(wildcard *.cpp)
TMPFILES = $(SRCFILES:.cpp=.o)
OBJFILES = $(addprefix $(OBJDIR)/, $(TMPFILES))
TMPDEPFILES = $(SRCFILES:.cpp=.d)
DEPFILES = $(addprefix $(DEPDIR)/, $(TMPDEPFILES))

# Main target
$(OUTDIR)/$(PROGRAM): $(OBJFILES)
	$(CC) $(CC_FLAGS) $(OBJFILES) -o $@ 

# pull in dependency info for *existing* .o files
-include $(DEPFILES)

# To obtain object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) -I$(INCLDIR) $< -o $@ 
	$(CC) -MM $(CC_FLAGS) -I$(INCLDIR) $< > $(DEPDIR)/$*.d
	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.o:|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\//' < $(DEPDIR)/$*.d.tmp | tr --delete '\n' |\
	  fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/$*.d
	@rm -f $(DEPDIR)/$*.d.tmp


# To remove generated files
clean:
	rm -f $(OUTDIR)/$(PROGRAM) $(OBJFILES) $(DEPFILES)
