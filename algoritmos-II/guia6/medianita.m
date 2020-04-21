%asume largos iguales
function M = medianita(A,B)
    L = length(A);
    m1 = median(A);
    m2 = median(B);
    K = ceil(L/2);
    p = mod(L,2) == 0;
    
    if( m1 ~= m2 )
        if( L > 2 )
            if(m1 < m2)
                M = medianita(A(K:end),B(1:K+p));
            end
            if(m1 > m2)
                M = medianita(A(1:K+p),B(K:end));
            end
        end

        if( L == 2 )
            M = (max(A(1),B(1)) + min(A(2),B(2))) / 2;
        end
    
    elseif(m1 == m2)
        M = m1;
    end

end