NAME		= 	minibash

# ---------------------------------------------------
# ------------------  MAIN SOURCES  -----------------
# ---------------------------------------------------
SRCS		=	\
				./srcs/minibash.c \

# ---------------------------------------------------
# ----------------  BUILTIN SOURCES  ----------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/builtins/utils/builtins_utils.c \
				./srcs/builtins/utils/check_long_long.c \
				./srcs/builtins/utils/ft_atoll.c \
				./srcs/builtins/cd_builtin.c \
				./srcs/builtins/cd_utils1.c \
				./srcs/builtins/cd_utils2.c \
				./srcs/builtins/cd_utils3.c \
				./srcs/builtins/cd_utils4.c \
				./srcs/builtins/echo_builtin.c \
				./srcs/builtins/env_builtin.c \
				./srcs/builtins/exit_builtin.c \
				./srcs/builtins/export_builtin.c \
				./srcs/builtins/export_utils1.c \
				./srcs/builtins/export_utils2.c \
				./srcs/builtins/pwd_builtin.c \
				./srcs/builtins/unset_builtin.c \

# ---------------------------------------------------
# -----------------  ERRORS SOURCES  ----------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/errors/ch_exit_error.c \
				./srcs/errors/exit_process.c \
				./srcs/errors/handle_error.c \
				./srcs/errors/ms_exit_error.c \
				./srcs/errors/printerr.c \
				./srcs/errors/printerr_files.c \
				./srcs/errors/printerr_shell.c \
				./srcs/errors/printerr_syntax.c \

# ---------------------------------------------------
# ---------------  EXECUTION SOURCES  ---------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/execution/builtin/can_use_builtin.c \
				./srcs/execution/builtin/check_only_builtin.c \
				./srcs/execution/builtin/compare_exactly.c \
				./srcs/execution/builtin/execute_builtins.c \
				./srcs/execution/childs/alloc_childs_pids_array.c \
				./srcs/execution/childs/get_correct_return_code.c \
				./srcs/execution/childs/wait_childs.c \
				./srcs/execution/command/execute_command.c \
				./srcs/execution/command/execute_selected_command.c \
				./srcs/execution/command/check_file.c \
				./srcs/execution/command/get_command.c \
				./srcs/execution/environment/environment.c \
				./srcs/execution/execute_file/child_execute_command_line.c \
				./srcs/execution/execute_file/format_command_line.c \
				./srcs/execution/execute_file/sigint_execute_file.c \
				./srcs/execution/execute_file/try_execute_file.c \
				./srcs/execution/heredoc/close_heredocs.c \
				./srcs/execution/heredoc/close_heredoc_fd_if_present.c \
				./srcs/execution/heredoc/do_heredocs.c \
				./srcs/execution/heredoc/heredoc.c \
				./srcs/execution/pipes/child_handle_pipe.c \
				./srcs/execution/pipes/handle_pipe.c \
				./srcs/execution/pipes/parent_handle_pipe.c \
				./srcs/execution/preprocessing/token_list_to_exec.c \
				./srcs/execution/preprocessing/loop_until_word.c \
				./srcs/execution/preprocessing/number_of_command_words.c \
				./srcs/execution/preprocessing/number_of_commands.c \
				./srcs/execution/redirections/redirect_heredoc.c \
				./srcs/execution/redirections/redirect_input.c \
				./srcs/execution/redirections/redirect_output.c \
				./srcs/execution/redirections/redirections.c \
				./srcs/execution/execution.c \

