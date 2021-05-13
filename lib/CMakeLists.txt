set(HEADERS_LIST
  ${PROJECT_SOURCE_DIR}/include/LibRT/Camera.h
  ${PROJECT_SOURCE_DIR}/include/LibRT/Equations.h
  ${PROJECT_SOURCE_DIR}/include/LibRT/HitableObject.h
  ${PROJECT_SOURCE_DIR}/include/LibRT/Ray.h
  ${PROJECT_SOURCE_DIR}/include/LibRT/Utils.h
  ${PROJECT_SOURCE_DIR}/include/LibRT/Vec3.h
)

set(SOURCES_LIST
  ${PROJECT_SOURCE_DIR}/lib/Equations.cpp
  ${PROJECT_SOURCE_DIR}/lib/HitableObject.cpp
  ${PROJECT_SOURCE_DIR}/lib/Utils.cpp
)

add_library(LibRT
  ${SOURCES_LIST}
  ${HEADERS_LIST}
)

target_compile_features(LibRT PUBLIC cxx_std_17)

target_include_directories(LibRT
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include/LibRT
)