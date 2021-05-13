add_executable(unit_tests
  main.cpp
  catch_utils.hpp
  CameraTests.cpp
  EquationsTests.cpp
  HitableObjectTests.cpp
  RayTests.cpp
  UtilsTests.cpp
  Vec3Tests.cpp
)

target_link_libraries(unit_tests
  LibRT
)

target_include_directories(unit_tests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include/external
    ${PROJECT_SOURCE_DIR}/tests
)
