int fibo(n){
    if(n==0) return 1;
    else if (n==1) return 2;
    else return fibo(n-1) + fibo(n-2);
}