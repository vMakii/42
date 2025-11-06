import pandas as pd

team_sports = ['Basketball', 'Football', 'Tug-Of-War', 'Badminton', 'Sailing',
               'Handball', 'Water Polo', 'Hockey', 'Rowing', 'Bobsleigh', 'Softball',
               'Volleyball', 'Synchronized Swimming', 'Baseball', 'Rugby Sevens',
               'Rugby', 'Lacrosse', 'Polo']

def how_many_medals_by_country(df: pd.DataFrame, country: str) -> dict:
    """
    Returns a dictionary of dictionaries giving the number and types of medals
    for each competition where the country delegation earned medals.
    """
    result = {}
    counted_team_medals = set()
    
    for index, row in df.iterrows():
        if row['Team'] == country:
            year = row['Year']
            medal = row['Medal']
            sport = row['Sport']
            event = row['Event']
            
            if pd.notna(medal):
                if year not in result:
                    result[year] = {'G': 0, 'S': 0, 'B': 0}
                
                # Pour les sports d'équipe, ne compter qu'une fois par événement
                if sport in team_sports:
                    medal_key = (year, sport, event, medal)
                    if medal_key in counted_team_medals:
                        continue
                    counted_team_medals.add(medal_key)
                
                if medal == 'Gold':
                    result[year]['G'] += 1
                elif medal == 'Silver':
                    result[year]['S'] += 1
                elif medal == 'Bronze':
                    result[year]['B'] += 1
    
    return dict(sorted(result.items()))