# ---------------------------------------------------
# -----------------  TOKENIZER SOURCES  -------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/tokenizer/check_characters/get_normal_operator.c \
				./srcs/tokenizer/check_characters/get_token_type_from_string.c \
				./srcs/tokenizer/check_characters/is_operators.c \
				./srcs/tokenizer/check_characters/is_quotes.c \
				./srcs/tokenizer/expansion/environment_variable.c \
				./srcs/tokenizer/expansion/expand_exit_status.c \
				./srcs/tokenizer/expansion/expand_variable.c \
				./srcs/tokenizer/expansion/expansion.c \
				./srcs/tokenizer/expansion/get_word_after_dollar.c \
				./srcs/tokenizer/expansion/get_word_expanded.c \
				./srcs/tokenizer/tokenization/list_tokenizer.c \
				./srcs/tokenizer/tokenization/tokenization.c \
				./srcs/tokenizer/word_manipulation/alter_word.c \
				./srcs/tokenizer/word_manipulation/check_amount_char.c \
				./srcs/tokenizer/word_manipulation/get_word_length_until.c \
				./srcs/tokenizer/word_manipulation/get_word_until.c \
				./srcs/tokenizer/tokenizer.c \
				./srcs/tokenizer/line_fonctions.c \
				./srcs/tokenizer/quotes_operations.c \

# ---------------------------------------------------
# ----------------  PARSING SOURCES  ----------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/parsing/change_quote_mode.c \
				./srcs/parsing/check_after_redirection_if_filename_is_valid.c \
				./srcs/parsing/check_consecutive_chars.c \
				./srcs/parsing/check_consecutive_chars_spaces.c \
				./srcs/parsing/check_is_final_pipe_not_followed_by_expression.c \
				./srcs/parsing/check_quotes.c \
				./srcs/parsing/is_empty_line.c \
				./srcs/parsing/parsing.c \

# ---------------------------------------------------
# ---------------  SIGNALING SOURCES  ---------------
# ---------------------------------------------------

SRCS		+= \
				./srcs/signaling/heredoc_stop_signal.c \
				./srcs/signaling/signaling.c \

# ---------------------------------------------------
# ----------------  MEMORY SOURCES  -----------------
# ---------------------------------------------------
SRCS		+= \
				./srcs/memory/alter_word.c \
				./srcs/memory/free_char_array.c \
				./srcs/memory/init_free_exec.c \
				./srcs/memory/init_free_tokenizer.c \
				./srcs/memory/malloc_token_without_quotes.c \
				./srcs/memory/ms_calloc.c \
				./srcs/memory/ms_free.c \
				./srcs/memory/ms_malloc.c \
				./srcs/memory/ms_strdup.c \
				./srcs/memory/ms_strjoin.c \
				./srcs/memory/ms_strndup.c \
				./srcs/memory/init_free_built_in.c \
				./srcs/memory/shell_vars.c \
				./srcs/memory/free_exec.c \

OBJS 		:=	$(SRCS:%.c=%.o)

HEADERS		= 	./includes

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

RM			=	rm -f

# ---------------------------------------------------
# --------------------  INCLUDES  -------------------
# ---------------------------------------------------
LIBFT_PATH	=	./libft
LIBFT		=	./libft/libft.a
LIBS		=	-lreadline
INCLUDES	:=	-I $(HEADERS) -I $(LIBFT_PATH)

# ---------------------------------------------------
# ---------------------  COLORS  --------------------
# ---------------------------------------------------

BLUE		:=	"\033[1;34m"
YELLOW		:=	"\033[1;33m"
GREEN		:=	"\033[1;32m"
PURPLE		:=	"\033[1;35m"
CYAN		:=	"\033[1;36m"
END			:=	"\033[0m"

# ---------------------------------------------------
# --------------------  COMPILATION  ----------------
# ---------------------------------------------------
%.o 		:	%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

# ---------------------------------------------------
# ----------------------  CLEAN  --------------------
# ---------------------------------------------------
clean		:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
	@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}

norm		:
	@norminette $(SRCS) $(HEADERS) $(LIBFT_PATH)
	@echo ${GREEN} "> ✅ Norminette done - $(NAME)" ${END}

readline		:
	@echo ${CYAN} "> 📘 Installing readline" ${END}
	sudo apt install -y libreadline8 libreadline-dev
	@echo ${GREEN} "> ✅ Done - readline successfully installed" ${END}

launch		:	all
	@./$(NAME)

.PHONY		:	all clean fclean re norm launch readline