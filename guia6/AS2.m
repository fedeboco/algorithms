function A = AS2(A,p,u)

    if(p < u)
        m = floor((p+u)/2);
        AS2(A,p,m);
        AS2(A,m+1,u);
        for i=p:u-1
            if( (A(i)<A(i+1) && mod(i,2)==0) || (A(i)>A(i+1) && mod(i,2)==1) )
                aux = A(i+1);
                A(i+1) = A(i);
                A(i) = aux;
            end      
        end
    end

end