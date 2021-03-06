cmake_minimum_required(VERSION 3.7)
project(Finance)


set(SOURCE_FILES main.cpp tests/vanilla/VanillaOptionTest.cpp main.cpp ../src/vanilla/VanillaOption.cpp ../src/vanilla/VanillaOption.h
        ../src/template/Matrix.cpp ../src/template/Matrix.h tests/template/TemplateTest.cpp ../src/functor/functor_pointer.cpp ../src/functor/functor_pointer.h ../src/utils/body/BoxMuller.cpp ../src/utils/header/BoxMuller.h ../src/european/body/EuropeanOption.cpp ../src/european/headers/EuropeanOption.h ../src/utils/header/OptionType.h tests/european/EuropeanOptionTest.cpp
        ../src/lookback/body/LookbackOption.cpp ../src/lookback/header/LookbackOption.h tests/european_lookback/EuropeanLookback_Test.cpp ../src/barrier/body/BarrierOption.cpp ../src/barrier/header/BarrierOption.h)


add_executable(tests ${SOURCE_FILES}
        ../src/vanilla/VanillaOption.cpp ../src/vanilla/VanillaOption.h
        main.cpp
        tests/vanilla/VanillaOptionTest.cpp
        ../src/template/Matrix.cpp ../src/template/Matrix.h tests/template/TemplateTest.cpp ../src/functor/functor_pointer.cpp ../src/functor/functor_pointer.h
        ../src/utils/body/BoxMuller.cpp ../src/utils/header/BoxMuller.h
        ../src/european/body/EuropeanOption.cpp ../src/european/headers/EuropeanOption.h
        ../src/utils/header/OptionType.h tests/european/EuropeanOptionTest.cpp
        ../src/lookback/body/LookbackOption.cpp ../src/lookback/header/LookbackOption.h tests/european_lookback/EuropeanLookback_Test.cpp ../src/barrier/body/BarrierOption.cpp ../src/barrier/header/BarrierOption.h)


add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

target_link_libraries(tests gtest gtest_main)

