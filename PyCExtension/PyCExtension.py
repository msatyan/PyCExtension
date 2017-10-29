# import os
# def __bootstrap__():
#        global __bootstrap__, __loader__, __file__
#    import sys, pkg_resources, imp
#    __file__ = pkg_resources.resource_filename(__name__,'MyCLib\MyCLib.pyd')
#    __loader__ = None; del __bootstrap__, __loader__
#    imp.load_dynamic(__name__,__file__)
# __bootstrap__()


# import MyCLib

def Main():
	# rc = MyCLib.Test1("Hello From Python")
    # print('The Pyhon has recieved {:d} from C function'.format(rc))
    print('Hello from PyCExtension')

if __name__ == "__main__":
    Main()
else:
    print("one.py is being imported into another module")



