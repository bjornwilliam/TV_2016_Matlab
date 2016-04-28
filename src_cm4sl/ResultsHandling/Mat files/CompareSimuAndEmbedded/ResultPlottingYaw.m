res = load('SimResult.mat')
embrref = load('yawRateRef.mat')
embr = load('yawRateMeasured.mat')
yawRate = embr.rMeas;
yawRateRef = embrref.rRef;


yawRateRef.Time((317:end),1);
% 18 inputs
%TRQ 3-6
%RPM 15-18
%SR = 11-14

%Yaw rate tracking
figure(1)
plot(res.sim.Time(:,1), res.sim.Data(:,1));
hold on
plot(res.sim.Time(:,1), res.sim.Data(:,2));
hold on

plot(yawRateRef.Time(:,1), yawRateRef.Data(:,1)*180/pi);
hold on 
plot(yawRate.Time(:,1), yawRate.Data(:,1)*180/(pi));

legend('Ref. yaw rate (Simulink)','Meas. yaw rate (Simulink)','Ref. yaw rate (Embedded)','Meas. yaw rate (Embedded)');
xlabel('Time [s]');
ylabel('Yaw rate [deg/s]');
axis([3.2 6.4 -2 75]);








