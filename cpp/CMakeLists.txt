# Deep3D-XE. cpp/game: the game (translated from its decompiled Java);
# cpp/m3g: the JSR-184 API; cpp/jrt: the Java semantics they rely on;
# cpp/midp, cpp/deep3d: the phone APIs and the PC layer; native/m3g: Nokia's
# M3G engine.
cmake_minimum_required(VERSION 3.20)
project(Deep3D-XE C CXX ASM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(M3G ${ROOT}/native/m3g)

find_package(PkgConfig REQUIRED)
pkg_check_modules(DEPS REQUIRED IMPORTED_TARGET glfw3 sdl3 fluidsynth libzip libpng zlib freetype2 fontconfig)
find_package(OpenGL REQUIRED COMPONENTS OpenGL GLX EGL)
find_package(X11 REQUIRED)
find_package(Threads REQUIRED)

# Java semantics: wrapping integers, no fused multiply-add (Java's float
# results bit for bit)
set(JAVA_FLAGS -fwrapv -ffp-contract=off -fno-strict-aliasing)

# --- the M3G engine (Nokia's JSR-184 reference, EPL) and its glue ---
# the Java build's flags for the engine (native/build-m3g.sh), whatever the build type
set(M3G_FLAGS -O2 -w -ffp-contract=off -DM3G_TARGET_ANDROID -DM3G_GL_ES_1_1
    $<$<COMPILE_LANGUAGE:C>:-Wno-error=int-conversion -Wno-error=incompatible-pointer-types>)
add_library(m3gengine STATIC
    ${M3G}/src/m3g_core.c
    ${M3G}/linux/m3g_linux.cpp
    ${M3G}/linux/deep3d_egl.cpp
    ${M3G}/linux/deep3d_remaster.cpp
    ${M3G}/src/m3g_android_gl.cpp
    ${M3G}/CSynchronization.cpp
    ${M3G}/m3g_android_java_api.cpp)
target_include_directories(m3gengine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/jni ${M3G}/linux/include ${M3G}/inc
    ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(m3gengine PRIVATE ${M3G_FLAGS} $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)
set_target_properties(m3gengine PROPERTIES C_STANDARD 11)

# --- the game ---
file(GLOB JRT_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/jrt/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/jni/*.cpp)
file(GLOB RUNTIME_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/midp/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/m3g/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deep3d/*.cpp)
file(GLOB GAME_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/game/*.cpp)

# Gervill's emergency soundbank, built in (midp/media.cpp)
set(GERVILL_EMG ${CMAKE_CURRENT_SOURCE_DIR}/midp/gervill_emg.S)
set_source_files_properties(${GERVILL_EMG} PROPERTIES
    COMPILE_OPTIONS "-I${CMAKE_CURRENT_SOURCE_DIR}/midp"
    OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/midp/gervill_emg.sf2)

add_executable(deep3d ${JRT_SRC} ${RUNTIME_SRC} ${GAME_SRC} ${GERVILL_EMG} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
# the commit, for demos' metadata: refreshed at every build, rewritten only when it changes
add_custom_target(build_info COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/build_info.sh ${CMAKE_BINARY_DIR}/build_info.h
                  BYPRODUCTS ${CMAKE_BINARY_DIR}/build_info.h)
add_dependencies(deep3d build_info)
target_include_directories(deep3d PRIVATE ${CMAKE_BINARY_DIR})
target_include_directories(deep3d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/jni ${M3G}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/m3g ${CMAKE_CURRENT_SOURCE_DIR}/game)
target_compile_options(deep3d PRIVATE ${JAVA_FLAGS} -Wall -Wno-unused -Wno-unused-variable -Wno-unused-but-set-variable
    -Wno-parentheses -Wno-sign-compare -Wno-dangling-else)
target_link_libraries(deep3d PRIVATE m3gengine PkgConfig::DEPS OpenGL::OpenGL OpenGL::GLX OpenGL::EGL ${X11_LIBRARIES}
    Threads::Threads)
set_target_properties(deep3d PROPERTIES OUTPUT_NAME Deep3D-XE RUNTIME_OUTPUT_DIRECTORY ${ROOT}/build/bin)
