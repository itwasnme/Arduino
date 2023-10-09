from pandas import DataFrame, read_csv
import pandas as pd

steps = 0
df = pd.read_excel("Nicholas30steps.xls")
YAcceleration = df['Linear Acceleration y (m/s^2)'].tolist()
AbsAcceleration = df['Absolute acceleration (m/s^2)'].tolist()
Time = df['Time (s)'].tolist()

ascending = False;
for i in range(len(YAcceleration)):
    if YAcceleration[i] < 0 and not ascending: #we want to start counting when we are in the negatives 
        ascending = True; #we should technically start to rise 
    elif YAcceleration[i] > 0 and YAcceleration[i] > YAcceleration[i-1] and ascending: #we should be rising
        if YAcceleration[i] > 0.7: #if the data reaches the threshold of 0.7 increase a step and we should start to descend back to negative
            steps += 1
            ascending = False;  
print(steps)