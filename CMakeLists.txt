cmake_minimum_required(VERSION 2.8.3)
project(iris_plugin_osqp_mpc)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  gazebo
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES iris_plugin_osqp_mpc
#  CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  SYSTEM
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)


# Types for QDLDL
# ----------------------------------------------
if(DFLOAT)
  set(QDLDL_FLOAT_TYPE "float")
else()
	set(QDLDL_FLOAT_TYPE "double")
endif()

if(DLONG)
  set(QDLDL_INT_TYPE "long long")
else()
	set(QDLDL_INT_TYPE "int")
endif()

# boolean type is always unsigned char for
# now, since _Bool does not exist in C89
set(QDLDL_BOOL_TYPE "unsigned char")


# Include header directory
# ----------------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Set sources
# ----------------------------------------------
set(
    osqp_src
    src/osqp/auxil.c
    src/osqp/lin_alg.c
    src/osqp/osqp.c
    src/osqp/proj.c
    src/osqp/qdldl.c
    src/osqp/qdldl_interface.c
    src/osqp/scaling.c
    src/osqp/util.c
    src/interface_osqp_ros_mpc.cc
)

set(
    osqp_headers
    include/auxil.h
    include/constants.h
    include/glob_opts.h
    include/osqp_configure.h
    include/lin_alg.h
    include/osqp.h
    include/proj.h
    include/qdldl.h
    include/qdldl_interface.h
    include/qdldl_types.h
    include/scaling.h
    include/types.h
    include/util.h
    include/workspace.h
    include/interface_osqp_ros_mpc.h
    include/matrices_mpc.h
)

# Build our plugin
add_library(iris_plugin_osqp_mpc SHARED src/iris_plugin_osqp_mpc.cc ${osqp_src})#${osqp_headers})
#add_executable(iris_plugin_osqp_mpc src/iris_plugin_osqp_mpc.cc ${osqp_src})
target_link_libraries(iris_plugin_osqp_mpc ${catkin_LIBRARIES})
#add_dependencies(iris_plugin_osqp_mpc iris_plugin_osqp_mpc_generate_messages_cpp)
