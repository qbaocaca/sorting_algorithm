import math

def check_prime(n):

    if n<2:
        return False
    elif n==2:
        return True
    elif n%2 == 0:
        return False
    else:
        for i in range(3, (int)(math.sqrt(n))+1, 2):
            if n%i == 0:
                return False
    return True

def gcd(a, b):

    gcd = 1
    if a%b ==0:
        return b
    else:

        for i in range((int)(b/2), 0, -1):
            if a%i==0 and b%i==0:
                gcd = i
                break

    return gcd


# n= int(input('enter n: '))
# print(check_prime(n))

# print(gcd(2, 4))
# print(gcd(4, 2))
# print(gcd(15, 12))
# print(gcd(12, 15))

def lcm(a, b):

    z = a*b
    y=1
    lcm = z
    if a>b:
        y=a
    else:
        y=b

    # while y<=z:
    #     if y%a==0 and y%b==0:
    #         lcm = y
    #         break
    #     y+=1

    # remember when replace while by for
    # the variable changes accord to i

    for i in range(y, z+1):
        if i%a==0 and i%b==0:
            lcm = i
            break

    return lcm

print(lcm(15,18))
print(lcm(36,54))