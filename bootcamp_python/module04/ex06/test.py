from FileLoader import FileLoader
loader = FileLoader()
df = loader.load("../athlete_events.csv")

from MyPlotLib import MyPlotLib
mpl = MyPlotLib()
mpl.histogram(df, ['Height', 'Weight'])
mpl.density(df, ['Height', 'Weight'])
mpl.pair_plot(df, ['Height', 'Weight'])
mpl.box_plot(df, ['Height', 'Weight'])