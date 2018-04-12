LIB_DIRS = ./media 	\
		   ./rtsp 	\
		   ./util 	


debug:
	### Test ###
ifeq ($(LIB_TYPE), static) 
	@echo "static"
else
	@echo "dynamic"
endif

	##############################
	@for target_dir in $(LIB_DIRS); do 			   \
		$(MAKE) -C $$target_dir debug $(LIB_TYPE); \
	done
release:
	@for target_dir in $(LIB_DIRS); do 					\
		$(MAKE) -C $$target_dir release $(LIB_TYPE);	\
	done
clean:
	@for target_dir in $(LIB_DIRS); do 	\
		$(MAKE) -C $$target_dir clean;	\
	done
