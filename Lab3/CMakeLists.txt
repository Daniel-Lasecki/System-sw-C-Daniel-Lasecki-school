cmake_minimum_required(VERSION 3.10.0)
project(fir_filter VERSION 0.1.0 LANGUAGES C)

add_executable(fir_filter main_fir.c fir_filter.c coefficients.c)
