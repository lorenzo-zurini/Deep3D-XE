# Deep3D-XE. cpp/game: the game (translated from its decompiled Java);
# cpp/m3g: the JSR-184 API; cpp/jrt: the Java semantics they rely on;
# cpp/midp, cpp/deep3d: the phone APIs and the PC layer; native/m3g: Nokia's
# M3G engine.
cmake_minimum_required(VERSION 3.20)
project(Deep3D-XE C CXX ASM)
if(WIN32)
    enable_language(RC)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(M3G ${ROOT}/native/m3g)

find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
if(WIN32)
    # MSYS2 (UCRT64): the engine's contexts are WGL's (native/m3g/win32), and
    # windows.h stays lean (its "interface" macro would break the engine)
    pkg_check_modules(DEPS REQUIRED IMPORTED_TARGET glfw3 sdl3 fluidsynth libzip libpng zlib freetype2)
    set(PLATFORM_LIBS opengl32 gdi32 comdlg32)
    add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX)
elseif(APPLE)
    # Homebrew: the engine's contexts are CGL's (native/m3g/macos), on Apple's
    # OpenGL 2.1 compatibility context; <GL/gl.h> is native/m3g/macos/include's
    # (no fontconfig: the FPS counter's font is the system's own)
    pkg_check_modules(DEPS REQUIRED IMPORTED_TARGET glfw3 sdl3 fluidsynth libzip libpng zlib freetype2)
    # the AMR sound effects decoded in the game (an app has no ffmpeg to call), linked statically
    pkg_check_modules(AMRNB QUIET opencore-amrnb)
    find_library(AMRNB_STATIC NAMES libopencore-amrnb.a HINTS ${AMRNB_LIBRARY_DIRS})
    find_library(OPENGL_FRAMEWORK OpenGL REQUIRED)
    find_library(COREFOUNDATION_FRAMEWORK CoreFoundation REQUIRED)
    set(PLATFORM_LIBS ${OPENGL_FRAMEWORK} ${COREFOUNDATION_FRAMEWORK})
    add_compile_definitions(GL_SILENCE_DEPRECATION)
else()
    pkg_check_modules(DEPS REQUIRED IMPORTED_TARGET glfw3 sdl3 fluidsynth libzip libpng zlib freetype2 fontconfig)
    find_package(OpenGL REQUIRED COMPONENTS OpenGL GLX EGL)
    find_package(X11 REQUIRED)
    set(PLATFORM_LIBS OpenGL::OpenGL OpenGL::GLX OpenGL::EGL ${X11_LIBRARIES})
endif()

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
if(WIN32)
    # Khronos's EGL headers, after the engine's wrappers (their #include_next)
    target_include_directories(m3gengine PRIVATE ${M3G}/win32/include)
elseif(APPLE)
    # <GL/gl.h> first; Khronos's EGL headers after the engine's wrappers
    target_include_directories(m3gengine BEFORE PRIVATE ${M3G}/macos/include)
    target_include_directories(m3gengine PRIVATE ${M3G}/win32/include)
    # the engine's framebuffer 0 is its surface's framebuffer object (macos/include/GL/gl.h)
    target_compile_definitions(m3gengine PRIVATE DEEP3D_CGL_SURFACES)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(m3gengine PRIVATE ${M3G_FLAGS} $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)
else()
    # clang has no -fpermissive: the C++ glue's C-isms as warnings (silenced by -w)
    target_compile_options(m3gengine PRIVATE ${M3G_FLAGS} $<$<COMPILE_LANGUAGE:CXX>:-Wno-error=c++11-narrowing>)
endif()
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
if(APPLE)
    target_include_directories(deep3d BEFORE PRIVATE ${M3G}/macos/include)
endif()
target_include_directories(deep3d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/jni ${M3G}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/m3g ${CMAKE_CURRENT_SOURCE_DIR}/game)
target_compile_options(deep3d PRIVATE ${JAVA_FLAGS} -Wall -Wno-unused -Wno-unused-variable -Wno-unused-but-set-variable
    -Wno-parentheses -Wno-sign-compare -Wno-dangling-else)
target_link_libraries(deep3d PRIVATE m3gengine PkgConfig::DEPS ${PLATFORM_LIBS} Threads::Threads)
if(APPLE)
    if(AMRNB_STATIC)
        target_compile_definitions(deep3d PRIVATE DEEP3D_OPENCORE_AMR)
        target_include_directories(deep3d PRIVATE ${AMRNB_INCLUDE_DIRS})
        target_link_libraries(deep3d PRIVATE ${AMRNB_STATIC})
    else()
        message(WARNING "opencore-amrnb not found: sound effects need ffmpeg on the PATH")
    endif()
endif()
set_target_properties(deep3d PROPERTIES OUTPUT_NAME Deep3D-XE RUNTIME_OUTPUT_DIRECTORY ${ROOT}/build/bin)
if(WIN32)
    # a windowed program (main.cpp attaches to a terminal it was started from),
    # with its icon and manifest (UTF-8 paths, Windows 10's behaviour)
    target_sources(deep3d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/win32/deep3d.rc)
    set_target_properties(deep3d PROPERTIES WIN32_EXECUTABLE TRUE)
    target_link_options(deep3d PRIVATE -static-libgcc -static-libstdc++)
endif()
