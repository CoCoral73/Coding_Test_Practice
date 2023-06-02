import sys
def ccw():
    global x1, y1, x2, y2
    global x3, y3, x4, y4

    v1 = x1*y3+x3*y2+x2*y1 - (x3*y1+x2*y3+x1*y2)
    v2 = x1*y4+x4*y2+x2*y1 - (x4*y1+x2*y4+x1*y2)
    v3 = x3*y1+x1*y4+x4*y3 - (x1*y3+x4*y1+x3*y4)
    v4 = x3*y2+x2*y4+x4*y3 - (x2*y3+x4*y2+x3*y4)
    if v1*v2 <= 0 and v3*v4 <= 0:
        if v1 == v2 == 0:
            if x2 - x1 == 0:
                if min(y1, y2) <= y3 <= max(y1, y2) or min(y1, y2) <= y4 <= max(y1, y2):
                    if max(y1, y2) == min(y3, y4):
                        return (2, x1, max(y1, y2))
                    elif min(y1, y2) == max(y3, y4):
                        return (2, x1, min(y1, y2))
                    return (1, 0, 0)
                elif min(y3, y4) <= y1 <= max(y3, y4) or min(y3, y4) <= y2 <= max(y3, y4):
                    if max(y1, y2) == min(y3, y4):
                        return (2, x1, max(y1, y2))
                    elif min(y1, y2) == max(y3, y4):
                        return (2, x1, min(y1, y2))
                    return (1, 0, 0)
                else:
                    return (0, 0, 0)
            if min(x1, x2) <= x3 <= max(x1, x2) or min(x1, x2) <= x4 <= max(x1, x2):
                if max(x1, x2) == min(x3, x4):
                    if x1 < x2:
                        return (2, x2, y2)
                    else:
                        return (2, x1, y1)
                elif min(x1, x2) == max(x3, x4):
                    if x1 < x2:
                        return (2, x1, y1)
                    else:
                        return (2, x2, y2)
                return (1, 0, 0)
            elif min(x3, x4) <= x1 <= max(x3, x4) or min(x3, x4) <= x2 <= max(x3, x4):
                if max(x1, x2) == min(x3, x4):
                    if x1 < x2:
                        return (2, x2, y2)
                    else:
                        return (2, x1, y1)
                elif min(x1, x2) == max(x3, x4):
                    if x1 < x2:
                        return (2, x1, y1)
                    else:
                        return (2, x2, y2)
                return (1, 0, 0)
            else:
                return (0, 0, 0)
        if x2 - x1 == 0:
            a = (y4-y3)/(x4-x3)
            x = x1
            y = a*(x-x3)+y3
        elif x4 - x3 == 0:
            a = (y2-y1)/(x2-x1)
            x = x3
            y = a*(x-x1)+y1
        else:
            a1 = (y2-y1)/(x2-x1)
            a2 = (y4-y3)/(x4-x3)
            x = (a1*x1-a2*x3-y1+y3)/(a1-a2)
            y = a1*(x-x1)+y1
        return (2, x, y)
    return (0, 0, 0)

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x3, y3, x4, y4 = map(int, sys.stdin.readline().split())
rst = ccw()
if rst[0] <= 1:
    print(rst[0])
else:
    print(1)
    print(rst[1], rst[2])