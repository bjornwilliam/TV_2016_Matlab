/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimations.c
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

#include "Estimations.h"
#include "Estimations_private.h"

/* Block signals (auto storage) */
B_Estimations_T Estimations_B;

/* Block states (auto storage) */
DW_Estimations_T Estimations_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Estimations_T Estimations_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Estimations_T Estimations_Y;

/* Real-time model */
RT_MODEL_Estimations_T Estimations_M_;
RT_MODEL_Estimations_T *const Estimations_M = &Estimations_M_;
real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void Estimations_step(void)
{
  real32_T rtb_IndexVector_RL;
  real32_T rtb_IndexVector_RR;
  real32_T rtb_mean_wheel_angle;
  real32_T rtb_Fz_damper_est_FL;
  real32_T rtb_Fz_damper_est_FR;
  real32_T rtb_Fz_damper_est_RL;
  real32_T rtb_Fz_damper_est_RR;
  real32_T rtb_Fz_loadTransfer_est_FL;
  real32_T rtb_Fz_loadTransfer_est_FR;
  real32_T rtb_Fz_loadTransfer_est_RL;
  real32_T rtb_Fz_loadTransfer_est_RR;
  real32_T rtb_DamperRateLookup1;
  real32_T rtb_DamperRateLookup2;
  real32_T rtb_DamperRateLookup3;
  real32_T varargin_1_idx_2;
  real32_T u0;

  /* Outputs for Atomic SubSystem: '<Root>/Estimations' */
  /* MATLAB Function: '<S3>/EstimateFx' incorporates:
   *  BusCreator: '<S3>/BusConversion_InsertedFor_EstimateFx_at_inport_1'
   *  Inport: '<Root>/Sensors_in'
   *  Inport: '<Root>/T_CM'
   */
  /* MATLAB Function 'Estimations/Fx_Estimation/EstimateFx': '<S12>:1' */
  /*  Torque constant */
  /*  Quadrature axis inductance  */
  /*  Direct access inductance */
  /* '<S12>:1:16' */
  /*  Motor inertia */
  /* '<S12>:1:17' */
  /*  Radius center of rim to tire contact */
  /* '<S12>:1:18' */
  /*  Gear ratio */
  /*  Convert RPM Derivative to angular acceleration */
  /* '<S12>:1:20' */
  Estimations_B.c = 6.28318548F / (car_params.GR * 60.0F);

  /* '<S12>:1:21' */
  /* '<S12>:1:22' */
  /* '<S12>:1:23' */
  /* '<S12>:1:24' */
  /* T_FL = (Iq_FL*Kt*sqrt(2)-(Lq-Ld)*Id_FL)*GR; */
  /* T_FR = (Iq_FR*Kt*sqrt(2)-(Lq-Ld)*Id_FR)*GR; */
  /* T_RL = (Iq_RL*Kt*sqrt(2)-(Lq-Ld)*Id_RL)*GR; */
  /* T_RR = (Iq_RR*Kt*sqrt(2)-(Lq-Ld)*Id_RR)*GR; */
  /* '<S12>:1:30' */
  /* '<S12>:1:31' */
  /* '<S12>:1:32' */
  /* '<S12>:1:33' */
  /* '<S12>:1:37' */
  Estimations_B.rtb_Fx_FL = (Estimations_U.T_CM.FL - Estimations_B.c *
    Estimations_U.Sensors_in.RPM_der_FL * car_params.Jw) / car_params.r_eff;

  /* '<S12>:1:38' */
  Estimations_B.rtb_Fx_FR = (Estimations_U.T_CM.FR - Estimations_B.c *
    Estimations_U.Sensors_in.RPM_der_FR * car_params.Jw) / car_params.r_eff;

  /* '<S12>:1:39' */
  Estimations_B.rtb_Fx_RL = (Estimations_U.T_CM.RL - Estimations_B.c *
    Estimations_U.Sensors_in.RPM_der_RL * car_params.Jw) / car_params.r_eff;

  /* '<S12>:1:40' */
  Estimations_B.rtb_Fx_RR = (Estimations_U.T_CM.RR - Estimations_B.c *
    Estimations_U.Sensors_in.RPM_der_RR * car_params.Jw) / car_params.r_eff;

  /* Outputs for Atomic SubSystem: '<S1>/Fz_Estimation' */
  /* Lookup_n-D: '<S4>/DamperRateLookup' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  Estimations_B.c = look1_iflf_binlxpw(Estimations_U.Sensors_in.damper_rate_FL,
    Estimations_P.DamperRateLookup_bp01Data,
    Estimations_P.DamperRateLookup_tableData, 2U);

  /* Lookup_n-D: '<S4>/DamperRateLookup1' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  rtb_DamperRateLookup1 = look1_iflf_binlxpw
    (Estimations_U.Sensors_in.damper_rate_FR,
     Estimations_P.DamperRateLookup1_bp01Data,
     Estimations_P.DamperRateLookup1_tableData, 2U);

  /* Lookup_n-D: '<S4>/DamperRateLookup2' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  rtb_DamperRateLookup2 = look1_iflf_binlxpw
    (Estimations_U.Sensors_in.damper_rate_RL,
     Estimations_P.DamperRateLookup2_bp01Data,
     Estimations_P.DamperRateLookup2_tableData, 2U);

  /* Lookup_n-D: '<S4>/DamperRateLookup3' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  rtb_DamperRateLookup3 = look1_iflf_binlxpw
    (Estimations_U.Sensors_in.damper_rate_RR,
     Estimations_P.DamperRateLookup3_bp01Data,
     Estimations_P.DamperRateLookup3_tableData, 2U);

  /* MATLAB Function: '<S4>/FzEstDamper' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  /* MATLAB Function 'Estimations/Fz_Estimation/FzEstDamper': '<S13>:1' */
  /* '<S13>:1:4' */
  /* '<S13>:1:5' */
  /* '<S13>:1:7' */
  /* '<S13>:1:8' */
  /* '<S13>:1:11' */
  rtb_Fz_damper_est_FL = (car_params.spring_constant_front *
    Estimations_U.Sensors_in.damper_pos_FL + Estimations_B.c) *
    car_params.motion_ratio_front;

  /* '<S13>:1:12' */
  rtb_Fz_damper_est_FR = (car_params.spring_constant_front *
    Estimations_U.Sensors_in.damper_pos_FR + rtb_DamperRateLookup1) *
    car_params.motion_ratio_front;

  /* '<S13>:1:13' */
  rtb_Fz_damper_est_RL = (car_params.spring_constant_rear *
    Estimations_U.Sensors_in.damper_pos_RL + rtb_DamperRateLookup2) *
    car_params.motion_ratio_rear;

  /* '<S13>:1:14' */
  rtb_Fz_damper_est_RR = (car_params.spring_constant_rear *
    Estimations_U.Sensors_in.damper_pos_RR + rtb_DamperRateLookup3) *
    car_params.motion_ratio_rear;

  /* MATLAB Function: '<S4>/FzEstLoadTransfer' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  /* MATLAB Function 'Estimations/Fz_Estimation/FzEstLoadTransfer': '<S14>:1' */
  /* '<S14>:1:7' */
  rtb_DamperRateLookup1 = car_params.car_mass + car_params.driver_mass;

  /*  Total mass( driver + car) X */
  /* '<S14>:1:8' */
  /* Wheel base X */
  /* '<S14>:1:9' */
  /*  X */
  /* '<S14>:1:10' */
  /*  X */
  /* '<S14>:1:12' */
  Estimations_B.c = car_params.t_f * 2.0F;

  /*  Front track X */
  /* '<S14>:1:13' */
  rtb_DamperRateLookup2 = car_params.t_r * 2.0F;

  /*  Rear track X */
  /* '<S14>:1:16' */
  /*  X */
  /* '<S14>:1:19' */
  rtb_Fz_loadTransfer_est_FL = (car_params.l_r * 9.81F / car_params.l -
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) * (0.5F *
    rtb_DamperRateLookup1) - (car_params.l_r * 9.81F / car_params.l -
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) *
    rtb_DamperRateLookup1 * car_params.CoG_height * Estimations_U.Sensors_in.ay /
    (Estimations_B.c * 9.81F);

  /* '<S14>:1:20' */
  rtb_Fz_loadTransfer_est_FR = (car_params.l_r * 9.81F / car_params.l -
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) *
    rtb_DamperRateLookup1 * car_params.CoG_height * Estimations_U.Sensors_in.ay /
    (Estimations_B.c * 9.81F) + (car_params.l_r * 9.81F / car_params.l -
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) * (0.5F *
    rtb_DamperRateLookup1);

  /* '<S14>:1:21' */
  rtb_Fz_loadTransfer_est_RL = (car_params.l_f * 9.81F / car_params.l +
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) * (0.5F *
    rtb_DamperRateLookup1) - (car_params.l_f * 9.81F / car_params.l +
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) *
    rtb_DamperRateLookup1 * car_params.CoG_height * Estimations_U.Sensors_in.ay /
    (rtb_DamperRateLookup2 * 9.81F);

  /* '<S14>:1:22' */
  rtb_Fz_loadTransfer_est_RR = (car_params.l_f * 9.81F / car_params.l +
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) *
    rtb_DamperRateLookup1 * car_params.CoG_height * Estimations_U.Sensors_in.ay /
    (rtb_DamperRateLookup2 * 9.81F) + (car_params.l_f * 9.81F / car_params.l +
    car_params.CoG_height * Estimations_U.Sensors_in.ax / car_params.l) * (0.5F *
    rtb_DamperRateLookup1);

  /* MultiPortSwitch: '<S4>/Index Vector' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (settings.select_Fz_est_method == 1U) {
    Estimations_B.rtb_IndexVector_FL = rtb_Fz_loadTransfer_est_FL;
    Estimations_B.rtb_IndexVector_FR = rtb_Fz_loadTransfer_est_FR;
    rtb_IndexVector_RL = rtb_Fz_loadTransfer_est_RL;
    rtb_IndexVector_RR = rtb_Fz_loadTransfer_est_RR;
  } else {
    Estimations_B.rtb_IndexVector_FL = rtb_Fz_damper_est_FL;
    Estimations_B.rtb_IndexVector_FR = rtb_Fz_damper_est_FR;
    rtb_IndexVector_RL = rtb_Fz_damper_est_RL;
    rtb_IndexVector_RR = rtb_Fz_damper_est_RR;
  }

  /* End of MultiPortSwitch: '<S4>/Index Vector' */
  /* End of Outputs for SubSystem: '<S1>/Fz_Estimation' */

  /* MATLAB Function: '<S7>/calculateWheelangleandSpeed' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  /* MATLAB Function 'Estimations/calculateMeanWheelAngle/calculateWheelangleandSpeed': '<S17>:1' */
  /*  Right now assumes rad for angle, and rad/s for speed */
  /* '<S17>:1:5' */
  rtb_mean_wheel_angle = 0.2536F * Estimations_U.Sensors_in.steering_wheel_angle;

  /* MATLAB Function: '<S5>/whl_v_calculation' incorporates:
   *  Inport: '<Root>/Sensors_in'
   */
  /* '<S17>:1:6' */
  /* MATLAB Function 'Estimations/RPM_to_linearVelocity/whl_v_calculation': '<S15>:1' */
  /*  Steering angle in rad( Mean of front wheels) */
  /* '<S15>:1:6' */
  Estimations_B.c = 6.28318548F / (car_params.GR * 60.0F);

  /*  Determine CoG Vx from motor RPM. Simple atm. Not considering vy. */
  /* '<S15>:1:9' */
  Estimations_B.rtb_whl_speed_FL = Estimations_U.Sensors_in.RPM_FL *
    Estimations_B.c * car_params.r_eff * arm_cos_f32(rtb_mean_wheel_angle) +
    Estimations_U.Sensors_in.yawRate * car_params.t_f;

  /* '<S15>:1:10' */
  Estimations_B.rtb_whl_speed_FR = Estimations_U.Sensors_in.RPM_FR *
    Estimations_B.c * car_params.r_eff * arm_cos_f32(rtb_mean_wheel_angle) -
    Estimations_U.Sensors_in.yawRate * car_params.t_f;

  /* '<S15>:1:11' */
  Estimations_B.rtb_whl_speed_RL = Estimations_U.Sensors_in.RPM_RL *
    Estimations_B.c * car_params.r_eff + Estimations_U.Sensors_in.yawRate *
    car_params.t_r;

  /* '<S15>:1:12' */
  Estimations_B.rtb_whl_speed_RR = Estimations_U.Sensors_in.RPM_RR *
    Estimations_B.c * car_params.r_eff - Estimations_U.Sensors_in.yawRate *
    car_params.t_r;

  /* MultiPortSwitch: '<S10>/Index Vector' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Sensors_in'
   */
  switch (settings.select_velocity_vx) {
   case 1:
    Estimations_B.IndexVector_b = Estimations_P.Constant_Value;
    break;

   case 2:
    Estimations_B.IndexVector_b = Estimations_U.Sensors_in.V_x_INS;
    break;

   default:
    Estimations_B.IndexVector_b = Estimations_U.Sensors_in.V_x_optical;
    break;
  }

  /* End of MultiPortSwitch: '<S10>/Index Vector' */

  /* MATLAB Function: '<S6>/Slip ratio' */
  /* MATLAB Function 'Estimations/SR_Calculation/Slip ratio': '<S16>:1' */
  /* '<S16>:1:10' */
  rtb_DamperRateLookup2 = (real32_T)fabs(Estimations_B.rtb_whl_speed_FL);
  varargin_1_idx_2 = (real32_T)fabs(Estimations_B.IndexVector_b);
  rtb_DamperRateLookup1 = 0.01F;
  if (rtb_DamperRateLookup2 > 0.01F) {
    rtb_DamperRateLookup1 = rtb_DamperRateLookup2;
  }

  if (varargin_1_idx_2 > rtb_DamperRateLookup1) {
    rtb_DamperRateLookup1 = varargin_1_idx_2;
  }

  Estimations_B.rtb_SR_n_FL = (Estimations_B.rtb_whl_speed_FL -
    Estimations_B.IndexVector_b) / rtb_DamperRateLookup1;

  /* '<S16>:1:11' */
  rtb_DamperRateLookup2 = (real32_T)fabs(Estimations_B.rtb_whl_speed_FR);
  varargin_1_idx_2 = (real32_T)fabs(Estimations_B.IndexVector_b);
  rtb_DamperRateLookup1 = 0.01F;
  if (rtb_DamperRateLookup2 > 0.01F) {
    rtb_DamperRateLookup1 = rtb_DamperRateLookup2;
  }

  if (varargin_1_idx_2 > rtb_DamperRateLookup1) {
    rtb_DamperRateLookup1 = varargin_1_idx_2;
  }

  Estimations_B.rtb_SR_n_FR = (Estimations_B.rtb_whl_speed_FR -
    Estimations_B.IndexVector_b) / rtb_DamperRateLookup1;

  /* '<S16>:1:12' */
  rtb_DamperRateLookup2 = (real32_T)fabs(Estimations_B.rtb_whl_speed_RL);
  varargin_1_idx_2 = (real32_T)fabs(Estimations_B.IndexVector_b);
  rtb_DamperRateLookup1 = 0.01F;
  if (rtb_DamperRateLookup2 > 0.01F) {
    rtb_DamperRateLookup1 = rtb_DamperRateLookup2;
  }

  if (varargin_1_idx_2 > rtb_DamperRateLookup1) {
    rtb_DamperRateLookup1 = varargin_1_idx_2;
  }

  Estimations_B.rtb_SR_n_RL = (Estimations_B.rtb_whl_speed_RL -
    Estimations_B.IndexVector_b) / rtb_DamperRateLookup1;

  /* '<S16>:1:13' */
  rtb_DamperRateLookup2 = (real32_T)fabs(Estimations_B.rtb_whl_speed_RR);
  varargin_1_idx_2 = (real32_T)fabs(Estimations_B.IndexVector_b);
  rtb_DamperRateLookup1 = 0.01F;
  if (rtb_DamperRateLookup2 > 0.01F) {
    rtb_DamperRateLookup1 = rtb_DamperRateLookup2;
  }

  if (varargin_1_idx_2 > rtb_DamperRateLookup1) {
    rtb_DamperRateLookup1 = varargin_1_idx_2;
  }

  rtb_DamperRateLookup1 = (Estimations_B.rtb_whl_speed_RR -
    Estimations_B.IndexVector_b) / rtb_DamperRateLookup1;

  /* End of MATLAB Function: '<S6>/Slip ratio' */

  /* MultiPortSwitch: '<S8>/Index Vector' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/Fz_CM'
   */
  /*  if (abs(whl_v.FL) >= abs(V_x)) */
  /*      SR_der.FL = (-ax*omega_FL + omega_der_FL*V_x)/(car_params.r_eff*omega_FL^2); */
  /*  else */
  /*      SR_der.FL = single(0); */
  /*  end */
  /* SR_Kp = tractionControl.Kp; */
  /* SR_Ki = tractionControl.Ki; */
  /* speed = states.V_x; */
  /*  if (states.V_x < 1)  */
  /*      SR_Kp = single(5); */
  /*      SR_Ki = single(0); */
  /*  else */
  /*      SR_Kp = single(5); */
  /*      SR_Ki = single(200); */
  /*  end */
  if (settings.use_estimated_Fz == 0U) {
    Estimations_B.rtb_IndexVector_FL = Estimations_U.Fz_CM.FL;
    Estimations_B.rtb_IndexVector_FR = Estimations_U.Fz_CM.FR;
    rtb_IndexVector_RL = Estimations_U.Fz_CM.RL;
    rtb_IndexVector_RR = Estimations_U.Fz_CM.RR;
  }

  /* End of MultiPortSwitch: '<S8>/Index Vector' */

  /* MATLAB Function: '<S9>/estimateFrictionCoefficient' incorporates:
   *  Inport: '<Root>/Fz_CM'
   */
  /* MATLAB Function 'Estimations/friction_estimation/estimateFrictionCoefficient': '<S18>:1' */
  if (!Estimations_DW.firstIteration_not_empty) {
    /* '<S18>:1:10' */
    Estimations_DW.firstIteration_not_empty = true;

    /*  */
    /* '<S18>:1:12' */
    Estimations_DW.mu_FL = settings.mu;

    /* '<S18>:1:13' */
    Estimations_DW.mu_FR = settings.mu;

    /* '<S18>:1:14' */
    Estimations_DW.mu_RL = settings.mu;

    /* '<S18>:1:15' */
    Estimations_DW.mu_RR = settings.mu;

    /* '<S18>:1:16' */
    rtb_DamperRateLookup3 = 0.0F;

    /* '<S18>:1:17' */
    Estimations_B.c = 0.0F;

    /* '<S18>:1:18' */
    rtb_DamperRateLookup2 = 0.0F;

    /* '<S18>:1:19' */
    varargin_1_idx_2 = 0.0F;
  } else {
    /* '<S18>:1:21' */
    rtb_DamperRateLookup3 = Estimations_B.rtb_Fx_FL / Estimations_U.Fz_CM.FL;

    /* '<S18>:1:22' */
    Estimations_B.c = Estimations_B.rtb_Fx_FR / Estimations_U.Fz_CM.FR;

    /* '<S18>:1:23' */
    rtb_DamperRateLookup2 = Estimations_B.rtb_Fx_RL / Estimations_U.Fz_CM.RL;

    /* '<S18>:1:24' */
    varargin_1_idx_2 = Estimations_B.rtb_Fx_RR / Estimations_U.Fz_CM.RR;
    if ((Estimations_B.rtb_SR_n_FL > 0.09) && (Estimations_B.rtb_SR_n_FL < 0.13))
    {
      /* '<S18>:1:26' */
      /* '<S18>:1:27' */
      u0 = Estimations_B.rtb_Fx_FL / Estimations_U.Fz_CM.FL;
      if (u0 >= Estimations_DW.mu_FL) {
        Estimations_DW.mu_FL = u0;
      }
    }

    if ((Estimations_B.rtb_SR_n_FR > 0.09) && (Estimations_B.rtb_SR_n_FR < 0.15))
    {
      /* '<S18>:1:29' */
      /* '<S18>:1:30' */
      u0 = Estimations_B.rtb_Fx_FR / Estimations_U.Fz_CM.FR;
      if (u0 >= Estimations_DW.mu_FR) {
        Estimations_DW.mu_FR = u0;
      }
    }

    if ((Estimations_B.rtb_SR_n_RL > 0.09) && (Estimations_B.rtb_SR_n_RL < 0.15))
    {
      /* '<S18>:1:33' */
      /* '<S18>:1:34' */
      u0 = Estimations_B.rtb_Fx_RL / Estimations_U.Fz_CM.RL;
      if (u0 >= Estimations_DW.mu_RL) {
        Estimations_DW.mu_RL = u0;
      }
    }

    if ((rtb_DamperRateLookup1 > 0.09) && (rtb_DamperRateLookup1 < 0.15)) {
      /* '<S18>:1:37' */
      /* '<S18>:1:38' */
      u0 = Estimations_B.rtb_Fx_RR / Estimations_U.Fz_CM.RR;
      if (u0 >= Estimations_DW.mu_RR) {
        Estimations_DW.mu_RR = u0;
      }
    }
  }

  /* Outport: '<Root>/States' incorporates:
   *  BusCreator: '<S8>/Bus Creator1'
   *  Inport: '<Root>/Sensors_in'
   *  MATLAB Function: '<S7>/calculateWheelangleandSpeed'
   */
  /* '<S18>:1:43' */
  Estimations_Y.States_a.Input_throttle =
    Estimations_U.Sensors_in.Input_throttle;
  Estimations_Y.States_a.Input_brake = Estimations_U.Sensors_in.Input_brake;
  Estimations_Y.States_a.KERS_pos = Estimations_U.Sensors_in.KERS_pos;
  Estimations_Y.States_a.sideSlipAngle =
    Estimations_U.Sensors_in.sideSlipAngle_optical;
  Estimations_Y.States_a.r = Estimations_U.Sensors_in.yawRate;
  Estimations_Y.States_a.r_der = Estimations_U.Sensors_in.yawRate_der;
  Estimations_Y.States_a.ax = Estimations_U.Sensors_in.ax;
  Estimations_Y.States_a.ay = Estimations_U.Sensors_in.ay;
  Estimations_Y.States_a.RPM_FL = Estimations_U.Sensors_in.RPM_FL;
  Estimations_Y.States_a.RPM_FR = Estimations_U.Sensors_in.RPM_FR;
  Estimations_Y.States_a.RPM_RL = Estimations_U.Sensors_in.RPM_RL;
  Estimations_Y.States_a.RPM_RR = Estimations_U.Sensors_in.RPM_RR;
  Estimations_Y.States_a.power = Estimations_U.Sensors_in.power;
  Estimations_Y.States_a.DC_voltage = Estimations_U.Sensors_in.DC_voltage;
  Estimations_Y.States_a.wheel_angle = rtb_mean_wheel_angle;
  Estimations_Y.States_a.wheel_speed = 0.2536F *
    Estimations_U.Sensors_in.steering_wheel_speed;
  Estimations_Y.States_a.V_x = Estimations_B.IndexVector_b;

  /* MultiPortSwitch: '<S10>/Index Vector1' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  if (settings.select_velocity_vy == 2U) {
    /* Outport: '<Root>/States' incorporates:
     *  Inport: '<Root>/Sensors_in'
     */
    Estimations_Y.States_a.V_y = Estimations_U.Sensors_in.V_y_INS;
  } else {
    /* Outport: '<Root>/States' incorporates:
     *  Inport: '<Root>/Sensors_in'
     */
    Estimations_Y.States_a.V_y = Estimations_U.Sensors_in.V_y_optical;
  }

  /* End of MultiPortSwitch: '<S10>/Index Vector1' */
  /* End of Outputs for SubSystem: '<Root>/Estimations' */

  /* Outport: '<Root>/States' incorporates:
   *  MATLAB Function: '<S9>/estimateFrictionCoefficient'
   */
  Estimations_Y.States_a.Fx_FL = Estimations_B.rtb_Fx_FL;
  Estimations_Y.States_a.Fx_FR = Estimations_B.rtb_Fx_FR;
  Estimations_Y.States_a.Fx_RL = Estimations_B.rtb_Fx_RL;
  Estimations_Y.States_a.Fx_RR = Estimations_B.rtb_Fx_RR;
  Estimations_Y.States_a.Fz_FL = Estimations_B.rtb_IndexVector_FL;
  Estimations_Y.States_a.Fz_FR = Estimations_B.rtb_IndexVector_FR;
  Estimations_Y.States_a.Fz_RL = rtb_IndexVector_RL;
  Estimations_Y.States_a.Fz_RR = rtb_IndexVector_RR;
  Estimations_Y.States_a.whl_v_FL = Estimations_B.rtb_whl_speed_FL;
  Estimations_Y.States_a.whl_v_FR = Estimations_B.rtb_whl_speed_FR;
  Estimations_Y.States_a.whl_v_RL = Estimations_B.rtb_whl_speed_RL;
  Estimations_Y.States_a.whl_v_RR = Estimations_B.rtb_whl_speed_RR;
  Estimations_Y.States_a.SR_FL = Estimations_B.rtb_SR_n_FL;
  Estimations_Y.States_a.SR_FR = Estimations_B.rtb_SR_n_FR;
  Estimations_Y.States_a.SR_RL = Estimations_B.rtb_SR_n_RL;
  Estimations_Y.States_a.SR_RR = rtb_DamperRateLookup1;

  /* Outputs for Atomic SubSystem: '<Root>/Estimations' */
  Estimations_Y.States_a.mu = (((Estimations_DW.mu_FL + Estimations_DW.mu_FR) +
    Estimations_DW.mu_RL) + Estimations_DW.mu_RR) / 4.0F;

  /* End of Outputs for SubSystem: '<Root>/Estimations' */

  /* Outport: '<Root>/whl_v' */
  Estimations_Y.whl_v.FL = Estimations_B.rtb_whl_speed_FL;
  Estimations_Y.whl_v.FR = Estimations_B.rtb_whl_speed_FR;
  Estimations_Y.whl_v.RL = Estimations_B.rtb_whl_speed_RL;
  Estimations_Y.whl_v.RR = Estimations_B.rtb_whl_speed_RR;

  /* Outport: '<Root>/Fx' */
  Estimations_Y.Fx_o.FL = Estimations_B.rtb_Fx_FL;
  Estimations_Y.Fx_o.FR = Estimations_B.rtb_Fx_FR;
  Estimations_Y.Fx_o.RL = Estimations_B.rtb_Fx_RL;
  Estimations_Y.Fx_o.RR = Estimations_B.rtb_Fx_RR;

  /* Outport: '<Root>/SR' */
  Estimations_Y.SR_i.FL = Estimations_B.rtb_SR_n_FL;
  Estimations_Y.SR_i.FR = Estimations_B.rtb_SR_n_FR;
  Estimations_Y.SR_i.RL = Estimations_B.rtb_SR_n_RL;
  Estimations_Y.SR_i.RR = rtb_DamperRateLookup1;

  /* Outport: '<Root>/normLongTireForce' */
  Estimations_Y.normLongTireForce_d.FL = rtb_DamperRateLookup3;
  Estimations_Y.normLongTireForce_d.FR = Estimations_B.c;
  Estimations_Y.normLongTireForce_d.RL = rtb_DamperRateLookup2;
  Estimations_Y.normLongTireForce_d.RR = varargin_1_idx_2;

  /* Outport: '<Root>/OutputTelemetri_est' */
  Estimations_Y.OutputTelemetri_est_l.normLongTireForce.FL =
    rtb_DamperRateLookup3;
  Estimations_Y.OutputTelemetri_est_l.normLongTireForce.FR = Estimations_B.c;
  Estimations_Y.OutputTelemetri_est_l.normLongTireForce.RL =
    rtb_DamperRateLookup2;
  Estimations_Y.OutputTelemetri_est_l.normLongTireForce.RR = varargin_1_idx_2;
  Estimations_Y.OutputTelemetri_est_l.SR.FL = Estimations_B.rtb_SR_n_FL;
  Estimations_Y.OutputTelemetri_est_l.SR.FR = Estimations_B.rtb_SR_n_FR;
  Estimations_Y.OutputTelemetri_est_l.SR.RL = Estimations_B.rtb_SR_n_RL;
  Estimations_Y.OutputTelemetri_est_l.SR.RR = rtb_DamperRateLookup1;
  Estimations_Y.OutputTelemetri_est_l.Fz_loadTransfer.FL =
    rtb_Fz_loadTransfer_est_FL;
  Estimations_Y.OutputTelemetri_est_l.Fz_loadTransfer.FR =
    rtb_Fz_loadTransfer_est_FR;
  Estimations_Y.OutputTelemetri_est_l.Fz_loadTransfer.RL =
    rtb_Fz_loadTransfer_est_RL;
  Estimations_Y.OutputTelemetri_est_l.Fz_loadTransfer.RR =
    rtb_Fz_loadTransfer_est_RR;
  Estimations_Y.OutputTelemetri_est_l.Fz_Damper.FL = rtb_Fz_damper_est_FL;
  Estimations_Y.OutputTelemetri_est_l.Fz_Damper.FR = rtb_Fz_damper_est_FR;
  Estimations_Y.OutputTelemetri_est_l.Fz_Damper.RL = rtb_Fz_damper_est_RL;
  Estimations_Y.OutputTelemetri_est_l.Fz_Damper.RR = rtb_Fz_damper_est_RR;
}

/* Model initialize function */
void Estimations_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Estimations_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Estimations_DW, 0,
                sizeof(DW_Estimations_T));

  /* external inputs */
  (void) memset((void *)&Estimations_U, 0,
                sizeof(ExtU_Estimations_T));

  /* external outputs */
  (void) memset((void *)&Estimations_Y, 0,
                sizeof(ExtY_Estimations_T));

  /* InitializeConditions for Atomic SubSystem: '<Root>/Estimations' */
  /* InitializeConditions for MATLAB Function: '<S9>/estimateFrictionCoefficient' */
  Estimations_DW.firstIteration_not_empty = false;

  /* End of InitializeConditions for SubSystem: '<Root>/Estimations' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
