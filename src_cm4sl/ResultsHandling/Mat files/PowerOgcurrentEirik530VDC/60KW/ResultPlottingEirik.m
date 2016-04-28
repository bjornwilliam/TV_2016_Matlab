current = load('currentDraw.mat');
power = load('Power_Sindre.mat');
power = power.Power;
current = current.ans;




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
axis([0 4.1 0 35]);


figure(2)

plot(power.Time(:,1), power.Data(:,1));
xlabel('Time [s]');
ylabel('Power [KW]');
axis([0 4.1 0 61000]);
