% Parameter file for Revolve TV 2016
% Initialize parameters automatically when the model gets loaded:
load('Buses.mat');

% STRUCTS
yawRateControl = struct;
tractionControl = struct;
powerLimitControl = struct;
energyLimitControl = struct;
settings = struct;
car_params = struct;
matlab_params = struct;
% speedEstimation = struct;

% ------------------------------
% "SETTINGS"
% ------------------------------
settings.KERS_active = uint32(1);           % 1 = Kers can be used, 0 = Kers is not used
settings.select_Fz_est_method = uint32(2);   % 1 = LoadTransfer, 2 = DamperBased
settings.select_velocity_vx = uint32(3);    % 1 = estimated, 2 = INS, 3 = Optical
settings.select_velocity_vy = uint32(3);    %                2 = INS, 3 = Optical
% 1 = Engineering (No negative torque), 2 = with negative torque , 
% 3 = static 25  , 4 = with negative, does not use Fz
settings.TV_Method = uint32(4); 
settings.use_estimated_Fz = uint32(0); % 1 = yes, 0 = no

settings.max_motor_torque = single(21);
settings.max_motor_brake_torque = single(18);
% The speed setpoint when driving
settings.max_RPM = single(23000);
% The speed at which KERS will be allowed again
settings.KERS_speed_limit_hyst_high = single(4); % Can not KERS under 5 Km/h = 1.4 m/s
% The speed at which KERS will be turned off
settings.KERS_speed_limit_hyst_low = single(1.4);
settings.KERS_motor_RPM_setpoint = single(1200);
settings.mu = single(2.5);
settings.max_battery_discharge =single(190); % Ampere


% ------------------------------
% Car Parameters
% ------------------------------
car_params.GR = single(15.47);
car_params.t_f = single(0.6); % Half trackwidth front
car_params.t_r = single(0.585); % Half trackwidth rear
car_params.l = single(1.53); % Wheelbase
car_params.l_f = single(0.813); % Distance CoG to front axle
car_params.l_r = single(0.717); % Distance CoG to rear axle
car_params.CoG_height = single(0.265); % Height of Center of gravity [m]

car_params.spring_constant_front            = single(30000);
car_params.spring_constant_rear             = single(35000);
car_params.motion_ratio_front               = single(1);
car_params.motion_ratio_rear                = single(1);
car_params.preload_front_mm                 = single(4.5);
car_params.preload_rear_mm                  = single(1.0);
car_params.unsprung_mass_per_wheel_newton   = single(122.625);

car_params.driver_mass = single(75);
car_params.car_mass    = single(185);
car_params.r_eff = single(0.225); % 0.25 % Hoosier = 0.225 ?


car_params.Kt   = single(0.26);         % Torque constant
car_params.Lq   = single(0.00054);      % Quadrature axis inductance [Henry] 
car_params.Ld   = single(0.00044);      % Direct access inductance [Henry]
car_params.Jw   = single(0.78);         % Total inertia the motor sees
car_params.Mn   = single(0.0098);       % Motor nomial torque(9.8Nm), for calculating setpoint in [0.1]% of Mn

car_params.aero_lift_coeff = single(3.163);
car_params.aero_ref_area   = single(1.1008);

% ------------------------------
% Yaw Rate Control Parameters
% ------------------------------
yawRateControl.Ku = single(0); % Understeer coefficient
yawRateControl.r_ref_tuning_param = single(1.5);
yawRateControl.negative_torque_limit = 10;
yawRateControl.max_moment = single(2000);

yawRateControl.Kp_start = single(4500); %4500  1000 skid
yawRateControl.Kp_end = single(4500);
yawRateControl.Kp_scaling = single(1); 

yawRateControl.Ki_start = single(2000); 
yawRateControl.Ki_end   = single(2000);
yawRateControl.Ki_scaling = single(1);
yawRateControl.Ksat         = single(25);

yawRateControl.Kd_start = single(50); % 50
yawRateControl.Kd_end   = single(50); % 50
yawRateControl.Kd_scaling = single(1);

yawRateControl.lookup_speed_end_kmh = single(50);

yawRateControl.ref_weight  = single(1);
yawRateControl.meas_weight = single(0.5); 

yawRateControl.enable_r_ref_limit = uint32(1);
yawRateControl.mu_scaling_r_ref_limit = single(1);

yawRateControl.enable = uint32(1);

% ------------------------------
% Traction ontrol Parameters
% ------------------------------
tractionControl.Slip_ratio_ref = single(0.15);
% Gains scheduled av torque request i tillegg ? 
% Det vil løse problemet med lave pådrag ved lav hastighet...
tractionControl.Kb = single(5); % 5 % Anti wind up gain

% While v_x is lower than full gain limit, Kp and Ki are multiplied 
% with a number between 0-1 which depends on how much torque the driver
% is requesting. 
tractionControl.full_gain_limit_kmh = single(10);

tractionControl.Kp_start = single(8);   % 7
tractionControl.Kp_end = single(150);   % 150
tractionControl.Kp_scaling = single(1); % OOOOBSBSS

tractionControl.Ki_start = single(120); % 120
tractionControl.Ki_end = single(450);   % 250
tractionControl.Ki_scaling = single(1);


tractionControl.Kp_braking = single(150); % 150
tractionControl.Ki_braking = single(450); % 450
tractionControl.lookup_speed_end_kmh = single(50);
tractionControl.enable = uint32(1);


