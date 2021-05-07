# The Makefile - Thanos Snap
#
# Author : Rishav Das
# Created on : May 7, 2021
#
# Last modified by : -
# Last modified on : -
#
#

CC = gcc
CFLAGS = -Wall -I include/
TARGET = bin/thanos-snap

all : $(TARGET)

$(TARGET) : src/thanos-snap.c src/regular.c
	$(CC) $(CFLAGS) -o $(TARGET) src/*.c
