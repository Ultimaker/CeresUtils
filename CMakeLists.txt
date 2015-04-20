cmake_minimum_required (VERSION 2.6)
project (CeresUtils)

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

include_directories(include)
link_libraries(stdc++)

set(CMAKE_CXX_FLAGS "-O2 -g -std=c++11 -Wall")
set(CMAKE_LD_FLAGS "-S")

add_library(CeresUtils SHARED
	${ceres_base}
)

install(TARGETS CeresUtils
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib)
install(DIRECTORY include/
		DESTINATION include/CeresUtils
		FILES_MATCHING PATTERN "*.h")

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
