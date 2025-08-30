# Directories
LIB_DIR		:= lib
TEST_DIR	:= test

# Main rules
.PHONY:	all clean fclean re test

all:
	@make -C $(LIB_DIR) all
	@make -C $(TEST_DIR) all

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(TEST_DIR) clean

fclean:
	@make -C $(LIB_DIR) fclean
	@make -C $(TEST_DIR) fclean

re:	fclean all

test:
	@make -C $(TEST_DIR) test
