#ifndef PID_H
#define PID_H

class PID {
public:
    /*
    * Errors
    */
    double p_error;
    double i_error;
    double d_error;

    /*
    * Coefficients
    */
    std::vector<double> pid;
    std::vector<bool> choice;
    std::vector<double> dp;

    double tol;
    double best_err;
    double total_err;

    bool twiddle;

    int index;

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
};

#endif /* PID_H */
