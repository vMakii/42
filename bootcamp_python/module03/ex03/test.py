from ImageProcessor import ImageProcessor
imp = ImageProcessor()
arr = imp.load("../ex01/42AI.png")

from ColorFilter import ColorFilter
cf = ColorFilter()
cf.invert(arr)
imp.display(arr)

cf.to_green(arr)
imp.display(arr)

cf.to_red(arr)
imp.display(arr)

cf.to_blue(arr)
imp.display(arr)

cf.to_celluloid(arr)
imp.display(arr)

cf.to_grayscale(arr, 'm')
imp.display(arr)

cf.to_grayscale(arr, 'weight', r_weight=0.2, g_weight=0.3, b_weight=0.5)
imp.display(arr)