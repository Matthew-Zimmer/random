cmake_minimum_required(VERSION 3.13)

project(random)

add_library(random INTERFACE)
add_library(random_test)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)

target_compile_features(random INTERFACE cxx_std_17)
target_compile_features(random_test PUBLIC cxx_std_17)

#Set(CMAKE_CXX_FLAGS "-Wall" "-Wextra")

install(TARGETS random EXPORT random DESTINATION lib/random)
install(EXPORT random DESTINATION lib/)
install(FILES random-config.cmake DESTINATION lib/random)

#libs
#find_Package(LIB REQUIRED)
#target_link_libraries(random PUBLIC LIB)