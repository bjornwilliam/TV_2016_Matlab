res = load('MotorTorques.mat')

torque_constant = 0.26

res.MotorTorques.Time(:,1);

averageTorque = sum(abs(res.MotorTorques.Data(:,1))) / length(res.MotorTorques.Data(:,1))
averageACRMS = averageTorque/torque_constant
figure(1) 
plot(res.MotorTorques.Time(:,1), abs(res.MotorTorques.Data(:,1)/0.26));
hold on
plot(res.MotorTorques.Time(:,1), abs(res.MotorTorques.Data(:,2)/0.26));
hold on
plot(res.MotorTorques.Time(:,1), abs(res.MotorTorques.Data(:,3)/0.26));
hold on
plot(res.MotorTorques.Time(:,1), abs(res.MotorTorques.Data(:,4)/0.26));
legend('AC RMS FL','AC RMS FR', 'AC RMS RL', 'AC RMS RR');
xlabel('Time [s]');
ylabel('AC RMS');
axis([0 75 0 80]);


% % 18 inputs
% %TRQ 3-6
% %RPM 15-18
% %SR = 11-14
% 
% %RPM
% figure(1)
% plot(res.sim.Time(:,1), res.sim.Data(:,15));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,16));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,17));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,18));
% 
% %SR
% figure(2)
% plot(res.sim.Time(:,1), res.sim.Data(:,11));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,12));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,13));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,14));
% hold on
% plot(res.sim.Time(:,1), ones(size(res.sim.Time(:,1)))*0.15);
% hold on
% plot(res.sim.Time(:,1), ones(size(res.sim.Time(:,1)))*(-0.15));
% legend('SR FL','SR FR', 'SR RL', 'SR RR', 'Positive SR reference','Negative SR reference');
% xlabel('Time [s]');
% ylabel('Slip ratio (SR)');
% axis([0 3.5 -0.2 0.4]);
% 
% %TRQ
% figure(3)
% plot(res.sim.Time(:,1), res.sim.Data(:,3));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,4));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,5));
% hold on
% plot(res.sim.Time(:,1), res.sim.Data(:,6));
% 
% legend('Torque FL','Torque FR', 'Torque RL', 'Torque RR');
% xlabel('Time [s]');
% ylabel('Wheel torque [Nm]');
% axis([0 3.5 -350 350]);
