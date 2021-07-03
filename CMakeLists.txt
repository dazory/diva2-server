### diva2/test/zmq
#참고: https://www.kudryavka.me/?p=758

cmake_minimum_required(VERSION 3.8)     #cmake 최소 버전 요구 사양
project(diva2 VERSION 1.0.0)            #프로젝트명 버전
set(CMAKE_CXX_STANDARD 11)              # use this to globally use C++11 with in our project

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




