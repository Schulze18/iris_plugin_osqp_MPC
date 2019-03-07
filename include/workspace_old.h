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
(c_float)0.08819868477997591700,
(c_float)1.00000000000000020000,
(c_float)1.00000000000000000000,
(c_float)1.00000000000000000000,
(c_float)0.01377277091943084400,
(c_float)0.07533947716618487300,
(c_float)0.42899286868323711000,
(c_float)1.00000000000000020000,
(c_float)0.61574812725033223000,
(c_float)1.00000000000000020000,
(c_float)0.40967893201473882000,
(c_float)1.00000000000000000000,
};
csc Pdata = {24, 8, 8, Pdata_p, Pdata_i, Pdata_x, -1};
c_int Adata_i[12] = {
0,
4,
1,
5,
2,
6,
3,
7,
4,
5,
6,
7,
};
c_int Adata_p[9] = {
0,
2,
4,
6,
8,
9,
10,
11,
12,
};
c_float Adata_x[12] = {
(c_float)1.00000000000000000000,
(c_float)1.00000000000000000000,
(c_float)0.99893838148953573000,
(c_float)0.85270216048608571000,
(c_float)0.99797131983635023000,
(c_float)0.83066870874107090000,
(c_float)0.99838922112007034000,
(c_float)0.82320324392295607000,
(c_float)1.00000000000000000000,
(c_float)0.99987727243598701000,
(c_float)0.99868970077860497000,
(c_float)0.99914491596392385000,
};
csc Adata = {12, 8, 8, Adata_p, Adata_i, Adata_x, -1};
c_float qdata[8] = {
(c_float)0.00000000183468730415,
(c_float)-0.00000000000000000000,
(c_float)0.00000000000000010836,
(c_float)0.00000000747105403916,
(c_float)-0.00000000050000961250,
(c_float)-0.00000000000000000000,
(c_float)0.00000000000000009771,
(c_float)0.00000001575201449157,
};
c_float ldata[8] = {
(c_float)-13.43970034470691000000,
(c_float)-0.23798020568146902000,
(c_float)-0.22848893709750839000,
(c_float)-0.13690170973288504000,
(c_float)-13.43970034470691000000,
(c_float)-0.20314189473321123000,
(c_float)-0.19018443372854710000,
(c_float)-0.11287975587744889000,
};
c_float udata[8] = {
(c_float)26.87939965529309600000,
(c_float)0.23798020568146902000,
(c_float)0.22848893709750831000,
(c_float)0.13690180912281763000,
(c_float)26.87939965529309600000,
(c_float)0.20314189473321123000,
(c_float)0.19018443372854704000,
(c_float)0.11287983782756734000,
};
OSQPData data = {8, 8, &Pdata, &Adata, qdata, ldata, udata};

// Define settings structure
OSQPSettings settings = {(c_float)0.10000000000000001000, (c_float)0.00000100000000000000, 10, 4000, (c_float)0.00100000000000000000, (c_float)0.00100000000000000000, (c_float)0.00010000000000000000, (c_float)0.00010000000000000000, (c_float)1.60000000000000010000, (enum linsys_solver_type) LINSYS_SOLVER, 0, 25, 1, 
#ifdef PROFILING
(c_float)0.00000000000000000000, 
#endif  // PROFILING
};

// Define scaling structure
c_float Dscaling[8] = {
(c_float)1.00000000000000000000,
(c_float)0.83951383992548667000,
(c_float)0.65515512425693256000,
(c_float)0.72927420749930694000,
(c_float)1.00000000000000000000,
(c_float)0.98441266755844570000,
(c_float)0.78767463866473575000,
(c_float)0.88514060427432795000,
};
c_float Dinvscaling[8] = {
(c_float)1.00000000000000000000,
(c_float)1.19116559184867970000,
(c_float)1.52635606892975990000,
(c_float)1.37122633670127470000,
(c_float)1.00000000000000000000,
(c_float)1.01583414451605370000,
(c_float)1.26955972798006770000,
(c_float)1.12976401169601550000,
};
c_float Escaling[8] = {
(c_float)1.00000000000000000000,
(c_float)1.18990102840734500000,
(c_float)1.52325958065005570000,
(c_float)1.36901759427851320000,
(c_float)1.00000000000000000000,
(c_float)1.01570947366605610000,
(c_float)1.26789622485698050000,
(c_float)1.12879796852508110000,
};
c_float Einvscaling[8] = {
(c_float)1.00000000000000000000,
(c_float)0.84040603052379648000,
(c_float)0.65648692626193550000,
(c_float)0.73045080222435754000,
(c_float)1.00000000000000000000,
(c_float)0.98453349695621617000,
(c_float)0.78870808225081723000,
(c_float)0.88589812161571113000,
};
OSQPScaling scaling = {(c_float)23.83643094031455700000, Dscaling, Escaling, (c_float)0.04195258939998017900, Dinvscaling, Einvscaling};

