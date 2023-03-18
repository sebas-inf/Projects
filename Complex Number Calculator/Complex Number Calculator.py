def menu():
    print('1-Addition')
    print('2-Substraction')
    print('3-Multiplication')
    print('4-Division')
    
def add(a,b,c,d):
    rea = (a+c)
    img = (b+d)
    return rea, img

def sub(a,b,c,d):
    rea = (a-c)
    img = (b-d)
    return rea ,img

def mul(a,b,c,d):
    rea = ((a*c)-(b*d)) 
    img = ((a*d)+(b*c))
    return rea, img
    
def div(a,b,c,d):
    rea = ((a*c)+(b*d))
    img = ((b*c)-(a*d))
    div = ((c**2)+(d**2))
    return rea, img, div

def main():
    value = ()
    print('Welcome to the Complex Number program!')
    print('Here are your choices')
    menu()
    choice = int(input('Enter your choice(1-4):'))
    while choice < 1 or choice >4:
        choice = int(input("Invalid entry. Re-enter your choice(1-4): "))
    a, b = input('Enter the first complex expression (enter real part, then imaginary part)(separate them by space): ').split()
    c, d = input('Enter the second complex expression (enter real part, then imaginary part)(separate them by space): ').split()
    a=int(a)
    b=int(b)
    c=int(c)
    d=int(d)
    if choice == 1:
        value = add(a,b,c,d)
        if b < 0:
            print('({}{}i) + ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        elif d <0:
            print('({}+{}i) + ({}{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        else:
            print('({}+{}i) + ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
    elif choice == 2:
        value = sub(a,b,c,d)
        if b < 0:
            print('({}{}i) - ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        elif d <0:
            print('({}+{}i) - ({}{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        else:
            print('({}+{}i) - ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')

    elif choice == 3:
        value = mul(a,b,c,d)
        if b < 0:
            print('({}{}i) * ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        elif d <0:
            print('({}+{}i) * ({}{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')
        else:
            print('({}+{}i) * ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i',sep='')

    elif choice == 4:
        value = div(a,b,c,d)
        if b < 0:
            print('({}{}i) / ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i /', value[2],sep='')
        elif d <0:
            print('({}+{}i) / ({}{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i /', value[2],sep='')  
        else:
            print('({}+{}i) / ({}+{}i) is: '.format(a,b,c,d), value[0],'+', value[1],'i /', value[2],sep='')
ans = ''
while ans != 'no':
    main()
    ans = input('Would you like to run the program again? Enter yes or no:')
    
    

    
        




























