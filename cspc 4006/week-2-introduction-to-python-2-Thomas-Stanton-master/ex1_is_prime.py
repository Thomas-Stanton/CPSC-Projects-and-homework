def is_prime(n):
    answer = True
    if(n==1):
        answer = False
    for i in range(2,n-1):
        if(n%i==0):
            answer = False
    return answer
