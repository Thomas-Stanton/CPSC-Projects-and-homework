def first_100_primes():
         counter = 0
         counting = True
         while counting == True:
                 prime_list = []
                 is_prime = True
                 for i in range(2,1000000000):
                           for j in range (2, i-1 ):
                                    if (i%j==0):
                                             is_prime = False
                           if(is_prime== True):
                                    prime_list.append(i)
                           is_prime=True
                           if len(prime_list) == 100:
                                    return prime_list