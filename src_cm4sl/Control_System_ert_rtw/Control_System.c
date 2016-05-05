/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_System.c
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

const States Control_System_rtZStates = {
  0.0F,                                /* Input_throttle */
  0.0F,                                /* Input_brake */
  0.0F,                                /* KERS_pos */
  0.0F,                                /* sideSlipAngle */
  0.0F,                                /* r */
  0.0F,                                /* r_der */
  0.0F,                                /* ax */
  0.0F,                                /* ay */
  0.0F,                                /* RPM_FL */
  0.0F,                                /* RPM_FR */
  0.0F,                                /* RPM_RL */
  0.0F,                                /* RPM_RR */
  0.0F,                                /* power */
  0.0F,                                /* DC_voltage */
  0.0F,                                /* wheel_angle */
  0.0F,                                /* wheel_speed */
  0.0F,                                /* V_x */
  0.0F,                                /* V_y */
  0.0F,                                /* Fx_FL */
  0.0F,                                /* Fx_FR */
  0.0F,                                /* Fx_RL */
  0.0F,                                /* Fx_RR */
  0.0F,                                /* Fz_FL */
  0.0F,                                /* Fz_FR */
  0.0F,                                /* Fz_RL */
  0.0F,                                /* Fz_RR */
  0.0F,                                /* whl_v_FL */
  0.0F,                                /* whl_v_FR */
  0.0F,                                /* whl_v_RL */
  0.0F,                                /* whl_v_RR */
  0.0F,                                /* SR_FL */
  0.0F,                                /* SR_FR */
  0.0F,                                /* SR_RL */
  0.0F,                                /* SR_RR */
  0.0F                                 /* mu */
} ;                                    /* States ground */

/* Exported block parameters */
YawRateControl yawRateControl = {
  0.0F,
  10.0,
  2000.0F,
  4500.0F,
  4500.0F,
  1.0F,
  2000.0F,
  2000.0F,
  1.0F,
  25.0F,
  50.0F,
  50.0F,
  1.0F,
  50.0F,
  1.0F,
  0.5F,
  1U,
  1.0F,
  0U
} ;                                    /* Variable: yawRateControl
                                        * Referenced by:
                                        *   '<S9>/Enable//disable'
                                        *   '<S9>/Ksat'
                                        *   '<S9>/Saturation'
                                        *   '<S44>/TorqueAllocation'
                                        */

TractionControl tractionControl = {
  0.15F,
  0.0F,
  5.0F,
  10.0F,
  8.0F,
  150.0F,
  1.0F,
  120.0F,
  450.0F,
  1.0F,
  150.0F,
  450.0F,
  20.0F,
  1U
} ;                                    /* Variable: tractionControl
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S14>/MATLAB Function1'
                                        *   '<S14>/Constant2'
                                        *   '<S27>/Gain2'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain2'
                                        *   '<S30>/Gain2'
                                        */

PowerLimitControl powerLimitControl = {
  79000.0F,
  100000.0F,
  7.0e-6F,
  0.001F,
  0.1F,
  0.0F,
  -0.7F,
  0U
} ;                                    /* Variable: powerLimitControl
                                        * Referenced by:
                                        *   '<S5>/extractPower'
                                        *   '<S5>/Negative Power limit'
                                        *   '<S5>/Positive Power limit '
                                        *   '<S5>/constant1'
                                        *   '<S10>/Integral Gain'
                                        *   '<S10>/Proportional Gain'
                                        *   '<S10>/Saturate'
                                        *   '<S12>/DeadZone'
                                        */

/* Block signals (auto storage) */
B_Control_System_T Control_System_B;

/* Block states (auto storage) */
DW_Control_System_T Control_System_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Control_System_T Control_System_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Control_System_T Control_System_Y;

/* Real-time model */
RT_MODEL_Control_System_T Control_System_M_;
RT_MODEL_Control_System_T *const Control_System_M = &Control_System_M_;

/* Forward declaration for local functions */
static void Control_Syst_allocateKersTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real32_T T[2], uint32_T *sat);
static void Control_Sy_allocateKersTorque_a(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real32_T T[2], uint32_T *sat);
static void Control__allocatePositiveTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real32_T T[2], uint32_T *sat);
static void Control_System_allocateTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real_T negative_torque_limit, real32_T T[2],
  uint32_T *sat);
