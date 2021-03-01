CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

SET(PROJECT_BASE_NAME zmq_tester)
PROJECT(${PROJECT_BASE_NAME}_server)

SET(${PROJECT_NAME}_MAJOR_VERSION 01)
SET(${PROJECT_NAME}_MINOR_VERSION 00)
SET(${PROJECT_NAME}_PATCH_VERSION 00)
include(${CMAKE_SOURCE_DIR}/cmake/set_version_numbers.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# Set the build type to Release if none is specified
# Force it into Release if "None" is specified (needed to overrule dkpg_buildpackage)
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "None")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "None")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -pedantic -Wuninitialized")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 --coverage")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include(${CMAKE_SOURCE_DIR}/cmake/add_dependency.cmake)
add_dependency(DOOCS 19.05 server REQUIRED)
add_dependency(ChimeraTK-cppext REQUIRED)

include(${CMAKE_SOURCE_DIR}/cmake/enable_latest_cxx_support.cmake)

include_directories(${PROJECT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR} server_sources)

add_executable(${PROJECT_NAME} ${server_sources})
target_link_libraries(${PROJECT_NAME} ${DOOCS_LIBRARIES} ${ChimeraTK-cppext_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${ChimeraTK-cppext_CXX_FLAGS} ${DOOCS_CXX_FLAGS}")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${DOOCS_LINKER_FLAGS} ${ChimeraTK-cppext_LINKER_FLAGS}")


# Install the executable, the server_rpc file, the dmap file and the mapp file.
if("${CMAKE_INSTALL_PREFIX}" STREQUAL "/export/doocs/server")
  install(PROGRAMS ${PROJECT_BINARY_DIR}/${PROJECT_NAME} DESTINATION ${PROJECT_BASE_NAME}_server RENAME ${PROJECT_BASE_NAME}_server.dist)
endif()
