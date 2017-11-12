#### Run a python script from its shell?
```python
>>> execfile('test1.py')
```

#### To check unicode 
```python
# If  Python interpreter is built with --enable-unicode=ucs4:
>>> import sys
>>> print sys.maxunicode
1114111

# If  Python interpreter is built with --enable-unicode=ucs2:
>>> import sys
>>> print sys.maxunicode
65535
```
