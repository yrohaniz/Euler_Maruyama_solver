cmake_minimum_required(VERSION 3.8)
project(Euler_Maruyama_solver)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        drift_function.c
        diffusion_function.c
        PRNG_uniform.c
        Marsaglia_polar_generator.c
        EuMa.h
        )
add_executable(Euler_Maruyama_solver ${SOURCE_FILES})

target_link_libraries(Euler_Maruyama_solver m)