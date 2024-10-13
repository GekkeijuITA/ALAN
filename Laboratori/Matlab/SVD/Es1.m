matr = [5 7 0 3 1 1 7];
d0 = matr(1,6);
d1 = matr(1,7);
m = 10 * (d0 + 1) + d1;
A = zeros(3);
for i=1:m
    A(i,2) = i/m;
    A(i,3) = (i/m) ^ 2;
end
A(:,1) = 1;
[U,S,V] = svd(A);
[U2,S2,V2] = svd(A');

VA = eig(A*A');
VA2 = eig(A'*A);

Q = orth(A);
Q2 = orth(A');

N = null(A);
N2 = null(A');