% ------------------------------
% Power Limit Control Parameters
% ------------------------------
powerLimitControl.positive_power_limit = single(79000); % Positive effect limit
powerLimitControl.negative_power_limit = single(100000); %
powerLimitControl.Kp = single(0.000007); % (0.000003
powerLimitControl.Ki = single(0.0010);  % single(0.0002)

powerLimitControl.upper_sat_limit = single(0);
powerLimitControl.lower_sat_limit = single(-0.7); % Based on Max effect = 120KW, 8/12 = 0.6
powerLimitControl.enable = uint32(1); % 1 == enabled , 0 = disabled



% % ------------------------------
% % SPEED ESTIMATION
% % ------------------------------
% %Limits (Speed Estimation)
% speedEstimation.variance_limit = single(0.05);
% speedEstimation.RPM_derivative_limit = single(10000);
% speedEstimation.velocity_deviation_limit = single(3);
% % Gains
% speedEstimation.High_gain = single(2);
% speedEstimation.Low_gain = single(0);

% Struct for parameters only used in Matlab, not in generated control
% system code.
Use_Joystick = 1; % 1 = No, -1 = yes
battery_voltage = single(530);
matlab_params.sensor_sampling_time = 0.01;
matlab_params.control_system_sample_time = 0.01;
matlab_params.sample_time = 0.001;

% Controller settings for motors inside Carmaker blocks
% ------------------------------
Kpd = 1.72; % V/A
%Kpq = 1.9; % V/A Torque Controller
Kpq = 1; % 1.9 V/A Torque Controller
Tnq = 10; % 5 ms  Time constant Torque controller
q_BCC = 10; %Torque controller
Tnd = 1.2; % ms Time constant
Kpq2 = 20; % % adaption gain
%INVERTER SPEED
Kp = 1; % A/V Voltage controller gain
Tn_n = 0; % 1 ms. Time constant Speed
SpdC_BCC = 0; % 25
Tn = 6; % ms Voltage time constant
Speed_Pos_sat = 21;%(21/Mn)*1000;
Speed_Neg_sat = -21;%-(21/Mn)*1000;

%Name the structures for Embedded Coder
% SETTINGS
Simulink_Settings = Simulink.Parameter;
Simulink_Settings.Value = settings;
Simulink_Settings.CoderInfo.StorageClass = 'ImportedExtern';
settings = Simulink_Settings;
clear Simulink_Settings;

busInfo=Simulink.Bus.createObject(settings.Value);
Settings = eval(busInfo.busName);
settings.DataType='Bus: Settings';
clear(busInfo.busName);
clear busInfo;

%*****************************%
% CAR_PARAMS
Simulink_Car_params = Simulink.Parameter;
Simulink_Car_params.Value = car_params;
Simulink_Car_params.CoderInfo.StorageClass = 'ImportedExtern';
car_params = Simulink_Car_params;
clear Simulink_Car_params;

busInfo=Simulink.Bus.createObject(car_params.Value);
CarParams = eval(busInfo.busName);
car_params.DataType='Bus: CarParams';
clear(busInfo.busName);
clear busInfo;


%*****************************%
% PowerLimitControl
Simulink_el = Simulink.Parameter;
Simulink_el.Value = powerLimitControl;
Simulink_el.CoderInfo.StorageClass = 'ExportedGlobal';
powerLimitControl = Simulink_el;
clear Simulink_el;

busInfo=Simulink.Bus.createObject(powerLimitControl.Value);
PowerLimitControl = eval(busInfo.busName);
powerLimitControl.DataType='Bus: PowerLimitControl';
clear(busInfo.busName);
clear busInfo;

%*****************************%
%traction control
Simulink_tc = Simulink.Parameter;
Simulink_tc.Value = tractionControl;
Simulink_tc.CoderInfo.StorageClass = 'ExportedGlobal';
tractionControl = Simulink_tc;
clear Simulink_tc;

busInfo=Simulink.Bus.createObject(tractionControl.Value);
TractionControl = eval(busInfo.busName);
tractionControl.DataType='Bus: TractionControl';
clear(busInfo.busName);
clear busInfo;

% %*****************************%
% %Speed Estimation
% Simulink_speedEst = Simulink.Parameter;
% Simulink_speedEst.Value = speedEstimation;
% Simulink_speedEst.CoderInfo.StorageClass = 'ExportedGlobal';
% speedEstimation = Simulink_speedEst;
% clear Simulink_speedEst;
% 
% busInfo=Simulink.Bus.createObject(speedEstimation.Value);
% SpeedEstimation = eval(busInfo.busName);
% speedEstimation.DataType='Bus: SpeedEstimation';
% clear(busInfo.busName);
% clear busInfo;

%*****************************%
%Yaw rate control struct
Simulink_yawRate = Simulink.Parameter;
Simulink_yawRate.Value = yawRateControl;
Simulink_yawRate.CoderInfo.StorageClass = 'ExportedGlobal';
yawRateControl = Simulink_yawRate;
clear Simulink_yawRate;

busInfo=Simulink.Bus.createObject(yawRateControl.Value);
YawRateControl = eval(busInfo.busName);
yawRateControl.DataType='Bus: YawRateControl';
clear(busInfo.busName);
clear busInfo;

%*****************************%
%EnergyLimitControl
Simulink_energyLimit = Simulink.Parameter;
Simulink_energyLimit.Value = energyLimitControl;
Simulink_energyLimit.CoderInfo.StorageClass = 'ExportedGlobal';
energyLimitControl = Simulink_energyLimit;
clear Simulink_yawRate;

busInfo=Simulink.Bus.createObject(energyLimitControl.Value);
EnergyLimitControl = eval(busInfo.busName);
energyLimitControl.DataType='Bus: EnergyLimitControl';
clear(busInfo.busName);
clear busInfo;

display('loading m-file complete')