// Define linsys_solver structure
c_int linsys_solver_L_i[16] = {
3,
2,
3,
3,
7,
6,
7,
7,
11,
10,
11,
11,
15,
14,
15,
15,
};
c_int linsys_solver_L_p[17] = {
0,
1,
3,
4,
4,
5,
7,
8,
8,
9,
11,
12,
12,
13,
15,
16,
16,
};
c_float linsys_solver_L_x[16] = {
(c_float)-0.10000000000000001000,
(c_float)13.27307760202016400000,
(c_float)0.18280705720845219000,
(c_float)-0.03511323069367557100,
(c_float)-0.09989383814895358400,
(c_float)0.99987627255971434000,
(c_float)0.42899243969079737000,
(c_float)-0.03852471491056196800,
(c_float)-0.09979713198363503200,
(c_float)0.99868870208990268000,
(c_float)0.61574751150282059000,
(c_float)-0.01961630937081156400,
(c_float)-0.09983892211200703900,
(c_float)0.99914391682000714000,
(c_float)0.40967852233621649000,
(c_float)-0.03763085420804480900,
};
csc linsys_solver_L = {0, 16, 16, linsys_solver_L_p, linsys_solver_L_i, linsys_solver_L_x, -1};
c_float linsys_solver_Dinv[16] = {
(c_float)-0.10000000000000001000,
(c_float)13.27307760202016400000,
(c_float)-0.04296810319204183400,
(c_float)4.66469671654227280000,
(c_float)-0.10000000000000001000,
(c_float)0.99999900000099984000,
(c_float)-0.09091112764744462000,
(c_float)1.07286995364831190000,
(c_float)-0.10000000000000001000,
(c_float)0.99999900000099984000,
(c_float)-0.09093074795922485900,
(c_float)1.37991544088325520000,
(c_float)-0.10000000000000001000,
(c_float)0.99999900000100006000,
(c_float)-0.09092322893551210700,
(c_float)1.05550152632614000000,
};
c_int linsys_solver_P[16] = {
8,
4,
12,
0,
9,
5,
13,
1,
10,
6,
14,
2,
11,
7,
15,
3,
};
c_float linsys_solver_bp[16];
qdldl_solver linsys_solver = {QDLDL_SOLVER, &solve_linsys_qdldl, &linsys_solver_L, linsys_solver_Dinv, linsys_solver_P, linsys_solver_bp};

// Define solution
c_float xsolution[8];
c_float ysolution[8];

OSQPSolution solution = {xsolution, ysolution};

// Define info
OSQPInfo info = {0, "Unsolved", OSQP_UNSOLVED, (c_float)0.0, (c_float)0.0, (c_float)0.0};

// Define workspace
c_float work_rho_vec[8] = {
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
(c_float)0.10000000000000001000,
};
c_float work_rho_inv_vec[8] = {
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
(c_float)10.00000000000000000000,
};
c_float work_x[8];
c_float work_y[8];
c_float work_z[8];
c_float work_xz_tilde[16];
c_float work_x_prev[8];
c_float work_z_prev[8];
c_float work_Ax[8];
c_float work_Px[8];
c_float work_Aty[8];
c_float work_delta_y[8];
c_float work_Atdelta_y[8];
c_float work_delta_x[8];
c_float work_Pdelta_x[8];
c_float work_Adelta_x[8];
c_float work_D_temp[8];
c_float work_D_temp_A[8];
c_float work_E_temp[8];

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

