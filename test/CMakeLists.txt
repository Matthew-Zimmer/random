target_sources(random_test PUBLIC 
    number.cpp)

find_package(ordeal REQUIRED)
target_link_libraries(random_test PUBLIC ordeal random)
