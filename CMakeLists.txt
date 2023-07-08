cmake_minimum_required(VERSION 3.5)

project(ROMITest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5Core)
find_package(Qt5 COMPONENTS Core SerialPort Network REQUIRED)
#find_package(Qt5Core REQUIRED COMPONENTS Network)

add_executable(ROMITest
  main.cpp
  Message.h
  Message.cpp
  ComportConnector.h
  ComportConnector.cpp
  UdpConnector.h
  UdpConnector.cpp
)
target_link_libraries(ROMITest PRIVATE Qt5::Core Qt5::Network)
#target_link_libraries(ROMITest PRIVATE Qt5::Network)


qt5_use_modules(ROMITest Core SerialPort)
