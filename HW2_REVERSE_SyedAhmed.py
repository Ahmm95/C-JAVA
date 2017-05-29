def reverse(x):
    g = len(x)
    y = 'Programming is pretty fun sometimes.'
    while g > 0:
        g -= 1
        y += x[g]
    return y

print reverse('Programming is pretty fun sometimes.')
