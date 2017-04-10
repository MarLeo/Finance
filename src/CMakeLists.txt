cmake_minimum_required(VERSION 3.7)
project(Finance)

set(SOURCE_FILES main.cpp
        vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h)

add_executable(Finance ${SOURCE_FILES} vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h)