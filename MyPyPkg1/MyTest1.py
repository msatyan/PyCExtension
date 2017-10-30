import MyCLib1 as myCextn1

def Main():
    print('Hello from PyCExtension')
    a1 = 10
    b1 = 2

    rc = myCextn1.Add( a1, b1);
    print('Value of C After Add() is {:d} from C function'.format(rc))

    a2 = 10.5
    b2 = 2.25
    rc2 = myCextn1.Multiply( a2, b2);
    print('Value of C After Multiply() is {:.6f} from C function'.format(rc2))


if __name__ == "__main__":
    Main()
else:
    print("one.py is being imported into another module")


