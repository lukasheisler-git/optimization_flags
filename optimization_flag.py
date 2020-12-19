#!/usr/bin/env python
# coding: utf-8

# In[1]:


import matplotlib
import numpy as np
import matplotlib.pyplot as plt

O0 = [49.3, 49.6, 52.02, 52.6, 55.8, 51.2, 50,1,51.4]
O1 = [20.0, 18.0, 17.7, 17.8, 18.4, 17.8, 17.8, 17.7]
O2 = [19.2, 18.5, 18.5, 18.6, 18.6, 18.6, 18.5, 18.9]
O3 = [18.3, 18.5, 18.2, 18.4, 18.2, 18.3, 18.2, 18.2]
Ofast = [18.2, 18.3, 18.3, 18.0, 19.2, 18.0, 18.0, 18.3]
Og = [18.6, 18.6, 18.6, 18.6, 18.6, 18.8, 22.8, 18.9]

flags = [O0, O1, O2, O3,Ofast, Og]
flaglist = ["O0", "O1", "O2", "O3","Ofast", "Og"]
time_averages = []

def computeAverage(liste):
    sum_time = 0
    for time in liste:
        sum_time += time
    average = sum_time/(len(liste))
    return round(average,2)

for i in flags:
    time_averages.append(computeAverage(i))
    
    
#print(time_averages)

import matplotlib
import matplotlib.pyplot as plt
import numpy as np


x = np.arange(len(flaglist))  # the label locations
width = 0.35  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x, time_averages,width)

ax.set_ylabel('Average computation time (s)')
ax.set_xlabel('Flags')
ax.set_title('Average computation time of different flags')
ax.set_xticks(x)
ax.set_xticklabels(flaglist)
#ax.legend()


def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')


autolabel(rects1)

fig.tight_layout()
plt.savefig('optimization_flags')



plt.show()



# In[ ]:





# In[ ]:





# In[ ]:




