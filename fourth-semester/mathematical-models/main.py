import matplotlib.pyplot as plt

from numpy import arange
from functions import *

p1 = 1
p3 = 20
p4 = [6, 8, 10, 12]
p6 = 0

x2 = list(arange(1, 10.1, 0.1).round(1))

values_6 = get_values(x2, p1, p3, p4[0], p6)
values_8 = get_values(x2, p1, p3, p4[1], p6)
values_10 = get_values(x2, p1, p3, p4[2], p6)
values_12 = get_values(x2, p1, p3, p4[3], p6)

print_values(values_6, p4[0])
print_values(values_8, p4[1])
print_values(values_10, p4[2])
print_values(values_12, p4[3])

plt.plot(values_6['p2'], values_6['p5'], color='green',
         label='p4 = 6', marker='.')
plt.plot(values_8['p2'], values_8['p5'], color='red',
         label='p4 = 8', marker='.')
plt.plot(values_10['p2'], values_10['p5'], color='orange',
         label='p4 = 10', marker='.')
plt.plot(values_12['p2'], values_12['p5'], color='blue',
         label='p4 = 12', marker='.')
plt.xlabel('p2')
plt.ylabel('p5')
plt.legend()
plt.show()

check_stat_points(values_6, p1, p3, p4[0], p6)
check_stat_points(values_8, p1, p3, p4[1], p6)
check_stat_points(values_10, p1, p3, p4[2], p6)
check_stat_points(values_12, p1, p3, p4[3], p6)

check_bifurcation_points(values_6, p1, p3, p4[0])
check_bifurcation_points(values_8, p1, p3, p4[1])
check_bifurcation_points(values_10, p1, p3, p4[2])
check_bifurcation_points(values_12, p1, p3, p4[3])

check_turning_points(values_6, p1, p3, p4[0], p6)
check_turning_points(values_8, p1, p3, p4[1], p6)
check_turning_points(values_10, p1, p3, p4[2], p6)
check_turning_points(values_12, p1, p3, p4[3], p6)
