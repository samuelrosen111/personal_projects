from lib2to3.pgen2.token import VBAR
import time
import math
from datetime import datetime




def is_prime(number, primes):
    max_value_that_you_need_to_check = int(1 + math.sqrt(len(primes)))
    for i in range(0,max_value_that_you_need_to_check):
        if(number%primes[i]==0):
            return 0
    return 1


def is_palindrome(number):
    if(number < 10 and number > 0):
        return 1
    temp = number
    array = []
    while(1):
        array.append(temp%10)
        temp = int(0.1*(temp-temp%10)) #removes last digit and scales down number by a facotr 10
        if(temp < 10):
            array.append(temp)
            break
    if(array == array[::-1]):
        return 1
    return 0

def main():
    primes = [3,5,7,11]
    current_number = 13

    max = int(input("This program will print all primes up to number X. Enter the desired value of X: "))
    print("For all primes enter 0 \nFor palindromic primes enter 1\nFor Balanced primes enter 2")
    prime_check = int(input("Enter your choice: "))
    
    if(prime_check == 0):
        then = datetime.now()
        while current_number <= max:
            if(is_prime(current_number, primes)):
                primes.append(current_number)
                #print(current_number)
            status = int(100*current_number/max)
            now = datetime.now()
            if(now.strftime("%S") != then.strftime("%S")):
                print("Calculation is ", status, " percent complete")
                then = now
            current_number += 2 # jumping increments of 2 to save time
        
        print("Done! Printing out all calculated primes:")
        time.sleep(2)
        print(".", end='')
        time.sleep(1)
        print(".", end='')
        time.sleep(1)
        print(".")
        time.sleep(2)
        for i in primes:
            print(i)
            time.sleep(0.1)

    if(prime_check == 1):
        then = datetime.now()
        while current_number <= max:
            if(is_prime(current_number, primes) and is_palindrome(current_number)):
                primes.append(current_number)
                #print(current_number)
                #time.sleep(0.1)
            current_number += 2 # jumping increments of 2 to save time
            status = int(100*current_number/max)
            now = datetime.now()
            if(now.strftime("%S") != then.strftime("%S")):
                print("Calculation is ", status, " percent complete")
                then = now
        print("Done! Here are all calculated palindrome primes:")
        time.sleep(2)
        print(".", end='')
        time.sleep(1)
        print(".", end='')
        time.sleep(1)
        print(".")


        time.sleep(2)
        for i in primes:
            print(i)
            time.sleep(0.1)



    if(prime_check==2): 
        then = datetime.now()
        while current_number <= max:
            if(is_prime(current_number, primes)):
                primes.append(current_number)
            current_number += 2 # jumping increments of 2 to save time
            status = int(100*current_number/max)
            now = datetime.now()
            if(now.strftime("%S") != then.strftime("%S")):
                print("Calculation is ", status, " percent complete")
                then = now
        balanced_primes = []
        for i in range(1,len(primes)-2):
            a = i+1
            b = i
            c = i-1
            d1 = primes[a] - primes[b]
            d2 = primes[b] - primes[c]
            if(d1==d2):
                balanced_primes.append(primes[i])

        print("Done! Here are the balanced primes", end = '')
        time.sleep(2)
        print(".", end='')
        time.sleep(1)
        print(".", end='')
        time.sleep(1)
        print(".")


        for i in balanced_primes:
            time.sleep(0.1)
            print(i)
    
    
    print("Done.")

main()