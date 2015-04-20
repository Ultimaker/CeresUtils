cmake_minimum_required (VERSION 2.6)
project (CeresUtils)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FindBoost)

set(ceres_base ${ceres_base}
		include/Menu/Menu.h
		include/Menu/MenuFactory.h
		include/Menu/MenuOption.h
		include/Menu/MenuOptionByFunctionPointer.h
		include/StdOut.h
		include/StringUtils.h
		include/SystemUtils.h
		include/VectorUtils.h
		src/Menu/Menu.cpp
		src/Menu/MenuFactory.cpp
		src/Menu/MenuOption.cpp
		src/Menu/MenuOptionByFunctionPointer.cpp
		src/StdOut.cpp
		src/StringUtils.cpp
		src/SystemUtils.cpp
		src/VectorUtils.cpp
)

find_package(Boost COMPONENTS system REQUIRED)
if(NOT Boost_FOUND)
	message("Warning: Boost libraries not found")
endif(NOT Boost_FOUND)

message("${Boost_SYSTEM_LIBRARY}")

include_directories(include)
include_directories(${Boost_INCLUDE_DIR})
link_libraries(${Boost_SYSTEM_LIBRARY})
link_libraries(stdc++)

set(CMAKE_CXX_FLAGS "-O2 -g -std=c++11 -Wall")
set(CMAKE_LD_FLAGS "-S")

set(CERESUTILS_VERSION 0.1.0)

add_library(CeresUtils SHARED
	${ceres_base}
)

target_include_directories(CeresUtils PUBLIC
	    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
   		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/CeresUtils>)

install(TARGETS CeresUtils
		EXPORT CeresUtils-targets
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/
		DESTINATION include/CeresUtils
		FILES_MATCHING PATTERN "*.h")
install(EXPORT CeresUtils-targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CeresUtils
)

configure_package_config_file(CeresUtilsConfig.cmake.in ${CMAKE_BINARY_DIR}/CeresUtilsConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CeresUtils)
write_basic_package_version_file(${CMAKE_BINARY_DIR}/CeresUtilsConfigVersion.cmake VERSION ${CERESUTILS_VERSION} COMPATIBILITY SameMajorVersion)

install(FILES
    ${CMAKE_BINARY_DIR}/CeresUtilsConfig.cmake
    ${CMAKE_BINARY_DIR}/CeresUtilsConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CeresUtils
)

FIND_PACKAGE(Doxygen)

IF (DOXYGEN_FOUND)

SET(DOXYGEN_INPUT Doxyfile)
SET(DOXYGEN_OUTPUT doc)

ADD_CUSTOM_COMMAND(
  OUTPUT ${DOXYGEN_OUTPUT}
  COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
  COMMAND ${CMAKE_COMMAND} -E echo "Done."
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${DOXYGEN_INPUT}
)

ADD_CUSTOM_TARGET(docs ALL DEPENDS ${DOXYGEN_OUTPUT})

ENDIF (DOXYGEN_FOUND)
