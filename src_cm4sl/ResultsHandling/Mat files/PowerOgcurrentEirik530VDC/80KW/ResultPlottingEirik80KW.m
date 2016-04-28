current1 = load('currentDraw.mat');
power1 = load('Power_Sindre.mat');
power = power1.Power;
current = current1.ans;




figure(1)
plot(current.Time(:,1), current.Data(:,1));
hold on
plot(current.Time(:,1), current.Data(:,2));
hold on
plot(current.Time(:,1), current.Data(:,3));
hold on
plot(current.Time(:,1), current.Data(:,4));

legend('Current FL','Current FR', 'Current RL', 'Current RR');
xlabel('Time [s]');
ylabel('Current draw [Ampere]');
axis([0 3.8 0 45]);


figure(2)

plot(power.Time(:,1), power.Data(:,1));
xlabel('Time [s]');
ylabel('Power [KW]');
axis([0 3.8 0 81000]);
