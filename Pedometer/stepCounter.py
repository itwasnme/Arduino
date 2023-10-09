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

# max_value = 0
# min_value = 1000
# counter = 0

# for i in range(len(Time)):
#     if AbsAcceleration[i] > max_value:
#         max_value = AbsAcceleration[i]
#     elif AbsAcceleration[i] < min_value:
#         min_value = AbsAcceleration[i]
#     counter += 1
#     if counter == 50:
#         # print(str(max_value) + " " + str(min_value))
#         if max_value-min_value >= 4:
#             steps += 1
#         counter = 0
#         max_value = 0
#         min_value = 1000

# if counter != 0: #accounts for last time frame which might not be 1 sec
#     if max_value-min_value >= 4:
#         # print(str(max_value) + " " + str(min_value))
#         steps += 1

# print(steps)