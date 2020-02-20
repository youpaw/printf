cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

link_directories(/libft)
add_definitions(-DDOUBLE_EXTENDED=1)

add_executable(ft_printf src/ft_get_params.c src/ft_printf.c src/utils/ft_util_handle.c src/utils/ft_util_hexpref.c
        src/utils/ft_util_print.c src/utils/ft_util_rigor.c src/utils/ft_util_sign.c src/utils/ft_util_size.c
        src/utils/ft_util_width.c src/handlers/ft_handle_chr.c src/handlers/ft_handle_hex.c src/handlers/ft_handle_int.c
        src/handlers/ft_handle_nul.c src/handlers/ft_handle_oct.c src/handlers/ft_handle_ptr.c src/handlers/ft_handle_str.c
        src/handlers/ft_handle_uns.c src/handlers/floats/ft_handle_flt.c src/handlers/floats/bigint/big_int_arithmetics.c
        src/handlers/floats/bigint/big_int_helper.c src/handlers/floats/bigint/big_int_operatoins.c src/handlers/floats/bigint/big_int_print.c
        src/handlers/floats/doubleunpacked/print_double_unpacked.c src/handlers/floats/printdouble/print_double.c
        src/handlers/floats/str/str.c src/handlers/floats/unpackdouble/unpack_double1.c src/handlers/floats/unpackdouble/unpack_double2.c
        src/handlers/floats/utils/utils.c libft/libft.h src/handlers/floats/unpackdouble/double_representation.h src/handlers/floats/unpackdouble/double_representation.c src/handlers/floats/unpackdouble/double_classifier1.c src/handlers/floats/unpackdouble/double_classifier3.c src/handlers/floats/unpackdouble/double_classifier.h)

target_link_libraries(ft_printf "/home/alina/CLionProjects/printf/libft/libft.a")

include_directories(includes)
include_directories(libft)
include_directories(src/handlers/floats/utils)
include_directories(src/handlers/floats/printdouble)
include_directories(src/handlers/floats/doubleunpacked)
include_directories(src/handlers/floats/bigint)
include_directories(src/handlers/floats/str)
include_directories(src/handlers/floats/unpackdouble)