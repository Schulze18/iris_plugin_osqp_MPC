cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)
include_directories(${roscpp_INCLUDE_DIRS})
include_directories(${std_msgs_INCLUDE_DIRS})

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")


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
)


# Build our plugin
add_library(iris_plugin_osqp_mpc SHARED src/iris_plugin_osqp_mpc.cc ${osqp_src} ${osqp_headers})
target_link_libraries(iris_plugin_osqp_mpc ${GAZEBO_libraries} ${roscpp_LIBRARIES})
