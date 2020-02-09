cmake_minimum_required( VERSION 3.0 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( ciSyphon2Vr )

get_filename_component( CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cinder_master" ABSOLUTE )
get_filename_component( APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

FILE(GLOB APP_SOURCES ${APP_PATH}/src/*.cpp ${APP_PATH}/src/*/*.cpp)

ci_make_app(
	SOURCES     ${APP_SOURCES}
	INCLUDES	${APP_PATH}/include
	CINDER_PATH ${CINDER_PATH}
	BLOCKS Cinder-Syphon Cinder-VR
)
