cmake_minimum_required(VERSION 3.18)

project(RayTracing
      VERSION 1.0
      DESCRIPTION "Ray tracing tutorial by Peter Shirley"
      LANGUAGES CXX)
	  
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(GTest CONFIG REQUIRED)

add_subdirectory(apps)

add_subdirectory(lib)

add_subdirectory(tests)