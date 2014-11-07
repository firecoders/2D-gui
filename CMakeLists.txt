cmake_minimum_required ( VERSION 2.6 )
project ( 2D_GUI )
include ( ExternalProject )

# Output compiled files in root directory
set ( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/.. )
set ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/.. )

# Use C++11 standard
if ( CMAKE_CXX_COMPILER MATCHES ".*clang" )
    set ( CMAKE_COMPILER_IS_CLANG )
endif ( CMAKE_CXX_COMPILER MATCHES ".*clang" )

if ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG )
    list ( APPEND CMAKE_CXX_FLAGS "-std=c++11" )
endif ( CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG )

# Add compiler options
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )
set ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O1" )

# Store external dependencies in build/external/
set ( EXTERNALS_PREFIX ${PROJECT_BINARY_DIR}/external CACHE FILEPATH "Installation Path" )
set ( EXTERNALS_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNALS_PREFIX} )

# Add the eventsystem
ExternalProject_Add ( EVENTSYSTEM
    PREFIX ${EXTERNALS_PREFIX}
    URL https://github.com/firecoders/eventsystem/archive/v0.2.1.tar.gz
    URL_HASH SHA256=de17ea1d0bf0b43652edc9bc84ae4d08bc92388807214c706d4ca588287c8846
    DOWNLOAD_NAME eventsystem-v0.2.1.tar.gz
    CMAKE_ARGS ${EXTERNALS_CMAKE_ARGS}
)

# Import libeventsystem.a
add_library ( libeventsystem STATIC IMPORTED )
set_target_properties ( libeventsystem PROPERTIES IMPORTED_LOCATION ${EXTERNALS_PREFIX}/lib/libeventsystem.a )
add_dependencies ( libeventsystem EVENTSYSTEM )

# Include headers from inc
include_directories ( ${CMAKE_SOURCE_DIR}/inc )

# Add the source directory
add_subdirectory ( ${CMAKE_SOURCE_DIR}/src )

file ( GLOB_RECURSE 2D_GUI_HEADERS ${CMAKE_SOURCE_DIR}/inc *.(h|hpp) )
install ( FILES ${2D_GUI_HEADERS} DESTINATION include )
