cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

include_directories(src src/handlers/floats/bigint src/handlers/floats/doubleunpacked src/handlers/floats/printdouble src/handlers/floats/str src/handlers/floats/unpackdouble src/handlers/floats/utils )

set(LIBFT_DIR "libft")
include_directories(${LIBFT_DIR})
add_subdirectory(${LIBFT_DIR})

add_executable(${PROJECT_NAME}
        src/get_params.c
        src/handlers/floats/bigint/big_int_arithmetics.c
        src/handlers/floats/bigint/big_int_helper.c
        src/handlers/floats/bigint/big_int_operatoins.c
        src/handlers/floats/bigint/big_int_print.c
        src/handlers/floats/doubleunpacked/print_double_unpacked.c
        src/handlers/floats/handle_flt.c
        src/handlers/floats/printdouble/print_double.c
        src/handlers/floats/str/str.c
        src/handlers/floats/unpackdouble/double_classifier1.c
        src/handlers/floats/unpackdouble/double_classifier3.c
        src/handlers/floats/unpackdouble/double_representation.c
        src/handlers/floats/unpackdouble/unpack_double1.c
        src/handlers/floats/unpackdouble/unpack_double2.c
        src/handlers/floats/utils/utils.c
        src/handlers/handle_chr.c
        src/handlers/handle_hex.c
        src/handlers/handle_int.c
        src/handlers/handle_nul.c
        src/handlers/handle_oct.c
        src/handlers/handle_ptr.c
        src/handlers/handle_str.c
        src/handlers/handle_uns.c
        src/printf.c
        src/utils/util_hexpref.c
        src/utils/util_print.c
        src/utils/util_rigor.c
        src/utils/util_sign.c
        src/utils/util_size.c
        src/utils/util_width.c
        main.c
        )

target_link_libraries(${PROJECT_NAME} ft)

#add_executable(${PROJECT_NAME} main.c)
