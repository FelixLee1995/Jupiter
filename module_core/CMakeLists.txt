
#扫描src目录, 获取.c .cpp 源码文件列表
file(GLOB_RECURSE DIR_SRCS ./src/*.cpp  ./src/*.c)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/runtime/lib)


find_package(yaml-cpp CONFIG REQUIRED)

ADD_LIBRARY(jupiter_core SHARED ${DIR_SRCS})
target_link_libraries(jupiter_core PRIVATE yaml-cpp)
