import numpy as np
from matplotlib import pyplot as plt
import pandas as pd

# y = np.array([1,3,2, 5, 2, 3, 1])
# curve, = plt.plot(y, c='red', lw=5)

# print("Extracting data from plot........")
# xdata = curve.get_xdata()
# ydata = curve.get_ydata()

# plt.show()

cse = pd.DataFrame({
    "Name":["Kin", "sam","Tim", "Top", "John", "kate"],
    "Marks":[60,70,95,55,85, 80]
})

columns = ["Name", "Marks"]
df = pd.read_csv("cse.csv")