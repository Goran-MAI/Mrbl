# Mrbl
A lightweight game engine developed as part of the "Engine Architecture and Design" course.

# Mrbl Engine + Tribalion

This project is a small example of a C++ engine with a game application.  
The structure is based on TheCherno's tutorials:

[TheCherno YouTube Channel](https://www.youtube.com/@TheCherno)

## Description

- **Mrbl**: The engine as a DLL, containing the base class `Application`.
- **Tribalion**: The game application that inherits from `Application` and uses the engine.
- `main()` is located in the engine and calls the concrete game application via `extern Application* CreateApplication()`.

## Project Structure

```text
├─ Mrbl
│  ├─ src
│  │  ├─ Mrbl
│  │  │  ├─ Events
│  │  │  │  ├─ ApplicationEvent.h
│  │  │  │  ├─ Event.h
│  │  │  │  ├─ KeyEvent.h
│  │  │  │  └─ MouseEvent.h
│  │  │  ├─ Application.cpp
│  │  │  ├─ Application.h
│  │  │  ├─ Core.h
│  │  │  ├─ EntryPoint.h
│  │  │  ├─ Log.cpp
│  │  │  ├─ Log.h
│  │  │  └─ Window.h
│  │  ├─ Platform
│  │  │  └─ Windows
│  │  │     ├─ WindowsWindow.cpp
│  │  │     └─ WindowsWindow.h
│  │  ├─ Mrbl.h
│  │  ├─ mrblpch.cpp
│  │  └─ mrblpch.h
│  ├─ vendor
│  │  └─ spdlog
│  │     ├─ LICENSE
│  │     ├─ README.md
|  |     └─ . . . 
│  ├─ Mrbl.vcxproj
│  ├─ Mrbl.vcxproj.filters
│  ├─ Mrbl.vcxproj.user
│  └─ projektstruktur.txt
├─ Tribalion
│  ├─ src
│  │  └─ Tribalion.cpp
│  ├─ Tribalion.vcxproj
│  └─ Tribalion.vcxproj.user
├─ vendor
├─ .gitignore
├─ .gitmodules
├─ GenerateProjects.bat
├─ LICENSE
├─ Mrbl.sln
├─ premake5.lua
└─ README.md

```


Note: This project is for learning purposes and follows the engine tutorials by TheCherno.
