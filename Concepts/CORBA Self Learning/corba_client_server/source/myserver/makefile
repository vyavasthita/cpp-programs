TIME_HOME = $(shell pwd)/../..

include $(TIME_HOME)/makefile/MakeVars.in

HEAD_FILE_DIRECTORY = source/myserver/headerfiles

INCLUDE = -I$(TIME_HOME)/$(HEAD_FILE_DIRECTORY) -I$(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)
MICOINCL= -I$(MICO_HOME)/include
MICOLIB = -L$(MICO_HOME)/lib -lmico2.3.12 -ldl -lrt -lnsl -lpthread

IDLO = \
	-L$(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)/mytime.o \
	-L$(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)/mytime_skel.o

DEPLIB  =  $(INCLUDE) $(MICOINCL) $(MICOLIB)

vpath %.cpp src
vpath %.h $(TIME_HOME)/$(HEAD_FILE_DIRECTORY) $(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)
vpath %.o $(TIME_HOME)/PM_OM_CORBA/interface/$(objdir)

RM_FILES = $(objdir)/*.o $(objdir)/server

$(objdir)/server: mytime.o mytime_skel.o $(objdir)/server.o
	$(COMP) $(DEPLIB) $(IDLO) -o $@ $^
$(objdir)/server.o: server.cpp server.h
	(mkdir -p $(objdir); cd $(objdir); $(COMP) $(OPTI) $(DEPLIB) ../../../$^)

.PHONY: clean
clean:
	rm $(RM_FILES)
	rm -rf bin
