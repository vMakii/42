import pandas as pd


# expected output 
# {'f': 13.0, 'm': 14.0}
def youngest_fellah(df: pd.DataFrame, year: int) -> dict:
    """
    Returns a dictionary containing the age of the youngest woman and man
    who took part in the Olympics on that year.
    """
    try:
        # Filter the DataFrame for the specified year
        df_year = df[df['Year'] == year]

        # Further filter for male and female athletes
        df_male = df_year[df_year['Sex'] == 'M']
        df_female = df_year[df_year['Sex'] == 'F']

        # Find the youngest male and female athletes
        df_youngest_male = df_male.loc[df_male['Age'].idxmin()]
        df_youngest_female = df_female.loc[df_female['Age'].idxmin()]

        df_result = {
            'f': df_youngest_female['Age'],
            'm': df_youngest_male['Age']
        }
        return df_result
    except ValueError:
        return {'f': None, 'm': None}
    except KeyError:
        return {'f': None, 'm': None}