# ########################   Makefile for all   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f


SUBDIRS = filter GUI test

all:
	@for i in $(SUBDIRS); do \
	echo; echo "make all in $$i..."; echo; \
	(cd $$i; $(MAKE) $(MFLAGS) ); done


clean:
	@for i in $(SUBDIRS); do \
	echo; echo "Clearing in $$i..."; echo; \
	(cd $$i; $(MAKE) $(MFLAGS) clean); done
