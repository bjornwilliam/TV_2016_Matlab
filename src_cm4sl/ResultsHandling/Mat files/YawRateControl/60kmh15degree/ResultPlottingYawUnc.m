res = load('SimResultUnc.mat')



% 18 inputs
%TRQ 3-6
%RPM 15-18
%SR = 11-14

%Steering ang 19

%RPM
figure(1)
plot(res.sim.Time(:,1), res.sim.Data(:,15));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,16));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,17));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,18));

%SR
figure(2)
plot(res.sim.Time(:,1), res.sim.Data(:,11));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,12));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,13));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,14));
hold on
plot(res.sim.Time(:,1), ones(size(res.sim.Time(:,1)))*0.15);
hold on
plot(res.sim.Time(:,1), ones(size(res.sim.Time(:,1)))*(-0.15));
legend('SR FL','SR FR', 'SR RL', 'SR RR', 'Positive SR reference','Negative SR reference');
xlabel('Time [s]');
ylabel('Slip ratio (SR)');
axis([0 3.5 -0.2 0.4]);

%TRQ
figure(3)
plot(res.sim.Time(:,1), res.sim.Data(:,3));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,4));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,5));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,6));
legend('Torque FL','Torque FR', 'Torque RL', 'Torque RR');
xlabel('Time [s]');
ylabel('Wheel torque [Nm]');
axis([6 8 -120 150]);

%Yaw rate tracking
figure(4)
plot(res.sim.Time(:,1), res.sim.Data(:,1));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,2));
legend('Ref. yaw rate','Meas. yaw rate');
xlabel('Time [s]');
ylabel('Yaw rate [deg/s]');
axis([6 8 -2 50]);


%Steering wheel angle
figure(5)
plot(res.sim.Time(:,1), res.sim.Data(:,8)); % mean wheel angle
xlabel('Time [s]');
ylabel('Mean wheel angle [deg]');
axis([6 8 -0.1 4.5]);




