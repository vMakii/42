SRCS_PATH = ./srcs/
SRCS = main.c

SRCS_PATH += ./srcs/mov/ 
SRCS += keypress.c
SRCS += keyrelease.c

SRCS_PATH += ./srcs/garbage/
SRCS += garbage_collector.c

SRCS_PATH += ./srcs/img/
SRCS += init_img.c
SRCS += upscale_img.c
SRCS += render.c
SRCS += utils_img.c
SRCS += minimap.c

SRCS_PATH += ./srcs/raycasting/
SRCS += raycasting.c

SRCS_PATH += ./srcs/parsing/
SRCS += check_data.c
SRCS += check_map_nl.c
SRCS += check_map.c
SRCS += get_data.c
SRCS += get_map.c
SRCS += parsing.c
SRCS += read_file.c

SRCS_PATH += ./srcs/utils/
SRCS += exit.c
SRCS += free.c
SRCS += print.c
SRCS += utils.c