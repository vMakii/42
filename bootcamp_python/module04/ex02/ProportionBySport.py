import pandas as pd

def proportion_by_sport(df: pd.DataFrame, year: int, sport: str, gender: str) -> float:
    """
    Returns a float corresponding to the proportion of participants who played
    the given sport among the participants fo the given gender
    """
    try:
        # Filter the DataFrame for the specified year and gender + drop duplicates
        df_filtered = df[(df['Year'] == year) & (df['Sex'] == gender)].drop_duplicates(subset=['ID'])
        
        total_count = len(df_filtered)
        if total_count == 0:
            return 0.0
        
        # Further filter for the specified sport (already deduplicated)
        df_sport = df_filtered[df_filtered['Sport'] == sport]
        sport_count = len(df_sport)
        
        # Calculate the proportion
        proportion = sport_count / total_count
        return proportion
    
    except KeyError:
        return 0.0