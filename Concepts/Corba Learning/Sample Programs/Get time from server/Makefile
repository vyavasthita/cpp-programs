MICOLIB = -L$(MICO_HOME)/lib -lmico2.3.12
MICOINCL= $(MICO_HOME)/include
REMOVE = rm mytime.h mytime.cc mytime.h.gch mytime.o server.o client.o myserver myclient mytime_skel.cc
DEPLIB = -I $(MICOINCL) $(MICOLIB) -ldl -lrt -lnsl -lpthread

myserver:mytime.o server.o
	g++ $(DEPLIB) -o myserver mytime.o server.o
myclient:mytime.o client.o
	g++ $(DEPLIB) -o myclient mytime.o client.o
mytime.o:mytime.h mytime.cc
	g++ $(DEPLIB) -c mytime.h mytime.cc
server.o:server.cc 
	g++ $(DEPLIB) -c server.cc
client.o:client.cc
	g++ $(DEPLIB) -c client.cc
mytime.h:
	idl mytime.idl
mytime.cc:
	idl mytime.idl
clean:
	$(REMOVE) 
