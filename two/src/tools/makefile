# submoudle makefile

# project root dir
SRC_BASE = ../..

CXXFLAGS += 
CPPFLAGS += -I. -I./inc -I$(SRC_BASE)/include 

# for ELF or EXE file
# # ELF or EXE file name, can modify according to need
# SRC_BIN = bb.out

# for submoudle lib file
# submoudle lib name, can modify according to need
SRC_LIB = libtools.a  
 
SRC_FILES = $(wildcard src/*.c)   


include $(SRC_BASE)/makefile.rule



# The following is an example of the makefile.rule file

# # makefile.rule for cpp
# # Set the rules required for each module to compile and links

# # if without a platform defined, give value "linux" to PLATFORM 
# ifndef PLATFORM 
	# PLATFORM = linux
# endif

# # define a root build directory base on the platform 
# # if without a SRC_BASE defined, just use module local src directory 
# ifeq ($(SRC_BASE),) 
    # BUILDDIR = $(MOD_SRC_DIR) 
    # OBJDIR = $(MOD_SRC_DIR)
	# LIBDIR = $(MOD_SRC_DIR) 
    # BINDIR = $(MOD_SRC_DIR)
# else
    # ifeq ($(DEBUG_SYMBOLS), TRUE) 
	    # BUILDDIR = $(SRC_BASE)/build/$(PLATFORM)_dbg
	# else
	    # BUILDDIR = $(SRC_BASE)/build/$(PLATFORM)
	# endif
	# OBJDIR = $(BUILDDIR)/obj/$(MODULE)
	# LIBDIR = $(BUILDDIR)/lib 
	# BINDIR = $(BUILDDIR)/bin
# endif


# # update compilation flags base on "DEBUG_SYMBOLS" 
# ifeq ($(DEBUG_SYMBOLS), TRUE) 
    # CXXFLAGS += -g -Wall -Werror -O0 
# else 
    # CXXFLAGS += -Wall -Werror -O2
# endif


# VPATH += $(MOD_SRC_DIR) 
# SRC_OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC_FILES))) 


# # Prevent makefile.rule being called directly
# ifeq($(MAKELEVEL), 0)
# all : msg
# else
# all : lib bin
# endif

# lib : $(OBJDIR) $(LIBDIR)/$(SRC_LIB)
# bin : $(OBJDIR) $(BINDIR)/$(SRC_BIN) 
# $(OBJDIR) : 
	# @echo "   MKDIR $(notdir $@)..." 
	# @mkdir -p $@


# ifneq ($(SRC_BIN),) 
# $(BINDIR)/$(SRC_BIN) : $(SRC_OBJ) 
	# $(CXX) -o $@ $^ $(LDFLAGS) 
# endif 

# ifneq ($(SRC_LIB),) 
# $(LIBDIR)/$(SRC_LIB) : $(SRC_OBJ) 
	# $(AR) rcs $@ $^ 
	# cp $@ $(SRC_BASE)/libs 
# endif 

# $(SRC_OBJ) : $(OBJDIR)/%.o : %.c
	# $(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@


# msg: 
	# @echo"You cannot directily execute this Makefile! \
	# This Makefile should calledby toplevel Makefile." 

# # clean target
# clean: 
# ifneq ($(SRC_LIB),) 
    # $(RM) $(SRC_OBJ) $(LIBDIR)/$(SRC_LIB)
# endif
# ifneq ($(SRC_BIN),) 
	# $(RM) $(SRC_OBJ) $(BINDIR)/$(SRC_BIN) 
# endif

	
# distclean:
# ifneq ($(SRC_LIB),) 
    # $(RM) $(SRC_OBJ) $(LIBDIR)/$(SRC_LIB)
# endif
# ifneq ($(SRC_BIN),) 
	# $(RM) $(SRC_OBJ) $(BINDIR)/$(SRC_BIN) 
# endif

# .PHONY : all clean disclean msg