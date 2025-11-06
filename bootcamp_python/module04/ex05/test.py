from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("../athlete_events.csv")

from HowManyMedalsByCountry import how_many_medals_by_country
# print(how_many_medals_by_country(data, "France"))
result = how_many_medals_by_country(data, 'France')
for year, medals in result.items():
    print(f"{year}: {medals}")