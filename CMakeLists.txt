cmake_minimum_required(VERSION 3.14)

project(cpp-steam-tools LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(WIN32)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

add_library(cpp-steam-tools SHARED
        include/cpp-steam-tools_global.h
        src/steamtools.cpp
        include/steamtools.h
        src/steamshortcutentry.cpp
        include/steamshortcutentry.h
        include/crc.h
        include/vdf_parser.hpp
        include/vdfstatemachine.h
        src/vdfstatemachine.cpp
)

target_include_directories(cpp-steam-tools
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
)

target_link_libraries(cpp-steam-tools PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

target_compile_definitions(cpp-steam-tools PRIVATE CPPSTEAMTOOLS_LIBRARY)

install(TARGETS cpp-steam-tools
        EXPORT SteamToolsTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
