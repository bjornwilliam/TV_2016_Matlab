
c = single(2*pi/(15.6*60));

rpm = 0:10:5000;
load = 600: :1000



whl_speed = sensors.RPM_FL*c*r_eff_true;


SR_True = (whl_speed_true- V_x) / max([0.01, abs(whl_speed_true), abs(V_x)]);
SR_False =(whl_v.FL - V_x) / max([0.01, abs(whl_v.FL), abs(V_x)]);

% Hva vil jeg vise.. Hvor stor feil introduserer maksimalt r_eff 