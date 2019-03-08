//Header file for OSQP interface
#ifndef INTERFACE_OSQP_ROS_MPC_H
#define INTERFACE_OSQP_ROS_MPC_H

//Necessary Includes
#include "types.h"
#include <iostream>

//template<typename E_tp, std::size_t N, std::size_t M>
//template<typename F_tp, std::size_t K, std::size_t J>

void update_OSQP_vectors(double state[], double* W_temp, double* E_temp, double* FT_temp, std::size_t number_states, std::size_t number_controls_actions, std::size_t number_opt_var, std::size_t number_ineq, OSQPWorkspace *workspace);
//void update_OSQP_vectors(double state[], double* W_temp, E_tp (&E_temp)[N][M], E_tp (&FT_temp)[K][J], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace);

void calculate_control_OSQP(double *array_control_action, double state[], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace);

#endif
