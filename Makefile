#
# Makefile for cc2530prog
#

CC?=gcc
CFLAGS?=
APP=cc2530prog
GPIO_BACKEND?=gpio-wiringpi

all: $(APP)

%.o: %.c
	$(CC) $(CFLAGS) -DGPIO_BACKEND=$(GPIO_BACKEND) -c $< -o $@

OBJS=$(APP).o $(GPIO_BACKEND).o

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lwiringPi

clean:
	rm -f *.o $(APP)
