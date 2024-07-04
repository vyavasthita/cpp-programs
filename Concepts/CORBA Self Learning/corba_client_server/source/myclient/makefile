TIME_HOME = $(shell pwd)/../..

include $(TIME_HOME)/makefile/MakeVars.in

INCLUDE = -I$(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)
MICOINCL= -I$(MICO_HOME)/include
MICOLIB = -L$(MICO_HOME)/lib -lmico2.3.12 -ldl -lrt -lnsl -lpthread

IDLO = \
	-L$(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)/mytime.o

DEPLIB  =  $(INCLUDE) $(MICOINCL) $(MICOLIB)

vpath %.cpp src
vpath %.h $(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)
vpath %.o $(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)

RM_FILES = $(objdir)/*.o $(objdir)/client

$(objdir)/client: mytime.o $(objdir)/client.o
	$(COMP) $(DEPLIB) $(IDLO) -o $@ $^
$(objdir)/client.o: client.cpp
	(mkdir -p $(objdir); cd $(objdir); $(COMP) $(OPTI) $(DEPLIB) ../../../$^)

.PHONY: clean
clean:
	rm $(RM_FILES)
	rm -rf bin
