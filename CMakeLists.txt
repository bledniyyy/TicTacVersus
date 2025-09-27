cmake_minimum_required(VERSION 3.5)

project(TicTacVersus VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

# Автоматический поиск файлов
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
file(GLOB FORMS "*.ui")
file(GLOB RESOURCES "*.qrc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TicTacVersus
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
        ${RESOURCES}
    )
    target_link_libraries(TicTacVersus PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets 
        Qt${QT_VERSION_MAJOR}::Multimedia
    )
else()
    add_executable(TicTacVersus 
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
        ${RESOURCES}
    )
    target_link_libraries(TicTacVersus PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets 
        Qt${QT_VERSION_MAJOR}::Multimedia
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TicTacVersus)
endif()