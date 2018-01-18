#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	pid_Kp = Kp;
	pid_Kd = Kd;
	pid_Ki = Ki;
	
}

void PID::UpdateError(double cte) {


	if (first_cte){
		//if this is the first cte signal received
		prev_cte = cte;
		int_cte = 0;
		
		first_cte= false;
	}

	

	
    p_error = - pid_Kp * cte;
    i_error = - pid_Ki * int_cte;
    d_error = - pid_Kd * (cte - prev_cte);
    prev_cte = cte;
    int_cte += cte;
}

double PID::TotalError() {

	double steer =  p_error + i_error + d_error;

	if(steer > 1){
		steer = 1;
	}
	if(steer < -1){
		steer = -1;
	}
	return steer;
}

