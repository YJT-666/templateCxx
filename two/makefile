# Top makefile for C++ program                                                                                                                                                              
# Copyright (C) 2023 JTsmileY  
 
# Debug option switch
export DEBUG_SYMBOLS = TRUE 

# Source file path   
DIR = src 
MODULES = $(shell ls $(DIR)) 

# you need to determine the order of module compilation!!!!
main:tools 


# set build directory build/lib build/bin
ifeq ($(DEBUG_SYMBOLS), TRUE)
    BUILDDIR = ./build/$(PLATFORM)_dbg
else
    BUILDDIR = ./build/$(PLATFORM)
endif

$(BUILDDIR):
	@echo "    Create directory $@ ..."
	mkdir -p $(BUILDDIR)/bin $(BUILDDIR)/lib

   
$(MODULES): 
	@$(MAKE) -C $(DIR)/$@


all : $(BUILDDIR) $(MODULES)	
       
clean : 
	@for subdir in $(MODULES); \ 
	do $(MAKE) -C $(DIR)/$$subdir $@; \ 
	done 
    
distclean: 
	@for subdir in $(MODULES); \ 
	do $(MAKE) -C $(DIR)/$$subdir $@; \ 
	done 
    
tags: 
	ctags -R 
    
 
help:
	@echo "===============A common Makefile for cprograms==============" 
	@echo "Copyright (C) 2023 2/21 JTsmileY" 
	@echo "The following targets are support:" 
	@echo 
	@echo " all             - (==make) compile and link" 
	@echo " obj             - just compile, without link" 
	@echo " clean           - clean target" 
	@echo " dist            - clean target and other information" 
	@echo " tags            - create ctags for vim editor" 
	@echo " help            - print help information" 
	@echo 
	@echo "To make a target, do 'make [target]'" 
	@echo "========================= Version 1.0=======================" 
    
.PHONY : all clean distclean tags help 