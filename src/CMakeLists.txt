cmake_minimum_required(VERSION 3.7)
project(Finance)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package( Threads REQUIRED )
set(SOURCE_FILES main.cpp
        vanilla/VanillaOption.cpp vanilla/VanillaOption.h

        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h utils/body/BoxMuller.cpp utils/header/BoxMuller.h european/body/Price.cpp european/headers/Price.h utils/header/OptionType.h
        payoff/Payoff.h payoff/Payoff.cpp
        asian/Asian.cpp asian/Asian.h
        utils/header/util.h
        lookback/body/LookbackOption.cpp lookback/header/LookbackOption.h barrier/body/BarrierOption.cpp barrier/header/BarrierOption.h)

add_executable(Finance ${SOURCE_FILES} vanilla/VanillaOption.cpp vanilla/VanillaOption.h
        template/Matrix.cpp template/Matrix.h functor/functor_pointer.cpp functor/functor_pointer.h utils/body/BoxMuller.cpp utils/header/BoxMuller.h european/body/Price.cpp european/headers/Price.h utils/header/OptionType.h
        payoff/Payoff.h payoff/Payoff.cpp
        asian/Asian.cpp asian/Asian.h
        utils/header/util.h lookback/body/LookbackOption.cpp lookback/header/LookbackOption.h barrier/body/BarrierOption.cpp barrier/header/BarrierOption.h)


target_link_libraries(Finance Threads::Threads)

#add_subdirectory(eigen/eigen/)

#include_directories(eigen/eigen/Eigen)

#include_directories(eigen/eigen/Eigen/src)
