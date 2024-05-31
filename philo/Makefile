CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

DFLAGS = -MD -MP

INCLUDE_DIR = include

IFLAGS = -I $(INCLUDE_DIR)

SRC_PARSING = parsing.c \
              ft_atol.c \
              ft_isdigit.c \
              check_args.c

SRC = main.c \
	  get_time.c \
	  init_philo.c \
	  init_fork_list.c \
	  create_thread.c \
	  philo_routine.c \
	  free_all_philo.c \
	  monitor_routine.c \
	  philo_eat.c \
	  wait_ms.c \
	  philo_sleep.c \
	  take_forks.c \
	  print_state_change.c \
	  $(addprefix parsing/, $(SRC_PARSING)) \


BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

NAME = philo

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all
