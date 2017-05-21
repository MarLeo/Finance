#include <iostream>
#include "european/headers/Price.h"
#include "utils/header/util.h"
#include "lookback/header/LookbackOption.h"
#include "barrier/header/BarrierOption.h"
#include <chrono>
#include <pthread.h>

void *asianArithmeticCall(void *);

void *asianArithmeticPut(void *);

void *asianGeometricCall(void *);

void *asianGeometricPut(void *);

//void *europeanCall(void *);

void *european(void *);

//void *europeanLookbackCall(void *);

void *europeanLookback(void *);

void *europeanBarrier(void *);

//void *europeanBarrierPut(void *);


typedef struct {
    int thread_id;
} thread_data;

//This function will be called from a thread

void *call_from_thread(void *args) {
    thread_data *my_data = (thread_data *) args;
    std::cout << "Launched by thread " << my_data->thread_id << std::endl;
    return NULL;
}

#define NUM_THREADS  6

static const int num_threads = 10;

int main(int argc, char *argv[]) {

    pthread_t threads[num_threads];


    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    pthread_create(&threads[0], NULL, european, NULL);
    pthread_create(&threads[1], NULL, europeanLookback, NULL);
    pthread_create(&threads[2], NULL, europeanBarrier, NULL);

    pthread_create(&threads[3], NULL, asianGeometricPut, NULL);
    pthread_create(&threads[4], NULL, asianGeometricCall, NULL);

    pthread_create(&threads[5], NULL, asianArithmeticCall, NULL);
    pthread_create(&threads[6], NULL, asianArithmeticPut, NULL);



    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    pthread_join(threads[4], NULL);
    pthread_join(threads[5], NULL);

    pthread_join(threads[6], NULL);


    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Elapsed total  Time: " << elapsed_seconds.count() << std::endl;


    return 0;
}


/*void *europeanBarrierPut(void *) {
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
    double barrier_put = 120.0;

    EuropeanBarrierOption put(strike, spot, rate, 0.0, volatility, maturity, barrier_put);

    double put_price = put(num_sims, pas, OptionType::PUT);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European Barrier put price: " << put_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

}
 */

void *europeanBarrier(void *) {
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
    double barrier_call = 20.0;
    double barrier_put = 120.0;


    EuropeanBarrierOption call(strike, spot, rate, 0.0, volatility, maturity, barrier_call);
    EuropeanBarrierOption put(strike, spot, rate, 0.0, volatility, maturity, barrier_put);


    double call_price = call(num_sims, pas, OptionType::CALL);
    double put_price = put(num_sims, pas, OptionType::PUT);


    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European Barrier call price: " << call_price << std::endl;

    std::cout << "European Barrier put price: " << put_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}

/*void *europeanLookbackCall(void *) {
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

    EuropeanLookback call(spot, rate, 0.0, volatility, maturity);

    double call_price = call(num_sims, pas, OptionType::CALL);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European Barrier call price: " << call_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}
 */


void *europeanLookback(void *) {
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

    EuropeanLookback call(spot, rate, 0.0, volatility, maturity);
    EuropeanLookback put(spot, rate, 0.0, volatility, maturity);

    double call_price = call(num_sims, pas, OptionType::CALL);

    double put_price = put(num_sims, pas, OptionType::PUT);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European Lookback call price: " << call_price << std::endl;

    std::cout << "European Lookback put price: " << put_price << std::endl;

    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}



/*
void *europeanPut(void *) {
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

    //return 0;
}
*/

void * european(void *) {
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
    European put(strike, spot, rate, dividend, volatility, maturity);

    double call_price = call(num_sims, pas, OptionType::CALL);
    double put_price = put(num_sims, pas, OptionType::PUT);


    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European call price: " << call_price << std::endl;

    std::cout << "European put price: " << put_price << std::endl;

    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

}

void *asianArithmeticCall(void *) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

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
    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}

void *asianArithmeticPut(void *) {

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
    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;

}

void *asianGeometricCall(void *) {
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
    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}

void * asianGeometricPut(void *) {
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
    //std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    std::cout << "\n" << std::endl;
}

