import datetime
import MyCLib1 as myCextn1


def PyPrimeCount(x, y):
    i = 0
    j = 0
    VRange = 0.0
    isPrime = 0
    PrimeCount = 0

    if x < 2:
        x = 2
    
    y = y+1
    i = x
    while ( i < y):
        isPrime = 1
        VRange = i / 2 # This Validation Range is good enough

        j = 2
        VRange = VRange + 1
        while ( j < VRange ):
            if ( i%j == 0):
                j = j+1
                isPrime = 0
                break
            j = j+1

        if (isPrime):
            #print( ' [{:d}] '.format(i))
            PrimeCount = PrimeCount + 1

        i = i +1

    return PrimeCount


def Main():
    print(' ')
    print('Hello from PyCExtension')
    a1 = 10
    b1 = 2

    print(' ')
    rc = myCextn1.Add( a1, b1);
    print('    Add( {:d} + {:d} ) = {:d}'.format(a1, b1, rc))

    a2 = 10.5
    b2 = 2.25
    rc2 = myCextn1.Multiply( a2, b2);
    print('    Multiply(  {:.6f} x {:.6f} ) =  {:.6f}'.format(a2, b2, rc2))

    x = 2
    y = 100000

    print(' ')
    print('  ************* C Py Speed Test *************')
    print('    C: Please Wait, Running CPrimes()........')
    s = datetime.datetime.now()
    rc3 = myCextn1.CPrimeCount( x, y)
    e = datetime.datetime.now()
    delta = e - s
    
    print('    Number of primes between {:d} and {:d} = {:d} '.format(x, y, rc3))
    print('    C() Time taken = {}'.format(delta))


    print(' ')
    print('    Py: Please Wait, Running PyPrimes()........')
    rc3 = 0
    s = datetime.datetime.now()
    rc3 = PyPrimeCount(x, y)
    e = datetime.datetime.now()
    delta = e - s

    print('    Number of primes between {:d} and {:d} = {:d} '.format(x, y, rc3))
    print('    Py() Time taken = {}'.format(delta))

    print(' ')
    print('Good By!');


if __name__ == "__main__":
    Main()
else:
    print("It is being imported into another module")


# Hello from PyCExtension

#     Add( 10 + 2 ) = 12
#     Multiply(  10.500000 x 2.250000 ) =  23.625000

#   ************* C Py Speed Test *************
#     C: Please Wait, Running CPrimes()........
#     Number of primes between 2 and 100000 = 9592
#     C() Time taken = 0:00:00.562664

#     Py: Please Wait, Running PyPrimes()........
#     Number of primes between 2 and 100000 = 9592
#     Py() Time taken = 0:00:23.202617

# Good By!

