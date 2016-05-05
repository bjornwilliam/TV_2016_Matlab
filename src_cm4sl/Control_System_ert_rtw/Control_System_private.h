/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_System_private.h
 *
 * Code generated for Simulink model 'Control_System'.
 *
 * Model version                  : 1.1659
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Thu Apr 28 22:06:15 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Control_System_private_h_
#define RTW_HEADER_Control_System_private_h_
#include "rtwtypes.h"

/* Imported (extern) block parameters */
extern Settings settings;              /* Variable: settings
                                        * Referenced by:
                                        *   '<S3>/MATLAB Function'
                                        *   '<S7>/MATLAB Function'
                                        *   '<S8>/MATLAB Function'
                                        *   '<S9>/yawRateReference'
                                        *   '<S14>/MATLAB Function1'
                                        *   '<S44>/TorqueAllocation'
                                        */
extern CarParams car_params;           /* Variable: car_params
                                        * Referenced by:
                                        *   '<S3>/MATLAB Function'
                                        *   '<S7>/MATLAB Function'
                                        *   '<S44>/TorqueAllocation'
                                        */
extern real32_T rt_roundf(real32_T u);
extern real32_T look1_iflf_binlcapw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);

#endif                                 /* RTW_HEADER_Control_System_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
