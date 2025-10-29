def ft_map(function_to_apply, iterable):
    """Map the function to all elements of the iterable.
    Args:
        function_to_apply: The function taking an iterable.
        iterable: An iterable object (list, tuple, iterator).
    Returns:
        An iterable.
        None if the iterable can not be used by the function.
    """
    for item in iterable:
        yield function_to_apply(item)

# Example 1:
x = [1, 2, 3, 4, 5]
print(ft_map(lambda dum: dum + 1, x))
# Output:
# <generator object ft_map at 0x7f708faab7b0> # The adress will be different
print(list(ft_map(lambda t: t + 1, x)))
# Output:
# [2, 3, 4, 5, 6]
