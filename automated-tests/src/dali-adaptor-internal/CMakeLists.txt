SET(PKG_NAME "dali-adaptor-internal")

SET(EXEC_NAME "tct-${PKG_NAME}-core")
SET(RPM_NAME "core-${PKG_NAME}-tests")

SET(CAPI_LIB "dali-adaptor-internal")

SET(TC_SOURCES
    utc-Dali-GifLoader.cpp
    utc-Dali-TiltSensor.cpp
    utc-Dali-CommandLineOptions.cpp
)

LIST(APPEND TC_SOURCES
    image-loaders.cpp
    ../dali-adaptor/dali-test-suite-utils/dali-test-suite-utils.cpp
    ../dali-adaptor/dali-test-suite-utils/test-application.cpp
    ../dali-adaptor/dali-test-suite-utils/test-gesture-manager.cpp
    ../dali-adaptor/dali-test-suite-utils/test-gl-abstraction.cpp
    ../dali-adaptor/dali-test-suite-utils/test-gl-sync-abstraction.cpp
    ../dali-adaptor/dali-test-suite-utils/test-native-image.cpp
    ../dali-adaptor/dali-test-suite-utils/test-platform-abstraction.cpp
    ../dali-adaptor/dali-test-suite-utils/test-render-controller.cpp
    ../dali-adaptor/dali-test-suite-utils/test-trace-call-stack.cpp
)

PKG_CHECK_MODULES(${CAPI_LIB} REQUIRED
    dali-core
    dali
)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0 -ggdb --coverage -Wall -Werror=return-type" )

# Shouldn't have to do this!
# But CMake's new auto-escape quote policy doesn't work right.
CMAKE_POLICY(SET CMP0005 OLD)
ADD_DEFINITIONS(-DTEST_IMAGE_DIR=\"\\\"${CMAKE_CURRENT_SOURCE_DIR}/../../images\\\"\" )


FOREACH(directory ${${CAPI_LIB}_LIBRARY_DIRS})
    SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -L${directory}")
ENDFOREACH(directory ${CAPI_LIB_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(
    ${${CAPI_LIB}_INCLUDE_DIRS}
    ../dali-adaptor/dali-test-suite-utils
    ../../../adaptors/tizen
    ../../../
)

ADD_EXECUTABLE(${EXEC_NAME} ${EXEC_NAME}.cpp ${TC_SOURCES})
TARGET_LINK_LIBRARIES(${EXEC_NAME}
    ${${CAPI_LIB}_LIBRARIES}
)

INSTALL(PROGRAMS ${EXEC_NAME}
    DESTINATION ${BIN_DIR}/${EXEC_NAME}
)