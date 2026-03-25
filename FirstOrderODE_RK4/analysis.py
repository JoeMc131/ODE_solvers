import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = pd.read_csv('solution.csv')

print(data.columns)

plt.figure()
plt.plot(data.x, data.y, 'k-')
plt.xlabel('x')
plt.ylabel('y')
plt.show()