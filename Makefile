NAME = STL

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

INC_DIRS += Iterator Vector Util

vpath %.hpp $(INC_DIRS)

## file
HEADERS = Etc_func.hpp Iterator_traits.hpp Reverse_iterator.hpp Vector.hpp
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

## compile
CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 $(addprefix -I,$(INC_DIRS))
#
.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Link"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) 

$(OBJS): %.o: %.cpp $(HEADERS)
	@$(LOG) "Compile"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(LOG) "clean"
	@rm -f $(OBJS) 

fclean: clean
	@$(LOG) "fclean"
	@rm -f $(NAME)

re:
	@$(LOG) "re"
	@make fclean
	@make all
