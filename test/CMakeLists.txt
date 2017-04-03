
set(SOURCE_FILES main.cpp vanilla_tests/VanillaOptionTest.cpp main.cpp ../src/vanilla/VanillaOption.cpp
        ../src/vanilla/VanillaOption.h
        ../src/payoff/PayOff.h ../src/payoff/PayOff.cpp ../src/payoff/PayOffDoubleDigital.cpp ../src/payoff/PayOffDoubleDigital.h)


add_executable(vanilla_tests ${SOURCE_FILES}
        vanilla_tests/VanillaOptionTest.cpp
        ../src/vanilla/VanillaOption.cpp ../src/vanilla/VanillaOption.h
        main.cpp
        ../src/payoff/PayOff.h ../src/payoff/PayOff.cpp ../src/payoff/PayOffDoubleDigital.cpp ../src/payoff/PayOffDoubleDigital.h)


add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

target_link_libraries(vanilla_tests gtest gtest_main)

