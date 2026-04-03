# Project Name
NAME	:= libasm-tester

# Tools Properties
RM		:= rm -f
RMDIR	:= rm -rf
MKDIR	:= mkdir -p

# Compiler Properties
CXX			:= c++
CXX_WFLAG	:= -Wall -Werror -Wextra -Wpedantic
CXX_MFLAG	:= -MP -MD
CXX_STDFLAG	:= -std=gnu++20
CXXFLAG		:= $(CXX_WFLAG) $(CXX_STDFLAG)

# Directories
BUILD_DIR	:= ./build
SRC_DIR		:= ./srcs
INCLUDE_DIR	:= ./includes

# Library Directories
LIB_DIR		:= ../lib
LIB_FILE	:= $(LIB_DIR)/libasm.a

# Main Source
MAIN_DIR	:= $(SRC_DIR)/
MAIN_SRC	:= main.cpp
MAIN_SRCS	:= $(addprefix $(MAIN_DIR), $(MAIN_SRC))

# Test Source
TEST_DIR	:= $(SRC_DIR)/tester/
TEST_SRC	:= ft_strlen_test.cpp \
				ft_strcpy_test.cpp \
				ft_strcmp_test.cpp
TEST_SRCS	:= $(addprefix $(TEST_DIR), $(TEST_SRC))

# Logger Source
LOGGER_DIR	:= $(SRC_DIR)/logger/
LOGGER_SRC	:= Logger.cpp
LOGGER_SRCS	:= $(addprefix $(LOGGER_DIR), $(LOGGER_SRC))

# Symbol Source
SYMBOL_DIR	:= $(SRC_DIR)/symbol/
SYMBOL_SRC	:= symbol.cpp \
				signal_name.cpp
SYMBOL_SRCS	:= $(addprefix $(SYMBOL_DIR), $(SYMBOL_SRC))

# Utils Source
UTILS_DIR	:= $(SRC_DIR)/utils/
UTILS_SRC	:= get_test_cases.cpp \
				signal.cpp \
				parent_wait.cpp
UTILS_SRCS	:= $(addprefix $(UTILS_DIR), $(UTILS_SRC))

# Objects & Dependencies File
DIRS		:= $(MAIN_DIR) $(TEST_DIR) $(LOGGER_DIR) $(SYMBOL_DIR) $(UTILS_DIR)
SRCS		:= $(MAIN_SRCS) $(TEST_SRCS) $(UTILS_SRCS) $(SYMBOL_SRCS) $(LOGGER_SRCS)
OBJS		:= $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
OBJS_DIR	:= $(addprefix $(BUILD_DIR)/, $(DIRS))
DEPS		:= $(OBJS:.o=.d)

# Main Rules
.PHONY:	all clean fclean re test

all:	$(NAME)

$(NAME):	$(LIB_FILE) $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -L$(LIB_DIR) -lasm -o $(NAME)

$(OBJS_DIR):
	$(MKDIR) $@

$(BUILD_DIR)/%.o:	%.cpp
	$(CXX) $(CXXFLAG) $(CXX_MFLAG) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RMDIR) $(BUILD_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	all
	@./$(NAME)

-include $(DEPS)
