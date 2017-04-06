set(SOURCE_FILES main.cpp
        vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h)

add_executable(Finance ${SOURCE_FILES} vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        payoff/PayOff.h payoff/PayOff.cpp
        payoff/PayOffDoubleDigital.cpp payoff/PayOffDoubleDigital.h
        template/Matrix.cpp template/Matrix.h)