print '{0}, {1}'.format('kzc', 18)
print '{}, {}'.format('kzc', 18)
print '{1}, {0}, {1}'.format('kzc', 18)
print '{name}, {age}'.format(age = 18, name = 'kzc')

# ':' : filling character
# '^' : middle alignment
# '<' : left alignment
# '>' : right alignment
print '{:>8}'.format('189')
print '{:0>8}'.format('189')

# .2f : two decimal number float
print '{:.2f}'.format(321.33345)

print '{2}, {1}, {0}'.format(*'abc')
print '{0}{1}{0}'.format('abra', 'cad')


# Accessing Arguments by Name

print 'Coordinates: {latitude}, {longitude}'.format(latitude = '37.24N', \
                                                    longitude = '-115.81W')
