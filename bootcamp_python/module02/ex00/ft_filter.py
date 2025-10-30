def ft_filter(function_to_apply, iterable):
    """Filter the result of function apply to all elements of the iterable.
    Args:
        function_to_apply: a function taking an iterable.
        iterable: an iterable object (list, tuple, iterator).
    Return:
        An iterable.
        None if the iterable can not be used by the function.
    """
    if not callable(function_to_apply):
        raise TypeError("argument must be a callable")
    try:
        iterator = iter(iterable)
    except TypeError:
        raise TypeError("argument must be an iterable")
    
    for item in iterator:
        if function_to_apply(item):
            yield item

# Example 2:
x = [1, 2, 3, 4, 5]
print(ft_filter(lambda dum: not (dum % 2), x))
# Output:
# <generator object ft_filter at 0x7f709c777d00> # The adress will be different
print(list(ft_filter(lambda dum: not (dum % 2), x)))
# Output:
# [2, 4]