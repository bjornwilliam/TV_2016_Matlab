/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_System_types.h
 *
 * Code generated for Simulink model 'Control_System'.
 *
 * Model version                  : 1.1637
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Apr 19 20:32:19 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Passed (5), Warnings (5), Errors (2)
 */

#ifndef RTW_HEADER_Control_System_types_h_
#define RTW_HEADER_Control_System_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_States_
#define _DEFINED_TYPEDEF_FOR_States_

typedef struct {
  real32_T Input_throttle;
  real32_T Input_brake;
  real32_T KERS_pos;
  real32_T sideSlipAngle;
  real32_T r;
  real32_T r_der;
  real32_T ax;
  real32_T ay;
  real32_T RPM_FL;
  real32_T RPM_FR;
  real32_T RPM_RL;
  real32_T RPM_RR;
  real32_T power;
  real32_T DC_voltage;
  real32_T wheel_angle;
  real32_T wheel_speed;
  real32_T V_x;
  real32_T V_y;
  real32_T Fx_FL;
  real32_T Fx_FR;
  real32_T Fx_RL;
  real32_T Fx_RR;
  real32_T Fz_FL;
  real32_T Fz_FR;
  real32_T Fz_RL;
  real32_T Fz_RR;
  real32_T whl_v_FL;
  real32_T whl_v_FR;
  real32_T whl_v_RL;
  real32_T whl_v_RR;
  real32_T SR_FL;
  real32_T SR_FR;
  real32_T SR_RL;
  real32_T SR_RR;
  real32_T mu;
} States;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Settings_
#define _DEFINED_TYPEDEF_FOR_Settings_

typedef struct {
  uint32_T KERS_active;
  uint32_T select_Fz_est_method;
  uint32_T select_velocity_vx;
  uint32_T select_velocity_vy;
  uint32_T TV_Method;
  uint32_T use_estimated_Fz;
  real32_T max_motor_torque;
  real32_T max_motor_brake_torque;
  real32_T max_RPM;
  real32_T KERS_speed_limit_hyst_high;
  real32_T KERS_speed_limit_hyst_low;
  real32_T KERS_motor_RPM_setpoint;
  real32_T max_RPM_rate_of_change;
  real32_T mu;
  real_T sensor_sampling_time;
  real_T control_system_sample_time;
  real_T sample_time;
  real32_T coasting_KERS_percent;
  real32_T max_battery_discharge;
  real32_T battery_voltage;
  real_T scaling_factor;
} Settings;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Ti_lim_
#define _DEFINED_TYPEDEF_FOR_Ti_lim_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} Ti_lim;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_PowerLimitControl_
#define _DEFINED_TYPEDEF_FOR_PowerLimitControl_

typedef struct {
  real32_T positive_power_limit;
  real32_T negative_power_limit;
  real32_T Kp;
  real32_T Ki;
  real32_T Kb;
  real32_T upper_sat_limit;
  real32_T lower_sat_limit;
  uint32_T enable;
} PowerLimitControl;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_TractionControl_
#define _DEFINED_TYPEDEF_FOR_TractionControl_

typedef struct {
  real32_T Slip_ratio_ref;
  real32_T Kd;
  real32_T Kb;
  real32_T Kp_start;
  real32_T Kp_end;
  real32_T Kp_scaling;
  real32_T Ki_start;
  real32_T Ki_end;
  real32_T Ki_scaling;
  real32_T Kp_braking;
  real32_T Ki_braking;
  real32_T lookup_speed_end_kmh;
  uint32_T enable;
} TractionControl;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_CarParams_
#define _DEFINED_TYPEDEF_FOR_CarParams_

typedef struct {
  real32_T GR;
  real32_T t_f;
  real32_T t_r;
  real32_T l;
  real32_T l_f;
  real32_T l_r;
  real32_T CoG_height;
  real32_T spring_constant_front;
  real32_T spring_constant_rear;
  real32_T motion_ratio_front;
  real32_T motion_ratio_rear;
  real32_T driver_mass;
  real32_T car_mass;
  real32_T r_eff;
  real32_T Kt;
  real32_T Lq;
  real32_T Ld;
  real32_T Jw;
  real32_T Mn;
} CarParams;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_maxMotorTorque_
#define _DEFINED_TYPEDEF_FOR_maxMotorTorque_

typedef struct {
  real32_T mmt_FL;
  real32_T mmt_FR;
  real32_T mmt_RL;
  real32_T mmt_RR;
} maxMotorTorque;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_YawRateControl_
#define _DEFINED_TYPEDEF_FOR_YawRateControl_

