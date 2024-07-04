ifndef TIME_HOME
TIME_HOME = $(shell pwd)/../..
endif

MICOINCL= -I$(MICO_HOME)/include
MICOLIB = -L$(MICO_HOME)/lib -lmico2.3.12 -ldl -lrt -lnsl -lpthread
DEPLIB  =  $(MICOINCL) $(MICOLIB)

include $(TIME_HOME)/makefile/MakeVars.in

RM_FILES = $(objdir)/*.gch $(objdir)/*.hh $(objdir)/*.cp $(objdir)/*.o

$(objdir)/mytime.o $(objdir)/mytime_skel.o: $(objdir)/mytime.cp $(objdir)/mytime_skel.cp $(objdir)/mytime.hh
	(cd $(objdir); $(IDL_OBJ_COMPILE) $(DEPLIB) mytime.cp mytime_skel.cp mytime.hh)
$(objdir)/mytime.hh $(objdir)/mytime.cp $(objdir)/mytime_skel.cp: mytime.idl
	(mkdir -p $(objdir); cd $(objdir); $(IDL_COMPILE) ../../../$^)

.PHONY: clean
clean:
	rm $(RM_FILES)
