cmake_minimum_required(VERSION 3.16)

project(QT_BasicCalculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

# Source files for the main application
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    calculation_Function.h
    calculation_Function.cpp
)

# Main application executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QT_BasicCalculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(QT_BasicCalculator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QT_BasicCalculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QT_BasicCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Set properties for the main application
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QT_BasicCalculator)
endif()

set_target_properties(QT_BasicCalculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QT_BasicCalculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QT_BasicCalculator)
endif()

# Test executable definition
qt_add_executable(QT_BasicCalculatorTest
    test_calculation_Function.cpp
    calculation_Function.cpp
)

# Link test libraries
target_link_libraries(QT_BasicCalculatorTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

# Ensure the test executable uses the same settings
set_target_properties(QT_BasicCalculatorTest PROPERTIES
    MACOSX_BUNDLE FALSE
    WIN32_EXECUTABLE TRUE
)

# Include directories for tests (if needed)
target_include_directories(QT_BasicCalculatorTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
