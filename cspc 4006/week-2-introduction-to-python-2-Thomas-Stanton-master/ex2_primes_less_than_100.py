def primes_less_than_100():
    prime_list = []
    is_prime = True
    for i in range(2,100):
        for j in range (2, i-1 ):
            if (i%j==0):
                is_prime = False
        if(is_prime== True):
            prime_list.append(i)
        is_prime=True
    return prime_list
