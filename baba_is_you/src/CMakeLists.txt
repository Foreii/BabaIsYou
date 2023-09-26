cmake_minimum_required(VERSION 3.5)

#project(baba_is_you VERSION 0.1 LANGUAGES CXX)
#
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#set(CMAKE_CXX_FLAGS "-std=c++20 -pedantic-errors -Wall -Wuninitialized")

# UNCOMMENT WHEN MOVING TO GUI
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES
        main.cpp
        position.h
        position.cpp
        direction.h
        game.h
        tile.h
        block.h
        blocktype.h
        map.h
        controller.h
        console.h
        main.h
        observer.h
        observable.h
        view.h
        facade.h
        view.cpp
        tile.cpp
        game.cpp
        map.cpp
        console.cpp
        controller.cpp
        facade.cpp
        ImageLoader.h
        tileDisplay.h
)

# UNCOMMENT WHEN MOVING TO GUI
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(baba_is_you
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
## Define target properties for Android with Qt 6 as:
##    set_property(TARGET baba_is_you APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
##                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
## For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(baba_is_you SHARED
#            ${PROJECT_SOURCES}
#        )
## Define properties for Android with Qt 5 after find_package() calls as:
##    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(baba_is_you
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()

add_executable(baba_is_you
    ${PROJECT_SOURCES}
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
)
find_package (QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package (Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
target_link_libraries(baba_is_you PRIVATE
Qt${QT_VERSION_MAJOR}::Widgets)

# UNCOMMENT WHEN MOVING TO GUI
#target_link_libraries(baba_is_you PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#target_link_libraries(baba_is_you Qt${QT_VERSION_MAJOR}::Core)

# UNCOMMENT WHEN MOVING TO GUI
#set_target_properties(baba_is_you PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)

# UNCOMMENT WHEN MOVING TO GUI
install(TARGETS baba_is_you
    #BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# UNCOMMENT WHEN MOVING TO GUI
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(baba_is_you)
#endif()
