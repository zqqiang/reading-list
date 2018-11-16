import pandas as pd
from matplotlib import pyplot
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import LabelEncoder
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import LSTM


def time_series_pre_process(csv):
    """
    raw data pre process
    merge time series column into one column
    set NA to 0 in pm2.5 column
    remove No column which is unnecessary
    """
    csv_data = pd.read_csv(csv,
                           parse_dates=[['year', 'month', 'day', 'hour']],
                           index_col=0)
    csv_data['pm2.5'].fillna(0, inplace=True)
    csv_data.drop('No', axis=1, inplace=True)

    return csv_data


def time_series_quick_view(time_series):
    """
    create a time series quick view of each series 
    """
    pyplot.figure(figsize=(10, 10))
    plot_index = 1
    cols = ['pm2.5', 'DEWP', 'TEMP', 'PRES', 'Iws', 'Is', 'Ir']
    col_titles = ['pm2.5', 'Dew Point', 'Temperature',
                  'Pressure', 'Cumulated wind speed', 'Cumulated hours of snow', 'Cumulated hours of rain']
    for col in cols:
        pyplot.subplot(len(cols), 1, plot_index)
        pyplot.plot(time_series[col].values)
        pyplot.title(col_titles[plot_index-1], y=0.7, loc='right')
        plot_index += 1
    pyplot.show()


def col_label_encode_and_normalize(csv_data, encode_col_index):
    """
    The wind speed feature is string 
    we need use LabelEncoder to encode it to integer
    use MinMaxScaler to normalize to [0, 1]
    """
    encoded_data = csv_data.values
    encoder = LabelEncoder()
    encoded_data[:, encode_col_index] = encoder.fit_transform(
        encoded_data[:, encode_col_index])

    scaler = MinMaxScaler(feature_range=(0, 1))
    scaled_data = scaler.fit_transform(encoded_data)
    return scaled_data


def series_to_supervised(data, n_in=1, n_out=1, dropnan=True):
    """
    time series forecasting problems must be re-framed as supervised learning problems
    this function is from below article:
    https://machinelearningmastery.com/convert-time-series-supervised-learning-problem-python/
    """
    n_vars = 1 if type(data) is list else data.shape[1]
    df = pd.DataFrame(data)
    cols, names = list(), list()
    # input sequence (t-n, ... t-1)
    for i in range(n_in, 0, -1):
        cols.append(df.shift(i))
        names += [('var%d(t-%d)' % (j+1, i)) for j in range(n_vars)]
    # forecast sequence (t, t+1, ... t+n)
    for i in range(0, n_out):
        cols.append(df.shift(-i))
        if i == 0:
            names += [('var%d(t)' % (j+1)) for j in range(n_vars)]
        else:
            names += [('var%d(t+%d)' % (j+1, i)) for j in range(n_vars)]
    # put it all together
    agg = pd.concat(cols, axis=1)
    agg.columns = names
    # drop rows with NaN values
    if dropnan:
        agg.dropna(inplace=True)
    return agg


def cleanup_supervised_data(supervised_data):
    """
    drop columns we don't want to predict
    only keep pm2.5(t)
    """
    supervised_data.drop(
        supervised_data.columns[[9, 10, 11, 12, 13, 14, 15]], axis=1, inplace=True)


def split_train_test_datas(datasets, threshold):
    """
    split datasets into train and test sub datasets
    threshold is the train hours 
    """
    train = datasets.values[:threshold, :]
    test = datasets.values[threshold:, :]
    train_X, train_y = train[:, :-1], train[:, -1]
    test_X, test_y = test[:, :-1], test[:, -1]

    # reshape input to be 3D [samples, timesteps, features]
    train_X = train_X.reshape((train_X.shape[0], 1, train_X.shape[1]))
    test_X = test_X.reshape((test_X.shape[0], 1, test_X.shape[1]))
    print(train_X.shape, train_y.shape, test_X.shape, test_y.shape)
    return train_X, train_y, test_X, test_y


def machine_learning(train_X, train_y, test_X, test_y):
    """
    fit an LSTM on the multivariate input data
    """
    # in production we need set neurons bigger than 50
    neurons = 5
    seqModel = Sequential()
    seqModel.add(LSTM(neurons, input_shape=(
        train_X.shape[1], train_X.shape[2])))
    seqModel.add(Dense(1))
    seqModel.compile(loss='mae', optimizer='adam')
    history = seqModel.fit(train_X, train_y, epochs=neurons, batch_size=72,
                           validation_data=(test_X, test_y), verbose=2, shuffle=False)
    return history


def history_plot(result):
    """

    """
    pyplot.figure(figsize=(10, 10))
    pyplot.plot(result.history['loss'], label='train')
    pyplot.plot(result.history['val_loss'], label='test')
    pyplot.legend()
    pyplot.show()


def evaluateModel():
    """
    """
    print("todo: Evaluate Model")


def main():
    pm25_time_series = time_series_pre_process('Beijing.csv')
    time_series_quick_view(pm25_time_series)
    encode_normalize_data = col_label_encode_and_normalize(pm25_time_series, 4)
    supervised_data = series_to_supervised(encode_normalize_data, 1, 1)
    cleanup_supervised_data(supervised_data)
    train_X, train_y, test_X, test_y = split_train_test_datas(
        supervised_data, 365*24)
    result = machine_learning(train_X, train_y, test_X, test_y)
    history_plot(result)
    evaluateModel()


if __name__ == "__main__":
    main()
