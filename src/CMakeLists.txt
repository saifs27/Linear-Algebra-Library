set(HEADER_LIST "${LinearAlgebraLibrary_SOURCE_DIR}/include/linalg/matrix.hpp")

add_library(linear_algebra matrix.cpp ${HEADER_LIST})

target_include_directories(linear_algebra PUBLIC ../include)

target_compile_features(linear_algebra PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

