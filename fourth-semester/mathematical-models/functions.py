from math import sqrt
from math import exp
from builtins import round


def solve(a, b, c):
    d = b ** 2 - 4 * a * c
    value1 = (-b - sqrt(d)) / (2 * a)
    value2 = (-b + sqrt(d)) / (2 * a)
    return [value1, value2]


def get_values(x2: list, p1, p3, p4, p6):
    x1_list = []
    x2_list = []
    p2_list = []
    p5_list = []
    for x2_ in x2:
        a = float((x2_ - p6) ** 2)
        b = float(2 * p1 * x2_ * (x2_ - p6) -
                  p1 * p4 * (x2_ - p6 - (1 + x2_ / p3) ** 2))
        c = float((p1 ** 2) * (x2_ ** 2) - (p1 ** 2) * p4 * x2_ +
                  (p1 ** 2) * p4 * (1 + x2_ / p3) ** 2)

        values_from_solve = solve(a, b, c)
        if values_from_solve[0] > 0 or values_from_solve[1] > 0:
            if values_from_solve[0] < 0:
                p5 = values_from_solve[1]
            else:
                p5 = values_from_solve[0]

            x1 = (p1 * x2_ + p5 * (x2_ - p6)) / (p1 * p4)
            p2 = (p1 * x1) / ((1 - x1) * exp(x2_ / (1 + x2_ / p3)))

            x1_list.append(x1)
            x2_list.append(x2_)
            p2_list.append(p2)
            p5_list.append(p5)

    return {"x1": x1_list, "x2": x2_list, "p2": p2_list, "p5": p5_list}


def print_values(values: dict, p4):
    print("p4 = " + str(p4) + "\n" +
          "x1\tx2\tp2\tp5")
    for i in range(0, len(values["x1"])):
        print(str(round(values["x1"][i], 3)) + "\t" +
              str(round(values["x2"][i], 3)) + "\t" +
              str(round(values["p2"][i], 3)) + "\t" +
              str(round(values["p5"][i], 3)))


def check_stat_points(values: dict, p1, p3, p4, p6):
    eps_ = 1.0E-10

    for i in range(0, len(values['x1'])):
        x1 = values['x1'][i]
        x2 = values['x2'][i]
        p2 = values['p2'][i]
        p5 = values['p5'][i]

        exp_val = exp(x2 / (1 + x2 / p3))

        value1 = -p1 * x1 + p2 * (1 - x1) * exp_val
        value2 = -p1 * x2 + p2 * p4 * (1 - x1) * exp_val - p5 * (x2 - p6)

        if abs(value1) > eps_ or abs(value2) > eps_:
            print('FALSE')


def check_bifurcation_points(values: dict, p1, p3, p4):
    eps_ = 1.0E-10

    for i in range(0, len(values['x1'])):
        x1 = values['x1'][i]
        x2 = values['x2'][i]
        p5 = values['p5'][i]

        a = -p1 - (p1 * x1) / (1 - x1)
        b = (p1 * x1) / ((1 + x2 / p3) ** 2)
        c = - (p1 * p4 * x1) / (1 - x1)
        d = (p1 * p4 * x1) / ((1 + x2 / p3) ** 2) - p1 - p5

        det = a * d - b * c

        if abs(det) > eps_:
            print('FALSE')


def check_turning_points(values: dict, p1, p3, p4, p6):
    eps_ = 1.0E-10

    for i in range(0, len(values['x1'])):
        x1 = values['x1'][i]
        x2 = values['x2'][i]

        a = -p1 - (p1 * x1) / (1 - x1)
        c = - (p1 * p4 * x1) / (1 - x1)

        b1 = (1 - x1) * exp((p3 * x2) / (p3 + x2))
        d1 = p4 * (1 - x1) * exp((p3 * x2) / (p3 + x2))

        b2 = 0
        d2 = p6 - x2

        det1 = a * d1 - b1 * c
        det2 = a * d2 - b2 * c

        if abs(det1) < eps_ or abs(det2) < eps_:
            print('FALSE')
