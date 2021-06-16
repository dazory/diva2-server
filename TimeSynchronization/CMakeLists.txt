# cmake_minimum_required(VERSION 3.10)

## use pkg-config support 
find_package(PkgConfig)                 # load in pkg-config support
pkg_check_modules(PC_ZeroMQ QUIET zmq)  # use pkg-config to get hints for 0mq locations

## use zmq library
find_path(ZeroMQ_INCLUDE_DIR            # use the hint from above to find where 'zmq.hpp' is located
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
)
find_library(ZeroMQ_LIBRARY             # use the hint from about to find the location of libzmq
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
)


## use thread
find_package( Threads )

## Use json
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

# ##use opencv
# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS}) 

# ## use mscl
# find_library(MSCL_LIB_PATH NAMES libmscl.so PATHS "/usr/share/c++-mscl" DOC "MSCL Library" NO_DEFAULT_PATH)
# find_library(BOOST_LIB_PATH NAMES libboost_chrono.so PATHS "/usr/share/c++-mscl/Boost/lib" NO_DEFAULT_PATH)
# set(MSCL_INC_PATH "/usr/share/c++-mscl/source")
# set(BOOST_INC_PATH "/usr/share/c++-mscl/Boost/include")
# set(MSCL_LIB "/usr/share/c++-mscl")
# add_definitions(-std=c++11)
# include_directories(/usr/share/c++-mscl/source /usr/share/c++-mscl/Boost/include /usr/include)
# link_directories(/usr/share/c++-mscl)
# link_libraries(mscl pthread GL GLU glut GLEW glfw X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor m)
# add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

## use libpqxx
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
set(PQXX /usr/local/include/pqxx)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

# ADD_EXECUTABLE(storingraw ${CLIENT_SRC_LIST} ${PROTO_SRCS} ${PROTO_HDRS}  )
SET(CLIENT_SRC_LIST main.cpp readfiles.cpp indexandtimes.cpp makejson.cpp makejsonThread.cpp)
add_executable(timesynchronization ${CLIENT_SRC_LIST} ${PROTO_SRCS} ${PROTO_HDRS}  )

target_include_directories(timesynchronization PUBLIC ${ZeroMQ_INCLUDE_DIR})  # add the include directory to our compile directives
target_link_libraries(timesynchronization ${PROTOBUF_LIBRARIES} ${ZeroMQ_LIBRARY} ${PQXX_LIB} ${PQ_LIB}
     ) 