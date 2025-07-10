SRCS_PATH = ./srcs/
SRCS = main.c

SRCS_PATH += ./srcs/builtin/
SRCS += cd.c
SRCS += echo.c
SRCS += env.c
SRCS += exit.c
SRCS += export.c
SRCS += pwd.c
SRCS += unset.c

SRCS_PATH += ./srcs/exec/
SRCS += exec_utils_2.c
SRCS += exec_utils_3.c
SRCS += exec_utils.c
SRCS += exec.c
SRCS += get_command_path.c
SRCS += heredoc.c
SRCS += readline.c

SRCS_PATH += ./srcs/parsing/
SRCS += expand.c
SRCS += parse.c
SRCS += str_utils.c
SRCS += tokens.c

SRCS_PATH += ./srcs/signals/
SRCS += handler.c
SRCS += signals.c

SRCS_PATH += ./srcs/utils/
SRCS += cd_utils.c
SRCS += env_utils.c
SRCS += err_utils.c
SRCS += export_utils.c
SRCS += lst_utils.c
SRCS += command_utils.c
SRCS += heredoc_utils.c
