### diva2/test/zmq
#참고: https://www.kudryavka.me/?p=758

cmake_minimum_required(VERSION 3.8)     #cmake 최소 버전 요구 사양
project(diva2 VERSION 1.0.0)            #프로젝트명 버전
set(CMAKE_CXX_STANDARD 11)              # use this to globally use C++11 with in our project

# ## Use pkg-config support 
# find_package(PkgConfig)                 # load in pkg-config support
# pkg_check_modules(PC_ZeroMQ QUIET zmq)  # use pkg-config to get hints for 0mq locations

# ## Use zmq library
# if(NOT PKG_CONFIG_FOUND)
#     INCLUDE(FindPkgConfig)
# endif()
# PKG_CHECK_MODULES(PC_ZEROMQ "libzmq")
# find_path(ZeroMQ_INCLUDE_DIR            # use the hint from above to find where 'zmq.hpp' is located
#         NAMES zmq.hpp
#         PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
# )
# find_library(ZeroMQ_LIBRARY             # use the hint from about to find the location of libzmq
#         NAMES zmq
#         PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
# )
# FIND_PATH(ZEROMQ_INCLUDE_DIRS
#     NAMES zmq.hpp
#     HINTS ${PC_ZEROMQ_INCLUDE_DIR}
#     ${CMAKE_INSTALL_PREFIX}/include
#     PATHS
#     /usr/local/include
#     /usr/include
# )

# FIND_LIBRARY(ZEROMQ_LIBRARIES
#     NAMES zmq libzmq ${ZEROMQ_LIBRARY_NAME}
#     HINTS ${PC_ZEROMQ_LIBDIR}
#     ${CMAKE_INSTALL_PREFIX}/lib
#     ${CMAKE_INSTALL_PREFIX}/lib64
#     PATHS
#     ${ZEROMQ_INCLUDE_DIRS}/../lib
#     /usr/local/lib
#     /usr/lib
# )
# INCLUDE(FindPackageHandleStandardArgs)
# FIND_PACKAGE_HANDLE_STANDARD_ARGS(ZeroMQ DEFAULT_MSG ZEROMQ_LIBRARIES ZEROMQ_INCLUDE_DIRS)
# MARK_AS_ADVANCED(ZEROMQ_LIBRARIES ZEROMQ_INCLUDE_DIRS)

# if (ZEROMQ_FOUND AND NOT TARGET ZEROMQ::ZEROMQ)
#   add_library(ZeroMQ::ZeroMQ INTERFACE IMPORTED)
#   set_target_properties(ZeroMQ::ZeroMQ PROPERTIES
#     INTERFACE_INCLUDE_DIRECTORIES "${ZEROMQ_INCLUDE_DIRS}"
#     INTERFACE_LINK_LIBRARIES "${ZEROMQ_LIBRARIES}"
#   )
# endif()


## use thread
find_package( Threads )
link_libraries(pthread)

## use libpqxx
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
set(PQXX /usr/local/include/pqxx)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

# 실행파일 만들기
set(SOURCE_MAIN main.cpp)
add_executable(diva2 ${SOURCE_MAIN})                           # 생성할 실행파일 이름 지정
target_include_directories(diva2 PUBLIC)  # add the include directory to our compile directives
target_link_libraries(diva2 PUBLIC)           # at the 0mq library to our link directive

# 서브 디렉토리에 있는 cmakeFiles을 실행시켜줌
add_subdirectory(DBStoring)
add_subdirectory(TimeSynchronization)




