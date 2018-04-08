#ifndef PID_H
#define PID_H

class PID {
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  double prev_cte;
  double int_cte;

public:
  /*
  * Constructor
  */
  PID(double Kp = 0.2, double Ki = 0.004, double Kd = 3.0);

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double SteeringValue(double cte);
};

#endif /* PID_H */
