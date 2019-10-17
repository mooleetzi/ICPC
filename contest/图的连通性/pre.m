function x=solvebyLU(A,b)
if flag==0
    disp('该方程组无解！');
    x=[];
    return;
else
    r=rank(A);
    [m,n]=size(A);
    [L,U,P]=lu(A);
    b=P*b;
    % 解Ly=b
    y(1)=b(1);
    if m>1
        for i=2:m
            y(i)=b(i)-L(i,1:i-1)*y(1:i-1)';
        end
    end
    y=y';
    % 解Ux=y得原方程组的一个特解
    x0(r)=y(r)/U(r,r);
    if r>1
        for i=r-1:-1:1
            x0(i)=(y(i)-U(i,i+1:r)*x0(i+1:r)')/U(i,i);
        end
    end
    x0=x0';
    if flag==1  %若方程组有唯一解
        x=x0;
        return;
    else        %若方程组有无穷多解
        format rat;
        Z=null(A,'r'); %求出对应齐次方程组的基础解系
        [~,nZ]=size(Z);
        x0(r+1:n)=0;
        for i=1:nZ
            t=sym(char([107 48+i]));
            k(i)=t;      %取k=[k1,k2...,];      
        end
        x=x0;        
        for i=1:nZ         
            x=x+k(i)*Z(:,i); %将方程组的通解表示为特解加对应齐次通解形式
        end       
   end
end