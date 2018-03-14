#include "PID.h"

using namespace std;
#include <math.h>
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  d_error = 0;
  i_error = 0;


}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::TotalError(double cte, double speed) {
// to step D-part with increase of control output depending on the acutaul cte
// cte >1 lead to a increse of Kd*d_error by a factor of cte
  if (cte>1){
    return Kp*p_error + Ki*i_error + cte*Kd*d_error;
  }
  else{
    return Kp*p_error + Ki*i_error + Kd*d_error;
  };
}
