file(GLOB_RECURSE test_files *.cpp)
message("${test_files}")

add_executable(UnitTests
  TestsUtils.h
  ${test_files}
)

target_link_libraries(UnitTests
  LibRT
)

target_include_directories(UnitTests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/include/External
    ${PROJECT_SOURCE_DIR}/tests
)

source_group(TREE ${PROJECT_SOURCE_DIR}/tests FILES 
  ${test_files} TestsUtils.h)
