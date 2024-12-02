% Genera una matrice di Pascal 10x10
n = 10;
P = pascal(n);

% Calcola l'inversa della matrice
P_inv = inv(P);

% Calcola la norma 2 della matrice e della sua inversa
norm_P = norm(P, inf);
norm_P_inv = norm(P_inv, inf);

% Calcola il condizionamento della matrice
conditioning = norm_P * norm_P_inv;

% Visualizza i risultati
disp('Matrice di Pascal 10x10:');
disp(P);

disp('Inversa della matrice di Pascal:');
disp(P_inv);

disp(['Norma infinito di P: ', num2str(norm_P)]);
disp(['Norma infinito di P^{-1}: ', num2str(norm_P_inv)]);
disp(['Condizionamento di P: ', num2str(conditioning)]);
