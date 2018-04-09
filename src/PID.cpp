#include "PID.h"
#include <iostream>
#include <math.h>

/*
* TODO: Complete the PID class.
*/

using namespace std;
PID::PID(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  std::cout << "Kp " << this->Kp << std::endl;
  std::cout << "Ki " << this->Ki << std::endl;
  std::cout << "Kd " << this->Kd << std::endl;
}

PID::~PID() {}

void PID::UpdateError(double cte) {
  int_cte += cte;
  p_error = -Kp * cte;
  d_error = -Kd * (cte - prev_cte);
  i_error = -Ki * int_cte;

  prev_cte = cte;
}

double PID::TotalError() {
  return p_error + d_error + i_error;
}

double PID::SteeringValue(double cte) {
  UpdateError(cte);
  double steer_value;
  steer_value = TotalError();
  // Clamp steering value.
  steer_value = std::min(steer_value, 1.0);
  steer_value = std::max(steer_value, -1.0);
  return steer_value;
}

