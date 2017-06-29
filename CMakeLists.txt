cmake_minimum_required(VERSION 3.7)
project(syncman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lboost_system -lboost_thread")
include_directories("include")

set(INCLUDE include/jsoncpp/jsoncpp.cpp)

set(SOURCE_FILES_CLIENT client/main.cpp client/connection.cpp client/connection.h client/files.cpp client/files.h client/config.cpp client/config.h)
set(SOURCE_FILES_SERVER server/files.cpp server/files.h server/server.cpp server/server.h)
add_executable(syncman-client ${SOURCE_FILES_CLIENT} ${INCLUDE})
add_executable(syncman-server ${SOURCE_FILES_SERVER})