def factorial(n):
    answer = n
    for i in range(n-1,0,-1):
        answer *= i
    if(answer==0):
        answer = 1
    return answer