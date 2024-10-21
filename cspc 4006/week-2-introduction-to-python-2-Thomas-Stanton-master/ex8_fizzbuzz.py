def fizzbuzz(n):
    number = []
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            number.append("FizzBuzz")
        elif i % 3 == 0:
            number.append("Fizz")
        elif i % 5 == 0:
            number.append("Buzz")
        else:
            number.append(i)
    print(number)