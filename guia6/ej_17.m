close all;
clear all;


SIZE = 100000;

A = randi([1 100],1,SIZE);
L = length(A);
u = L;
p = 1;

A = AS2(A,p,u);
A = A'

%% Checkeo si cumple.
OK = 1;
for i=2:L
    j = (-1)^(mod(i,2)==0);
    if(j*A(i-1)<j*A(i))
        OK = 0;
    end
end