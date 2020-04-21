close all
clear all

M = 1;
Mreal = 1;
N = 553;

while( M == Mreal )
    A = sort( randi(500,1,N) );
    B = sort( randi(500,1,N) );

    M = medianita(A,B)
    Mreal = median( sort([A B]) )
end