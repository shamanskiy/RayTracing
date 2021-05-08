add_executable(unit_tests
  main.cpp
  Vec3Tests.cpp
  RayTests.cpp
  catch_utils.hpp
)

target_link_libraries(unit_tests
  LibRT
)

target_include_directories(unit_tests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include/external
    ${PROJECT_SOURCE_DIR}/tests
)
