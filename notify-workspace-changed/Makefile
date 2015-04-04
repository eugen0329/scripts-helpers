CC = gcc

LDLIBS = $(shell pkg-config  --cflags --libs libwnck-1.0 )
CCFLAGS = -O2 -DWNCK_I_KNOW_THIS_IS_UNSTABLE 

SRC = notify-workspace-changed.c
TARGET = notify-workspace-changed

all: $(TARGET)

$(TARGET):
	 $(CC) $(CCFLAGS) $(SRC) -o $(TARGET) $(LDLIBS) 
