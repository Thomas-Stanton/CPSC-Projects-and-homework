import pytest
from ex1_is_prime import is_prime
from ex2_primes_less_than_100 import primes_less_than_100
from ex3_first_100_primes import first_100_primes
from ex4_even_numbers import even_numbers
from ex5_unique_elements import unique_elements
from ex6_word_count import word_count
from ex7_factorial import factorial
from ex8_fizzbuzz import fizzbuzz
from ex9_squares_of_evens import squares_of_evens

def test_is_prime():
    assert is_prime(7) == True
    assert is_prime(10) == False
    assert is_prime(2) == True
    assert is_prime(1) == False

def test_primes_less_than_100():
    expected_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    assert primes_less_than_100() == expected_primes

def test_first_100_primes():
    assert len(first_100_primes()) == 100

def test_even_numbers():
    assert even_numbers([1, 2, 3, 4, 5, 6]) == [2, 4, 6]
    assert even_numbers([10, 11, 12]) == [10, 12]
    assert even_numbers([1, 3, 5]) == []

def test_unique_elements():
    assert unique_elements([1, 2, 2, 3, 4, 4, 5]) == {1, 2, 3, 4, 5}

def test_word_count():
    sentence = "this is a test this is only a test"
    expected_output = {'this': 2, 'is': 2, 'a': 2, 'test': 2, 'only': 1}
    assert word_count(sentence) == expected_output

def test_factorial():
    assert factorial(5) == 120
    assert factorial(0) == 1
    assert factorial(1) == 1

def test_fizzbuzz():
    # You may want to test this by capturing print output
    captured_output = fizzbuzz(15)
    expected_output = [1, 2, "Fizz", 4, "Buzz", "Fizz", 7, 8, "Fizz", "Buzz", 11, "Fizz", 13, 14, "FizzBuzz"]
    assert captured_output == expected_output

def test_squares_of_evens():
    assert squares_of_evens([1, 2, 3, 4, 5]) == [4, 16]
    assert squares_of_evens([2, 4, 6]) == [4, 16, 36]
    assert squares_of_evens([1, 3, 5]) == []
