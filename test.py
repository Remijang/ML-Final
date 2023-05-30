import numpy as np
import pandas as pd


def get_data(filename='train.csv'):


    # read csv
    df = pd.read_csv(filename)

    # get x and y
    y = df['Danceability'].to_numpy().astype(np.int32)
    x = df.drop(['Danceability'], axis=1).to_numpy()

    print(type(x), type(y))
    print(x.shape, y.shape)

get_data()
