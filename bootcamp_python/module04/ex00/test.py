from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("non_existent_file.csv")
data = loader.load("../athlete_events.csv")
#output
# Loading dataset of dimensions 

loader.display(data, 12)
# output    