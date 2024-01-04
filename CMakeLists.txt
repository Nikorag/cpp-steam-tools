cmake_minimum_required(VERSION 3.14)

project(cpp-steam-tools LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

add_library(cpp-steam-tools SHARED
  include/cpp-steam-tools_global.h
  src/steamtools.cpp
  include/steamtools.h
  src/steamshortcutentry.cpp
  include/steamshortcutentry.h
  include/crc.h
  src/crc.c
  include/vdf_parser.hpp
  include/vdfstatemachine.h
  src/vdfstatemachine.cpp
)

target_link_libraries(cpp-steam-tools PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

target_compile_definitions(cpp-steam-tools PRIVATE CPPSTEAMTOOLS_LIBRARY)
