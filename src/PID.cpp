#include "PID.h"
#include <iostream>

/*
* TODO: Complete the PID class.
*/

using namespace std;
PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0;
  i_error = 0;
  d_error = 0;

  int_cte = 0.0;
  prev_cte = 0.0;

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  std::cout << "Kp " << this->Kp << std::endl;
  std::cout << "Ki " << this->Ki << std::endl;
  std::cout << "Kd " << this->Kd << std::endl;
}

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

