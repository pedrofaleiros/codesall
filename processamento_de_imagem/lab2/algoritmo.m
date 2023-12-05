function X = algoritmo(L,alfa)
X = zeros(L,L);
for i = 1:L
for j = 1:L
X(i,j) = exp( -((i-L/2)^2 + (j-L/2)^2)/alfa^2 );
end
end
