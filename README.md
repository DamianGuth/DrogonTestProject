# Getting started

## Prerequisites

In order to be able to effectively debug projects created with drogon using
Visual Studio Code (called VSCode in the following document) you need

### The following packages:

- jsoncpp (A c++ JSON library. Version 1.7+ needed)
  - Install via: sudo apt-get install libjsoncpp-dev
- c++ boost
  - Install via: sudo apt-get install libboost-all-dev
  - Check via: dpkg -S /usr/include/boost/version.hpp

### These compiler/linker settings
The following settings were set using the VSCode UI.

> You can view the C/C++ configuration UI by running the command C/C++: Edit Configurations (UI) from the Command Palette (Ctrl+Shift+P).

-Microsoft: https://code.visualstudio.com/docs/cpp/config-msvc#:~:text=From%20the%20main%20menu%2C%20choose%20Run%20%3E%20Add%20Configuration..,VS%20Code%20creates%20a%20launch.


Include paths extended by:

 - /home/damian/Documents/dev/drogon/**
  - This is the path to the drogon framework, make sure to adjust it
 - /usr/include/jsoncpp/**
  - jsoncpp might already by installed on your system but VSCode might not
  recognize it, so you have to add this include path


Further more i have changed the C++ language settings to **gnu++17**

and also added **-ljsoncpp** to the compiler arguments

## Including debug symbols
In order to debug (using VSCode for example) you need to include debug symbols in your build.
To do that you need to update the **CMakeLists.txt** file in the project and add
- set(CMAKE_BUILD_TYPE Debug)

to the top of the file right below the project name line. It should look similar to this:

>cmake_minimum_required (VERSION 3.5)
>
>project(drogonTestProject CXX)
>
>set(CMAKE_BUILD_TYPE Debug)
>
>include(CheckIncludeFileCXX)

(You can also use "set(CMAKE_BUILD_TYPE RelWithDebInfo)" instead. This will optimize the code similar to release versions but will still include debug symbols.)

Your build will now include debug symbols the next time you run **make**.

### When using VSCode for debugging
You need to change the **program** part of the **launch.json** file.
If your project does not contain one, it needs to be created in the **.vscode**
directory and should look like this (replace the program path):

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/drogonTestProject",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

## Building
- Navigate to the 'Build' directory
- Run 'cmake ..'' to generate the cmake file
- Run 'make' to build the project

## Running it
- Navigate to the build directory
- Use './drogonTestProject' to start it
- You can now access the server via [http://localhost:8081/](http://localhost:8081/)
