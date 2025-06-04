# CMake的使用总结

## 指定 CMake 的最低版本要求
```cmake
# 语法:
cmake_minimum_required(VERRSION <version>)
# 示例:
cmake_minimum_required(VERRSION 3.10)
```

## 定义项目的名称
```cmake
# 语法:
project(<name>)
# 示例:
project(demo)
```

## 指定要生成的可执行文件和其源文件
```cmake
# 语法:
add_executable(<target> <source_files>...)
# 示例：
add_executable(main main.cpp)
```

## 定义一个变量

```cmake
# 语法:
set(<name> "string")
# 示例:
set(SUB_NAME "test_sub")
```

## 输出
```cmake
# 语法:
message(<string>)
# 示例:
message(${SUB_NAME})
```
使用${}来将一个定义好的变量内容取出

## 添加子文件
```cmake
# 语法:
add_subdirectory(<sub name>)
# 示例:
add_subdirectory(${SUB_NAME})
```
子文件内部也要有一个`CMakeLists.txt`文件才能被正确的包含

## 生成库文件
```cmake
# 语法:
add_library(target <type:[STATIC | SHARED | MODULE | INTERFACE]> <source file>)
# 示例:
add_library(${SUB_NAME} INTERFACE)
add_library(DataRoom STATIC ${SOURCES})
```

|类型|描述|用途|
| -- | -- | -- |
|STATIC|创建静态库（归档文件）|代码重用，减少编译时间|
|SHARED|创建动态链接库（共享库）|插件系统，运行时加载|
|MODULE|类似 SHARED，但不链接到可执行文件（需显式加载）|运行时插件|
|INTERFACE|不编译源文件，仅用于传递属性（头文件库）|纯头文件库|

## file()用法
file() 命令是 CMake 中用于处理文件和文件系统的多功能工具，提供了丰富的文件操作功能。它可以执行文件读写、路径操作、文件传输、归档处理等任务，是 CMake 脚本中不可或缺的一部分。

使用file自动检测源文件添加和删除
```cmake
# 语法:
file(<操作模式> [选项] [参数...])
# 示例:
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")
```

## 链接头文件
```cmake
# 语法:
target_include_directories(<target> [SYSTEM] [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...)
# 示例:
target_include_directories(DataRoom
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
```
|关键字|当前目标|依赖目标|典型场景|
| -- | -- | -- | -- |
|PUBLIC|✓|✓|公共API依赖|
|PRIVATE|✓|✗|仅内部实现使用|
|INTERFACE|✗|✓|头文件库/接口|

`target_include_directories`是 CMake 中用于管理头文件包含路径的核心命令，它允许为目标（库或可执行文件）精确指定包含目录，并控制这些目录如何传播给依赖项。

## 连接库文件
```cmake
# 语法:
target_link_libraries(<target>
                      <PRIVATE|PUBLIC|INTERFACE> <item>...
                      [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
# 示例:
target_link_libraries(main
    PRIVATE ${COMMON_HEAD_NAME}
    PUBLIC ${SUB_NAME}
)
```
`target_link_libraries` 是 CMake 中最核心的命令之一，用于定义目标之间的依赖关系，它不仅处理链接库，还控制依赖属性的传递（如包含路径、编译定义等）。这是现代 CMake 依赖管理的基石。

他有着依赖传递的特性,可以将子类的依赖根据修饰符号向外传递依赖