static void Contro_allocatePositiveTorque_p(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real32_T T[2], uint32_T *sat);
static void Control_System_allocateTorque_f(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real_T negative_torque_limit, real32_T T[2], uint32_T *sat);
real32_T look1_iflf_binlcapw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
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
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Control_Syst_allocateKersTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real32_T T[2], uint32_T *sat)
{
  real32_T TV_des;
  real32_T T_driver;
  real32_T max_t_add;
  real32_T mtmp;

  /* '<S45>:1:277' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:279' */
  TV_des = (real32_T)fabs(alfa * Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs
    (alfa * Mz_ref * R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:281' */
  T_driver = (real32_T)fabs(alfa * T_req);
  if (Mz_ref + 0.0001F >= 0.0F) {
    /* '<S45>:1:283' */
    /*  Positive Mz_ref requires left side (inner wheels) */
    /*  to brake more than the outer wheels. */
    /* '<S45>:1:286' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (L_max < mtmp) {
      mtmp = L_max;
    }

    /* Max torque that can be added to both */
    if (L_max < TV_des) {
      /* '<S45>:1:288' */
      /* '<S45>:1:289' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:291' */
      max_t_add = L_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (R_max < max_t_add) {
        max_t_add = R_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:293' */
    TV_des = -(mtmp + max_t_add);

    /* '<S45>:1:294' */
    /* '<S45>:1:295' */
    T[0] = TV_des;
    T[1] = -max_t_add;

    /*  Floats comparison */
    if (((real32_T)fabs(TV_des) + (real32_T)fabs(-max_t_add)) + 0.001F <
        T_driver) {
      /* '<S45>:1:297' */
      /* '<S45>:1:298' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:302' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (R_max < mtmp) {
      mtmp = R_max;
    }

    /* Max torque that can be added to both */
    if (R_max < TV_des) {
      /* '<S45>:1:304' */
      /* '<S45>:1:305' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:307' */
      max_t_add = R_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (L_max < max_t_add) {
        max_t_add = L_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:309' */
    TV_des = -(mtmp + max_t_add);

    /* '<S45>:1:310' */
    /* '<S45>:1:311' */
    T[0] = -max_t_add;
    T[1] = TV_des;

    /*  Floats comparison */
    if (((real32_T)fabs(-max_t_add) + (real32_T)fabs(TV_des)) + 0.001F <
        T_driver) {
      /* '<S45>:1:313' */
      /* '<S45>:1:314' */
      *sat = 1U;
    }
  }
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Control_Sy_allocateKersTorque_a(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real32_T T[2], uint32_T *sat)
{
  real32_T TV_des;
  real32_T T_driver;
  real32_T max_t_add;
  real32_T mtmp;

  /* '<S45>:1:277' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:279' */
  TV_des = (real32_T)fabs(Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs(Mz_ref *
    R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:281' */
  T_driver = (real32_T)fabs(T_req);
  if (Mz_ref + 0.0001F >= 0.0F) {
    /* '<S45>:1:283' */
    /*  Positive Mz_ref requires left side (inner wheels) */
    /*  to brake more than the outer wheels. */
    /* '<S45>:1:286' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (L_max < mtmp) {
      mtmp = L_max;
    }

    /* Max torque that can be added to both */
    if (L_max < TV_des) {
      /* '<S45>:1:288' */
      /* '<S45>:1:289' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:291' */
      max_t_add = L_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (R_max < max_t_add) {
        max_t_add = R_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:293' */
    TV_des = -(mtmp + max_t_add);

    /* '<S45>:1:294' */
    /* '<S45>:1:295' */
    T[0] = TV_des;
    T[1] = -max_t_add;

    /*  Floats comparison */
    if (((real32_T)fabs(TV_des) + (real32_T)fabs(-max_t_add)) + 0.001F <
        T_driver) {
      /* '<S45>:1:297' */
      /* '<S45>:1:298' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:302' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (R_max < mtmp) {
      mtmp = R_max;
    }

    /* Max torque that can be added to both */
    if (R_max < TV_des) {
      /* '<S45>:1:304' */
      /* '<S45>:1:305' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:307' */
      max_t_add = R_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (L_max < max_t_add) {
        max_t_add = L_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:309' */
    TV_des = -(mtmp + max_t_add);

    /* '<S45>:1:310' */
    /* '<S45>:1:311' */
    T[0] = -max_t_add;
    T[1] = TV_des;

    /*  Floats comparison */
    if (((real32_T)fabs(-max_t_add) + (real32_T)fabs(TV_des)) + 0.001F <
        T_driver) {
      /* '<S45>:1:313' */
      /* '<S45>:1:314' */
      *sat = 1U;
    }
  }
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Control__allocatePositiveTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real32_T T[2], uint32_T *sat)
{
  real32_T TV_des;
  real32_T T_driver;
  real32_T max_t_add;
  real32_T mtmp;

  /* '<S45>:1:323' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:325' */
  TV_des = (real32_T)fabs(alfa * Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs
    (alfa * Mz_ref * R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:327' */
  T_driver = alfa * T_req;
  if (Mz_ref <= 0.0F) {
    /* '<S45>:1:329' */
    /*  Implies that left side should realize the TV torque, */
    /*  since only torque >= 0 is used here. */
    /*  Mz is defined positive counter clockwise */
    /* '<S45>:1:333' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (L_max < mtmp) {
      mtmp = L_max;
    }

    /* Max torque that can be added to both */
    /* Skal det ikke være L < TV_des */
    if (L_max < TV_des) {
      /* '<S45>:1:336' */
      /* '<S45>:1:337' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:339' */
      max_t_add = L_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (R_max < max_t_add) {
        max_t_add = R_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:341' */
    TV_des = mtmp + max_t_add;

    /* '<S45>:1:343' */
    T[0] = TV_des;
    T[1] = max_t_add;

    /*  Floats comparison */
    if ((TV_des + max_t_add) + 0.001F < T_driver) {
      /* '<S45>:1:345' */
      /* '<S45>:1:346' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:350' */
    mtmp = TV_des;
    if (T_driver < TV_des) {
      mtmp = T_driver;
    }

    if (R_max < mtmp) {
      mtmp = R_max;
    }

    /* Max torque that can be added to both */
    if (R_max < TV_des) {
      /* '<S45>:1:352' */
      /* '<S45>:1:353' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:355' */
      max_t_add = R_max - TV_des;
      TV_des = (T_driver - mtmp) / 2.0F;
      if (L_max < max_t_add) {
        max_t_add = L_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:357' */
    TV_des = mtmp + max_t_add;

    /* '<S45>:1:359' */
    T[0] = max_t_add;
    T[1] = TV_des;

    /*  Floats comparison */
    if ((max_t_add + TV_des) + 0.001F < T_driver) {
      /* '<S45>:1:361' */
      /* '<S45>:1:362' */
      *sat = 1U;
    }
  }
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Control_System_allocateTorque(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T alfa, real32_T
  Mz_ref, real32_T GR, real32_T t, real_T negative_torque_limit, real32_T T[2],
  uint32_T *sat)
{
  real32_T TV_des;
  real32_T T_driver;
  real32_T R;
  real32_T varargin_1_idx_2;

  /* '<S45>:1:229' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:231' */
  TV_des = (real32_T)fabs(alfa * Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs
    (alfa * Mz_ref * R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:233' */
  T_driver = alfa * T_req;
  if (Mz_ref <= 0.0F) {
    /* '<S45>:1:235' */
    /*  Implies that left side should realize the TV torque, */
    /*  since only torque >= 0 is used here. */
    /*  Mz is defined positive counter clockwise */
    /* '<S45>:1:239' */
    R = TV_des;
    if (T_driver < TV_des) {
      R = T_driver;
    }

    if (L_max < R) {
      R = L_max;
    }

    if (R < TV_des) {
      /* '<S45>:1:240' */
      /* && (T_driver > 0)) */
      /*  Not fulfilled desired yaw moment */
      /* '<S45>:1:242' */
      TV_des -= R;
      if (R_max < TV_des) {
        TV_des = R_max;
      }

      if ((real32_T)negative_torque_limit < TV_des) {
        TV_des = (real32_T)negative_torque_limit;
      }

      /* '<S45>:1:243' */
      T[0] = R;
      T[1] = -TV_des;
    } else {
      /* '<S45>:1:245' */
      TV_des = L_max - TV_des;
      varargin_1_idx_2 = (T_driver - R) / 2.0F;
      if (R_max < TV_des) {
        TV_des = R_max;
      }

      if (varargin_1_idx_2 < TV_des) {
        TV_des = varargin_1_idx_2;
      }

      /* '<S45>:1:246' */
      R += TV_des;

      /* '<S45>:1:248' */
      T[0] = R;
      T[1] = TV_des;
    }

    /*  Floats comparison */
    if (R + 0.001F < T_driver) {
      /* '<S45>:1:251' */
      /* '<S45>:1:252' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:256' */
    R = TV_des;
    if (T_driver < TV_des) {
      R = T_driver;
    }

    if (R_max < R) {
      R = R_max;
    }

    /* Max torque that can be added to both   */
    if (R < TV_des) {
      /* '<S45>:1:258' */
      /*  && (T_driver > 0) ) */
      /* '<S45>:1:259' */
      TV_des -= R;
      if (L_max < TV_des) {
        TV_des = L_max;
      }

      if ((real32_T)negative_torque_limit < TV_des) {
        TV_des = (real32_T)negative_torque_limit;
      }

      /* '<S45>:1:260' */
      T[0] = -TV_des;
      T[1] = R;
    } else {
      /* '<S45>:1:262' */
      TV_des = R_max - TV_des;
      varargin_1_idx_2 = (T_driver - R) / 2.0F;
      if (L_max < TV_des) {
        TV_des = L_max;
      }

      if (varargin_1_idx_2 < TV_des) {
        TV_des = varargin_1_idx_2;
      }

      /* '<S45>:1:263' */
      R += TV_des;

      /* '<S45>:1:265' */
      T[0] = TV_des;
      T[1] = R;
    }

    if (R + 0.001F < T_driver) {
      /* '<S45>:1:268' */
      /* '<S45>:1:269' */
      *sat = 1U;
    }
  }
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Contro_allocatePositiveTorque_p(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real32_T T[2], uint32_T *sat)
{
  real32_T TV_des;
  real32_T max_t_add;
  real32_T mtmp;

  /* '<S45>:1:323' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:325' */
  TV_des = (real32_T)fabs(Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs(Mz_ref *
    R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:327' */
  if (Mz_ref <= 0.0F) {
    /* '<S45>:1:329' */
    /*  Implies that left side should realize the TV torque, */
    /*  since only torque >= 0 is used here. */
    /*  Mz is defined positive counter clockwise */
    /* '<S45>:1:333' */
    mtmp = TV_des;
    if (T_req < TV_des) {
      mtmp = T_req;
    }

    if (L_max < mtmp) {
      mtmp = L_max;
    }

    /* Max torque that can be added to both */
    /* Skal det ikke være L < TV_des */
    if (L_max < TV_des) {
      /* '<S45>:1:336' */
      /* '<S45>:1:337' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:339' */
      max_t_add = L_max - TV_des;
      TV_des = (T_req - mtmp) / 2.0F;
      if (R_max < max_t_add) {
        max_t_add = R_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:341' */
    TV_des = mtmp + max_t_add;

    /* '<S45>:1:343' */
    T[0] = TV_des;
    T[1] = max_t_add;

    /*  Floats comparison */
    if ((TV_des + max_t_add) + 0.001F < T_req) {
      /* '<S45>:1:345' */
      /* '<S45>:1:346' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:350' */
    mtmp = TV_des;
    if (T_req < TV_des) {
      mtmp = T_req;
    }

    if (R_max < mtmp) {
      mtmp = R_max;
    }

    /* Max torque that can be added to both */
    if (R_max < TV_des) {
      /* '<S45>:1:352' */
      /* '<S45>:1:353' */
      max_t_add = 0.0F;
    } else {
      /* '<S45>:1:355' */
      max_t_add = R_max - TV_des;
      TV_des = (T_req - mtmp) / 2.0F;
      if (L_max < max_t_add) {
        max_t_add = L_max;
      }

      if (TV_des < max_t_add) {
        max_t_add = TV_des;
      }
    }

    /* '<S45>:1:357' */
    TV_des = mtmp + max_t_add;

    /* '<S45>:1:359' */
    T[0] = max_t_add;
    T[1] = TV_des;

    /*  Floats comparison */
    if ((max_t_add + TV_des) + 0.001F < T_req) {
      /* '<S45>:1:361' */
      /* '<S45>:1:362' */
      *sat = 1U;
    }
  }
}

/* Function for MATLAB Function: '<S44>/TorqueAllocation' */
static void Control_System_allocateTorque_f(real32_T L_max, real32_T R_max,
  real32_T T_req, real32_T R_eff_L, real32_T R_eff_R, real32_T Mz_ref, real32_T
  GR, real32_T t, real_T negative_torque_limit, real32_T T[2], uint32_T *sat)
{
  real32_T TV_des;
  real32_T R;
  real32_T varargin_1_idx_2;

  /* '<S45>:1:229' */
  *sat = 0U;

  /*  Desired torque vectoring torque */
  /* '<S45>:1:231' */
  TV_des = (real32_T)fabs(Mz_ref * R_eff_L / (GR * t)) + (real32_T)fabs(Mz_ref *
    R_eff_R / (GR * t));

  /*  Take absolute value since T_req can be negative in case of KERS */
  /* '<S45>:1:233' */
  if (Mz_ref <= 0.0F) {
    /* '<S45>:1:235' */
    /*  Implies that left side should realize the TV torque, */
    /*  since only torque >= 0 is used here. */
    /*  Mz is defined positive counter clockwise */
    /* '<S45>:1:239' */
    R = TV_des;
    if (T_req < TV_des) {
      R = T_req;
    }

    if (L_max < R) {
      R = L_max;
    }

    if (R < TV_des) {
      /* '<S45>:1:240' */
      /* && (T_driver > 0)) */
      /*  Not fulfilled desired yaw moment */
      /* '<S45>:1:242' */
      TV_des -= R;
      if (R_max < TV_des) {
        TV_des = R_max;
      }

      if ((real32_T)negative_torque_limit < TV_des) {
        TV_des = (real32_T)negative_torque_limit;
      }

      /* '<S45>:1:243' */
      T[0] = R;
      T[1] = -TV_des;
    } else {
      /* '<S45>:1:245' */
      TV_des = L_max - TV_des;
      varargin_1_idx_2 = (T_req - R) / 2.0F;
      if (R_max < TV_des) {
        TV_des = R_max;
      }

      if (varargin_1_idx_2 < TV_des) {
        TV_des = varargin_1_idx_2;
      }

      /* '<S45>:1:246' */
      R += TV_des;

      /* '<S45>:1:248' */
      T[0] = R;
      T[1] = TV_des;
    }

    /*  Floats comparison */
    if (R + 0.001F < T_req) {
      /* '<S45>:1:251' */
      /* '<S45>:1:252' */
      *sat = 1U;
    }
  } else {
    /* '<S45>:1:256' */
    R = TV_des;
    if (T_req < TV_des) {
      R = T_req;
    }

    if (R_max < R) {
      R = R_max;
    }

    /* Max torque that can be added to both   */
    if (R < TV_des) {
      /* '<S45>:1:258' */
      /*  && (T_driver > 0) ) */
      /* '<S45>:1:259' */
      TV_des -= R;
      if (L_max < TV_des) {
        TV_des = L_max;
      }

      if ((real32_T)negative_torque_limit < TV_des) {
        TV_des = (real32_T)negative_torque_limit;
      }

      /* '<S45>:1:260' */
      T[0] = -TV_des;
      T[1] = R;
    } else {
      /* '<S45>:1:262' */
      TV_des = R_max - TV_des;
      varargin_1_idx_2 = (T_req - R) / 2.0F;
      if (L_max < TV_des) {
        TV_des = L_max;
      }

      if (varargin_1_idx_2 < TV_des) {
        TV_des = varargin_1_idx_2;
      }

      /* '<S45>:1:263' */
      R += TV_des;

      /* '<S45>:1:265' */
      T[0] = TV_des;
      T[1] = R;
    }

    if (R + 0.001F < T_req) {
      /* '<S45>:1:268' */
      /* '<S45>:1:269' */
      *sat = 1U;
    }
  }
}

real32_T rt_roundf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Control_System_step(void)
{
  int16_T rtb_Ti_pos_FL;
  int16_T rtb_Ti_pos_FR;
  int16_T rtb_Ti_pos_RL;
  int16_T rtb_Ti_pos_RR;
  int16_T rtb_Ti_neg_FL;
  int16_T rtb_Ti_neg_FR;
  int16_T rtb_Ti_neg_RL;
  int16_T rtb_Ti_neg_RR;
  int16_T rtb_wi_setpoints_FL;
  int16_T rtb_wi_setpoints_FR;
  int16_T rtb_wi_setpoints_RL;
  int16_T rtb_wi_setpoints_RR;
  boolean_T rtb_NotEqual;
  real32_T Fzi_idx_1;
  real32_T Fzi_idx_2;
  real32_T Fzi_idx_3;
  real32_T Ti_max_tire_idx_0;
  real32_T Ti_max_tire_idx_1;
  int8_T rtb_SignDeltaU_0;

  /* Outputs for Atomic SubSystem: '<Root>/Control_System ' */
  /* MATLAB Function: '<S5>/extractPower' incorporates:
   *  Inport: '<Root>/states'
   */
  /* MATLAB Function 'Control_System /Control /Power Limit Torque Reduction Controller /extractPower': '<S11>:1' */
  if (powerLimitControl.enable == 1U) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    Control_System_B.power = Control_System_U.states.power;
  } else {
    /* '<S11>:1:8' */
    Control_System_B.power = 0.0F;
  }

  /* End of MATLAB Function: '<S5>/extractPower' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Negative Power limit'
   *  Constant: '<S5>/Positive Power limit '
   */
  if (Control_System_B.power > Control_System_P.Switch_Threshold) {
    Control_System_B.Fzi_idx_0 = powerLimitControl.positive_power_limit;
  } else {
    Control_System_B.Fzi_idx_0 = powerLimitControl.negative_power_limit;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Abs: '<S5>/Abs'
   */
  Control_System_B.IntegralGain = Control_System_B.Fzi_idx_0 - (real32_T)fabs
    (Control_System_B.power);

  /* Sum: '<S10>/Sum' incorporates:
   *  DiscreteIntegrator: '<S10>/Integrator'
   *  Gain: '<S10>/Proportional Gain'
   */
  Control_System_B.SignDeltaU = powerLimitControl.Kp *
    Control_System_B.IntegralGain + Control_System_DW.Integrator_DSTATE;

  /* MultiPortSwitch: '<S5>/Index Vector' incorporates:
   *  Constant: '<S5>/constant'
   *  Constant: '<S5>/constant1'
   *  Constant: '<S5>/constant2'
   *  Saturate: '<S10>/Saturate'
   *  Sum: '<S5>/Add'
   */
  if (powerLimitControl.enable == 0U) {
    Control_System_B.IndexVector_j = Control_System_P.constant2_Value;
  } else {
    if (Control_System_B.SignDeltaU > powerLimitControl.upper_sat_limit) {
      /* Saturate: '<S10>/Saturate' */
      Control_System_B.Fzi_idx_0 = powerLimitControl.upper_sat_limit;
    } else if (Control_System_B.SignDeltaU < powerLimitControl.lower_sat_limit)
    {
      /* Saturate: '<S10>/Saturate' */
      Control_System_B.Fzi_idx_0 = powerLimitControl.lower_sat_limit;
    } else {
      /* Saturate: '<S10>/Saturate' */
      Control_System_B.Fzi_idx_0 = Control_System_B.SignDeltaU;
    }

    Control_System_B.IndexVector_j = Control_System_P.constant_Value +
      Control_System_B.Fzi_idx_0;
  }

  /* End of MultiPortSwitch: '<S5>/Index Vector' */

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Inport: '<Root>/states'
   */
  /* MATLAB Function 'Control_System /Control /Throttle // Brake Mapping/MATLAB Function': '<S39>:1' */
  /* '<S39>:1:4' */
  /* '<S39>:1:5' */
  /* '<S39>:1:8' */
  Control_System_B.power = settings.max_motor_torque * 4.0F;

  /* '<S39>:1:9' */
  /*  Hysteresis on KERS pedal input to avoid oscillation around  */
  /*  allowed KERS speed.  */
  if (!Control_System_DW.firstIteration_not_empty_f) {
    /* '<S39>:1:17' */
    Control_System_DW.firstIteration_not_empty_f = true;

    /*  Avoid overflow in the register and count 1 again */
    /* '<S39>:1:19' */
    Control_System_DW.KERS_allowed = 0U;
  } else {
    /*  EVALUATE THE CASE WHEN TRACTION CONTROL IS NOT ON AND ALOT OF KERS */
    /*  AND FRICTION BRAKING IS APPLIED -> WHEEL RPM < KERS LIMIT -> KERS */
    /*  RELEASES, BUT FRICTION BRAKING IS NOT ENOUGH TO KEEP WHEEL */
    /*  LOCKED-> WHEEL > KERS LIMIT -> MAXIMUM KERS IS APPLIED AGAIN -> */
    /*  REPEAT...  */
    /*  Hysteresis around the minimum KERS speed */
    if ((Control_System_DW.KERS_allowed == 0U) && (Control_System_U.states.V_x >
         settings.KERS_speed_limit_hyst_high)) {
      /* '<S39>:1:29' */
      /* '<S39>:1:30' */
      Control_System_DW.KERS_allowed = 1U;
    } else {
      if ((Control_System_DW.KERS_allowed == 1U) && (Control_System_U.states.V_x
           < settings.KERS_speed_limit_hyst_low)) {
        /* '<S39>:1:31' */
        /* '<S39>:1:32' */
        Control_System_DW.KERS_allowed = 0U;
      }
    }

    /*  Hysteresis around maximum allowable RPM. */
    /*  The problem is if the motor RPM increases beyond a set limit, */
    /*  around 20k RPM, as no direct speed control is done by the inverter */
    /*  (as we bypass the speed controller).  */
    /*  Find a solution that prohibits (too large) torque requests to the inverters at */
    /*  some RPM limit without oscillating */
    /*  The speed limit set in the inverters must be the last line of */
    /*  defense (as it disabled output stage). While the solution implemented here must be the first.  */
    /*  Perhaps start a torque request derating at LIMIT_START, which at */
    /*  LIMIT_END equals just enough torque to maintain top speed..  */
    /*  Maxmotortorque calculation used in torque allocation will already */
    /*  limit torque to maximum 10-14 Nm for each motor.  */
    /*  I think we should test maximum acceleration while monitoring Max */
    /*  RPM and evaluate if this is even a case...  */
  }

  if (settings.KERS_active == 1U) {
    /* '<S39>:1:57' */
    /* '<S39>:1:58' */
    Control_System_B.T_req = Control_System_B.power *
      Control_System_U.states.Input_throttle - settings.max_motor_brake_torque *
      4.0F * Control_System_U.states.KERS_pos * (real32_T)
      Control_System_DW.KERS_allowed;
  } else {
    /* '<S39>:1:60' */
    Control_System_B.T_req = Control_System_B.power *
      Control_System_U.states.Input_throttle;
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  Inport: '<Root>/states'
   */
  /* MATLAB Function 'Control_System /Control /Torque allocation /MATLAB Function': '<S40>:1' */
  /*  DC Voltage */
  /*  Max allowable current draw in total */
  /*  Load distribution */
  /* '<S40>:1:8' */
  if (1.0F < Control_System_U.states.Fz_FL) {
    Control_System_B.Fzi_idx_0 = Control_System_U.states.Fz_FL;
  } else {
    Control_System_B.Fzi_idx_0 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_FR) {
    Fzi_idx_1 = Control_System_U.states.Fz_FR;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_RL) {
    Fzi_idx_2 = Control_System_U.states.Fz_RL;
  } else {
    Fzi_idx_2 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_RR) {
    Fzi_idx_3 = Control_System_U.states.Fz_RR;
  } else {
    Fzi_idx_3 = 1.0F;
  }

  /* '<S40>:1:10' */
  switch (settings.TV_Method) {
   case 1U:
    /*  No negative torque */
    /* '<S40>:1:12' */
    Control_System_B.power = (Fzi_idx_2 + Fzi_idx_3) /
      (((Control_System_B.Fzi_idx_0 + Fzi_idx_1) + Fzi_idx_2) + Fzi_idx_3);
    break;

   case 2U:
    /*  with negative torque */
    /* '<S40>:1:14' */
    Control_System_B.power = (Fzi_idx_2 + Fzi_idx_3) /
      (((Control_System_B.Fzi_idx_0 + Fzi_idx_1) + Fzi_idx_2) + Fzi_idx_3);
    break;

   case 3U:
    /*  static 25 % */
    /* '<S40>:1:16' */
    Control_System_B.power = 0.5F;
    break;

   case 4U:
    /*  with negative torque, no Fz */
    /* '<S40>:1:18' */
    Control_System_B.power = 0.5F;
    break;

   default:
    /* '<S40>:1:20' */
    Control_System_B.power = 0.5F;
    break;
  }

  /* '<S40>:1:27' */
  /* '<S40>:1:28' */
  /* '<S40>:1:31' */
  if (1.0F < Control_System_U.states.RPM_FL) {
    Fzi_idx_1 = Control_System_U.states.RPM_FL;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  Control_System_B.Fzi_idx_0 = Control_System_U.states.DC_voltage *
    settings.max_battery_discharge * (1.0F - Control_System_B.power) / (2.0F *
    Fzi_idx_1 * 2.0F * 3.14159274F / 60.0F);
  if (settings.max_motor_torque <= Control_System_B.Fzi_idx_0) {
    Control_System_B.Fzi_idx_0 = settings.max_motor_torque;
  }

  if (1.0F < Control_System_U.states.RPM_FR) {
    Fzi_idx_1 = Control_System_U.states.RPM_FR;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  Control_System_B.max_torque_front = Control_System_U.states.DC_voltage *
    settings.max_battery_discharge * (1.0F - Control_System_B.power) / (2.0F *
    Fzi_idx_1 * 2.0F * 3.14159274F / 60.0F);
  if (settings.max_motor_torque <= Control_System_B.max_torque_front) {
    Control_System_B.max_torque_front = settings.max_motor_torque;
  }

  if (Control_System_B.Fzi_idx_0 <= Control_System_B.max_torque_front) {
    Control_System_B.max_torque_front = Control_System_B.Fzi_idx_0;
  }

  /* '<S40>:1:34' */
  if (1.0F < Control_System_U.states.RPM_RL) {
    Fzi_idx_1 = Control_System_U.states.RPM_RL;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  Control_System_B.Fzi_idx_0 = Control_System_U.states.DC_voltage *
    settings.max_battery_discharge * (1.0F - Control_System_B.power) / (2.0F *
    Fzi_idx_1 * 2.0F * 3.14159274F / 60.0F);
  if (settings.max_motor_torque <= Control_System_B.Fzi_idx_0) {
    Control_System_B.Fzi_idx_0 = settings.max_motor_torque;
  }

  if (1.0F < Control_System_U.states.RPM_RR) {
    Fzi_idx_1 = Control_System_U.states.RPM_RR;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  Control_System_B.max_torque_rear = Control_System_U.states.DC_voltage *
    settings.max_battery_discharge * (1.0F - Control_System_B.power) / (2.0F *
    Fzi_idx_1 * 2.0F * 3.14159274F / 60.0F);
  if (settings.max_motor_torque <= Control_System_B.max_torque_rear) {
    Control_System_B.max_torque_rear = settings.max_motor_torque;
  }

  if (Control_System_B.Fzi_idx_0 <= Control_System_B.max_torque_rear) {
    Control_System_B.max_torque_rear = Control_System_B.Fzi_idx_0;
  }

  /* MATLAB Function: '<S9>/yawRateReference' incorporates:
   *  Inport: '<Root>/states'
   */
  /* '<S40>:1:37' */
  /* '<S40>:1:38' */
  /* '<S40>:1:39' */
  /* '<S40>:1:40' */
  /* maxMotorTorque.mmt_FR = min(settings.max_motor_torque,(DC_voltage*max_discharge*(1-alfa_r))/(2*max(1,states.RPM_FR)*2*pi/60)); */
  /* maxMotorTorque.mmt_RL = min(settings.max_motor_torque,(DC_voltage*max_discharge*(alfa_r))/(2*max(1,states.RPM_RL)*2*pi/60)); */
  /* maxMotorTorque.mmt_RR = min(settings.max_motor_torque,(DC_voltage*max_discharge*(alfa_r))/(2*max(1,states.RPM_RR)*2*pi/60)); */
  /* MATLAB Function 'Control_System /Control /Yaw Rate Controller /yawRateReference': '<S46>:1' */
  /* '<S46>:1:6' */
  /* '<S46>:1:8' */
  /* '<S46>:1:9' */
  /*  If Ku is negative there will be a problem if the denominator approaches */
  /*  zero at high speeds */
  /* denominator = (car_params.l_f + car_params.l_r + car_params.Ku*states.V_x^2); */
  /* r_ref = (states.V_x/(car_params.l_f + car_params.l_r + car_params.Ku*states.V_x^2))* delta; */
  /* '<S46>:1:18' */
  /* '<S46>:1:19' */
  Control_System_B.r_ref = Control_System_U.states.V_x / 1.5F *
    Control_System_U.states.wheel_angle;

  /* Fzi = [states.Fz_FL states.Fz_FR states.Fz_RL states.Fz_RR]; */
  /*      ay_max = (1/car_params.mass)*sqrt(max(0, sum(Fzi.*settings.mu_max_r)^2 - (car_params.mass*abs(states.ax))^2)); */
  /*      r_lim = (ay_max/abs(states.V_x))*sign(r_ref); */
  /*      if abs(r_ref) > abs(r_lim)  */
  /*          r_ref = r_lim; */
  /*      end */
  /* '<S46>:1:31' */
  Control_System_B.power = settings.mu * 9.81F / Control_System_U.states.V_x;
  if ((real32_T)fabs(Control_System_B.r_ref) > (real32_T)fabs
      (Control_System_B.power)) {
    /* '<S46>:1:32' */
    /* '<S46>:1:33' */
    if (Control_System_B.r_ref < 0.0F) {
      Control_System_B.r_ref = -1.0F;
    } else {
      if (Control_System_B.r_ref > 0.0F) {
        Control_System_B.r_ref = 1.0F;
      }
    }

    Control_System_B.r_ref *= Control_System_B.power;
  }

  /* '<S46>:1:37' */
  /* '<S46>:1:38' */
  Control_System_B.r_error = Control_System_B.r_ref - Control_System_U.states.r;

  /* Lookup_n-D: '<S9>/Kd lookup' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  /* '<S46>:1:40' */
  /* '<S46>:1:41' */
  /* '<S46>:1:44' */
  /* --------------------------% */
  /* -----FEED FORWARD---------% */
  /* --------------------------% */
  /*  Cornering Stiffnesses */
  /*  Cr = 26000; */
  /*  Cf = 26000; */
  /*   */
  /*  lf = car_params.l_f; */
  /*  lr = car_params.l_r; */
  /*  Nbeta = lf*Cf - lr*Cr; */
  /*  Nr = (lf^2*Cf + lr^2*Cr)/states.V_x; */
  /*  Ndelta = -lf*Cf; */
  /*  Ybeta = Cf+Cr; */
  /*  Yr = (lf*Cf - lr*Cr)/states.V_x; */
  /*  Ydelta = -Cf; */
  /*   */
  /*  C = car_params.mass*states.V_x*Nbeta + Nr*Ybeta - Nbeta*Yr; */
  /*   */
  /*  E = Nbeta*Ydelta - Ndelta*Ybeta; */
  /*  F1 = -Ybeta; */
  /*   */
  /*  Mz_FF = (C*r_ref/delta - E)*delta/(F1); */
  Control_System_B.power = look1_iflf_binlcapw(Control_System_P.Gain1_Gain_f *
    Control_System_U.states.V_x, Control_System_P.Kdlookup_bp01Data,
    Control_System_P.Kdlookup_tableData, 1U);

  /* Product: '<S9>/Product10' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  Control_System_B.Product10 = ((Control_System_U.states.ax *
    Control_System_U.states.wheel_angle + Control_System_U.states.V_x *
    Control_System_U.states.wheel_speed) / 1.5F - Control_System_U.states.r_der *
    0.5F) * Control_System_B.power;

  /* Lookup_n-D: '<S9>/Kp Lookup' incorporates:
   *  Gain: '<S9>/Gain'
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  Control_System_B.power = look1_iflf_binlcapw(Control_System_P.Gain_Gain_ip *
    Control_System_U.states.V_x, Control_System_P.KpLookup_bp01Data,
    Control_System_P.KpLookup_tableData, 1U);

  /* Product: '<S9>/Product3' incorporates:
   *  Constant: '<S9>/Enable//disable'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator2'
   *  Product: '<S9>/Product7'
   *  Sum: '<S9>/Sum2'
   */
  Control_System_B.Saturation = ((Control_System_B.power *
    Control_System_B.r_error + Control_System_B.Product10) +
    Control_System_DW.DiscreteTimeIntegrator2_DSTATE) * (real32_T)
    yawRateControl.enable;

  /* Saturate: '<S9>/Saturation' */
  if (Control_System_B.Saturation > yawRateControl.max_moment) {
    Control_System_B.Saturation = yawRateControl.max_moment;
  } else {
    if (Control_System_B.Saturation < Control_System_P.Saturation_LowerSat) {
      Control_System_B.Saturation = Control_System_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* MATLAB Function: '<S44>/TorqueAllocation' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S8>/MATLAB Function'
   */
  /* MATLAB Function 'Control_System /Control /Torque allocation /Torque Allocation/TorqueAllocation': '<S45>:1' */
  /* STATES */
  /* '<S45>:1:5' */
  /* PARAMETERS */
  /* mu = states.mu; */
  /* '<S45>:1:9' */
  /* '<S45>:1:10' */
  Control_System_B.tf = car_params.t_f * 2.0F;

  /* '<S45>:1:11' */
  Control_System_B.tr = car_params.t_r * 2.0F;

  /* '<S45>:1:12' */
  /* '<S45>:1:13' */
  /* '<S45>:1:14' */
  /* Load Transfer */
  /* '<S45>:1:16' */
  if (1.0F < Control_System_U.states.Fz_FL) {
    Control_System_B.Fzi_idx_0 = Control_System_U.states.Fz_FL;
  } else {
    Control_System_B.Fzi_idx_0 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_FR) {
    Fzi_idx_1 = Control_System_U.states.Fz_FR;
  } else {
    Fzi_idx_1 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_RL) {
    Fzi_idx_2 = Control_System_U.states.Fz_RL;
  } else {
    Fzi_idx_2 = 1.0F;
  }

  if (1.0F < Control_System_U.states.Fz_RR) {
    Fzi_idx_3 = Control_System_U.states.Fz_RR;
  } else {
    Fzi_idx_3 = 1.0F;
  }

  /* '<S45>:1:17' */
  Control_System_B.power = (Fzi_idx_2 + Fzi_idx_3) /
    (((Control_System_B.Fzi_idx_0 + Fzi_idx_1) + Fzi_idx_2) + Fzi_idx_3);

  /* MZ */
  /* '<S45>:1:19' */
  /* '<S45>:1:21' */
  Control_System_B.l1 = car_params.t_f * arm_cos_f32
    (Control_System_U.states.wheel_angle);

  /* '<S45>:1:22' */
  Control_System_B.l2 = car_params.t_f * arm_cos_f32
    (Control_System_U.states.wheel_angle);

  /* '<S45>:1:23' */
  /* '<S45>:1:24' */
  /* '<S45>:1:25' */
  /* FIND MAXIMUM ALLOWED MOTOR TORQUE, TIRE/MOTOR */
  /* '<S45>:1:30' */
  /* '<S45>:1:31' */
  /* '<S45>:1:34' */
  /* Tire saturation based on mu and Fz */
  /* '<S45>:1:37' */
  /* '<S45>:1:38' */
  Ti_max_tire_idx_0 = Control_System_B.Fzi_idx_0 * settings.mu *
    car_params.r_eff / car_params.GR;

  /* '<S45>:1:37' */
  /* '<S45>:1:38' */
  Ti_max_tire_idx_1 = Fzi_idx_1 * settings.mu * car_params.r_eff / car_params.GR;

  /* '<S45>:1:37' */
  /* '<S45>:1:38' */
  Fzi_idx_1 = Fzi_idx_2 * settings.mu * car_params.r_eff / car_params.GR;

  /* '<S45>:1:37' */
  /* '<S45>:1:38' */
  Control_System_B.Fzi_idx_0 = Fzi_idx_3 * settings.mu * car_params.r_eff /
    car_params.GR;

  /* '<S45>:1:37' */
  /*  Find minimum of tire saturation Torque and motor */
  /* '<S45>:1:43' */
  /* '<S45>:1:44' */
  if (!(Ti_max_tire_idx_0 <= Control_System_B.max_torque_front)) {
    Ti_max_tire_idx_0 = Control_System_B.max_torque_front;
  }

  /* '<S45>:1:43' */
  /* '<S45>:1:44' */
  if (!(Ti_max_tire_idx_1 <= Control_System_B.max_torque_front)) {
    Ti_max_tire_idx_1 = Control_System_B.max_torque_front;
  }

  /* '<S45>:1:43' */
  /* '<S45>:1:44' */
  if (!(Fzi_idx_1 <= Control_System_B.max_torque_rear)) {
    Fzi_idx_1 = Control_System_B.max_torque_rear;
  }

  /* '<S45>:1:43' */
  /* '<S45>:1:44' */
  if (!(Control_System_B.Fzi_idx_0 <= Control_System_B.max_torque_rear)) {
    Control_System_B.Fzi_idx_0 = Control_System_B.max_torque_rear;
  }

  /* '<S45>:1:43' */
  /* **********************************************% */
  /* '<S45>:1:48' */
  Control_System_B.T_F[0] = 0.0F;
  Control_System_B.T_F[1] = 0.0F;

  /* '<S45>:1:49' */
  Control_System_B.T_R[0] = 0.0F;
  Control_System_B.T_R[1] = 0.0F;

  /* '<S45>:1:50' */
  Control_System_B.sat_F = 0U;

  /* '<S45>:1:51' */
  Control_System_B.sat_R = 0U;
  if (Control_System_B.T_req >= 0.0F) {
    /* '<S45>:1:53' */
    /* '<S45>:1:54' */
    switch (settings.TV_Method) {
     case 1U:
      /*  Only positive Torque */
      Control__allocatePositiveTorque(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff, 1.0F -
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tf, Control_System_B.T_F, &Control_System_B.sat_F);

      /* '<S45>:1:57' */
      Control__allocatePositiveTorque(Fzi_idx_1, Control_System_B.Fzi_idx_0,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff,
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tr, Control_System_B.T_R, &Control_System_B.sat_R);

      /* '<S45>:1:58' */
      break;

     case 2U:
      /*  Can also allocate negative torque */
      Control_System_allocateTorque(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff, 1.0F -
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tf, yawRateControl.negative_torque_limit,
        Control_System_B.T_F, &Control_System_B.sat_F);

      /* '<S45>:1:61' */
      Control_System_allocateTorque(Fzi_idx_1, Control_System_B.Fzi_idx_0,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff,
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tr, yawRateControl.negative_torque_limit,
        Control_System_B.T_R, &Control_System_B.sat_R);

      /* '<S45>:1:62' */
      break;

     case 3U:
      /*  Static 25 percent to each wheel */
      /* '<S45>:1:65' */
      Control_System_B.T_F[0] = 0.25F * Control_System_B.T_req;
      Control_System_B.T_F[1] = 0.25F * Control_System_B.T_req;

      /* '<S45>:1:66' */
      Control_System_B.T_R[0] = 0.25F * Control_System_B.T_req;
      Control_System_B.T_R[1] = 0.25F * Control_System_B.T_req;
      break;

     case 4U:
      /*  Allocation with negative torque, but does not use Fz */
      Control_System_allocateTorque(Control_System_B.max_torque_front,
        Control_System_B.max_torque_front, Control_System_B.T_req,
        car_params.r_eff, car_params.r_eff, 1.0F - Control_System_B.power,
        Control_System_B.Saturation, car_params.GR, Control_System_B.tf,
        yawRateControl.negative_torque_limit, Control_System_B.T_F,
        &Control_System_B.sat_F);

      /* '<S45>:1:69' */
      Control_System_allocateTorque(Control_System_B.max_torque_rear,
        Control_System_B.max_torque_rear, Control_System_B.T_req,
        car_params.r_eff, car_params.r_eff, Control_System_B.power,
        Control_System_B.Saturation, car_params.GR, Control_System_B.tr,
        yawRateControl.negative_torque_limit, Control_System_B.T_R,
        &Control_System_B.sat_R);

      /* '<S45>:1:70' */
      break;
    }

    if (!((Control_System_B.sat_F == 1U) && (Control_System_B.sat_R == 1U))) {
      if ((Control_System_B.sat_F == 1U) && (Control_System_B.sat_R == 0U)) {
        /* '<S45>:1:75' */
        if (Control_System_B.T_F[0] < 0.0F) {
          /* '<S45>:1:76' */
          /* '<S45>:1:77' */
          Control_System_B.power = Control_System_B.T_req -
            Control_System_B.T_F[1];
        } else if (Control_System_B.T_F[1] < 0.0F) {
          /* '<S45>:1:78' */
          /* '<S45>:1:79' */
          Control_System_B.power = Control_System_B.T_req -
            Control_System_B.T_F[0];
        } else {
          /* '<S45>:1:81' */
          Control_System_B.power = Control_System_B.T_req -
            (Control_System_B.T_F[0] + Control_System_B.T_F[1]);
        }

        if (yawRateControl.enable == 1U) {
          /* '<S45>:1:84' */
          /* '<S45>:1:85' */
          Control_System_B.Product10 = Control_System_B.Saturation -
            (-Control_System_B.l1 * car_params.GR * Control_System_B.T_F[0] /
             car_params.r_eff + Control_System_B.l2 * car_params.GR *
             Control_System_B.T_F[1] / car_params.r_eff);
        } else {
          /* '<S45>:1:87' */
          Control_System_B.Product10 = 0.0F;
        }

        /* '<S45>:1:90' */
        switch (settings.TV_Method) {
         case 1U:
          /*  Only positive Torque */
          Contro_allocatePositiveTorque_p(Fzi_idx_1, Control_System_B.Fzi_idx_0,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tr,
            Control_System_B.T_R, &Control_System_B.sat_F);

          /* '<S45>:1:93' */
          break;

         case 2U:
          /*  Can also allocate negative torque */
          Control_System_allocateTorque_f(Fzi_idx_1, Control_System_B.Fzi_idx_0,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tr,
            yawRateControl.negative_torque_limit, Control_System_B.T_R,
            &Control_System_B.sat_F);

          /* '<S45>:1:96' */
          break;

         case 4U:
          Control_System_allocateTorque_f(Control_System_B.max_torque_rear,
            Control_System_B.max_torque_rear, Control_System_B.power,
            car_params.r_eff, car_params.r_eff, Control_System_B.Product10,
            car_params.GR, Control_System_B.tr,
            yawRateControl.negative_torque_limit, Control_System_B.T_R,
            &Control_System_B.sat_F);

          /* '<S45>:1:98' */
          break;
        }
      } else if ((Control_System_B.sat_F == 0U) && (Control_System_B.sat_R == 1U))
      {
        /* '<S45>:1:100' */
        if (Control_System_B.T_R[0] < 0.0F) {
          /* '<S45>:1:101' */
          /* '<S45>:1:102' */
          Control_System_B.power = Control_System_B.T_req -
            Control_System_B.T_R[1];
        } else if (Control_System_B.T_R[1] < 0.0F) {
          /* '<S45>:1:103' */
          /* '<S45>:1:104' */
          Control_System_B.power = Control_System_B.T_req -
            Control_System_B.T_R[0];
        } else {
          /* '<S45>:1:106' */
          Control_System_B.power = Control_System_B.T_req -
            (Control_System_B.T_R[0] + Control_System_B.T_R[1]);
        }

        /*  For example rear is saturated, and front can still use more torque */
        /* T_remaining = T_req - (T_R(1) + T_R(2)); */
        if (yawRateControl.enable == 1U) {
          /* '<S45>:1:110' */
          /* '<S45>:1:111' */
          Control_System_B.Product10 = Control_System_B.Saturation -
            (-car_params.t_r * car_params.GR * Control_System_B.T_R[0] /
             car_params.r_eff + car_params.t_r * car_params.GR *
             Control_System_B.T_R[1] / car_params.r_eff);
        } else {
          /* '<S45>:1:113' */
          Control_System_B.Product10 = 0.0F;
        }

        /* Mz_remaining = Mz_ref*(1-alfa_r); */
        /* '<S45>:1:116' */
        switch (settings.TV_Method) {
         case 1U:
          /*  Only positive Torque */
          Contro_allocatePositiveTorque_p(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tf,
            Control_System_B.T_F, &Control_System_B.sat_F);

          /* '<S45>:1:119' */
          break;

         case 2U:
          /*  Can also allocate negative torque */
          Control_System_allocateTorque_f(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tf,
            yawRateControl.negative_torque_limit, Control_System_B.T_F,
            &Control_System_B.sat_F);

          /* '<S45>:1:122' */
          break;

         case 4U:
          Control_System_allocateTorque_f(Control_System_B.max_torque_front,
            Control_System_B.max_torque_front, Control_System_B.power,
            car_params.r_eff, car_params.r_eff, Control_System_B.Product10,
            car_params.GR, Control_System_B.tf,
            yawRateControl.negative_torque_limit, Control_System_B.T_F,
            &Control_System_B.sat_F);

          /* '<S45>:1:124' */
          break;
        }
      } else {
        /* both false */
        /*  Nothing to do here either */
      }
    } else {
      /* '<S45>:1:73' */
      /*  Nothing more to do */
    }
  } else {
    /* REGENERATIVE BRAKE COMMAND ( T_DRIVER_REQ < 0 ) */
    /* '<S45>:1:132' */
    switch (settings.TV_Method) {
     case 1U:
      /*  Only positive Torque */
      Control_Syst_allocateKersTorque(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff, 1.0F -
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tf, Control_System_B.T_F, &Control_System_B.sat_F);

      /* '<S45>:1:135' */
      Control_Syst_allocateKersTorque(Fzi_idx_1, Control_System_B.Fzi_idx_0,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff,
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tr, Control_System_B.T_R, &Control_System_B.sat_R);

      /* '<S45>:1:136' */
      break;

     case 2U:
      /*  Can also allocate negative torque */
      Control_Syst_allocateKersTorque(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff, 1.0F -
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tf, Control_System_B.T_F, &Control_System_B.sat_F);

      /* '<S45>:1:140' */
      Control_Syst_allocateKersTorque(Fzi_idx_1, Control_System_B.Fzi_idx_0,
        Control_System_B.T_req, car_params.r_eff, car_params.r_eff,
        Control_System_B.power, Control_System_B.Saturation, car_params.GR,
        Control_System_B.tr, Control_System_B.T_R, &Control_System_B.sat_R);

      /* '<S45>:1:141' */
      break;

     case 3U:
      /*  Static 25 percent to each wheel */
      /* '<S45>:1:144' */
      Control_System_B.T_F[0] = 0.25F * Control_System_B.T_req;
      Control_System_B.T_F[1] = 0.25F * Control_System_B.T_req;

      /* '<S45>:1:145' */
      Control_System_B.T_R[0] = 0.25F * Control_System_B.T_req;
      Control_System_B.T_R[1] = 0.25F * Control_System_B.T_req;
      break;

     case 4U:
      /*  Allocation with negative torque, but does not use Fz */
      Control_Syst_allocateKersTorque(Control_System_B.max_torque_front,
        Control_System_B.max_torque_front, Control_System_B.T_req,
        car_params.r_eff, car_params.r_eff, 1.0F - Control_System_B.power,
        Control_System_B.Saturation, car_params.GR, Control_System_B.tf,
        Control_System_B.T_F, &Control_System_B.sat_F);

      /* '<S45>:1:148' */
      Control_Syst_allocateKersTorque(Control_System_B.max_torque_rear,
        Control_System_B.max_torque_rear, Control_System_B.T_req,
        car_params.r_eff, car_params.r_eff, Control_System_B.power,
        Control_System_B.Saturation, car_params.GR, Control_System_B.tr,
        Control_System_B.T_R, &Control_System_B.sat_R);

      /* '<S45>:1:149' */
      break;
    }

    if (!((Control_System_B.sat_F == 1U) && (Control_System_B.sat_R == 1U))) {
      if ((Control_System_B.sat_F == 1U) && (Control_System_B.sat_R == 0U)) {
        /* '<S45>:1:154' */
        /* '<S45>:1:155' */
        Control_System_B.power = Control_System_B.T_req - (Control_System_B.T_F
          [0] + Control_System_B.T_F[1]);

        /* Disable Mz_remaining if yaw control disabled? */
        if (yawRateControl.enable == 1U) {
          /* '<S45>:1:157' */
          /* '<S45>:1:158' */
          Control_System_B.Product10 = Control_System_B.Saturation -
            (-Control_System_B.l1 * car_params.GR * Control_System_B.T_F[0] /
             car_params.r_eff + Control_System_B.l2 * car_params.GR *
             Control_System_B.T_F[1] / car_params.r_eff);
        } else {
          /* '<S45>:1:160' */
          Control_System_B.Product10 = 0.0F;
        }

        /* '<S45>:1:162' */
        switch (settings.TV_Method) {
         case 1U:
          /*  Only positive Torque */
          Control_Sy_allocateKersTorque_a(Fzi_idx_1, Control_System_B.Fzi_idx_0,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tr,
            Control_System_B.T_R, &Control_System_B.sat_F);

          /* '<S45>:1:165' */
          break;

         case 2U:
          /*  Can also allocate negative torque */
          Control_Sy_allocateKersTorque_a(Fzi_idx_1, Control_System_B.Fzi_idx_0,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tr,
            Control_System_B.T_R, &Control_System_B.sat_F);

          /* '<S45>:1:169' */
          break;

         case 3U:
          /*  Static 25 % */
          break;

         case 4U:
          /*  Allocation with negative torque, but does not use Fz */
          Control_Sy_allocateKersTorque_a(Control_System_B.max_torque_rear,
            Control_System_B.max_torque_rear, Control_System_B.power,
            car_params.r_eff, car_params.r_eff, Control_System_B.Product10,
            car_params.GR, Control_System_B.tr, Control_System_B.T_R,
            &Control_System_B.sat_F);

          /* '<S45>:1:174' */
          break;
        }
      } else if ((Control_System_B.sat_F == 0U) && (Control_System_B.sat_R == 1U))
      {
        /* '<S45>:1:177' */
        /* For example rear is saturated, and front can still use more torque */
        /* '<S45>:1:179' */
        Control_System_B.power = Control_System_B.T_req - (Control_System_B.T_R
          [0] + Control_System_B.T_R[1]);

        /* Mz_remaining = Mz_ref*(1-alfa_r); */
        if (yawRateControl.enable == 1U) {
          /* '<S45>:1:182' */
          /* '<S45>:1:183' */
          Control_System_B.Product10 = Control_System_B.Saturation -
            (-car_params.t_r * car_params.GR * Control_System_B.T_R[0] /
             car_params.r_eff + car_params.t_r * car_params.GR *
             Control_System_B.T_R[1] / car_params.r_eff);
        } else {
          /* '<S45>:1:185' */
          Control_System_B.Product10 = 0.0F;
        }

        /* '<S45>:1:187' */
        switch (settings.TV_Method) {
         case 1U:
          /*  Only positive Torque */
          Control_Sy_allocateKersTorque_a(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tf,
            Control_System_B.T_F, &Control_System_B.sat_F);

          /* '<S45>:1:190' */
          break;

         case 2U:
          /*  Can also allocate negative torque */
          Control_Sy_allocateKersTorque_a(Ti_max_tire_idx_0, Ti_max_tire_idx_1,
            Control_System_B.power, car_params.r_eff, car_params.r_eff,
            Control_System_B.Product10, car_params.GR, Control_System_B.tf,
            Control_System_B.T_F, &Control_System_B.sat_F);

          /* '<S45>:1:194' */
          break;

         case 3U:
          /*  Static 25 % */
          break;

         case 4U:
          /*  Allocation with negative torque, but does not use Fz */
          Control_Sy_allocateKersTorque_a(Control_System_B.max_torque_front,
            Control_System_B.max_torque_front, Control_System_B.power,
            car_params.r_eff, car_params.r_eff, Control_System_B.Product10,
            car_params.GR, Control_System_B.tf, Control_System_B.T_F,
            &Control_System_B.sat_F);

          /* '<S45>:1:199' */
          break;
        }
      } else {
        /* both false */
        /* Nothing to do here either */
      }
    } else {
      /* '<S45>:1:151' */
      /* Nothing more to do */
    }
  }

  /* '<S45>:1:207' */
  /* '<S45>:1:210' */
  /* '<S45>:1:211' */
  /* '<S45>:1:212' */
  /* '<S45>:1:213' */
  /* '<S45>:1:215' */
  /*  Calculate what yaw moment that was achieved with the current  */
  /*  allocation */
  /* '<S45>:1:219' */
  /* '<S45>:1:220' */
  /* '<S45>:1:221' */
  Control_System_B.Mz_error = Control_System_B.Saturation - (((1.0F /
    car_params.r_eff * Control_System_B.T_F[0] * car_params.GR *
    -Control_System_B.l1 + 1.0F / car_params.r_eff * Control_System_B.T_F[1] *
    car_params.GR * Control_System_B.l2) + 1.0F / car_params.r_eff *
    Control_System_B.T_R[0] * car_params.GR * -car_params.t_r) + 1.0F /
    car_params.r_eff * Control_System_B.T_R[1] * car_params.GR * car_params.t_r);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Gain: '<S27>/Gain'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_F[0] > Control_System_P.Switch_Threshold_c) {
    Control_System_B.max_torque_rear = Control_System_P.Constant_Value_h;
  } else {
    Control_System_B.max_torque_rear = Control_System_P.Gain_Gain *
      Control_System_B.T_F[0];
  }

  /* End of Switch: '<S27>/Switch' */

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator2' incorporates:
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (((Control_System_B.T_F[0] > 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevRes <= 0)) ||
      ((Control_System_B.T_F[0] <= 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevRes == 1))) {
    Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n =
      Control_System_P.DiscreteTimeIntegrator2_IC_f;
  }

  /* Switch: '<S27>/Switch1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Gain: '<S27>/Gain1'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_F[0] > Control_System_P.Switch1_Threshold) {
    Control_System_B.tr = Control_System_P.Gain1_Gain * Control_System_B.T_F[0];
  } else {
    Control_System_B.tr = Control_System_P.Constant1_Value;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S31>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator2'
   *  RelationalOperator: '<S31>/LowerRelop1'
   *  RelationalOperator: '<S31>/UpperRelop'
   *  Switch: '<S31>/Switch'
   */
  if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n >
      Control_System_B.max_torque_rear) {
    Control_System_B.Switch2_n = Control_System_B.max_torque_rear;
  } else if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n <
             Control_System_B.tr) {
    /* Switch: '<S31>/Switch' */
    Control_System_B.Switch2_n = Control_System_B.tr;
  } else {
    Control_System_B.Switch2_n =
      Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n;
  }

  /* End of Switch: '<S31>/Switch2' */

  /* MATLAB Function: '<S14>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/states'
   */
  /* MATLAB Function 'Control_System /Control /Slip Rate Control /Traction Controllers/MATLAB Function1': '<S26>:1' */
  /* '<S26>:1:5' */
  /* '<S26>:1:6' */
  /* '<S26>:1:7' */
  /* '<S26>:1:8' */
  /* '<S26>:1:10' */
  /* '<S26>:1:11' */
  Control_System_B.Product10 = Control_System_U.states.V_x * 3.6F;

  /* '<S26>:1:15' */
  Control_System_B.power = (tractionControl.Kp_end - tractionControl.Kp_start) /
    tractionControl.lookup_speed_end_kmh;

  /* '<S26>:1:16' */
  Control_System_B.tf = (tractionControl.Ki_end - tractionControl.Ki_start) /
    tractionControl.lookup_speed_end_kmh;
  if ((Control_System_B.T_req + 0.0001F > 0.0F) && (Control_System_B.Product10 <
       tractionControl.full_gain_limit_kmh)) {
    /* '<S26>:1:19' */
    /* '<S26>:1:20' */
    if (0.0F < Control_System_B.Product10) {
      Fzi_idx_1 = Control_System_B.Product10;
    } else {
      Fzi_idx_1 = 0.0F;
    }

    Control_System_B.Fzi_idx_0 = Control_System_B.power * Fzi_idx_1 +
      tractionControl.Kp_start;
    if (!(Control_System_B.Fzi_idx_0 <= tractionControl.Kp_end)) {
      Control_System_B.Fzi_idx_0 = tractionControl.Kp_end;
    }

    Control_System_B.max_torque_front = Control_System_B.Fzi_idx_0 * (real32_T)
      fabs(Control_System_B.T_req) / (settings.max_motor_torque * 4.0F);

    /* '<S26>:1:21' */
    if (!(0.0F < Control_System_B.Product10)) {
      Control_System_B.Product10 = 0.0F;
    }

    Control_System_B.Fzi_idx_0 = Control_System_B.tf *
      Control_System_B.Product10 + tractionControl.Ki_start;
    if (!(Control_System_B.Fzi_idx_0 <= tractionControl.Ki_end)) {
      Control_System_B.Fzi_idx_0 = tractionControl.Ki_end;
    }

    Control_System_B.Ki = Control_System_B.Fzi_idx_0 * (real32_T)fabs
      (Control_System_B.T_req) / (settings.max_motor_torque * 4.0F);
  } else {
    /* '<S26>:1:23' */
    if (0.0F < Control_System_B.Product10) {
      Fzi_idx_1 = Control_System_B.Product10;
    } else {
      Fzi_idx_1 = 0.0F;
    }

    Control_System_B.max_torque_front = Control_System_B.power * Fzi_idx_1 +
      tractionControl.Kp_start;
    if (!(Control_System_B.max_torque_front <= tractionControl.Kp_end)) {
      Control_System_B.max_torque_front = tractionControl.Kp_end;
    }

    /* '<S26>:1:24' */
    if (!(0.0F < Control_System_B.Product10)) {
      Control_System_B.Product10 = 0.0F;
    }

    Control_System_B.Ki = Control_System_B.tf * Control_System_B.Product10 +
      tractionControl.Ki_start;
    if (!(Control_System_B.Ki <= tractionControl.Ki_end)) {
      Control_System_B.Ki = tractionControl.Ki_end;
    }
  }

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Gain: '<S27>/Gain7'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  /*  This one solves starting from 0 kmh with the driver controlling the */
  /*  throttle. This statement reduces the gains according to the requested */
  /*  torque, to avoid oscillating torque output */
  /*  if ( ( (T_req + 0.0001) > 0) && (vx_kmh < tractionControl.full_gain_limit_kmh) )    */
  /*      Kp_driving = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end)  * abs(T_req)/(settings.max_motor_torque*4); */
  /*      Ki_driving = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end)  * abs(T_req)/(settings.max_motor_torque*4); */
  /*      Kp_FL = Kp_driving; */
  /*      Kp_FR = Kp_driving; */
  /*      Kp_RL = Kp_driving; */
  /*      Kp_RR = Kp_driving; */
  /*       */
  /*      Ki_FL = Ki_driving; */
  /*      Ki_FR = Ki_driving; */
  /*      Ki_RL = Ki_driving; */
  /*      Ki_RR = Ki_driving; */
  /*      %Kp = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end)  * abs(T_req)/(settings.max_motor_torque*4); */
  /*      %Ki = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end)  * abs(T_req)/(settings.max_motor_torque*4); */
  /*   */
  /*  % T_req positive and speed over full gain limit */
  /*  elseif ( ( (T_req + 0.0001) > 0) && (vx_kmh > tractionControl.full_gain_limit_kmh)) */
  /*      Kp_driving = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end); */
  /*      Ki_driving = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end); */
  /*      Kp_FL = Kp_driving; */
  /*      Kp_FR = Kp_driving; */
  /*      Kp_RL = Kp_driving; */
  /*      Kp_RR = Kp_driving; */
  /*       */
  /*      Ki_FL = Ki_driving; */
  /*      Ki_FR = Ki_driving; */
  /*      Ki_RL = Ki_driving; */
  /*      Ki_RR = Ki_driving;     */
  /*  else    */
  /*      Kp_FL = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end); */
  /*      Kp_FR = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end); */
  /*      Kp_RL = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end); */
  /*      Kp_RR = min( (a_kp*max(0,vx_kmh) + tractionControl.Kp_start), tractionControl.Kp_end); */
  /*       */
  /*      Ki_FL = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end); */
  /*      Ki_FR = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end); */
  /*      Ki_RL = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end); */
  /*      Ki_RR = min( (a_ki*max(0,vx_kmh) + tractionControl.Ki_start), tractionControl.Ki_end); */
  /*       */
  /*      %Kp = tractionControl.Kp_braking; */
  /*      %Ki = tractionControl.Ki_braking; */
  /*  end */
  /*   */
  /*  if ( (T_tv.FL < 0) || (T_tv.FR < 0) || (T_tv.RL < 0) || (T_tv.RR < 0) ) */
  /*      Kp = tractionControl.Kp_braking; */
  /*      Ki = tractionControl.Ki_braking; */
  /*  end */
  if (Control_System_B.T_F[0] > Control_System_P.Switch2_Threshold) {
    Control_System_B.Fzi_idx_0 = tractionControl.Slip_ratio_ref;
  } else {
    Control_System_B.Fzi_idx_0 = Control_System_P.Gain7_Gain *
      tractionControl.Slip_ratio_ref;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* Sum: '<S27>/Sum' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S14>/MATLAB Function1'
   */
  Control_System_B.Sum = Control_System_B.Fzi_idx_0 -
    Control_System_U.states.SR_FL;

  /* Sum: '<S27>/Sum2' incorporates:
   *  Product: '<S27>/Product'
   */
  Control_System_B.power = Control_System_B.max_torque_front *
    Control_System_B.Sum + Control_System_B.Switch2_n;

  /* Switch: '<S32>/Switch' incorporates:
   *  RelationalOperator: '<S32>/UpperRelop'
   */
  if (!(Control_System_B.power < Control_System_B.tr)) {
    Control_System_B.tr = Control_System_B.power;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Switch: '<S32>/Switch2' incorporates:
   *  RelationalOperator: '<S32>/LowerRelop1'
   */
  if (Control_System_B.power > Control_System_B.max_torque_rear) {
    Control_System_B.tr = Control_System_B.max_torque_rear;
  }

  /* End of Switch: '<S32>/Switch2' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Gain: '<S28>/Gain'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_F[1] > Control_System_P.Switch_Threshold_b) {
    Control_System_B.power = Control_System_P.Constant_Value_c;
  } else {
    Control_System_B.power = Control_System_P.Gain_Gain_b *
      Control_System_B.T_F[1];
  }

  /* End of Switch: '<S28>/Switch' */

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator2' incorporates:
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (((Control_System_B.T_F[1] > 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevR_p <= 0)) ||
      ((Control_System_B.T_F[1] <= 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevR_p == 1))) {
    Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c =
      Control_System_P.DiscreteTimeIntegrator2_IC_i;
  }

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Gain: '<S28>/Gain1'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_F[1] > Control_System_P.Switch1_Threshold_f) {
    Control_System_B.max_torque_rear = Control_System_P.Gain1_Gain_h *
      Control_System_B.T_F[1];
  } else {
    Control_System_B.max_torque_rear = Control_System_P.Constant1_Value_h;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Switch: '<S33>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator2'
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  RelationalOperator: '<S33>/UpperRelop'
   *  Switch: '<S33>/Switch'
   */
  if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c > Control_System_B.power)
  {
    Control_System_B.Switch2_c = Control_System_B.power;
  } else if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c <
             Control_System_B.max_torque_rear) {
    /* Switch: '<S33>/Switch' */
    Control_System_B.Switch2_c = Control_System_B.max_torque_rear;
  } else {
    Control_System_B.Switch2_c =
      Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Gain: '<S28>/Gain7'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_F[1] > Control_System_P.Switch2_Threshold_o) {
    Control_System_B.Fzi_idx_0 = tractionControl.Slip_ratio_ref;
  } else {
    Control_System_B.Fzi_idx_0 = Control_System_P.Gain7_Gain_l *
      tractionControl.Slip_ratio_ref;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Sum: '<S28>/Sum' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S14>/MATLAB Function1'
   */
  Fzi_idx_3 = Control_System_B.Fzi_idx_0 - Control_System_U.states.SR_FR;

  /* Sum: '<S28>/Sum2' incorporates:
   *  Product: '<S28>/Product'
   */
  Control_System_B.Product10 = Control_System_B.max_torque_front * Fzi_idx_3 +
    Control_System_B.Switch2_c;

  /* Switch: '<S34>/Switch' incorporates:
   *  RelationalOperator: '<S34>/UpperRelop'
   */
  if (!(Control_System_B.Product10 < Control_System_B.max_torque_rear)) {
    Control_System_B.max_torque_rear = Control_System_B.Product10;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S34>/Switch2' incorporates:
   *  RelationalOperator: '<S34>/LowerRelop1'
   */
  if (Control_System_B.Product10 > Control_System_B.power) {
    Control_System_B.tf = Control_System_B.power;
  } else {
    Control_System_B.tf = Control_System_B.max_torque_rear;
  }

  /* End of Switch: '<S34>/Switch2' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Gain: '<S29>/Gain'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[0] > Control_System_P.Switch_Threshold_n) {
    Control_System_B.Product10 = Control_System_P.Constant_Value_o;
  } else {
    Control_System_B.Product10 = Control_System_P.Gain_Gain_i *
      Control_System_B.T_R[0];
  }

  /* End of Switch: '<S29>/Switch' */

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' incorporates:
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (((Control_System_B.T_R[0] > 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevR_g <= 0)) ||
      ((Control_System_B.T_R[0] <= 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_PrevR_g == 1))) {
    Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b =
      Control_System_P.DiscreteTimeIntegrator2_IC_l;
  }

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Gain: '<S29>/Gain1'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[0] > Control_System_P.Switch1_Threshold_d) {
    Control_System_B.max_torque_rear = Control_System_P.Gain1_Gain_k *
      Control_System_B.T_R[0];
  } else {
    Control_System_B.max_torque_rear = Control_System_P.Constant1_Value_p;
  }

  /* End of Switch: '<S29>/Switch1' */

  /* Switch: '<S35>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator2'
   *  RelationalOperator: '<S35>/LowerRelop1'
   *  RelationalOperator: '<S35>/UpperRelop'
   *  Switch: '<S35>/Switch'
   */
  if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b >
      Control_System_B.Product10) {
    Ti_max_tire_idx_1 = Control_System_B.Product10;
  } else if (Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b <
             Control_System_B.max_torque_rear) {
    /* Switch: '<S35>/Switch' */
    Ti_max_tire_idx_1 = Control_System_B.max_torque_rear;
  } else {
    Ti_max_tire_idx_1 = Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b;
  }

  /* End of Switch: '<S35>/Switch2' */

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Gain: '<S29>/Gain7'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[0] > Control_System_P.Switch2_Threshold_p) {
    Control_System_B.Fzi_idx_0 = tractionControl.Slip_ratio_ref;
  } else {
    Control_System_B.Fzi_idx_0 = Control_System_P.Gain7_Gain_b *
      tractionControl.Slip_ratio_ref;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S14>/MATLAB Function1'
   */
  Ti_max_tire_idx_0 = Control_System_B.Fzi_idx_0 - Control_System_U.states.SR_RL;

  /* Sum: '<S29>/Sum2' incorporates:
   *  Product: '<S29>/Product'
   */
  Control_System_B.power = Control_System_B.max_torque_front * Ti_max_tire_idx_0
    + Ti_max_tire_idx_1;

  /* Switch: '<S36>/Switch' incorporates:
   *  RelationalOperator: '<S36>/UpperRelop'
   */
  if (!(Control_System_B.power < Control_System_B.max_torque_rear)) {
    Control_System_B.max_torque_rear = Control_System_B.power;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Switch: '<S36>/Switch2' incorporates:
   *  RelationalOperator: '<S36>/LowerRelop1'
   */
  if (Control_System_B.power > Control_System_B.Product10) {
    Control_System_B.l2 = Control_System_B.Product10;
  } else {
    Control_System_B.l2 = Control_System_B.max_torque_rear;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  Gain: '<S30>/Gain'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[1] > Control_System_P.Switch_Threshold_h) {
    Control_System_B.power = Control_System_P.Constant_Value_m;
  } else {
    Control_System_B.power = Control_System_P.Gain_Gain_k *
      Control_System_B.T_R[1];
  }

  /* End of Switch: '<S30>/Switch' */

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' incorporates:
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (((Control_System_B.T_R[1] > 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_Prev_pr <= 0)) ||
      ((Control_System_B.T_R[1] <= 0.0F) &&
       (Control_System_DW.DiscreteTimeIntegrator2_Prev_pr == 1))) {
    Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2 =
      Control_System_P.DiscreteTimeIntegrator2_IC_c;
  }

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Gain: '<S30>/Gain1'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[1] > Control_System_P.Switch1_Threshold_p) {
    Control_System_B.max_torque_rear = Control_System_P.Gain1_Gain_m *
      Control_System_B.T_R[1];
  } else {
    Control_System_B.max_torque_rear = Control_System_P.Constant1_Value_d;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* Switch: '<S37>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator2'
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  RelationalOperator: '<S37>/UpperRelop'
   *  Switch: '<S37>/Switch'
   */
  if (Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2 > Control_System_B.power)
  {
    Control_System_B.Switch2_ck = Control_System_B.power;
  } else if (Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2 <
             Control_System_B.max_torque_rear) {
    /* Switch: '<S37>/Switch' */
    Control_System_B.Switch2_ck = Control_System_B.max_torque_rear;
  } else {
    Control_System_B.Switch2_ck =
      Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2;
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Gain: '<S30>/Gain7'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (Control_System_B.T_R[1] > Control_System_P.Switch2_Threshold_k) {
    Control_System_B.Fzi_idx_0 = tractionControl.Slip_ratio_ref;
  } else {
    Control_System_B.Fzi_idx_0 = Control_System_P.Gain7_Gain_d *
      tractionControl.Slip_ratio_ref;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* Sum: '<S30>/Sum' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S14>/MATLAB Function1'
   */
  Fzi_idx_2 = Control_System_B.Fzi_idx_0 - Control_System_U.states.SR_RR;

  /* Sum: '<S30>/Sum2' incorporates:
   *  Product: '<S30>/Product'
   */
  Control_System_B.l1 = Control_System_B.max_torque_front * Fzi_idx_2 +
    Control_System_B.Switch2_ck;

  /* Switch: '<S38>/Switch' incorporates:
   *  RelationalOperator: '<S38>/UpperRelop'
   */
  if (!(Control_System_B.l1 < Control_System_B.max_torque_rear)) {
    Control_System_B.max_torque_rear = Control_System_B.l1;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Switch: '<S38>/Switch2' incorporates:
   *  RelationalOperator: '<S38>/LowerRelop1'
   */
  if (Control_System_B.l1 > Control_System_B.power) {
    Control_System_B.max_torque_front = Control_System_B.power;
  } else {
    Control_System_B.max_torque_front = Control_System_B.max_torque_rear;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  /* MATLAB Function 'Control_System /Control /Slip Rate Control /Traction Controllers/MATLAB Function': '<S25>:1' */
  /* '<S25>:1:4' */
  /* '<S25>:1:5' */
  if ((Control_System_U.states.r > -0.3) && (Control_System_U.states.r < 0.3) &&
      (Control_System_U.states.ay > -3.0F) && (Control_System_U.states.ay < 3.0F))
  {
    /* '<S25>:1:9' */
    /* '<S25>:1:10' */
    /* '<S25>:1:11' */
    Control_System_B.ix = 1;
  } else {
    /* '<S25>:1:13' */
    Control_System_B.ix = 0;
  }

  /*  FRONT SIDE */
  /* '<S25>:1:18' */
  /* '<S25>:1:19' */
  /*  If driving ~ straightline then couple the outputs */
  /*  Else, each TC works individually.  */
  if ((Control_System_B.ix == 1) && (Control_System_B.T_req > 0.03F)) {
    /* '<S25>:1:23' */
    /*  Couple TC outputs to maintain stability on mu split surfaces  */
    /*  under acceleration and deceleration */
    /* '<S25>:1:26' */
    if (Control_System_B.tr <= Control_System_B.tf) {
      Control_System_B.Fzi_idx_0 = Control_System_B.tr;
    } else {
      Control_System_B.Fzi_idx_0 = Control_System_B.tf;
    }

    Control_System_B.power = Control_System_B.T_F[0] +
      Control_System_B.Fzi_idx_0;
    if (0.0F < Control_System_B.power) {
      Control_System_B.l1 = Control_System_B.power;
    } else {
      Control_System_B.l1 = 0.0F;
    }

    /* '<S25>:1:27' */
    if (Control_System_B.tr <= Control_System_B.tf) {
      Control_System_B.tf = Control_System_B.tr;
    }

    Control_System_B.power = Control_System_B.T_F[1] + Control_System_B.tf;
    if (0.0F < Control_System_B.power) {
      Control_System_B.tf = Control_System_B.power;
    } else {
      Control_System_B.tf = 0.0F;
    }

    /* '<S25>:1:29' */
    if (Control_System_B.l2 <= Control_System_B.max_torque_front) {
      Control_System_B.Fzi_idx_0 = Control_System_B.l2;
    } else {
      Control_System_B.Fzi_idx_0 = Control_System_B.max_torque_front;
    }

    Control_System_B.power = Control_System_B.T_R[0] +
      Control_System_B.Fzi_idx_0;
    if (0.0F < Control_System_B.power) {
      Control_System_B.Product10 = Control_System_B.power;
    } else {
      Control_System_B.Product10 = 0.0F;
    }

    /* '<S25>:1:30' */
    if (Control_System_B.l2 <= Control_System_B.max_torque_front) {
      Control_System_B.max_torque_front = Control_System_B.l2;
    }

    Control_System_B.power = Control_System_B.T_R[1] +
      Control_System_B.max_torque_front;
    if (!(0.0F < Control_System_B.power)) {
      Control_System_B.power = 0.0F;
    }
  } else if ((Control_System_B.ix == 1) && (Control_System_B.T_req < -0.03F)) {
    /* '<S25>:1:32' */
    /*  Couple TC outputs to maintain stability on mu split surfaces  */
    /*  under acceleration and deceleration */
    /* '<S25>:1:35' */
    if (Control_System_B.tr >= Control_System_B.tf) {
      Control_System_B.Fzi_idx_0 = Control_System_B.tr;
    } else {
      Control_System_B.Fzi_idx_0 = Control_System_B.tf;
    }

    Control_System_B.power = Control_System_B.T_F[0] +
      Control_System_B.Fzi_idx_0;
    if (0.0F > Control_System_B.power) {
      Control_System_B.l1 = Control_System_B.power;
    } else {
      Control_System_B.l1 = 0.0F;
    }

    /* '<S25>:1:36' */
    if (Control_System_B.tr >= Control_System_B.tf) {
      Control_System_B.tf = Control_System_B.tr;
    }

    Control_System_B.power = Control_System_B.T_F[1] + Control_System_B.tf;
    if (0.0F > Control_System_B.power) {
      Control_System_B.tf = Control_System_B.power;
    } else {
      Control_System_B.tf = 0.0F;
    }

    /* '<S25>:1:37' */
    if (Control_System_B.l2 >= Control_System_B.max_torque_front) {
      Control_System_B.Fzi_idx_0 = Control_System_B.l2;
    } else {
      Control_System_B.Fzi_idx_0 = Control_System_B.max_torque_front;
    }

    Control_System_B.power = Control_System_B.T_R[0] +
      Control_System_B.Fzi_idx_0;
    if (0.0F > Control_System_B.power) {
      Control_System_B.Product10 = Control_System_B.power;
    } else {
      Control_System_B.Product10 = 0.0F;
    }

    /* '<S25>:1:38' */
    if (Control_System_B.l2 >= Control_System_B.max_torque_front) {
      Control_System_B.max_torque_front = Control_System_B.l2;
    }

    Control_System_B.power = Control_System_B.T_R[1] +
      Control_System_B.max_torque_front;
    if (!(0.0F > Control_System_B.power)) {
      Control_System_B.power = 0.0F;
    }
  } else {
    /*  Decouple TC outputs to avoid interferring too much with the stability */
    /*  of the vehicle while cornering. This is the DYC systems job.  */
    /* '<S25>:1:42' */
    Control_System_B.l1 = Control_System_B.T_F[0] + Control_System_B.tr;

    /* '<S25>:1:43' */
    Control_System_B.tf += Control_System_B.T_F[1];

    /* '<S25>:1:44' */
    Control_System_B.Product10 = Control_System_B.T_R[0] + Control_System_B.l2;

    /* '<S25>:1:45' */
    Control_System_B.power = Control_System_B.T_R[1] +
      Control_System_B.max_torque_front;
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function' */

  /* MultiPortSwitch: '<S6>/Index Vector' incorporates:
   *  Constant: '<S6>/Constant'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   */
  if (tractionControl.enable == 0U) {
    Control_System_B.l1 = Control_System_B.T_F[0];
    Control_System_B.tf = Control_System_B.T_F[1];
    Control_System_B.Product10 = Control_System_B.T_R[0];
    Control_System_B.power = Control_System_B.T_R[1];
  }

  /* End of MultiPortSwitch: '<S6>/Index Vector' */

  /* Product: '<S2>/Product3' */
  Control_System_B.max_torque_rear = Control_System_B.IndexVector_j *
    Control_System_B.power;

  /* Product: '<S2>/Product5' */
  Control_System_B.max_torque_front = Control_System_B.IndexVector_j *
    Control_System_B.l1;

  /* Product: '<S2>/Product2' */
  Control_System_B.tr = Control_System_B.IndexVector_j * Control_System_B.tf;

  /* Product: '<S2>/Product1' */
  Control_System_B.tf = Control_System_B.IndexVector_j *
    Control_System_B.Product10;

  /* Gain: '<S10>/Integral Gain' */
  Control_System_B.IntegralGain *= powerLimitControl.Ki;

  /* Gain: '<S12>/ZeroGain' */
  Control_System_B.power = Control_System_P.ZeroGain_Gain *
    Control_System_B.SignDeltaU;

  /* DeadZone: '<S12>/DeadZone' */
  if (Control_System_B.SignDeltaU > powerLimitControl.upper_sat_limit) {
    Control_System_B.SignDeltaU -= powerLimitControl.upper_sat_limit;
  } else if (Control_System_B.SignDeltaU >= powerLimitControl.lower_sat_limit) {
    Control_System_B.SignDeltaU = 0.0F;
  } else {
    Control_System_B.SignDeltaU -= powerLimitControl.lower_sat_limit;
  }

  /* End of DeadZone: '<S12>/DeadZone' */

  /* RelationalOperator: '<S12>/NotEqual' */
  rtb_NotEqual = (Control_System_B.power != Control_System_B.SignDeltaU);

  /* Signum: '<S12>/SignDeltaU' */
  if (Control_System_B.SignDeltaU < 0.0F) {
    Control_System_B.SignDeltaU = -1.0F;
  } else {
    if (Control_System_B.SignDeltaU > 0.0F) {
      Control_System_B.SignDeltaU = 1.0F;
    }
  }

  /* End of Signum: '<S12>/SignDeltaU' */

  /* Lookup_n-D: '<S9>/Ki lookup' incorporates:
   *  Gain: '<S9>/Gain2'
   *  Inport: '<Root>/states'
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  Control_System_B.l1 = look1_iflf_binlcapw(Control_System_P.Gain2_Gain *
    Control_System_U.states.V_x, Control_System_P.Kilookup_bp01Data,
    Control_System_P.Kilookup_tableData, 1U);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  BusCreator: '<S2>/Bus Creator'
   *  Inport: '<Root>/states'
   */
  /* MATLAB Function 'Control_System /Output Interface /MATLAB Function': '<S47>:1' */
  /*  Conversion factor to calculate RPM limits based on speed limits */
  /* '<S47>:1:5' */
  Control_System_B.power = 60.0F * car_params.GR / (6.28318548F *
    car_params.r_eff);

  /* '<S47>:1:7' */
  /* '<S47>:1:8' */
  /*  The RPM at which KERS is turned off */
  /* '<S47>:1:11' */
  Control_System_B.Product10 = settings.KERS_speed_limit_hyst_low *
    Control_System_B.power;

  /*  The RPM at which KERS is allowed again */
  /* '<S47>:1:14' */
  Control_System_B.power *= settings.KERS_speed_limit_hyst_high;

  /*  Hysteresis on regenerative input based on RPM to avoid oscillation around  */
  /*  allowed KERS RPM  */
  if (!Control_System_DW.firstIteration_not_empty) {
    /* '<S47>:1:26' */
    Control_System_DW.firstIteration_not_empty = true;

    /*  Avoid overflow in the register and count 1 again */
    /* '<S47>:1:28' */
    Control_System_DW.KERS_ALLOWED_FL = 0U;

    /* '<S47>:1:29' */
    Control_System_DW.KERS_ALLOWED_FR = 0U;

    /* '<S47>:1:30' */
    Control_System_DW.KERS_ALLOWED_RL = 0U;

    /* '<S47>:1:31' */
    Control_System_DW.KERS_ALLOWED_RR = 0U;
  } else {
    /* Hysteris around the minimum RPM Set point */
    if ((Control_System_DW.KERS_ALLOWED_FL == 0U) &&
        (Control_System_U.states.RPM_FL > Control_System_B.power)) {
      /* '<S47>:1:35' */
      /* '<S47>:1:36' */
      Control_System_DW.KERS_ALLOWED_FL = 1U;
    } else {
      if ((Control_System_DW.KERS_ALLOWED_FL == 1U) &&
          (Control_System_U.states.RPM_FL < Control_System_B.Product10)) {
        /* '<S47>:1:37' */
        /* '<S47>:1:38' */
        Control_System_DW.KERS_ALLOWED_FL = 0U;
      }
    }

    if ((Control_System_DW.KERS_ALLOWED_FR == 0U) &&
        (Control_System_U.states.RPM_FR > Control_System_B.power)) {
      /* '<S47>:1:40' */
      /* '<S47>:1:41' */
      Control_System_DW.KERS_ALLOWED_FR = 1U;
    } else {
      if ((Control_System_DW.KERS_ALLOWED_FR == 1U) &&
          (Control_System_U.states.RPM_FR < Control_System_B.Product10)) {
        /* '<S47>:1:42' */
        /* '<S47>:1:43' */
        Control_System_DW.KERS_ALLOWED_FR = 0U;
      }
    }

    if ((Control_System_DW.KERS_ALLOWED_RL == 0U) &&
        (Control_System_U.states.RPM_RL > Control_System_B.power)) {
      /* '<S47>:1:45' */
      /* '<S47>:1:46' */
      Control_System_DW.KERS_ALLOWED_RL = 1U;
    } else {
      if ((Control_System_DW.KERS_ALLOWED_RL == 1U) &&
          (Control_System_U.states.RPM_RL < Control_System_B.Product10)) {
        /* '<S47>:1:47' */
        /* '<S47>:1:48' */
        Control_System_DW.KERS_ALLOWED_RL = 0U;
      }
    }

    if ((Control_System_DW.KERS_ALLOWED_RR == 0U) &&
        (Control_System_U.states.RPM_RR > Control_System_B.power)) {
      /* '<S47>:1:50' */
      /* '<S47>:1:51' */
      Control_System_DW.KERS_ALLOWED_RR = 1U;
    } else {
      if ((Control_System_DW.KERS_ALLOWED_RR == 1U) &&
          (Control_System_U.states.RPM_RR < Control_System_B.Product10)) {
        /* '<S47>:1:52' */
        /* '<S47>:1:53' */
        Control_System_DW.KERS_ALLOWED_RR = 0U;
      }
    }

    /*  Hysteresis around maximum RPM ?  */
  }

  /* ***************** FL ************ */
  if ((Control_System_B.max_torque_front <= 0.0F) &&
      (Control_System_DW.KERS_ALLOWED_FL == 1U)) {
    /* '<S47>:1:62' */
    /* '<S47>:1:63' */
    rtb_Ti_pos_FL = 0;

    /* '<S47>:1:64' */
    Fzi_idx_1 = rt_roundf(Control_System_B.max_torque_front / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_neg_FL = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_neg_FL = MIN_int16_T;
      }
    } else {
      rtb_Ti_neg_FL = MAX_int16_T;
    }

    /* '<S47>:1:65' */
    Fzi_idx_1 = rt_roundf(settings.KERS_motor_RPM_setpoint);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_FL = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_FL = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_FL = MAX_int16_T;
    }
  } else if ((Control_System_B.max_torque_front <= 0.0F) &&
             (Control_System_DW.KERS_ALLOWED_FL == 0U)) {
    /* '<S47>:1:66' */
    /* '<S47>:1:67' */
    rtb_Ti_pos_FL = 0;

    /* '<S47>:1:68' */
    rtb_Ti_neg_FL = 0;

    /* '<S47>:1:69' */
    rtb_wi_setpoints_FL = 0;
  } else if (Control_System_B.max_torque_front > 0.0F) {
    /* '<S47>:1:70' */
    /* '<S47>:1:71' */
    Fzi_idx_1 = rt_roundf(Control_System_B.max_torque_front / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_pos_FL = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_pos_FL = MIN_int16_T;
      }
    } else {
      rtb_Ti_pos_FL = MAX_int16_T;
    }

    /* '<S47>:1:72' */
    rtb_Ti_neg_FL = 0;

    /* '<S47>:1:73' */
    Fzi_idx_1 = rt_roundf(settings.max_RPM);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_FL = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_FL = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_FL = MAX_int16_T;
    }
  } else {
    /* '<S47>:1:75' */
    rtb_Ti_pos_FL = 0;

    /* '<S47>:1:76' */
    rtb_Ti_neg_FL = 0;

    /* '<S47>:1:77' */
    rtb_wi_setpoints_FL = 0;
  }

  /* ***************** FR ************ */
  if ((Control_System_B.tr <= 0.0F) && (Control_System_DW.KERS_ALLOWED_FR == 1U))
  {
    /* '<S47>:1:82' */
    /* '<S47>:1:83' */
    rtb_Ti_pos_FR = 0;

    /* '<S47>:1:84' */
    Fzi_idx_1 = rt_roundf(Control_System_B.tr / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_neg_FR = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_neg_FR = MIN_int16_T;
      }
    } else {
      rtb_Ti_neg_FR = MAX_int16_T;
    }

    /* '<S47>:1:85' */
    Fzi_idx_1 = rt_roundf(settings.KERS_motor_RPM_setpoint);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_FR = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_FR = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_FR = MAX_int16_T;
    }
  } else if ((Control_System_B.tr <= 0.0F) && (Control_System_DW.KERS_ALLOWED_FR
              == 0U)) {
    /* '<S47>:1:86' */
    /* '<S47>:1:87' */
    rtb_Ti_pos_FR = 0;

    /* '<S47>:1:88' */
    rtb_Ti_neg_FR = 0;

    /* '<S47>:1:89' */
    rtb_wi_setpoints_FR = 0;
  } else if (Control_System_B.tr > 0.0F) {
    /* '<S47>:1:90' */
    /* '<S47>:1:91' */
    Fzi_idx_1 = rt_roundf(Control_System_B.tr / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_pos_FR = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_pos_FR = MIN_int16_T;
      }
    } else {
      rtb_Ti_pos_FR = MAX_int16_T;
    }

    /* '<S47>:1:92' */
    rtb_Ti_neg_FR = 0;

    /* '<S47>:1:93' */
    Fzi_idx_1 = rt_roundf(settings.max_RPM);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_FR = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_FR = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_FR = MAX_int16_T;
    }
  } else {
    /* '<S47>:1:95' */
    rtb_Ti_pos_FR = 0;

    /* '<S47>:1:96' */
    rtb_Ti_neg_FR = 0;

    /* '<S47>:1:97' */
    rtb_wi_setpoints_FR = 0;
  }

  /* ***************** RL ************ */
  if ((Control_System_B.tf <= 0.0F) && (Control_System_DW.KERS_ALLOWED_RL == 1U))
  {
    /* '<S47>:1:100' */
    /* '<S47>:1:101' */
    rtb_Ti_pos_RL = 0;

    /* '<S47>:1:102' */
    Fzi_idx_1 = rt_roundf(Control_System_B.tf / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_neg_RL = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_neg_RL = MIN_int16_T;
      }
    } else {
      rtb_Ti_neg_RL = MAX_int16_T;
    }

    /* '<S47>:1:103' */
    Fzi_idx_1 = rt_roundf(settings.KERS_motor_RPM_setpoint);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_RL = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_RL = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_RL = MAX_int16_T;
    }
  } else if ((Control_System_B.tf <= 0.0F) && (Control_System_DW.KERS_ALLOWED_RL
              == 0U)) {
    /* '<S47>:1:104' */
    /* '<S47>:1:105' */
    rtb_Ti_pos_RL = 0;

    /* '<S47>:1:106' */
    rtb_Ti_neg_RL = 0;

    /* '<S47>:1:107' */
    rtb_wi_setpoints_RL = 0;
  } else if (Control_System_B.tf > 0.0F) {
    /* '<S47>:1:108' */
    /* '<S47>:1:109' */
    Fzi_idx_1 = rt_roundf(Control_System_B.tf / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_pos_RL = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_pos_RL = MIN_int16_T;
      }
    } else {
      rtb_Ti_pos_RL = MAX_int16_T;
    }

    /* '<S47>:1:110' */
    rtb_Ti_neg_RL = 0;

    /* '<S47>:1:111' */
    Fzi_idx_1 = rt_roundf(settings.max_RPM);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_RL = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_RL = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_RL = MAX_int16_T;
    }
  } else {
    /* '<S47>:1:113' */
    rtb_Ti_pos_RL = 0;

    /* '<S47>:1:114' */
    rtb_Ti_neg_RL = 0;

    /* '<S47>:1:115' */
    rtb_wi_setpoints_RL = 0;
  }

  /* ***************** RR ************ */
  if ((Control_System_B.max_torque_rear <= 0.0F) &&
      (Control_System_DW.KERS_ALLOWED_RR == 1U)) {
    /* '<S47>:1:119' */
    /* '<S47>:1:120' */
    rtb_Ti_pos_RR = 0;

    /* '<S47>:1:121' */
    Fzi_idx_1 = rt_roundf(Control_System_B.max_torque_rear / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_neg_RR = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_neg_RR = MIN_int16_T;
      }
    } else {
      rtb_Ti_neg_RR = MAX_int16_T;
    }

    /* '<S47>:1:122' */
    Fzi_idx_1 = rt_roundf(settings.KERS_motor_RPM_setpoint);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_RR = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_RR = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_RR = MAX_int16_T;
    }
  } else if ((Control_System_B.max_torque_rear <= 0.0F) &&
             (Control_System_DW.KERS_ALLOWED_RR == 0U)) {
    /* '<S47>:1:123' */
    /* '<S47>:1:124' */
    rtb_Ti_pos_RR = 0;

    /* '<S47>:1:125' */
    rtb_Ti_neg_RR = 0;

    /* '<S47>:1:126' */
    rtb_wi_setpoints_RR = 0;
  } else if (Control_System_B.max_torque_rear > 0.0F) {
    /* '<S47>:1:127' */
    /* '<S47>:1:128' */
    Fzi_idx_1 = rt_roundf(Control_System_B.max_torque_rear / car_params.Mn);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_Ti_pos_RR = (int16_T)Fzi_idx_1;
      } else {
        rtb_Ti_pos_RR = MIN_int16_T;
      }
    } else {
      rtb_Ti_pos_RR = MAX_int16_T;
    }

    /* '<S47>:1:129' */
    rtb_Ti_neg_RR = 0;

    /* '<S47>:1:130' */
    Fzi_idx_1 = rt_roundf(settings.max_RPM);
    if (Fzi_idx_1 < 32768.0F) {
      if (Fzi_idx_1 >= -32768.0F) {
        rtb_wi_setpoints_RR = (int16_T)Fzi_idx_1;
      } else {
        rtb_wi_setpoints_RR = MIN_int16_T;
      }
    } else {
      rtb_wi_setpoints_RR = MAX_int16_T;
    }
  } else {
    /* '<S47>:1:132' */
    rtb_Ti_pos_RR = 0;

    /* '<S47>:1:133' */
    rtb_Ti_neg_RR = 0;

    /* '<S47>:1:134' */
    rtb_wi_setpoints_RR = 0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* Signum: '<S12>/SignPreIntegrator' */
  /* MATLAB Function 'Control_System /OutputTelemetri': '<S4>:1' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:6' */
  if (Control_System_B.IntegralGain < 0.0F) {
    Control_System_B.Fzi_idx_0 = -1.0F;
  } else if (Control_System_B.IntegralGain > 0.0F) {
    Control_System_B.Fzi_idx_0 = 1.0F;
  } else {
    Control_System_B.Fzi_idx_0 = Control_System_B.IntegralGain;
  }

  /* DataTypeConversion: '<S12>/DataTypeConv2' incorporates:
   *  Signum: '<S12>/SignPreIntegrator'
   */
  Fzi_idx_1 = (real32_T)fmod(Control_System_B.Fzi_idx_0, 256.0F);

  /* DataTypeConversion: '<S12>/DataTypeConv1' */
  if (Control_System_B.SignDeltaU < 128.0F) {
    rtb_SignDeltaU_0 = (int8_T)Control_System_B.SignDeltaU;
  } else {
    rtb_SignDeltaU_0 = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S12>/DataTypeConv1' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S12>/DataTypeConv2'
   *  Logic: '<S12>/AND'
   *  RelationalOperator: '<S12>/Equal'
   */
  if (rtb_NotEqual && ((Fzi_idx_1 < 0.0F ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -Fzi_idx_1 : (int32_T)(int8_T)(uint8_T)Fzi_idx_1) ==
                       rtb_SignDeltaU_0)) {
    Control_System_B.IntegralGain = Control_System_P.Constant_Value;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Update for DiscreteIntegrator: '<S10>/Integrator' */
  Control_System_DW.Integrator_DSTATE += Control_System_P.Integrator_gainval *
    Control_System_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator2' incorporates:
   *  Constant: '<S9>/Ksat'
   *  Product: '<S9>/Product11'
   *  Product: '<S9>/Product8'
   *  Sum: '<S9>/Sum3'
   */
  Control_System_DW.DiscreteTimeIntegrator2_DSTATE += (Control_System_B.r_error *
    Control_System_B.l1 - yawRateControl.Ksat * Control_System_B.Mz_error) *
    Control_System_P.DiscreteTimeIntegrator2_gainval;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator2'
   *  Gain: '<S27>/Gain2'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   *  Product: '<S27>/Product1'
   *  Sum: '<S27>/Sum1'
   *  Sum: '<S27>/Sum3'
   */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n +=
    ((Control_System_B.Switch2_n -
      Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n) * tractionControl.Kb +
     Control_System_B.Ki * Control_System_B.Sum) *
    Control_System_P.DiscreteTimeIntegrator2_gainv_i;
  if (Control_System_B.T_F[0] > 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevRes = 1;
  } else if (Control_System_B.T_F[0] < 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevRes = -1;
  } else if (Control_System_B.T_F[0] == 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevRes = 0;
  } else {
    Control_System_DW.DiscreteTimeIntegrator2_PrevRes = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator2' */

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator2'
   *  Gain: '<S28>/Gain2'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   *  Product: '<S28>/Product1'
   *  Sum: '<S28>/Sum1'
   *  Sum: '<S28>/Sum3'
   */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c +=
    ((Control_System_B.Switch2_c -
      Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c) * tractionControl.Kb +
     Control_System_B.Ki * Fzi_idx_3) *
    Control_System_P.DiscreteTimeIntegrator2_gainv_n;
  if (Control_System_B.T_F[1] > 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_p = 1;
  } else if (Control_System_B.T_F[1] < 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_p = -1;
  } else if (Control_System_B.T_F[1] == 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_p = 0;
  } else {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator2' */

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator2'
   *  Gain: '<S29>/Gain2'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   *  Product: '<S29>/Product1'
   *  Sum: '<S29>/Sum1'
   *  Sum: '<S29>/Sum3'
   */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b += ((Ti_max_tire_idx_1 -
    Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b) * tractionControl.Kb +
    Control_System_B.Ki * Ti_max_tire_idx_0) *
    Control_System_P.DiscreteTimeIntegrator2_gainv_f;
  if (Control_System_B.T_R[0] > 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_g = 1;
  } else if (Control_System_B.T_R[0] < 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_g = -1;
  } else if (Control_System_B.T_R[0] == 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_g = 0;
  } else {
    Control_System_DW.DiscreteTimeIntegrator2_PrevR_g = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator2'
   *  Gain: '<S30>/Gain2'
   *  MATLAB Function: '<S44>/TorqueAllocation'
   *  Product: '<S30>/Product1'
   *  Sum: '<S30>/Sum1'
   *  Sum: '<S30>/Sum3'
   */
  Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2 +=
    ((Control_System_B.Switch2_ck -
      Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2) * tractionControl.Kb +
     Control_System_B.Ki * Fzi_idx_2) *
    Control_System_P.DiscreteTimeIntegrator2_gain_fb;
  if (Control_System_B.T_R[1] > 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_Prev_pr = 1;
  } else if (Control_System_B.T_R[1] < 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_Prev_pr = -1;
  } else if (Control_System_B.T_R[1] == 0.0F) {
    Control_System_DW.DiscreteTimeIntegrator2_Prev_pr = 0;
  } else {
    Control_System_DW.DiscreteTimeIntegrator2_Prev_pr = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' */
  /* End of Outputs for SubSystem: '<Root>/Control_System ' */

  /* Outport: '<Root>/Ti_pos ' */
  Control_System_Y.Ti_pos_l.FL = rtb_Ti_pos_FL;
  Control_System_Y.Ti_pos_l.FR = rtb_Ti_pos_FR;
  Control_System_Y.Ti_pos_l.RL = rtb_Ti_pos_RL;
  Control_System_Y.Ti_pos_l.RR = rtb_Ti_pos_RR;

  /* Outport: '<Root>/Ti_neg' */
  Control_System_Y.Ti_neg_a.FL = rtb_Ti_neg_FL;
  Control_System_Y.Ti_neg_a.FR = rtb_Ti_neg_FR;
  Control_System_Y.Ti_neg_a.RL = rtb_Ti_neg_RL;
  Control_System_Y.Ti_neg_a.RR = rtb_Ti_neg_RR;

  /* Outport: '<Root>/wi_sp' */
  Control_System_Y.wi_sp.FL = rtb_wi_setpoints_FL;
  Control_System_Y.wi_sp.FR = rtb_wi_setpoints_FR;
  Control_System_Y.wi_sp.RL = rtb_wi_setpoints_RL;
  Control_System_Y.wi_sp.RR = rtb_wi_setpoints_RR;

  /* Outputs for Atomic SubSystem: '<Root>/Control_System ' */
  /* Outport: '<Root>/States' incorporates:
   *  Inport: '<Root>/states'
   */
  Control_System_Y.States_m = Control_System_U.states;

  /* Outport: '<Root>/Ti_lim ' incorporates:
   *  BusCreator: '<S2>/Bus Creator'
   */
  Control_System_Y.Ti_lim_n.FL = Control_System_B.max_torque_front;
  Control_System_Y.Ti_lim_n.FR = Control_System_B.tr;
  Control_System_Y.Ti_lim_n.RL = Control_System_B.tf;
  Control_System_Y.Ti_lim_n.RR = Control_System_B.max_torque_rear;

  /* Outport: '<Root>/r_ref' incorporates:
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  Control_System_Y.r_ref = Control_System_B.r_ref;

  /* End of Outputs for SubSystem: '<Root>/Control_System ' */

  /* Outport: '<Root>/T_req' */
  Control_System_Y.T_req = Control_System_B.T_req;

  /* Outport: '<Root>/Mz_error' */
  Control_System_Y.Mz_error = Control_System_B.Mz_error;

  /* Outport: '<Root>/Mz_ref' */
  Control_System_Y.Mz_ref = Control_System_B.Saturation;

  /* Outputs for Atomic SubSystem: '<Root>/Control_System ' */
  /* Outport: '<Root>/OutputTelemetri_Control' incorporates:
   *  MATLAB Function: '<S1>/OutputTelemetri'
   *  MATLAB Function: '<S9>/yawRateReference'
   */
  Control_System_Y.OutputTelemetri_Control_j.T_req = Control_System_B.T_req;
  Control_System_Y.OutputTelemetri_Control_j.Mz_ref =
    Control_System_B.Saturation;
  Control_System_Y.OutputTelemetri_Control_j.r_ref = Control_System_B.r_ref;

  /* End of Outputs for SubSystem: '<Root>/Control_System ' */
}

/* Model initialize function */
void Control_System_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Control_System_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Control_System_DW, 0,
                sizeof(DW_Control_System_T));

  /* external inputs */
  Control_System_U.states = Control_System_rtZStates;

  /* external outputs */
  (void) memset((void *)&Control_System_Y, 0,
                sizeof(ExtY_Control_System_T));

  /* InitializeConditions for Atomic SubSystem: '<Root>/Control_System ' */
  /* InitializeConditions for DiscreteIntegrator: '<S10>/Integrator' */
  Control_System_DW.Integrator_DSTATE = Control_System_P.Integrator_IC;

  /* InitializeConditions for MATLAB Function: '<S7>/MATLAB Function' */
  Control_System_DW.firstIteration_not_empty_f = false;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator2' */
  Control_System_DW.DiscreteTimeIntegrator2_DSTATE =
    Control_System_P.DiscreteTimeIntegrator2_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator2' */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_n =
    Control_System_P.DiscreteTimeIntegrator2_IC_f;
  Control_System_DW.DiscreteTimeIntegrator2_PrevRes = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator2' */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_c =
    Control_System_P.DiscreteTimeIntegrator2_IC_i;
  Control_System_DW.DiscreteTimeIntegrator2_PrevR_p = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */
  Control_System_DW.DiscreteTimeIntegrator2_DSTAT_b =
    Control_System_P.DiscreteTimeIntegrator2_IC_l;
  Control_System_DW.DiscreteTimeIntegrator2_PrevR_g = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' */
  Control_System_DW.DiscreteTimeIntegrator2_DSTA_c2 =
    Control_System_P.DiscreteTimeIntegrator2_IC_c;
  Control_System_DW.DiscreteTimeIntegrator2_Prev_pr = 2;

  /* InitializeConditions for MATLAB Function: '<S3>/MATLAB Function' */
  Control_System_DW.firstIteration_not_empty = false;

  /* End of InitializeConditions for SubSystem: '<Root>/Control_System ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
