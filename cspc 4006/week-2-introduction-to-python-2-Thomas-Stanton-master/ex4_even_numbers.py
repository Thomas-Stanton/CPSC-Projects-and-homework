def even_numbers(n):
    end_of_list = False
    while end_of_list == False:
        for i in range(len(n)):
            if n[i]%2 != 0:
                n.pop(i)
                break
            if(i == len(n) -1):
                return n
    for i in range(len(n)):
        if(n[i]%2 != 0):
            return []