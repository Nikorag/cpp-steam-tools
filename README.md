# cpp-steam-tools
Simple C++ library for parsing and updating steam shortcuts and controller configs.

# Requirements
cpp-steam-tools relies on QT6 being included in your project

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
steamTools->buildShortcutEntry("appName", "/path/to/my/exe", mapOfArtwork)
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
- This project includes crc algorithms generated at [pycrc](https://pycrc.org). This is licensed under the MIT license included in crc.h
- This project uses [ValveFileVDF originally by TinyTinni](https://github.com/TinyTinni/ValveFileVDF). This is licensed under the MIT license included in vdf_parser.hpp
