from FileLoader import FileLoader
loader = FileLoader()
data = loader.load('../athlete_events.csv')
# Output
# Loading dataset of dimensions 271116 x 15
from ProportionBySport import proportion_by_sport
print(proportion_by_sport(data, 2004, 'Tennis', 'F'))
# Output
# 0.019302325581395347