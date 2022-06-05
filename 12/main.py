def eratosphen(n):
    prime_numbers = set()
    for i in range(2, n):
        is_prime = 1
        for p in prime_numbers:
            if i % p == 0:
                is_prime = 0
                break
        if is_prime:
            yield i
            prime_numbers.add(i)


print('Простые числа от 2 до 500')
for a in eratosphen(500):
    print(a)
