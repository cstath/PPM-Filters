# ########################   Makefile for Test   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f

# Declaration of variables
SRCDIR = ../filter
TESTDIR = .
INCLDIR = -I. -I../filter
OUTDIR = ../bin
$(shell mkdir -p $(OUTDIR) >/dev/null)
DEPDIR = $(OUTDIR)/deps-test
$(shell mkdir -p $(DEPDIR) >/dev/null)
CC = g++
CC_FLAGS = -std=c++11 -g -ggdb3 -Wall -Wextra -pedantic
LIBS   = -lgtest -lgtest_main


# File names
PROGRAM = filter
SRCFILES := $(shell find $(SRCDIR)/ -name '*.cpp' -exec basename {} \;)
TMPFILES = $(SRCFILES:.cpp=.o)
OBJFILES = $(addprefix $(OUTDIR)/, $(TMPFILES))
TMPDEPFILES = $(SRCFILES:.cpp=.d)
DEPFILES = $(addprefix $(DEPDIR)/, $(TMPDEPFILES))

# Do the same for the test program but don't link main.c or .check files
# Check framework provides it's own main() function.
SRCFILES-TEST := $(shell find $(TESTDIR)/ -name '*.cpp' -exec basename {} \;)
TMPFILES-TEST  = $(SRCFILES-TEST:.cpp=.o)
OBJFILES-TEST  = $(addprefix $(OUTDIR)/, $(TMPFILES-TEST))
OBJFILES-TEST += $(OBJFILES)
OBJFILES-TEST := $(filter-out %/main.o, $(OBJFILES-TEST))

TMPDEPFILES-TEST = $(SRCFILES-TEST:.cpp=.d)
DEPFILES-TEST = $(addprefix $(DEPDIR)/, $(TMPDEPFILES-TEST))
DEPFILES-TEST += $(DEPFILES)
DEPFILES-TEST := $(filter-out %/main.d, $(DEPFILES-TEST))

# @echo $(OBJFILES-TEST)

# all:
# 	@echo "DEPFILES="
# 	@echo
# 	@echo $(DEPFILES)
# 	@echo
# 	@echo "DEPFILES-TEST="
# 	@echo
# 	@echo $(DEPFILES-TEST)

# Build test program
$(OUTDIR)/$(PROGRAM)-test: $(OBJFILES-TEST)
	$(CC) $(CC_FLAGS) $^ -o $@ $(LIBS)

# pull in dependency info for *existing* .o files
-include $(DEPFILES-TEST)

# Generic rules to build all source files needed for test
$(OUTDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $(INCLDIR) $< -o $@ $(LIBS)
	$(CC) -MM $(CC_FLAGS) $(INCLDIR) $< $(LIBS) > $(DEPDIR)/$*.d
	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OUTDIR)/$*.o:|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\//' < $(DEPDIR)/$*.d.tmp | tr --delete '\n' |\
	  fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/$*.d
	@rm -f $(DEPDIR)/$*.d.tmp

$(OUTDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $(INCLDIR) $< -o $@ $(LIBS)
	$(CC) -MM $(CC_FLAGS) $(INCLDIR) $< $(LIBS) > $(DEPDIR)/$*.d
	@mv -f $(DEPDIR)/$*.d $(DEPDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OUTDIR)/$*.o:|' < $(DEPDIR)/$*.d.tmp > $(DEPDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\//' < $(DEPDIR)/$*.d.tmp | tr --delete '\n' |\
	  fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(DEPDIR)/$*.d
	@rm -f $(DEPDIR)/$*.d.tmp

# To remove generated files
clean:
	rm -f $(OUTDIR)/$(PROGRAM)-test $(OBJFILES-TEST) $(DEPFILES-TEST)