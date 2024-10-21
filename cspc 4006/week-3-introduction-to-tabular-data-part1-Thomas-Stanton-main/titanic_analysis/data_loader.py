import pandas as pd

def load_titanic_data(filepath: str) -> pd.DataFrame:
    df = pd.read_csv(filepath)
    return df
    pass  # Implement the loading logic here
