add_executable(RayTracer RayTracer.cpp)
target_link_libraries(RayTracer PRIVATE LibRT)
source_group(TREE ${PROJECT_SOURCE_DIR}/apps FILES 
  RayTracer.cpp)