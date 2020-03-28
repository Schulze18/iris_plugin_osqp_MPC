#include "types.h"
#include "constants.h"
#include "qdldl.h"

#include "qdldl_interface.h"
// Define data structure
c_int Pdata_i[12] = {
0,
1,
2,
3,
0,
4,
1,
5,
2,
6,
3,
7,
};
c_int Pdata_p[9] = {
0,
1,
2,
3,
4,
6,
8,
10,
12,
};
c_float Pdata_x[12] = {
(c_float)0.04212525973680004300,
(c_float)1.00000000000000020000,
(c_float)1.00000000000000000000,
(c_float)1.00000000000000000000,
(c_float)0.01102397570461932000,
(c_float)0.03510230965954500000,
(c_float)0.74838763378508533000,
(c_float)1.00000000000000020000,
(c_float)0.91599305259156594000,
(c_float)1.00000000000000020000,
(c_float)0.55442443365191640000,
(c_float)1.00000000000000020000,
};
csc Pdata = {24, 8, 8, Pdata_p, Pdata_i, Pdata_x, -1};
c_int Adata_i[18] = {
0,
3,
6,
9,
1,
4,
7,
10,
2,
5,
8,
11,
3,
9,
4,
10,
5,
11,
};
c_int Adata_p[9] = {
0,
4,
8,
12,
12,
14,
16,
18,
18,
};
c_float Adata_x[18] = {
(c_float)1.00000000000000000000,
(c_float)1.00000000000000000000,
(c_float)-1.00000000000000000000,
(c_float)-1.00000000000000000000,
(c_float)0.99968589438863464000,
(c_float)0.85801486820960449000,
(c_float)-0.99968589438863464000,
(c_float)-0.85801486820960449000,
(c_float)0.99859905804014204000,
(c_float)0.84925432801902867000,
(c_float)-0.99859905804014204000,
(c_float)-0.84925432801902867000,
(c_float)1.00000000000000000000,
(c_float)-1.00000000000000000000,
(c_float)0.99998490523107297000,
(c_float)-0.99998490523107297000,
(c_float)0.99898863405860949000,
(c_float)-0.99898863405860949000,
};
csc Adata = {18, 12, 8, Adata_p, Adata_i, Adata_x, -1};
c_float qdata[8] = {
(c_float)0.00000000031975599286,
(c_float)0.00000000000000000015,
(c_float)-0.00000000000000043328,
(c_float)-0.00000039294554392057,
(c_float)-0.00000000004872119186,
(c_float)0.00000000000000000020,
(c_float)-0.00000000000000050967,
(c_float)-0.00000060144047187488,
};
c_float ldata[12] = {
(c_float)-100000000000000000000.00000000000000000000,
(c_float)-117413673142452370000.00000000000000000000,
(c_float)-204701628956771090000.00000000000000000000,
(c_float)-100000000000000000000.00000000000000000000,
(c_float)-100774331070197600000.00000000000000000000,
(c_float)-174087631011058810000.00000000000000000000,
(c_float)-100000000000000000000.00000000000000000000,
(c_float)-117413673142452370000.00000000000000000000,
(c_float)-204701628956771090000.00000000000000000000,
(c_float)-100000000000000000000.00000000000000000000,
(c_float)-100774331070197600000.00000000000000000000,
(c_float)-174087631011058810000.00000000000000000000,
};
c_float udata[12] = {
(c_float)26.87939989305069600000,
(c_float)0.22148382243516151000,
(c_float)0.62376438827785163000,
(c_float)26.87939989305069600000,
(c_float)0.19009612297619019000,
(c_float)0.53047777498285287000,
(c_float)13.43970010694930800000,
(c_float)0.22148382243516151000,
(c_float)0.62376438827785075000,
(c_float)13.43970010694930800000,
(c_float)0.19009612297619019000,
(c_float)0.53047777498285209000,
};
OSQPData data = {8, 12, &Pdata, &Adata, qdata, ldata, udata};

// Define settings structure
OSQPSettings settings = {(c_float)0.14447357181111220000, (c_float)0.00000100000000000000, 10, 4000, (c_float)0.00100000000000000000, (c_float)0.00100000000000000000, (c_float)0.00010000000000000000, (c_float)0.00010000000000000000, (c_float)1.60000000000000010000, (enum linsys_solver_type) LINSYS_SOLVER, 0, 25, 1, 
#ifdef PROFILING
(c_float)0.00000000000000000000, 
#endif  // PROFILING
};

