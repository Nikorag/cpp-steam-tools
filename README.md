# cpp-steam-tools
Simple C++ library for parsing and updating steam shortcuts and controller configs.

# Requirements
cpp-steam-tools relies on QT6 being included in your project

# Installation
The easiest way to include `cpp-steam-tools` in your CMake project is to use `FetchContent`

```CMAKE
include(FetchContent)

FetchContent_Declare(
        cpp-steam-tools
        GIT_REPOSITORY https://github.com/nikorag/cpp-steam-tools.git
        GIT_TAG main #this can be any tag, revision or branch
)
FetchContent_GetProperties(cpp-steam-tools)

if(NOT cpp-steam-tools_POPULATED)
    message(STATUS "Fetching cpp-steam-tools...")
    FetchContent_Populate(cpp-steam-tools)
    add_subdirectory(${cpp-steam-tools_SOURCE_DIR} ${cpp-steam-tools_BINARY_DIR})
endif()

target_link_libraries(<YOUR PROJECT NAME> PUBLIC cpp-steam-tools)
```

# Usage
The `SteamTools` object must be instantiated with lamba functions for logging info and error:
```c++
//Create steam tools
auto infoLambda = [this](const QString &infoMessage) {
    std::cout << infoMessage.toStdString() << std::endl;
};

auto errorLambda = [this](const QString &errorMessage) {
    std::cerr << errorMessage.toStdString() << std::endl;
};
SteamTools* steam_tools = new SteamTools(infoLambda, errorLambda);
```
The `SteamTools` object provides methods for:
- Checking if Steam is installed
```c++
steamTools->steamExists()
```
- Reading a shortcuts.vdf file
```c++
steamTools->parseShortcuts()
```
- Creating new shortcut entries
```c++
steamTools->buildShortcutEntry("appName", "/path/to/my/exe", "launchOptions", mapOfArtwork)
```
- Writing entries back to shortcuts.vdf
```c++
steamTools->updateShortcuts(lsitOfShortcuts)
```
- Setting the neptune controller config for a shortcut
```c++
steamTools->updateControllerConfig("AppName", "ControllerConfigId")
```

# Acknowledgements
- This project was originally developed for use in [Chiaki4Deck](https://github.com/streetpea/chiaki4deck). Thanks to the team there especially:
  - [@streetpea](https://github.com/streetpea)
  - [@jbaiter](https://github.com/jbaiter)
  - [@nowrep](https://github.com/nowrep)
- This project includes crc algorithms generated at [pycrc](https://pycrc.org). This is licensed under the MIT license included in crc.h
- This project uses [ValveFileVDF originally by TinyTinni](https://github.com/TinyTinni/ValveFileVDF). This is licensed under the MIT license included in vdf_parser.hpp
