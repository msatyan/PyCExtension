import imp
import pkg_resources

def __bootstrap__():
   global __bootstrap__, __loader__, __file__
   #__file__ = pkg_resources.resource_filename(__name__,'../x64/Debug/MyCLib1.pyd')
   __file__ = pkg_resources.resource_filename(__name__,'../MyCLib1/build/lib.win-amd64-3.6/MyCLib1.cp36-win_amd64.pyd')
   __loader__ = None; del __bootstrap__, __loader__
   imp.load_dynamic(__name__,__file__)
__bootstrap__()
