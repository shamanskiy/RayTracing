set(HEADERS_LIST
  ${PROJECT_SOURCE_DIR}/lib/Ray.h
  ${PROJECT_SOURCE_DIR}/lib/Vec3.h
)

set(SOURCES_LIST
  ${PROJECT_SOURCE_DIR}/lib/Vec3.cpp
)

add_library(LibRT
  ${SOURCES_LIST}
  ${HEADERS_LIST}
)

target_compile_features(LibRT PUBLIC cxx_std_17)

target_include_directories(LibRT
  PUBLIC
    ${PROJECT_SOURCE_DIR}/lib
)