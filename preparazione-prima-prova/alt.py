def al(x):
    a = [True, False] * len(x)
    return [y[0] for y in zip(x, a) if y[1]]


print("".join(al("tanto va la gatta etc")))
print("".join(al(str(123456789))))
