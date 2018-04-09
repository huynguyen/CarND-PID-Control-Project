#ifndef PID_H
#define PID_H

class PID {
  /*
  * Errors
  */
  // Proportional - This term tries to adjust the steering angle back to
  // the center of the lane.
  double p_error;
  // Integral - This term is to try to adjust for systematic bias,
  // things such as steering drift due to wheel alignment.
  double i_error;
  // Derivative - This term is to dampen the oscillation due to the
  // proportional part. When we are already counter-steering to come
  // back to the center of the lane, we want to reduce the amount of
  // counter-steer if the cte is now smaller in comparison to what it
  // was before.
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Kd;
  double Ki;

  double prev_cte;
  double int_cte;

public:
  /*
  * Constructor
  */
  // PID(double Kp = 0.2, double Ki = 0.004, double Kd = 3.0);
  //
  // Started with the default parameters from the lecture above and
  // tuned manually.
  //
  // Mostly adjusted Kd which is the derivative portion. This is to
  // smooth out the oscillations from the proportional part. Ki is
  // relatively unchanged and small since we don't have much bias/drift
  // in the simulator it seems. The turns are relatively wide and so it
  // also seems that we don't need to change Kp much which controls
  // how quickly we oscillate. In this case I tended to favor a wide
  // turn for smoothness.
  //
  PID(double Kp = 0.12, double Ki = 0.0, double Kd = 3.5);

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

  /*
   * Calculate steering value here, just to simplify where I have to
   * change things.
   */
  double SteeringValue(double cte);
};

#endif /* PID_H */
