syms x1 x2 x3 x4 x5 x6 x7 x8
syms a1 b1 c1  d1 a2 b2 c2 d2 te

v = [x1,x2,x3,x4,x5,x6,x7,x8];
A = [ (x1 + te*(-a1*x6 - b1*x8 + c1*x5*x8 + d1*x6*x7)),
      (x2 + te*(-a1*x6 + b1*x8 - c1*x5*x8 - d1*x6*x7)),
      (x3 + te*(a2*x6  - b2*x8 - c2*x5*x8 - d2*x6*x7)),
      (x4 + te*(a2*x6  + b2*x8 + c2*x5*x8 + d2*x6*x7)),
      (x5 + te*x6),
      (x6),
      (x7 + te*x8),
      x8];

%A = [x1, x1*x2, x2,x3,x4,x5,x6,x8];
jacobian(A,v)


H = [ (x1-x2+x3-x4),
      (x1+x2),
      (x5),
      (x7),
      (x1+x2+x3+x4)];
 
 jacobian(H,v)
    