typedef struct {
  real32_T Ku;
  real_T negative_torque_limit;
  real32_T max_moment;
  real32_T Kp_start;
  real32_T Kp_end;
  real32_T Kp_scaling;
  real32_T Ki_start;
  real32_T Ki_end;
  real32_T Ki_scaling;
  real32_T Ksat;
  real32_T Kd_start;
  real32_T Kd_end;
  real32_T Kd_scaling;
  real32_T lookup_speed_end_kmh;
  real32_T ref_weight;
  real32_T meas_weight;
  uint32_T enable_r_ref_limit;
  real32_T mu_scaling_r_ref_limit;
  uint32_T enable;
} YawRateControl;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Ti_pos_
#define _DEFINED_TYPEDEF_FOR_Ti_pos_

typedef struct {
  int16_T FL;
  int16_T FR;
  int16_T RL;
  int16_T RR;
} Ti_pos;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Ti_neg_
#define _DEFINED_TYPEDEF_FOR_Ti_neg_

typedef struct {
  int16_T FL;
  int16_T FR;
  int16_T RL;
  int16_T RR;
} Ti_neg;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_wi_set_
#define _DEFINED_TYPEDEF_FOR_wi_set_

typedef struct {
  int16_T FL;
  int16_T FR;
  int16_T RL;
  int16_T RR;
} wi_set;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_OutputTelemetri_Control_
#define _DEFINED_TYPEDEF_FOR_OutputTelemetri_Control_

typedef struct {
  real32_T T_req;
  real32_T Mz_ref;
  real32_T r_ref;
} OutputTelemetri_Control;

#endif

/* Custom Type definition for MATLAB Function: '<S9>/yawRateReference' */
#ifndef struct_stJxTitUMuT3Ho2jJeUFcJH
#define struct_stJxTitUMuT3Ho2jJeUFcJH

struct stJxTitUMuT3Ho2jJeUFcJH
{
  real32_T Ku;
  real_T negative_torque_limit;
  real32_T max_moment;
  real32_T Kp_start;
  real32_T Kp_end;
  real32_T Kp_scaling;
  real32_T Ki_start;
  real32_T Ki_end;
  real32_T Ki_scaling;
  real32_T Ksat;
  real32_T Kd_start;
  real32_T Kd_end;
  real32_T Kd_scaling;
  real32_T lookup_speed_end_kmh;
  real32_T ref_weight;
  real32_T meas_weight;
  uint32_T enable_r_ref_limit;
  real32_T mu_scaling_r_ref_limit;
  uint32_T enable;
};

#endif                                 /*struct_stJxTitUMuT3Ho2jJeUFcJH*/

#ifndef typedef_stJxTitUMuT3Ho2jJeUFcJH_Contr_T
#define typedef_stJxTitUMuT3Ho2jJeUFcJH_Contr_T

typedef struct stJxTitUMuT3Ho2jJeUFcJH stJxTitUMuT3Ho2jJeUFcJH_Contr_T;

#endif                                 /*typedef_stJxTitUMuT3Ho2jJeUFcJH_Contr_T*/

#ifndef struct_sxOEtKrnKDbijZ2mVJTGnCG
#define struct_sxOEtKrnKDbijZ2mVJTGnCG

struct sxOEtKrnKDbijZ2mVJTGnCG
{
  real32_T GR;
  real32_T t_f;
  real32_T t_r;
  real32_T l;
  real32_T l_f;
  real32_T l_r;
  real32_T CoG_height;
  real32_T spring_constant_front;
  real32_T spring_constant_rear;
  real32_T motion_ratio_front;
  real32_T motion_ratio_rear;
  real32_T driver_mass;
  real32_T car_mass;
  real32_T r_eff;
  real32_T Kt;
  real32_T Lq;
  real32_T Ld;
  real32_T Jw;
  real32_T Mn;
};

#endif                                 /*struct_sxOEtKrnKDbijZ2mVJTGnCG*/

#ifndef typedef_sxOEtKrnKDbijZ2mVJTGnCG_Contr_T
#define typedef_sxOEtKrnKDbijZ2mVJTGnCG_Contr_T

typedef struct sxOEtKrnKDbijZ2mVJTGnCG sxOEtKrnKDbijZ2mVJTGnCG_Contr_T;

#endif                                 /*typedef_sxOEtKrnKDbijZ2mVJTGnCG_Contr_T*/

/* Parameters (auto storage) */
typedef struct P_Control_System_T_ P_Control_System_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Control_System_T RT_MODEL_Control_System_T;

#endif                                 /* RTW_HEADER_Control_System_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
