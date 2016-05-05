/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_System.h
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

#ifndef RTW_HEADER_Control_System_h_
#define RTW_HEADER_Control_System_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Control_System_COMMON_INCLUDES_
# define Control_System_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Control_System_COMMON_INCLUDES_ */

#include "Control_System_types.h"
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
  real32_T T_F[2];
  real32_T T_R[2];
  real32_T max_torque_front;
  real32_T max_torque_rear;
  real32_T r_ref;
  real32_T tf;
  real32_T tr;
  real32_T l1;
  real32_T l2;
  real32_T T_req;                      /* '<S7>/MATLAB Function' */
  real32_T Mz_error;                   /* '<S44>/TorqueAllocation' */
  real32_T Saturation;                 /* '<S9>/Saturation' */
  real32_T power;                      /* '<S5>/extractPower' */
  real32_T SignDeltaU;                 /* '<S12>/SignDeltaU' */
  real32_T IntegralGain;               /* '<S10>/Integral Gain' */
  real32_T IndexVector_j;              /* '<S5>/Index Vector' */
  real32_T Product10;                  /* '<S9>/Product10' */
  real32_T r_error;                    /* '<S9>/yawRateReference' */
  real32_T Sum;                        /* '<S27>/Sum' */
  real32_T Switch2_n;                  /* '<S31>/Switch2' */
  real32_T Switch2_c;                  /* '<S33>/Switch2' */
  real32_T Switch2_ck;                 /* '<S37>/Switch2' */
  real32_T Ki;                         /* '<S14>/MATLAB Function1' */
  real32_T Fzi_idx_0;
  int32_T ix;
  uint32_T sat_F;
  uint32_T sat_R;
} B_Control_System_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S10>/Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S9>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator2_DSTAT_n;/* '<S27>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator2_DSTAT_c;/* '<S28>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator2_DSTAT_b;/* '<S29>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator2_DSTA_c2;/* '<S30>/Discrete-Time Integrator2' */
  uint32_T KERS_ALLOWED_FL;            /* '<S3>/MATLAB Function' */
  uint32_T KERS_ALLOWED_FR;            /* '<S3>/MATLAB Function' */
  uint32_T KERS_ALLOWED_RL;            /* '<S3>/MATLAB Function' */
  uint32_T KERS_ALLOWED_RR;            /* '<S3>/MATLAB Function' */
  uint32_T KERS_allowed;               /* '<S7>/MATLAB Function' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S27>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator2_PrevR_p;/* '<S28>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator2_PrevR_g;/* '<S29>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator2_Prev_pr;/* '<S30>/Discrete-Time Integrator2' */
  boolean_T firstIteration_not_empty;  /* '<S3>/MATLAB Function' */
  boolean_T firstIteration_not_empty_f;/* '<S7>/MATLAB Function' */
} DW_Control_System_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  States states;                       /* '<Root>/states' */
} ExtU_Control_System_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  Ti_pos Ti_pos_l;                     /* '<Root>/Ti_pos ' */
  Ti_neg Ti_neg_a;                     /* '<Root>/Ti_neg' */
  wi_set wi_sp;                        /* '<Root>/wi_sp' */
  States States_m;                     /* '<Root>/States' */
  Ti_lim Ti_lim_n;                     /* '<Root>/Ti_lim ' */
  real32_T r_ref;                      /* '<Root>/r_ref' */
  real32_T T_req;                      /* '<Root>/T_req' */
  real32_T Mz_error;                   /* '<Root>/Mz_error' */
  real32_T Mz_ref;                     /* '<Root>/Mz_ref' */
  OutputTelemetri_Control OutputTelemetri_Control_j;/* '<Root>/OutputTelemetri_Control' */
} ExtY_Control_System_T;

