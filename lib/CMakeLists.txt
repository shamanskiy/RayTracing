file(GLOB_RECURSE include_files *.h)
list(REMOVE_ITEM ${include_files} ${PROJECT_SOURCE_DIR}/lib/include/External/catch.hpp)

file(GLOB_RECURSE source_files *.cpp)

add_library(LibRT
  ${include_files}
  ${source_files}
)

target_compile_features(LibRT PUBLIC cxx_std_17)

target_include_directories(LibRT
  PUBLIC
    ${PROJECT_SOURCE_DIR}/lib/include
)

source_group(TREE ${PROJECT_SOURCE_DIR}/lib/include FILES 
  ${include_files})
source_group(TREE ${PROJECT_SOURCE_DIR}/lib/source FILES 
  ${source_files})