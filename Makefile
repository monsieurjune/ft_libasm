# Directories
LIB_DIR		:= lib
TEST_DIR	:= test

# Main rules
.PHONY:	all clean fclean re test

all:
	@$(MAKE) -C $(LIB_DIR) all
	@$(MAKE) -C $(TEST_DIR) all

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(TEST_DIR) clean

fclean:
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(TEST_DIR) fclean

re:	fclean all

test:	all
	@$(MAKE) -C $(TEST_DIR) test
