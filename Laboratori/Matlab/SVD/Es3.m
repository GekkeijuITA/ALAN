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

y = zeros(m, 1);
for i=1:m
    y(i,1) = sin(i/m);
end

[U,S,V] = svd(A);
c1 = (V*pinv(S)*U')*y;
[Q,R] = qr(A);
c2 = R \ (Q'*y);
c3 = (A'*A) \ (A'*y);
c4 = A\y;