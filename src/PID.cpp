#include <limits>
#include <vector>
#include <iostream>
#include "PID.h"

using namespace std;
using std::vector;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    this->p_error = 0.0;
    this->i_error = 0.0;
    this->d_error = 0.0;

    this->pid = {Kp, Ki, Kd};
    this->dp = {0.01, 0.01, 0.01};
    this->choice = {false, false};
    this->tol = 0.0000001;
    this->twiddle = false;
    this->index = 0;
}


void PID::UpdateError(double cte) {

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;


    total_err += cte;
    /*
     * Twiddle part TODO work in progress
     * don't do it at every iteration
     */
    if (twiddle) {
        cout << "dp sum: " << dp[0] + dp[1] + dp[2] << endl;
        cout << "pid[0]: " << pid[0] << endl;
        cout << "pid[1]: " << pid[1] << endl;
        cout << "pid[2]: " << pid[2] << endl;
        if (dp[0] + dp[1] + dp[2] > tol) {

            // Got a better err
            // increase dp effect
            // try an other param ?
            if (total_err < best_err) {

                best_err = total_err;
                dp[index] *= 1.1;
                choice = {false, false};
                index = (index + 1) % 3;
            }
                // try a new param
            else if (!choice[0] && !choice[1]) {

                choice[0] = true;
                pid[index] += dp[index];
            }
                // choice 0 unsuccessful
                // try choice 1
            else if (choice[0] && !choice[1]) {

                choice[1] = true;
                pid[index] -= 2 * dp[index];
                // choice 0 and 1 unsuccessful
                // try an other param and reduce dp effect
            } else {

                pid[index] += dp[index];
                dp[index] *= 0.9;
                choice = {false, false};
                index = (index + 1) % 3;
            }
        }
        total_err = 0;
    }
}

double PID::TotalError() {

    return p_error * pid[0] + i_error * pid[1] + d_error * pid[2];
}
