# CMakeList.txt: проект CMake для Block3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("runUnitTests")
set(CMAKE_CXX_STANDARD 20) 

# Добавьте источник в исполняемый файл этого проекта.
include(GoogleTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(runUnitTests test.cpp fileworker.h fileworker.cpp ext_sort.h ext_sort.cpp )

#if (CMAKE_VERSION VERSION_GREATER 3.12)
  #set_property(TARGET runUnitTests PROPERTY CXX_STANDARD 20)
#endif()

target_link_libraries(runUnitTests GTest::gtest_main)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
