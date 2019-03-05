#ifndef OSQP_CONFIGURE_H
# define OSQP_CONFIGURE_H

# ifdef __cplusplus
extern "C" {
# endif /* ifdef __cplusplus */

/* Operative system */
/* #undef IS_LINUX */
/* #undef IS_MAC */
#define IS_WINDOWS

/* EMBEDDED */
#define EMBEDDED (1)

/* PRINTING */
/* #undef PRINTING */

/* PROFILING */
/* #undef PROFILING */

/* CTRLC */
/* #undef CTRLC */

/* DFLOAT */
/* #undef DFLOAT */

/* DLONG */
#define DLONG

/* ENABLE_MKL_PARDISO */
/* #undef ENABLE_MKL_PARDISO */


# ifdef __cplusplus
}
# endif /* ifdef __cplusplus */

#endif /* ifndef OSQP_CONFIGURE_H */
