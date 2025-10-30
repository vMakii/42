def ft_reduce(function_to_apply, iterable):
    """Apply function of two arguments cumulatively.
    Args:
        function_to_apply: a function taking an iterable.
        iterable: an iterable object (list, tuple, iterator).
    Return:
        A value, of same type of elements in the iterable parameter.
        None if the iterable can not be used by the function.
    """
    if not callable(function_to_apply):
        raise TypeError("argument must be a callable")
    try:
        iterator = iter(iterable)
    except TypeError:
        raise TypeError("argument must be an iterable")
    try:
        result = next(iterator)
    except StopIteration:
        return None
    
    for item in iterator:
        result = function_to_apply(result, item)
    return result

# Example 3:
lst = ['H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']
print(ft_reduce(lambda u, v: u + v, lst))
# Output:
# "Hello world"