/* Parameters (auto storage) */
struct P_Control_System_T_ {
  real32_T constant_Value;             /* Expression: single(1)
                                        * Referenced by: '<S5>/constant'
                                        */
  real32_T constant2_Value;            /* Expression: single(1)
                                        * Referenced by: '<S5>/constant2'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S10>/Constant'
                                        */
  real32_T Gain7_Gain;                 /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain7'
                                        */
  real32_T Constant1_Value;            /* Expression: single(0)
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real32_T Gain1_Gain;                 /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Expression: single(-1)
                                        * Referenced by: '<S27>/Gain'
                                        */
  real32_T Constant_Value_h;           /* Expression: single(0)
                                        * Referenced by: '<S27>/Constant'
                                        */
  real32_T Gain7_Gain_l;               /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain7'
                                        */
  real32_T Constant1_Value_h;          /* Expression: single(0)
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real32_T Gain1_Gain_h;               /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real32_T Gain_Gain_b;                /* Expression: single(-1)
                                        * Referenced by: '<S28>/Gain'
                                        */
  real32_T Constant_Value_c;           /* Expression: single(0)
                                        * Referenced by: '<S28>/Constant'
                                        */
  real32_T Gain7_Gain_b;               /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain7'
                                        */
  real32_T Constant1_Value_p;          /* Expression: single(0)
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real32_T Gain1_Gain_k;               /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real32_T Gain_Gain_i;                /* Expression: single(-1)
                                        * Referenced by: '<S29>/Gain'
                                        */
  real32_T Constant_Value_o;           /* Expression: single(0)
                                        * Referenced by: '<S29>/Constant'
                                        */
  real32_T Gain7_Gain_d;               /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain7'
                                        */
  real32_T Constant1_Value_d;          /* Expression: single(0)
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real32_T Gain1_Gain_m;               /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real32_T Gain_Gain_k;                /* Expression: single(-1)
                                        * Referenced by: '<S30>/Gain'
                                        */
  real32_T Constant_Value_m;           /* Expression: single(0)
                                        * Referenced by: '<S30>/Constant'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S5>/Switch'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real32_T Integrator_IC;              /* Computed Parameter: Integrator_IC
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real32_T Gain1_Gain_f;               /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real32_T Kdlookup_tableData[2];      /* Expression: [yawRateControl.Kd_start  yawRateControl.Kd_end]*yawRateControl.Kd_scaling
                                        * Referenced by: '<S9>/Kd lookup'
                                        */
  real32_T Kdlookup_bp01Data[2];       /* Expression: [0  yawRateControl.lookup_speed_end_kmh]
                                        * Referenced by: '<S9>/Kd lookup'
                                        */
  real32_T Gain_Gain_ip;               /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T KpLookup_tableData[2];      /* Expression: [yawRateControl.Kp_start  yawRateControl.Kp_end]*yawRateControl.Kp_scaling
                                        * Referenced by: '<S9>/Kp Lookup'
                                        */
  real32_T KpLookup_bp01Data[2];       /* Expression: [0  yawRateControl.lookup_speed_end_kmh]
                                        * Referenced by: '<S9>/Kp Lookup'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S9>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S9>/Discrete-Time Integrator2'
                                        */
  real32_T Saturation_LowerSat;        /* Expression: -yawRateControl.max_moment
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S27>/Switch'
                                        */
  real32_T DiscreteTimeIntegrator2_gainv_i;/* Computed Parameter: DiscreteTimeIntegrator2_gainv_i
                                            * Referenced by: '<S27>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC_f;/* Computed Parameter: DiscreteTimeIntegrator2_IC_f
                                         * Referenced by: '<S27>/Discrete-Time Integrator2'
                                         */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S27>/Switch1'
                                        */
  real32_T Switch2_Threshold;          /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S27>/Switch2'
                                        */
  real32_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S28>/Switch'
                                        */
  real32_T DiscreteTimeIntegrator2_gainv_n;/* Computed Parameter: DiscreteTimeIntegrator2_gainv_n
                                            * Referenced by: '<S28>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC_i;/* Computed Parameter: DiscreteTimeIntegrator2_IC_i
                                         * Referenced by: '<S28>/Discrete-Time Integrator2'
                                         */
  real32_T Switch1_Threshold_f;        /* Computed Parameter: Switch1_Threshold_f
                                        * Referenced by: '<S28>/Switch1'
                                        */
  real32_T Switch2_Threshold_o;        /* Computed Parameter: Switch2_Threshold_o
                                        * Referenced by: '<S28>/Switch2'
                                        */
  real32_T Switch_Threshold_n;         /* Computed Parameter: Switch_Threshold_n
                                        * Referenced by: '<S29>/Switch'
                                        */
  real32_T DiscreteTimeIntegrator2_gainv_f;/* Computed Parameter: DiscreteTimeIntegrator2_gainv_f
                                            * Referenced by: '<S29>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC_l;/* Computed Parameter: DiscreteTimeIntegrator2_IC_l
                                         * Referenced by: '<S29>/Discrete-Time Integrator2'
                                         */
  real32_T Switch1_Threshold_d;        /* Computed Parameter: Switch1_Threshold_d
                                        * Referenced by: '<S29>/Switch1'
                                        */
  real32_T Switch2_Threshold_p;        /* Computed Parameter: Switch2_Threshold_p
                                        * Referenced by: '<S29>/Switch2'
                                        */
  real32_T Switch_Threshold_h;         /* Computed Parameter: Switch_Threshold_h
                                        * Referenced by: '<S30>/Switch'
                                        */
  real32_T DiscreteTimeIntegrator2_gain_fb;/* Computed Parameter: DiscreteTimeIntegrator2_gain_fb
                                            * Referenced by: '<S30>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC_c;/* Computed Parameter: DiscreteTimeIntegrator2_IC_c
                                         * Referenced by: '<S30>/Discrete-Time Integrator2'
                                         */
  real32_T Switch1_Threshold_p;        /* Computed Parameter: Switch1_Threshold_p
                                        * Referenced by: '<S30>/Switch1'
                                        */
  real32_T Switch2_Threshold_k;        /* Computed Parameter: Switch2_Threshold_k
                                        * Referenced by: '<S30>/Switch2'
                                        */
  real32_T ZeroGain_Gain;              /* Computed Parameter: ZeroGain_Gain
                                        * Referenced by: '<S12>/ZeroGain'
                                        */
  real32_T Gain2_Gain;                 /* Expression: single(3.6)
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real32_T Kilookup_tableData[2];      /* Expression: [yawRateControl.Ki_start  yawRateControl.Ki_end]*yawRateControl.Ki_scaling
                                        * Referenced by: '<S9>/Ki lookup'
                                        */
  real32_T Kilookup_bp01Data[2];       /* Expression: [0  yawRateControl.lookup_speed_end_kmh]
                                        * Referenced by: '<S9>/Ki lookup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_System_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_Control_System_T Control_System_P;

/* Block signals (auto storage) */
extern B_Control_System_T Control_System_B;

/* Block states (auto storage) */
extern DW_Control_System_T Control_System_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Control_System_T Control_System_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Control_System_T Control_System_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern YawRateControl yawRateControl;  /* Variable: yawRateControl
                                        * Referenced by:
                                        *   '<S9>/Enable//disable'
                                        *   '<S9>/Ksat'
                                        *   '<S9>/Saturation'
                                        *   '<S44>/TorqueAllocation'
                                        */
extern TractionControl tractionControl;/* Variable: tractionControl
                                        * Referenced by:
                                        *   '<S6>/Constant'
                                        *   '<S14>/MATLAB Function1'
                                        *   '<S14>/Constant2'
                                        *   '<S27>/Gain2'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain2'
                                        *   '<S30>/Gain2'
                                        */
extern PowerLimitControl powerLimitControl;/* Variable: powerLimitControl
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

/* External data declarations for dependent source files */
extern const States Control_System_rtZStates;/* States ground */

/* Model entry point functions */
extern void Control_System_initialize(void);
extern void Control_System_step(void);

/* Real-time Model object */
extern RT_MODEL_Control_System_T *const Control_System_M;

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
 * hilite_system('TV2016/CarMaker/Control_System ')    - opens subsystem TV2016/CarMaker/Control_System
 * hilite_system('TV2016/CarMaker/Control_System /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TV2016/CarMaker'
 * '<S1>'   : 'TV2016/CarMaker/Control_System '
 * '<S2>'   : 'TV2016/CarMaker/Control_System /Control '
 * '<S3>'   : 'TV2016/CarMaker/Control_System /Output Interface '
 * '<S4>'   : 'TV2016/CarMaker/Control_System /OutputTelemetri'
 * '<S5>'   : 'TV2016/CarMaker/Control_System /Control /Power Limit Torque Reduction Controller '
 * '<S6>'   : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control '
 * '<S7>'   : 'TV2016/CarMaker/Control_System /Control /Throttle // Brake Mapping'
 * '<S8>'   : 'TV2016/CarMaker/Control_System /Control /Torque allocation '
 * '<S9>'   : 'TV2016/CarMaker/Control_System /Control /Yaw Rate Controller '
 * '<S10>'  : 'TV2016/CarMaker/Control_System /Control /Power Limit Torque Reduction Controller /Discrete PI controller'
 * '<S11>'  : 'TV2016/CarMaker/Control_System /Control /Power Limit Torque Reduction Controller /extractPower'
 * '<S12>'  : 'TV2016/CarMaker/Control_System /Control /Power Limit Torque Reduction Controller /Discrete PI controller/Clamping circuit'
 * '<S13>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control'
 * '<S14>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers'
 * '<S15>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/MATLAB Function'
 * '<S16>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/MATLAB Function1'
 * '<S17>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL'
 * '<S18>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL1'
 * '<S19>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL2'
 * '<S20>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL3'
 * '<S21>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL/SMC'
 * '<S22>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL1/SMC'
 * '<S23>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL2/SMC'
 * '<S24>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /SMC Traction Control/Slip Rate FL3/SMC'
 * '<S25>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/MATLAB Function'
 * '<S26>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/MATLAB Function1'
 * '<S27>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FL'
 * '<S28>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FR'
 * '<S29>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RL'
 * '<S30>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RR'
 * '<S31>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FL/Saturation Dynamic'
 * '<S32>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FL/Saturation Dynamic1'
 * '<S33>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FR/Saturation Dynamic'
 * '<S34>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate FR/Saturation Dynamic1'
 * '<S35>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RL/Saturation Dynamic'
 * '<S36>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RL/Saturation Dynamic1'
 * '<S37>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RR/Saturation Dynamic'
 * '<S38>'  : 'TV2016/CarMaker/Control_System /Control /Slip Rate Control /Traction Controllers/Slip Rate RR/Saturation Dynamic1'
 * '<S39>'  : 'TV2016/CarMaker/Control_System /Control /Throttle // Brake Mapping/MATLAB Function'
 * '<S40>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /MATLAB Function'
 * '<S41>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /Switch Case Action Subsystem'
 * '<S42>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /Switch Case Action Subsystem1'
 * '<S43>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /Switch Case Action Subsystem2'
 * '<S44>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /Torque Allocation'
 * '<S45>'  : 'TV2016/CarMaker/Control_System /Control /Torque allocation /Torque Allocation/TorqueAllocation'
 * '<S46>'  : 'TV2016/CarMaker/Control_System /Control /Yaw Rate Controller /yawRateReference'
 * '<S47>'  : 'TV2016/CarMaker/Control_System /Output Interface /MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Control_System_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
