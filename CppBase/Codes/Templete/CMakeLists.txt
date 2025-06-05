file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

set(COMMON_HEAD_NAME "Common")

add_library(Templete STATIC ${SOURCES})

# 链接工具库并继承其包含路径
target_link_libraries(Templete 
    PUBLIC ${COMMON_HEAD_NAME}
)

target_include_directories(Templete
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)