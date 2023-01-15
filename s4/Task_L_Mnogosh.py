import sys

def main():
    a = 341
    m = 5608713984039443
  
    n, k = [int(x) for x in input().split()]

    str_ = sys.stdin.readline().rstrip()

    a_pow = 1

    i1 = 1
    while i1 <= n:
        a_pow = (a_pow * a) % m
        i1+=1

    hash_ = []
    hash_.append(0)
    i=0
    for s in str_:
        hash_.append((hash_[i]*a + ord(s)) % m)
        i+=1
        
    begin = 1
    res = dict()
    answer = []
    end = n

    while end<=len(str_):
        h = (hash_[end] + m - (hash_[begin - 1] * a_pow) % m) % m
        if h in res:
            temp1, temp2 = res[h]
            temp1 += 1
            res[h] = (temp1, temp2)
        else:
          res[h] = (1, begin - 1)
            
            
        if res[h][0] == k:
            answer.append(res[h][1])
        begin += 1
        end += 1
      
    for ans in answer:
        print(ans, end = ' ')
        
if __name__ == '__main__':
    main() 