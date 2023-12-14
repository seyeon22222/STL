NAME = STL

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

INC_DIRS += Iterator Vector Util test

vpath %.hpp $(INC_DIRS)

## file
HEADERS = Etc_func.hpp Iterator_traits.hpp Reverse_iterator.hpp Vector.hpp vector_test.hpp Number.hpp
SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

## compile
CXX= c++ -fsanitize=address -g
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
	@rm -f std_out
	@rm -f ft_out
	@rm -f $(OBJS) 

fclean: clean
	@$(LOG) "fclean"
	@rm -f std_out
	@rm -f ft_out
	@rm -f $(NAME)

re:
	@$(LOG) "re"
	@make fclean
	@make all
