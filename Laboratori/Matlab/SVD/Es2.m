n = 7;
B = zeros(n);

for i=1:n
    for j=1:n
        if i==j
           k = 1;
        else 
            if(i<j)
                k = -1;
            else
                k = 0;
            end
        end
        B(i,j) = k;
    end
end

S = svd(B);
S_max = max(S);
S_min = min(S);

if det(B) == 0
    error('B non invertibile')
else
    cond_2 = norm(B,2) * norm(inv(B),2);
end

B2 = B;
B2(n,1) = -pow2(2-n);
VB2 = real(eig(B2));