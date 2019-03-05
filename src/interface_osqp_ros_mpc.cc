#include "interface_osqp_ros_mpc.h"
#include "types.h"
#include "osqp.h"
#include "matrix_drque.h"
#include <iostream>

void update_OSQP_vectors(double state[], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace){

	double F_t_new[] = {0.0420,    0.0033,         0,         0,         0,         0,         0,         0,    0.0011,  0, 0,  0,   -0.0420, 0, 0, 0,
         0,         0,    0.0967,    0.0076,   0,     0,   0,   0,        0,    0.0355,         0,  0,         0,   -0.0967,         0,         0,
         0,         0,         0,         0,    0.1731,    0.0136,         0,         0,         0,         0,   0.0712,  0,         0,         0,   -0.1731,         0,
         0,         0,         0,         0,         0,         0,    0.0315,    0.0025,         0,         0,  0,  0.0514,         0,         0,         0,   -0.0315,
    0.0311,    0.0025,         0,         0,         0,         0,         0,         0,    0.0006,         0,  0,  0,   -0.0311,         0,         0,         0,
         0,         0,    0.0716,    0.0058,         0,         0,         0,         0,         0,    0.0218,   0, 0,  0,   -0.0716,         0,         0,
         0,         0,         0,         0,    0.1281,    0.0104,         0,         0,         0,         0,  0.0501,   0,  0, 0,   -0.1281,         0,
         0,        0,         0,        0,         0 ,        0,    0.0233,    0.0019,         0,         0,    0, 0.0266,  0, 0, 0,   -0.0233};

	c_float l_new[8];
	c_float u_new[8];
	for (int i = 0; i < 2; i++ ){
			u_new[i*4] = (c_float)(26.8794 - state[8]);
			u_new[i*4+1] = (c_float)(0.2 - state[9]);
			u_new[i*4+2] = (c_float)(0.15 - state[10]);
			u_new[i*4+3] = (c_float)(0.1 - state[11]);

			l_new[i*4] = (c_float)(-13.4397 - state[8]);
			l_new[i*4+1] = (c_float)(-0.2 - state[9]);
			l_new[i*4+2] = (c_float)(-0.15 - state[10]);
			l_new[i*4+3] = (c_float)(-0.1 - state[11]);
			//(&udata)[i] = (26.8794 - state[7]);
			//(&ldata)[i] = (-13.4397 - state[7]);
	}

    /*c_float l_new[2] = {
		(c_float)(-13.43970000000000200000 - state[7]),
		(c_float)(-13.43970000000000200000 - state[7]),
	};

	c_float u_new[2] = {
		(c_float)(26.87940000000000400000 - state[7]),
		(c_float)(26.87940000000000400000 - state[7]),
	};*/

	Matrix <double> Ft(number_controls_actions*2,number_states);
	Ft = F_t_new;

	Matrix <double> control_state(number_states,1);
	control_state = state; 

	Matrix <double> q_new(8,1);
	q_new = Ft*control_state;

	c_float q_new_cfloat[8];
	for (int i = 0; i < 8; i++ ){
			//q_new_cfloat[i] = (c_float)( q_new[i][0] );
			q_new_cfloat[i] = (c_float)(q_new.get(i,0));
	}

	c_int flag_bounds = osqp_update_bounds(workspace, l_new, u_new);
	c_int flag_cost = osqp_update_lin_cost(workspace, q_new_cfloat);

}

void calculate_control_OSQP(double *array_control_action, double state[], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace){

    osqp_solve(workspace);
    //cfloat solution[] = (&workspace)->x;
    for (int it_control = 0; it_control < number_controls_actions; it_control++){
        //array_control_action[it_control] = solution[it_control];
        array_control_action[it_control] = (workspace)->solution->x[it_control];
    }
}
