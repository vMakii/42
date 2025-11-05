from dataclasses import dataclass
import pandas as pd
from typing import List

@dataclass
class SpatioTemporalData:
    df: pd.DataFrame

    def when(self, location: str) -> List[int]:
        """
        Returns a list containing the years where games were held in the given location.
        """
        try:
            # Filter the DataFrame for the specified location
            df_location = self.df[self.df['City'] == location]
            # Extract unique years and sort them
            years = sorted(df_location['Year'].unique())
            return years
        except KeyError:
            return []
        
    def where(self, date: int) -> List[str]:
        """
        Returns a list containing the locations where games were held in the given year.
        """
        try:
            # Filter the DataFrame for the specified year
            df_year = self.df[self.df['Year'] == date]
            # Extract unique locations and sort them
            locations = sorted(df_year['City'].unique())
            return locations
        except KeyError:
            return []
