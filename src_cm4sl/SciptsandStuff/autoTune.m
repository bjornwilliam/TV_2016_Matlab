

%TRACTION CONTROL AUTO TUNE
tractionControl.Value.Kp = single(50);
%set_param('TV2016','TractionControl', single(20))
%tractionControl.Kp.Value = single(5000);



%KP start value = 7.2. Then a linear graph. 
%9.12. Kp End = 200, start = 7.2 og Ki end = 200 fungerte best.
Kp_start = single(7.2);
Kp_end = 200;
Ki_start = 200;
Ki_end = 200

Kp_Set = 200:20:300;
Ki_Set = 200:20:300;
A =combvec(Kp_Set,Ki_Set)'
Results = zeros(size(A,1),3);
for i=1:size(A,1)
   
   % Set current Gains
   Kp_end = A(i,1);
   Ki_end =A(i,2);
   tractionControl.Value.Kp = A(i,1);
   tractionControl.Value.Ki = A(i,2);
   % Run Model
   SimOut = sim('TV2016.mdl');
   pause(0.3);
   T_elapsed = SimOut(end);
   Results(i,1) = T_elapsed;
   Results(i,2) = A(i,1);
   Results(i,3) = A(i,2);
   i
end

f = scatteredInterpolant(Results(:, 3), Results(:, 2), Results(:, 1));
xlin = linspace(min(Results(:, 2)),max(Results(:, 2)),400);
ylin = linspace(min(Results(:, 3)),max(Results(:, 3)),400);
Z = f(X,Y);

[X,Y] = meshgrid(xlin,ylin);
Z = f(X,Y);
mesh(X,Y,Z)


% for (i=1:10) 
%     sim('TV2016.mdl')
%     %get_param('TV2016','SimulationStatus')
% end


