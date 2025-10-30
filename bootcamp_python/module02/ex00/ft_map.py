def ft_map(function_to_apply, iterable):
    """Map the function to all elements of the iterable.
    Args:
        function_to_apply: The function taking an iterable.
        iterable: An iterable object (list, tuple, iterator).
    Returns:
        An iterable.
        None if the iterable can not be used by the function.
    Raises:
        TypeError: If iterable is not an iterable object or if
                   function_to_apply is not callable.
    """
    if not callable(function_to_apply):
        raise TypeError("argument must be a callable")
    try:
        iterator = iter(iterable)
    except TypeError:
        raise TypeError("argument must be an iterable")
    
    for item in iterator:
        yield function_to_apply(item)

# Example 1:
x = [1, 2, 3, 4, 5]
y = ['a', 'b', 'c', 'd', 'e']
print(ft_map(lambda dum: dum + 1, x))
print(map(lambda dum: dum + 1, x))
# Output:
# <generator object ft_map at 0x7f708faab7b0> # The adress will be different
print(list(ft_map(lambda t: t + 1, x)))
print(list(map(str.upper, y)))
# Output:
# [2, 3, 4, 5, 6]
