/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimations_types.h
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

#ifndef RTW_HEADER_Estimations_types_h_
#define RTW_HEADER_Estimations_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_normalForces_
#define _DEFINED_TYPEDEF_FOR_normalForces_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} normalForces;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SensorInputs_
#define _DEFINED_TYPEDEF_FOR_SensorInputs_

typedef struct {
  real32_T Input_throttle;
  real32_T Input_brake;
  real32_T steering_wheel_angle;
  real32_T steering_wheel_speed;
  real32_T V_x_INS;
  real32_T V_y_INS;
  real32_T V_x_optical;
  real32_T V_y_optical;
  real32_T sideSlipAngle_optical;
  real32_T yawRate;
  real32_T yawRate_der;
  real32_T ay;
  real32_T ax;
  real32_T roll_angle;
  real32_T roll_rate;
  real32_T RPM_FL;
  real32_T RPM_FR;
  real32_T RPM_RL;
  real32_T RPM_RR;
  real32_T KERS_pos;
  real32_T damper_pos_FL;
  real32_T damper_pos_FR;
  real32_T damper_pos_RL;
  real32_T damper_pos_RR;
  real32_T damper_rate_FL;
  real32_T damper_rate_FR;
  real32_T damper_rate_RL;
  real32_T damper_rate_RR;
  real32_T power;
  real32_T Iq_FL;
  real32_T Iq_FR;
  real32_T Iq_RL;
  real32_T Iq_RR;
  real32_T Id_FL;
  real32_T Id_FR;
  real32_T Id_RL;
  real32_T Id_RR;
  real32_T RPM_der_FL;
  real32_T RPM_der_FR;
  real32_T RPM_der_RL;
  real32_T RPM_der_RR;
  real32_T DC_voltage;
} SensorInputs;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_T_meas_
#define _DEFINED_TYPEDEF_FOR_T_meas_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} T_meas;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_normLongTireForce_
#define _DEFINED_TYPEDEF_FOR_normLongTireForce_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} normLongTireForce;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SR_
#define _DEFINED_TYPEDEF_FOR_SR_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} SR;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_OutputTelemetri_est_
#define _DEFINED_TYPEDEF_FOR_OutputTelemetri_est_

typedef struct {
  normLongTireForce normLongTireForce;
  SR SR;
  normalForces Fz_loadTransfer;
  normalForces Fz_Damper;
} OutputTelemetri_est;

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

#ifndef _DEFINED_TYPEDEF_FOR_Fx_
#define _DEFINED_TYPEDEF_FOR_Fx_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} Fx;

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

#ifndef _DEFINED_TYPEDEF_FOR_Whl_speed_
#define _DEFINED_TYPEDEF_FOR_Whl_speed_

typedef struct {
  real32_T FL;
  real32_T FR;
  real32_T RL;
  real32_T RR;
} Whl_speed;

#endif

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

/* Parameters (auto storage) */
typedef struct P_Estimations_T_ P_Estimations_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Estimations_T RT_MODEL_Estimations_T;

#endif                                 /* RTW_HEADER_Estimations_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
