/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimations_private.h
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.1659
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Thu Apr 28 22:06:41 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Estimations_private_h_
#define RTW_HEADER_Estimations_private_h_
#include "rtwtypes.h"

/* Imported (extern) block parameters */
extern Settings settings;              /* Variable: settings
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S8>/Constant'
                                        *   '<S9>/estimateFrictionCoefficient'
                                        *   '<S10>/Constant1'
                                        *   '<S10>/Constant2'
                                        */
extern CarParams car_params;           /* Variable: car_params
                                        * Referenced by:
                                        *   '<S3>/EstimateFx'
                                        *   '<S4>/FzEstDamper'
                                        *   '<S4>/FzEstLoadTransfer'
                                        *   '<S5>/whl_v_calculation'
                                        *   '<S6>/Slip ratio'
                                        */
extern real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);

#endif                                 /* RTW_HEADER_Estimations_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
