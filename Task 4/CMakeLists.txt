cmake_minimum_required(VERSION 3.23)
project(Task_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(Application)
include_directories(Card)
include_directories(Server)
include_directories(Terminal)

add_executable(Task_4
        Application/app.c
        Application/app.h
        Card/card.c
        Card/card.h
        Server/server.c
        Server/server.h
        Terminal/terminal.c
        Terminal/terminal.h)
