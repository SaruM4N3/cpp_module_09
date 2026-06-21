NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NORELINK = -MMD -MP
RM = rm -rf

BUILDDIR = obj
SRCS = main.cpp

OBJS = $(SRCS:%.cpp=$(BUILDDIR)/%.o)
DEPS = $(OBJS:.o=.d)

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

# Base rule
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREY) "
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@printf "\n $(GREEN)✅ Build done!$(RESET)\n"

# Relink prevention for linked projects
FORCE:
$(BUILDDIR)/%.o: %.cpp
	@printf "$(GREY) "
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(NORELINK) -c $< -o $@
	@printf "$(RESET)"

clean:
	@printf "$(RED)  "
	$(RM) $(BUILDDIR)
	@printf "$(RESET)\n"

fclean: clean
	@printf "$(RED)  "
	$(RM) $(NAME)
	@printf "$(RESET)\n"

debug: fclean
	@$(MAKE) all CXX=g++ CXXFLAGS="$(CXXFLAGS) -DDEBUG_MODE"

re: fclean all

-include $(DEPS)

.PHONY: all FORCE clean fclean re debug

# COLORS
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
GREY = \033[1;90m