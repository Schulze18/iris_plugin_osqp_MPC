//Header file for OSQP interface
#ifndef INTERFACE_OSQP_ROS_MPC_H
#define INTERFACE_OSQP_ROS_MPC_H

//Necessary Includes
#include "types.h"
#include <iostream>

void update_OSQP_vectors(double state[], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace);
void calculate_control_OSQP(double *array_control_action, double state[], std::size_t number_states, std::size_t number_controls_actions, OSQPWorkspace *workspace);

#endif
