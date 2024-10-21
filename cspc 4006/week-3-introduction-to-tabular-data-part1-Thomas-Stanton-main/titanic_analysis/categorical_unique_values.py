def display_unique_values(df, categorical_features):
    unique_values = {}
    for feature in categorical_features:
        if feature in df:
            unique_values[feature] = df[feature].unique()  # List of unique values for each categorical feature
    
    return unique_values
    pass  # Implement the logic here
