# submoudle makefile

# project root dir
SRC_BASE = ../..

CXXFLAGS += 
CPPFLAGS += -I. -I./inc -I$(SRC_BASE)/include/display/ 

# for ELF or EXE file
# # ELF or EXE file name, can modify according to need
# SRC_BIN = bb.out

# for submoudle lib file
# select module src file according to if test mode
ifeq (GLOBAL_BIN_SYMBOAL,)
# submoudle lib name, can modify according to need
SRC_LIB = libdisplay.a  
SRC_FILES := $(filter-out src/%_test.cpp,$(wildcard src/*.cpp));
else
# tets submodule
MODULE_TEST_SYMBOL=TRUE
SRC_BIN = mt.out
SRC_FILES := $(wildcard src/*.cpp) 
endif
MOD_SRC_DIR = src
include $(SRC_BASE)/makefile.rule
