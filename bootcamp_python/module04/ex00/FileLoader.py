from dataclasses import dataclass
import pandas as pd

@dataclass
class FileLoader:
    def load(self, path):
        """
        takes as an argument the file path of the dataset to load,
        displays a message specifying the dimensions of the dataset
        (e.g. 1000 x 15) and returns the dataset as a pandas DataFrame.
        """
        try:
            df = pd.read_csv(path)
            print(f"Loading dataset of dimensions {df.shape[0]} x {df.shape[1]}\n")
            return df
        except FileNotFoundError as e:
            print(f"Exception: FileNotFoundError -- strerror: {e.strerror}")
            return None
        except pd.errors.EmptyDataError as e:
            print(f"Exception: EmptyDataError -- strerror: {str(e)}")
            return None
        except Exception as e:
            print(f"Exception: {type(e).__name__} -- strerror: {str(e)}")
            return None
        
    def display(self, df, n):
        """
        takes a pandas DataFrame and an integer as arguments, displays the first n rows
        of the dataset if n is positive, or the last n rows if n is negative.
        """
        try:
            if df is not None:
                if n > 0:
                    print(df.head(n))
                else:
                    print(df.tail(-n))
                print(f"\n{abs(n)} rows x {df.shape[1]} columns")
            else:
                print("No data to display.")
        except Exception as e:
            print(f"Exception: {type(e).__name__} -- {str(e)}")