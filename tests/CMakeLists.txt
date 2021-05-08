add_executable(unit_tests
  Vec3Tests.cpp
  RayTests.cpp
)

target_link_libraries(unit_tests
  GTest::gtest_main
  LibRT
)
