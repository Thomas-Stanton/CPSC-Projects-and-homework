def create_feature_type_dict(df):

    feature_types = {
        'numerical': {
            'continuous': [],  # Fill with continuous numerical features
            'discrete': []  # Fill with discrete numerical features
        },
        'categorical': {
            'nominal': [],  # Fill with nominal categorical features
            'ordinal': []  # Fill with ordinal categorical features
        }
    }
    return feature_types
