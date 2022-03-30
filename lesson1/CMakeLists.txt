cmake_minimum_required(VERSION 3.11-3.18)
project(
  lesson1
  VERSION 1.0)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
if(WIN32)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MDd")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MD")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

# includes
include_directories(${ROOT_DIR}/include)
include_directories(${ROOT_DIR}/include/glad)
include_directories(${ROOT_DIR}/include/glfw)

# sources
aux_source_directory(src/. SRCS)

# link dir
link_directories(${ROOT_DIR}/lib/glfw/glfw-win32/lib-vc2019)

# target
add_executable(lesson1 ${SRCS})

# target link
target_link_libraries(lesson1 opengl32.lib)
target_link_libraries(lesson1 glfw3.lib)