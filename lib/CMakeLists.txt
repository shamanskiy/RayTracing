set(HEADERS_LIST
  ${PROJECT_SOURCE_DIR}/lib/include/Core/Camera.h
  ${PROJECT_SOURCE_DIR}/lib/include/Core/QuadraticEquation.h
  ${PROJECT_SOURCE_DIR}/lib/include/Core/Ray.h
  ${PROJECT_SOURCE_DIR}/lib/include/Core/Vec3.h
  ${PROJECT_SOURCE_DIR}/lib/include/Objects/HitableObject.h
  ${PROJECT_SOURCE_DIR}/lib/include/Utils/ProgressBar.h
)

set(SOURCES_LIST
  ${PROJECT_SOURCE_DIR}/lib/source/Core/QuadraticEquation.cpp
  ${PROJECT_SOURCE_DIR}/lib/source/Objects/HitableObject.cpp
  ${PROJECT_SOURCE_DIR}/lib/source/Utils/ProgressBar.cpp
)

add_library(LibRT
  ${SOURCES_LIST}
  ${HEADERS_LIST}
)

target_compile_features(LibRT PUBLIC cxx_std_17)

target_include_directories(LibRT
  PUBLIC
    ${PROJECT_SOURCE_DIR}/lib/include
)