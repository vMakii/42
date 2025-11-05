import pandas as pd

def how_many_medals(df: pd.DataFrame, name: str) -> dict:
    """
    Returns a dictionay giving the number and type of medals
    for each year during which the participant won medals.
    """
    medals_count = {}
    try:
        # Filter the DataFrame for the specified participant name and medals won
        df_participant = df[(df['Name'] == name) & (df['Medal'].notna())]
        
        # Group by Year and Medal type, then count occurrences
        medal_groups = df_participant.groupby(['Year', 'Medal']).size().unstack(fill_value=0)

        # Convert the grouped data into the desired dictionary format
        for year in medal_groups.index:
            medals_count[year] = {
                'G': int(medal_groups.at[year, 'Gold']) if 'Gold' in medal_groups.columns else 0,
                'S': int(medal_groups.at[year, 'Silver']) if 'Silver' in medal_groups.columns else 0,
                'B': int(medal_groups.at[year, 'Bronze']) if 'Bronze' in medal_groups.columns else 0,
            }
        
        return medals_count
    
    except KeyError:
        return {}