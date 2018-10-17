import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.linear_model import LinearRegression

carseats = pd.read_csv("Carseats.csv", index_col=0)
carseats.head()
carseats.shape

carseats["isUS"] = carseats.US.map({"Yes": 1, "No": 0})

feature_cols = ["CompPrice", "Price", "isUS"]
X = carseats[feature_cols]
y = carseats["Sales"]

lm = LinearRegression()
lm.fit(X, y)

sales_min = lm.predict([[50, 120, 1]])
sales_max = lm.predict([[200, 120, 1]])

print("Sales Min: {0}, Max: {1}".format(sales_min, sales_max))

fig, axs = plt.subplots()

sales = []

compPriceRange = range(50, 200)

for price in compPriceRange:
    sales.append(lm.predict([[price, 120, 1]])[0])

# print(sales)

plt.plot(compPriceRange, sales)
