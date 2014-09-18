# Files needed in lib2D-gui.a
file ( GLOB_RECURSE 2D_GUI_LIBRARY_SRC ${CMAKE_SOURCE_DIR} *.cpp )

# Create lib2D-gui and target alias
add_library ( 2D-gui ${2D_GUI_LIBRARY_SRC} )
add_custom_target ( lib2D-gui.a DEPENDS 2D-gui )
install ( TARGETS 2D-gui ARCHIVE DESTINATION lib )

# Use eventsystem headers
include_directories ( ${EXTERNALS_PREFIX}/src/EVENTSYSTEM/inc )
