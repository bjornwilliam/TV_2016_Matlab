/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimations.h
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.1637
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Apr 19 20:35:27 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Estimations_h_
#define RTW_HEADER_Estimations_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Estimations_COMMON_INCLUDES_
# define Estimations_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Estimations_COMMON_INCLUDES_ */

#include "Estimations_types.h"
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T c;
  real32_T rtb_whl_speed_FL;
  real32_T rtb_whl_speed_FR;
  real32_T rtb_whl_speed_RL;
  real32_T rtb_whl_speed_RR;
  real32_T rtb_Fx_FL;
  real32_T rtb_Fx_FR;
  real32_T rtb_Fx_RL;
  real32_T rtb_Fx_RR;
  real32_T rtb_SR_n_FL;
  real32_T rtb_SR_n_FR;
  real32_T rtb_SR_n_RL;
  real32_T IndexVector_b;              /* '<S10>/Index Vector' */
  real32_T rtb_IndexVector_FL;
  real32_T rtb_IndexVector_FR;
} B_Estimations_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T mu_FL;                      /* '<S9>/estimateFrictionCoefficient' */
  real32_T mu_FR;                      /* '<S9>/estimateFrictionCoefficient' */
  real32_T mu_RL;                      /* '<S9>/estimateFrictionCoefficient' */
  real32_T mu_RR;                      /* '<S9>/estimateFrictionCoefficient' */
  boolean_T firstIteration_not_empty;  /* '<S9>/estimateFrictionCoefficient' */
} DW_Estimations_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  normalForces Fz_CM;                  /* '<Root>/Fz_CM' */
  SensorInputs Sensors_in;             /* '<Root>/Sensors_in' */
  T_meas T_CM;                         /* '<Root>/T_CM' */
} ExtU_Estimations_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  States States_a;                     /* '<Root>/States' */
  Whl_speed whl_v;                     /* '<Root>/whl_v' */
  Fx Fx_o;                             /* '<Root>/Fx' */
  SR SR_i;                             /* '<Root>/SR' */
  normLongTireForce normLongTireForce_d;/* '<Root>/normLongTireForce' */
  OutputTelemetri_est OutputTelemetri_est_l;/* '<Root>/OutputTelemetri_est' */
} ExtY_Estimations_T;

/* Parameters (auto storage) */
struct P_Estimations_T_ {
  real32_T DamperRateLookup_tableData[3];/* Expression: single([-900,0,900]);
                                          * Referenced by: '<S4>/DamperRateLookup'
                                          */
  real32_T DamperRateLookup_bp01Data[3];/* Expression: single([-250,0,250]);
                                         * Referenced by: '<S4>/DamperRateLookup'
                                         */
  real32_T DamperRateLookup1_tableData[3];/* Expression: single([-900,0,900]);
                                           * Referenced by: '<S4>/DamperRateLookup1'
                                           */
  real32_T DamperRateLookup1_bp01Data[3];/* Expression: single([-250,0,250]);
                                          * Referenced by: '<S4>/DamperRateLookup1'
                                          */
  real32_T DamperRateLookup2_tableData[3];/* Expression: single([-900,0,900]);
                                           * Referenced by: '<S4>/DamperRateLookup2'
                                           */
  real32_T DamperRateLookup2_bp01Data[3];/* Expression: single([-250,0,250]);
                                          * Referenced by: '<S4>/DamperRateLookup2'
                                          */
  real32_T DamperRateLookup3_tableData[3];/* Expression: single([-900,0,900]);
                                           * Referenced by: '<S4>/DamperRateLookup3'
                                           */
  real32_T DamperRateLookup3_bp01Data[3];/* Expression: single([-250,0,250]);
                                          * Referenced by: '<S4>/DamperRateLookup3'
                                          */
  real32_T Constant_Value;             /* Expression: single(1)
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Estimations_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Estimations_T Estimations_P;

/* Block signals (auto storage) */
extern B_Estimations_T Estimations_B;

/* Block states (auto storage) */
extern DW_Estimations_T Estimations_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Estimations_T Estimations_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Estimations_T Estimations_Y;

/* Model entry point functions */
extern void Estimations_initialize(void);
extern void Estimations_step(void);

/* Real-time Model object */
extern RT_MODEL_Estimations_T *const Estimations_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('TV2016/CarMaker/Estimations')    - opens subsystem TV2016/CarMaker/Estimations
 * hilite_system('TV2016/CarMaker/Estimations/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TV2016/CarMaker'
 * '<S1>'   : 'TV2016/CarMaker/Estimations'
 * '<S2>'   : 'TV2016/CarMaker/Estimations/EstimateVx'
 * '<S3>'   : 'TV2016/CarMaker/Estimations/Fx_Estimation'
 * '<S4>'   : 'TV2016/CarMaker/Estimations/Fz_Estimation'
 * '<S5>'   : 'TV2016/CarMaker/Estimations/RPM_to_linearVelocity'
 * '<S6>'   : 'TV2016/CarMaker/Estimations/SR_Calculation'
 * '<S7>'   : 'TV2016/CarMaker/Estimations/calculateMeanWheelAngle'
 * '<S8>'   : 'TV2016/CarMaker/Estimations/createStateBus'
 * '<S9>'   : 'TV2016/CarMaker/Estimations/friction_estimation'
 * '<S10>'  : 'TV2016/CarMaker/Estimations/selectVelocity'
 * '<S11>'  : 'TV2016/CarMaker/Estimations/EstimateVx/velocity_Estimation'
 * '<S12>'  : 'TV2016/CarMaker/Estimations/Fx_Estimation/EstimateFx'
 * '<S13>'  : 'TV2016/CarMaker/Estimations/Fz_Estimation/FzEstDamper'
 * '<S14>'  : 'TV2016/CarMaker/Estimations/Fz_Estimation/FzEstLoadTransfer'
 * '<S15>'  : 'TV2016/CarMaker/Estimations/RPM_to_linearVelocity/whl_v_calculation'
 * '<S16>'  : 'TV2016/CarMaker/Estimations/SR_Calculation/Slip ratio'
 * '<S17>'  : 'TV2016/CarMaker/Estimations/calculateMeanWheelAngle/calculateWheelangleandSpeed'
 * '<S18>'  : 'TV2016/CarMaker/Estimations/friction_estimation/estimateFrictionCoefficient'
 */
#endif                                 /* RTW_HEADER_Estimations_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
