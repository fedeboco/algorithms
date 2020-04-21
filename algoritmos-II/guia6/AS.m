function A = AS(L,A)
    if( L > 2 )
        A = AS(L-1, A);
    end
    if( (A(L)<A(L-1) && mod(L,2)==0) || (A(L)>A(L-1) && mod(L,2)==1) )
        aux = A(L);
        A(L) = A(L-1);
        A(L-1) = aux;
    end
end