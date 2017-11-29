
def main():
    exa = {
        'a':1,
        'b':2,
        'c':3,
    }
    cha = ['a','b','c']
    change(cha)
    print cha
    # for i in range(5):
    # print ('a' in exa)

def change(a):
    a[0]='changed'

if __name__ == '__main__':
    main()