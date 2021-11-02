q1 = q;
r1 = [0,0,h]

% carica 2
q2 = -q;
r2 = [0,0,-h]

% Dominio
r = [0,0,0.5]

% Funzione potenziale
pot = q1/(4*pi*e0*norm(r-r1)) + q2/(4*pi*e0*norm(r-r2))

% Funzione campo elettrico
ef_e = q1./(4*pi*e0*(norm(r-r1))^2*((r-r1)/norm(r-r1))) + q2./(4*pi*e0*(norm(r-r2))^2*((r-r2)/norm(r-r2)))
ef_g = gradient(pot)*(-1) % campo elettrico calcolato dal gradiente del potenziale

% PUNTO A
function ef = electrical_field(x,y,z) 