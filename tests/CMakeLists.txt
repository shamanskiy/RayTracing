add_executable(unit_tests
  main.cpp
  catch_utils.hpp
  Core/CameraTests.cpp
  Core/QuadraticEquationTests.cpp
  Core/RayTests.cpp
  Core/Vec3Tests.cpp
  Objects/HitableObjectTests.cpp
  Utils/ProgressBarTests.cpp
)

target_link_libraries(unit_tests
  LibRT
)

target_include_directories(unit_tests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/include/External
    ${PROJECT_SOURCE_DIR}/tests
)
