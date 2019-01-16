cmake_minimum_required(VERSION 3.12)
project(prog2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(prog2 main.cpp Searcher.h DepthSearcher.h Node.h Matrix.cpp Matrix.h Searchable.h MatrixReader.cpp MatrixReader.h BreadthSearcher.h BestFirstSearcher.h AStarSearcher.h GeneralSearcher.h GeneralServer.h GeneralServer.cpp MyParallelServer.h MyParallelServer.cpp FileCacheManager.h FileCacheManager.cpp illegal_state_exception.h MySerialServer.h MySerialServer.cpp MyTestClientHandler.h MyTestClientHandler.cpp StringReverser.h StringReverser.cpp timeout_exception.h timeout_exception.cpp)