// Define scaling structure
c_float Dscaling[8] = {
(c_float)1.00000000000000000000,
(c_float)0.85142204279374145000,
(c_float)0.48783151513221545000,
(c_float)1.00603479765605490000,
(c_float)1.00000000000000000000,
(c_float)0.99230120866245330000,
(c_float)0.57384239664628989000,
(c_float)1.22127836058718420000,
};
c_float Dinvscaling[8] = {
(c_float)1.00000000000000000000,
(c_float)1.17450565023984450000,
(c_float)2.04988806376925670000,
(c_float)0.99400140266508152000,
(c_float)1.00000000000000000000,
(c_float)1.00775852258400870000,
(c_float)1.74263875559614490000,
(c_float)0.81881414775842365000,
};
c_float Escaling[12] = {
(c_float)1.00000000000000000000,
(c_float)1.17413673142452370000,
(c_float)2.04701628956771090000,
(c_float)1.00000000000000000000,
(c_float)1.00774331070197600000,
(c_float)1.74087631011058820000,
(c_float)1.00000000000000000000,
(c_float)1.17413673142452370000,
(c_float)2.04701628956771090000,
(c_float)1.00000000000000000000,
(c_float)1.00774331070197600000,
(c_float)1.74087631011058820000,
};
c_float Einvscaling[12] = {
(c_float)1.00000000000000000000,
(c_float)0.85168956326470435000,
(c_float)0.48851589755115243000,
(c_float)1.00000000000000000000,
(c_float)0.99231618744600536000,
(c_float)0.57442334885726343000,
(c_float)1.00000000000000000000,
(c_float)0.85168956326470435000,
(c_float)0.48851589755115243000,
(c_float)1.00000000000000000000,
(c_float)0.99231618744600536000,
(c_float)0.57442334885726343000,
};
OSQPScaling scaling = {(c_float)1.00000000000000000000, Dscaling, Escaling, (c_float)1.00000000000000000000, Dinvscaling, Einvscaling};

// Define linsys_solver structure
c_int linsys_solver_L_i[22] = {
3,
3,
3,
5,
4,
5,
5,
9,
9,
9,
11,
10,
11,
11,
15,
15,
15,
17,
16,
17,
17,
19,
};
c_int linsys_solver_L_p[21] = {
0,
1,
2,
4,
6,
7,
7,
8,
9,
11,
13,
14,
14,
15,
16,
18,
20,
21,
21,
22,
22,
};
c_float linsys_solver_L_x[22] = {
(c_float)0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)2.10284167960952660000,
(c_float)0.32698672399314305000,
(c_float)-0.07457605105905056000,
(c_float)0.14442819185151234000,
(c_float)-0.14442819185151234000,
(c_float)0.12396047267728226000,
(c_float)0.14447139101592965000,
(c_float)0.61500861638242965000,
(c_float)0.62528106570285413000,
(c_float)-0.06221795902111407900,
(c_float)0.14427117272227147000,
(c_float)-0.14427117272227147000,
(c_float)0.12269480614495497000,
(c_float)0.14432745616115142000,
(c_float)0.60994830294724378000,
(c_float)0.74591342986568065000,
(c_float)-0.04913091796080036600,
(c_float)0.55442387922803726000,
};
csc linsys_solver_L = {31525622600892416, 20, 20, linsys_solver_L_p, linsys_solver_L_i, linsys_solver_L_x, -1};
c_float linsys_solver_Dinv[20] = {
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)2.10284167960952660000,
(c_float)-0.11080918269774330000,
(c_float)5.58903011200641940000,
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)0.71678083815231641000,
(c_float)-0.13423958123665605000,
(c_float)1.59274806934768160000,
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)-0.14447357181111220000,
(c_float)0.71821630202345821000,
(c_float)-0.13441434013801248000,
(c_float)2.58089771827544020000,
(c_float)0.99999900000100006000,
(c_float)1.44380385885953430000,
};
c_int linsys_solver_P[20] = {
14,
8,
17,
0,
11,
4,
15,
9,
18,
1,
12,
5,
16,
10,
19,
2,
13,
6,
3,
7,
};
c_float linsys_solver_bp[20];
qdldl_solver linsys_solver = {QDLDL_SOLVER, &solve_linsys_qdldl, &linsys_solver_L, linsys_solver_Dinv, linsys_solver_P, linsys_solver_bp};

// Define solution
c_float xsolution[8];
c_float ysolution[12];

OSQPSolution solution = {xsolution, ysolution};

// Define info
OSQPInfo info = {0, "Unsolved", OSQP_UNSOLVED, (c_float)0.0, (c_float)0.0, (c_float)0.0};

// Define workspace
c_float work_rho_vec[12] = {
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
(c_float)0.14447357181111220000,
};
c_float work_rho_inv_vec[12] = {
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
(c_float)6.92168115914944690000,
};
c_float work_x[8];
c_float work_y[12];
c_float work_z[12];
c_float work_xz_tilde[20];
c_float work_x_prev[8];
c_float work_z_prev[12];
c_float work_Ax[12];
c_float work_Px[8];
c_float work_Aty[8];
c_float work_delta_y[12];
c_float work_Atdelta_y[8];
c_float work_delta_x[8];
c_float work_Pdelta_x[8];
c_float work_Adelta_x[12];
c_float work_D_temp[8];
c_float work_D_temp_A[8];
c_float work_E_temp[12];

OSQPWorkspace workspace = {
&data, (LinSysSolver *)&linsys_solver,
work_rho_vec, work_rho_inv_vec,
work_x, work_y, work_z, work_xz_tilde,
work_x_prev, work_z_prev,
work_Ax, work_Px, work_Aty,
work_delta_y, work_Atdelta_y,
work_delta_x, work_Pdelta_x, work_Adelta_x,
work_D_temp, work_D_temp_A, work_E_temp,
&settings, &scaling, &solution, &info};

