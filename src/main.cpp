#include <iostream>
#include "european/headers/Price.h"
#include "utils/header/util.h"
#include "lookback/body/LookbackOption.h"
#include <chrono>
#include <thread>

unsigned int __stdcall asianArithmeticCall(void *data);

unsigned int __stdcall asianArithmeticPut(void *data);

unsigned int __stdcall asianGeometricCall(void *data);

unsigned int __stdcall asianGeometricPut(void *data);

unsigned int __stdcall europeanCall(void *data);

unsigned int __stdcall europeanPut(void *data);

#define NUM_THREADS  6

int main(int argc, char *argv[]) {

    /*
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // create threads
    HANDLE handle[NUM_THREADS];

    handle[0] = (HANDLE) _beginthreadex(0, 0, &asianArithmeticCall, 0, 0, 0);

    handle[1] = (HANDLE) _beginthreadex(0, 0, &europeanCall, 0, 0, 0);

    handle[2] = (HANDLE) _beginthreadex(0, 0, &europeanPut, 0, 0, 0);

    handle[3] = (HANDLE) _beginthreadex(0, 0, &asianArithmeticPut, 0, 0, 0);

    //handle[4] = (HANDLE) _beginthreadex(0, 0,  &asianGeometricCall, 0, 0, 0);

    //handle[5] = (HANDLE) _beginthreadex(0, 0,  &asianGeometricPut, 0, 0, 0);


    // WaitForSingleObject(handle[0], INFINITE);
    // WaitForSingleObject(handle[1], INFINITE);
    // WaitForSingleObject(handle[2], INFINITE);
    // WaitForSingleObject(handle[3], INFINITE);
    //WaitForSingleObject(handle[4], INFINITE);
    //WaitForSingleObject(handle[5], INFINITE);

    // WaitForMultipleObjectsEx(6, handle, true, INFINITE, true);
    WaitForMultipleObjects(4, handle, true, INFINITE);


    CloseHandle(handle[0]);
    CloseHandle(handle[1]);
    CloseHandle(handle[2]);
    CloseHandle(handle[3]);
    CloseHandle(handle[4]);
    //CloseHandle(handle[5]);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Elapsed total  Time: " << elapsed_seconds.count() << std::endl;
     */

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int num_sims = 10000;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double dividend = 0.05;
    double volatility = 0.2;
    double pas = 500.0;
    double maturity = 1.0;

    EuropeanLookback call(spot, rate, dividend, volatility, maturity);
    EuropeanLookback put(spot, rate, dividend, volatility, maturity);


    double call_price = call(num_sims, pas, OptionType::CALL);
    double put_price = put(num_sims, pas, OptionType::PUT);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European Lookback call price: " << call_price << std::endl;

    std::cout << "European Lookback put price: " << put_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

unsigned int europeanPut(void *data) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int num_sims = 10000;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double dividend = 0.05;
    double volatility = 0.2;
    double pas = 500.0;
    double maturity = 1.0;

    European put(strike, spot, rate, dividend, volatility, maturity);


    double put_price = put(num_sims, pas, OptionType::PUT);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European put price: " << put_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

unsigned int europeanCall(void *data) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int num_sims = 10000;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double dividend = 0.05;
    double volatility = 0.2;
    double pas = 500.0;
    double maturity = 1.0;

    European call(strike, spot, rate, dividend, volatility, maturity);

    double call_price = call(num_sims, pas, OptionType::CALL);


    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European call price: " << call_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

unsigned int asianArithmeticCall(void *data) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // First we create the parameter list
    // Note that you could easily modify this code to input the parameters
    // either from the command line or via a file
    unsigned num_sims = 100000;   // Number of simulated asset paths
    unsigned num_intervals = 250;  // Number of intervals for the asset path to be sampled
    double spot = 30.0;  // Option price
    double strike = 29.0;  // Strike price
    double rate = 0.08;   // Risk-free rate (5%)
    double volatility = 0.3;    // Volatility of the underlying (20%)
    double maturity = 1.00;    // One year until expiry
    std::vector<double> spot_prices(num_intervals, spot);  // The vector of spot prices

    // Create the PayOff objects
    PayOff *pay_off_call = new PayOffCall(strike);

    // Create the AsianOption objects
    AsianOptionArithmetic asian(spot, strike, rate, volatility, maturity,
                                pay_off_call);                        //asian(pay_off_call);

    // Update the spot price vector with correct
    // spot price paths at constant intervals
    double discount_payoff_avg = update_spot_prices(num_sims, rate, volatility, maturity, spot_prices,
                                                    (AsianOption &) asian);

    delete pay_off_call;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Arithmetic Asian call Price: " << discount_payoff_avg << std::endl;
    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

unsigned int __stdcall asianArithmeticPut(void *data) {

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // First we create the parameter list
    // Note that you could easily modify this code to input the parameters
    // either from the command line or via a file
    unsigned num_sims = 100000;   // Number of simulated asset paths
    unsigned num_intervals = 250;  // Number of intervals for the asset path to be sampled
    double spot = 30.0;  // Option price
    double strike = 29.0;  // Strike price
    double rate = 0.08;   // Risk-free rate (5%)
    double volatility = 0.3;    // Volatility of the underlying (20%)
    double maturity = 1.00;    // One year until expiry
    std::vector<double> spot_prices(num_intervals, spot);  // The vector of spot prices

    // Create the PayOff objects
    PayOff *pay_off_put = new PayOffPut(strike);

    // Create the AsianOption objects
    AsianOptionArithmetic asian(spot, strike, rate, volatility, maturity,
                                pay_off_put);                        //asian(pay_off_call);

    // Update the spot price vector with correct
    // spot price paths at constant intervals
    double discount_payoff_avg = update_spot_prices(num_sims, rate, volatility, maturity, spot_prices,
                                                    (AsianOption &) asian);

    delete pay_off_put;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Arithmetic Asian put Price: " << discount_payoff_avg << std::endl;
    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;


    return 0;
}

unsigned int __stdcall asianGeometricCall(void *data) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // First we create the parameter list
    // Note that you could easily modify this code to input the parameters
    // either from the command line or via a file
    unsigned num_sims = 100000;   // Number of simulated asset paths
    unsigned num_intervals = 250;  // Number of intervals for the asset path to be sampled
    double spot = 30.0;  // Option price
    double strike = 29.0;  // Strike price
    double rate = 0.08;   // Risk-free rate (5%)
    double volatility = 0.3;    // Volatility of the underlying (20%)
    double maturity = 1.00;    // One year until expiry
    std::vector<double> spot_prices(num_intervals, spot);  // The vector of spot prices

    // Create the PayOff objects
    PayOff *pay_off_call = new PayOffCall(strike);

    // Create the AsianOption objects
    AsianOptionGeometric asian(spot, strike, rate, volatility, maturity,
                               pay_off_call);                        //asian(pay_off_call);

    // Update the spot price vector with correct
    // spot price paths at constant intervals
    double discount_payoff_avg = update_spot_prices(num_sims, rate, volatility, maturity, spot_prices,
                                                    (AsianOption &) asian);

    delete pay_off_call;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Geometric Asian call Price: " << discount_payoff_avg << std::endl;
    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

unsigned int __stdcall asianGeometricPut(void *data) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // First we create the parameter list
    // Note that you could easily modify this code to input the parameters
    // either from the command line or via a file
    unsigned num_sims = 100000;   // Number of simulated asset paths
    unsigned num_intervals = 250;  // Number of intervals for the asset path to be sampled
    double spot = 30.0;  // Option price
    double strike = 29.0;  // Strike price
    double rate = 0.08;   // Risk-free rate (5%)
    double volatility = 0.3;    // Volatility of the underlying (20%)
    double maturity = 1.00;    // One year until expiry
    std::vector<double> spot_prices(num_intervals, spot);  // The vector of spot prices

    // Create the PayOff objects
    PayOff *pay_off_put = new PayOffPut(strike);

    // Create the AsianOption objects
    AsianOptionGeometric asian(spot, strike, rate, volatility, maturity,
                               pay_off_put);                        //asian(pay_off_call);

    // Update the spot price vector with correct
    // spot price paths at constant intervals
    double discount_payoff_avg = update_spot_prices(num_sims, rate, volatility, maturity, spot_prices,
                                                    (AsianOption &) asian);

    delete pay_off_put;
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Geometric Asian put Price: " << discount_payoff_avg << std::endl;
    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

    return 0;
}

