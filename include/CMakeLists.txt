target_include_directories(random PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> 
	$<INSTALL_INTERFACE:include/random>)

target_include_directories(random_test PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

set(headers 
	random.hpp)

install(FILES ${headers} DESTINATION include/random)
