from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("../athlete_events.csv")

from YoungestFellah import youngest_fellah
assert data is not None, "Failed to load data: loader.load returned None"
print(youngest_fellah(data, 2004))