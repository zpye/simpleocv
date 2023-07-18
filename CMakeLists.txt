cmake_minimum_required(VERSION 3.14)

project(simpleocv)

option(BUILD_SIMPLEOCV_SAMPLE "build simpleocv sample" OFF)

set(SIMPLEOCV_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(SIMPLEOCV_SRC 
  ${SIMPLEOCV_ROOT}/src/mat_pixel_affine.cpp
  ${SIMPLEOCV_ROOT}/src/mat_pixel_drawing.cpp
  ${SIMPLEOCV_ROOT}/src/mat_pixel_resize.cpp
  ${SIMPLEOCV_ROOT}/src/mat_pixel_rotate.cpp
  ${SIMPLEOCV_ROOT}/src/simpleocv.cpp)

add_library(simpleocv STATIC ${SIMPLEOCV_SRC})
target_include_directories(simpleocv PUBLIC ${SIMPLEOCV_ROOT}/include)

if(BUILD_SIMPLEOCV_SAMPLE)
  add_executable(simpleocv_basic ${SIMPLEOCV_ROOT}/sample/basic.cpp)
  target_link_libraries(simpleocv_basic PUBLIC simpleocv)
  target_compile_definitions(simpleocv_basic PUBLIC -DIMAGE_PATH="${SIMPLEOCV_ROOT}/imgs")
endif()
