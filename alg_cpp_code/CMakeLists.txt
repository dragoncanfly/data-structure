cmake_minimum_required(VERSION 3.10)

#project name
PROJECT(algorithm_data_structure)
#head file path
INCLUDE_DIRECTORIES(
	${PEOJECT_SOURCE_DIR}/inc/
)

#source directories
#AUX_SOURCE_DIRECTORY(src)

#set environment variable
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#add executable file
#ADD_EXECUTABLE()

#add link library
#TARGET_LINK_LIBRARIES()

ADD_SUBDIRECTORY(demo)
