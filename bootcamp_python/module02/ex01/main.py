def what_are_the_vars(*args, **kwargs):
    """
    Returns an instance of ObjectC
    """
    obj = ObjectC()
    
    # Set attributes from *args as var_0, var_1, var_2, etc.
    for i, arg in enumerate(args):
        setattr(obj, f"var_{i}", arg)
    
    # Set attributes from **kwargs
    for key, value in kwargs.items():
        if hasattr(obj, key):  # not getattr to avoid overwriting existing attributes
            return None
        setattr(obj, key, value)
    
    return obj

class ObjectC(object):
    def __init__(self):
        pass

def doom_printer(obj):
    if obj is None:
        print("ERROR")
        print("end")
        return
    for attr in dir(obj):
        if attr[0] != '_':
            value = getattr(obj, attr)
            print("{}: {}".format(attr, value))
    print("end")

if __name__ == "__main__":
    obj = what_are_the_vars(7)
    doom_printer(obj)
    obj = what_are_the_vars(None, [])
    doom_printer(obj)
    obj = what_are_the_vars("ft_lol", "Hi")
    doom_printer(obj)
    obj = what_are_the_vars()
    doom_printer(obj)
    obj = what_are_the_vars(12, "Yes", [0, 0, 0], a=10, hello="world")
    doom_printer(obj)
    obj = what_are_the_vars(42, a=10, var_0="world")
    doom_printer(obj)
    obj = what_are_the_vars(42, "Yes", a=10, var_2="world")
    doom_printer(obj)
    obj = what_are_the_vars(None, var_0="test")
    doom_printer(obj)

# $> python main.py
# var_0: 7
# end
# var_0: None
# var_1: []
# end
# var_0: ft_lol
# var_1: Hi
# end
# end
# a: 10
# hello: world
# var_0: 12
# var_1: Yes
# var_2: [0, 0, 0]
# end
# ERROR
# end
# a: 10
# var_0: 42
# var_1: Yes
# var_2: world
# end
# ERROR
# end