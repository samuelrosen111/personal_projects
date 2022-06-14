import time
import math

print("Test 101 ")


primes = [3,5,7,9,11]

max = int(input("This program will print all primes up to number X. Enter the desired value of X: "))

def is_prime(number, primes):
    max_value_that_you_need_to_check = int(1 + math.sqrt(len(primes)))
    for i in range(0,max_value_that_you_need_to_check):
        if(number%primes[i]==0):
            return 0
    return 1


current_number = 13
while current_number <= max:
    if(is_prime(current_number, primes)):
        primes.append(current_number)
    current_number += 2


for i in primes:
    print(i)
    #time.sleep(0.1)