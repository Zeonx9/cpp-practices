cmake_minimum_required(VERSION 3.23)
project(cpp_trainings)

set(CMAKE_CXX_STANDARD 20)

add_executable(practice_1 practice_1/main.cpp practice_5/main.cpp)

add_executable(practice_2 practice_2/main.cpp)

add_executable(practice_3 practice_3/DynArray.h practice_3/main.cpp practice_3/MyStack.h)

add_executable(practice_4 practice_4/main.cpp practice_4/DynArray.h practice_4/Vec3d.h)

add_executable(practice_5 practice_5/include/Matrix.h practice_5/src/Matrix.cpp practice_5/include/Vector.h practice_5/src/Vector.cpp practice_5/main.cpp practice_5/src/SLESolver.cpp practice_5/include/SLESolver.h)