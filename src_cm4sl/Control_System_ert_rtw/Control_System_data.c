/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_System_data.c
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

#include "Control_System.h"
#include "Control_System_private.h"

/* Block parameters (auto storage) */
P_Control_System_T Control_System_P = {
  1.0F,                                /* Expression: single(1)
                                        * Referenced by: '<S5>/constant'
                                        */
  1.0F,                                /* Expression: single(1)
                                        * Referenced by: '<S5>/constant2'
                                        */
  0.0F,                                /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain7'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S27>/Constant1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S27>/Constant'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain7'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S28>/Constant1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S28>/Constant'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain7'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S29>/Constant1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S29>/Constant'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain7'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S30>/Constant1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain1'
                                        */
  -1.0F,                               /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain'
                                        */
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S30>/Constant'
                                        */
  0.0F,                                /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S5>/Switch'
                                        */
  0.01F,                               /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0F,                                /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S10>/Integrator'
                                        */
  3.6F,                                /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain1'
                                        */

  /*  Expression: [yawRateControl.Kd_start  yawRateControl.Kd_end]*yawRateControl.Kd_scaling
   * Referenced by: '<S9>/Kd lookup'
   */
  { 50.0F, 50.0F },

  /*  Expression: [0  yawRateControl.lookup_speed_end_kmh]
   * Referenced by: '<S9>/Kd lookup'
   */
  { 0.0F, 50.0F },
  3.6F,                                /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain'
                                        */

  /*  Expression: [yawRateControl.Kp_start  yawRateControl.Kp_end]*yawRateControl.Kp_scaling
   * Referenced by: '<S9>/Kp Lookup'
   */
  { 4500.0F, 4500.0F },

  /*  Expression: [0  yawRateControl.lookup_speed_end_kmh]
   * Referenced by: '<S9>/Kp Lookup'
   */
  { 0.0F, 50.0F },
  0.01F,                               /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                        * Referenced by: '<S9>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S9>/Discrete-Time Integrator2'
                                        */
  -2000.0F,                            /* Expression: -yawRateControl.max_moment
                                        * Referenced by: '<S9>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S27>/Switch'
                                        */
  0.01F,                               /* Computed Parameter: DiscreteTimeIntegrator2_gainv_i
                                        * Referenced by: '<S27>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC_f
                                        * Referenced by: '<S27>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S27>/Switch1'
                                        */
  0.0F,                                /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S27>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S28>/Switch'
                                        */
  0.01F,                               /* Computed Parameter: DiscreteTimeIntegrator2_gainv_n
                                        * Referenced by: '<S28>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC_i
                                        * Referenced by: '<S28>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: Switch1_Threshold_f
                                        * Referenced by: '<S28>/Switch1'
                                        */
  0.0F,                                /* Computed Parameter: Switch2_Threshold_o
                                        * Referenced by: '<S28>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: Switch_Threshold_n
                                        * Referenced by: '<S29>/Switch'
                                        */
  0.01F,                               /* Computed Parameter: DiscreteTimeIntegrator2_gainv_f
                                        * Referenced by: '<S29>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC_l
                                        * Referenced by: '<S29>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: Switch1_Threshold_d
                                        * Referenced by: '<S29>/Switch1'
                                        */
  0.0F,                                /* Computed Parameter: Switch2_Threshold_p
                                        * Referenced by: '<S29>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: Switch_Threshold_h
                                        * Referenced by: '<S30>/Switch'
                                        */
  0.01F,                               /* Computed Parameter: DiscreteTimeIntegrator2_gain_fb
                                        * Referenced by: '<S30>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC_c
                                        * Referenced by: '<S30>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: Switch1_Threshold_p
                                        * Referenced by: '<S30>/Switch1'
                                        */
  0.0F,                                /* Computed Parameter: Switch2_Threshold_k
                                        * Referenced by: '<S30>/Switch2'
                                        */
  0.0F,                                /* Computed Parameter: ZeroGain_Gain
                                        * Referenced by: '<S12>/ZeroGain'
                                        */
  3.6F,                                /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain2'
                                        */

  /*  Expression: [yawRateControl.Ki_start  yawRateControl.Ki_end]*yawRateControl.Ki_scaling
   * Referenced by: '<S9>/Ki lookup'
   */
  { 2000.0F, 2000.0F },

  /*  Expression: [0  yawRateControl.lookup_speed_end_kmh]
   * Referenced by: '<S9>/Ki lookup'
   */
  { 0.0F, 50.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
