#####################################
#				EXPORT				#
#####################################
DEFAULT_PATH = $(shell pwd)
export DEFAULT_PATH

BUILD_BIN = $(DEFAULT_PATH)/bin
export BUILD_BIN

PUBLIC_INCLUDE_DIR 	  = $(DEFAULT_PATH)/include
PUBLIC_CPPFLAGS 	  = -W -Wall -std=c++17 -I$(PUBLIC_INCLUDE_DIR)
PUBLIC_DEBUG_FLAGS 	  = -g -ggdb
export PUBLIC_CPPFLAGS
export PUBLIC_DEBUG_FLAGS



#####################################
#			PUBLIC VALUE			#
#####################################
LIB_DIR 	  = $(DEFAULT_PATH)/src
UNIT_TEST_DIR = $(DEFAULT_PATH)/unit_test
EXAM_DIR 	  = $(DEFAULT_PATH)/examples



#####################################
#				ETC				    #
#####################################



#MAKEARGS  = $(filter-out $@, $(MAKECMDGOALS))
LIB_TYPE = ${LIB_BUILD_TYPE}
export LIB_TYPE

MAKEFLAGS = --silent --ignore-errors --no-print-directory
all: debug unittest exams 

debug: libd
libd:
	@$(MAKE) -C $(LIB_DIR) debug $(LIB_TYPE)
release: lib
lib:
	@$(MAKE) -C $(LIB_DIR) release $(LIB_TYPE)

unittest:
	@$(MAKE) -C $(UNIT_TEST_DIR) all
exams:
	@$(MAKE) -C $(EXAM_DIR) all



DEL_ITEM = tags
clean: libclean unittestclean examplesclean
	echo "CCC Library Clean"
	@rm -rf $(DEL_ITEM)

libclean:
	@$(MAKE) -C $(LIB_DIR) clean
unittestclean:
	@$(MAKE) -C $(UNIT_TEST_DIR) clean 
examplesclean:
	@$(MAKE) -C $(EXAM_DIR) clean
