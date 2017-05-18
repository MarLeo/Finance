cmake_minimum_required(VERSION 3.7)
project(Finance)

set(SOURCE_FILES main.cpp
        vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h european/body/BoxMuller.cpp european/headers/BoxMuller.h european/body/Price.cpp european/headers/Price.h european/headers/OptionType.h european/headers/ExerciseType.h)

add_executable(Finance ${SOURCE_FILES} vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h european/body/BoxMuller.cpp european/headers/BoxMuller.h european/body/Price.cpp european/headers/Price.h european/headers/OptionType.h european/headers/ExerciseType.h)


#add_subdirectory(eigen/eigen/)

#include_directories(eigen/eigen/Eigen)

#include_directories(eigen/eigen/Eigen/src)
