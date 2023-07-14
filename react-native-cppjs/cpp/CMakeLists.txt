cmake_minimum_required(VERSION 3.4.1)
project(react_native_cppjs VERSION "1.0.0")
set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(../node_modules/react-native-embind/cpp ${CMAKE_CURRENT_BINARY_DIR}/react-native-embind)
file(GLOB_RECURSE SRC_FILES ../../../native/*.cpp)
add_library(react_native_cppjs SHARED ./src/JSI_module.cpp ../../react-native-embind/cpp/src/bind.cpp ../../react-native/ReactCommon/jsi/jsi/jsi.cpp ${SRC_FILES})

#target_link_libraries(react_native_cppjs
#    react_native_embind
#    )

target_include_directories(react_native_cppjs PUBLIC ./src ../../react-native-embind/cpp/src ../../react-native/ReactCommon/jsi ../../../native)
