res = load('79KW_max_aks_75m_with_TC.mat')
resUnc = load('max_aks_75m_with_TC_No_power.mat')


% 18 inputs
%TRQ 3-6
%RPM 15-18
%SR = 11-14

figure(1)
plot(resUnc.Power.Time(:,1), resUnc.Power.Data(:,1));
hold on
plot(resUnc.Power.Time(:,1), ones(size(resUnc.Power.Time(:,1)))*80000);
xlabel('Time [s]');
ylabel('Power [KW]');
axis([0 3.5 0 13*10^4]);
legend('Total power','80 KW power limit');

figure(2)
plot(res.Power.Time(:,1), res.Power.Data(:,1));
hold on
plot(res.Power.Time(:,1), ones(size(res.Power.Time(:,1)))*80000);
legend('Total power','80 KW power limit');
xlabel('Time [s]');
ylabel('Power [KW]');
axis([0 3.5 0 8.3*10^4]);

