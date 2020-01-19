#code
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)
    
def maxDiscount(n, x, y, a, b):
    ans = 0
    lcm = x * y // gcd(x, y)
    maxVal = max(a, b)
    temp = (n // lcm) * maxVal
    ans = ans + temp
    ans = ans + a * (n // x) - temp
    ans = ans + b * (n // y) - temp
    return ans
    
def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        x = int(input())
        y = int(input())
        a = int(input())
        b = int(input())
        print(maxDiscount(n, x, y, a, b))
        
if __name__ == '__main__':
    main()
