SRCPATH	= ./src
OBJPATH = ./obj

SRCS	= $(wildcard $(SRCPATH)/*.cpp)
OBJS	= ${SRCS:.cpp=.o}


.c.o:
	@echo "Compiling" $< "..."
	g++ -c $<

all: app crobjdir putobj 

app:  $(OBJS)


putobj:
	(mv $(SRCPATH)/*.o $(OBJPATH);cd $(OBJPATH);pwd;sudo chmod 777 *.o)

cleanall:
	-rm -rf $(OBJPATH)/*.o

OBJDIR := obj

crobjdir:| $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

