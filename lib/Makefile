# Library Name
NAME	:= libasm.a

# Tools Properties
RM			:= rm -f
RMDIR		:= rm -rf
MKDIR		:= mkdir -p

# Assembler Properties
ASM			:= nasm
ASM_FORMAT	:= elf64
ASM_WFLAG	:= -w+all -w+error
ASM_MFLAG	:= -MP -MD
ASM_FLAG	:= -f $(ASM_FORMAT) $(ASM_WFLAG) -g

# Libary Properties
LIB			:= ar
LIB_FLAG	:= rcs

# Directories
BUILD_DIR	:= ./build
INCLUDE_DIR	:= ./include

# Main Source
MAIN_DIR	:= ./srcs/
MAIN_SRC	:= ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s
MAIN_SRCS	:= $(addprefix $(MAIN_DIR), $(MAIN_SRC))

# Objects & Dependencies File
DIRS		:= $(MAIN_DIR)
SRCS		:= $(MAIN_SRCS)
OBJS		:= $(SRCS:%.s=$(BUILD_DIR)/%.o)
OBJS_DIR	:= $(addprefix $(BUILD_DIR)/, $(DIRS))
DEPS		:= $(OBJS:.o=.o.d)

# Main Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS)
	$(LIB) $(LIB_FLAG) $(NAME) $(OBJS)

$(OBJS_DIR):
	$(MKDIR) $@

$(BUILD_DIR)/%.o:	%.s
	$(ASM) $(ASM_FLAG) $(ASM_MFLAG) -I$(INCLUDE_DIR)/ $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RMDIR) $(BUILD_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

-include $(DEPS)
