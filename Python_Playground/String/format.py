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

# Accesing Arguments by Name Directly using Basic API

coord = {'latitude' : '37.24N', 'longitude' : '-115.81W'}
print 'Coordinates: {latitude}, {longitude}'.format(**coord)

## Accessing Arguments' Attributes

class Point(object):
    def __init__(self, x, y):
        self.x, self.y = x, y

    def __str__(self):
        return 'Point({self.x}, {self.y})'.format(self = self)

print str(Point(4, 2))

## Accessing Arguments' Items:

coord = (3, 5)
print 'X: {0[0]}; Y: {0[1]}'.format(coord)

## : -> filling character
## < -> left align
## > -> right align
## * -> centre

## Left Align
print '{:<30}'.format('left aligned')

## Right Align
print '{:>30}'.format('right aligned')

## Centre
print '{:^30}'.format('centre')

## Centre and Use * as Filling Character
print '{:*^30}'.format('centre')

## +/-, Specify a Sign
print '{:+f}, {:+f}'.format(3.14, -3.14) # always show
print '{: f}, {: f}'.format(3.14, -3.14) # if positive, leave a space
print '{:-f}, {:-f}'.format(3.14, -3.14) # only show negative sign

## Using the Comma as a Thousands Separator

print '{:,}'.format(123456890)

## Expressing a Percentage

points = 19.5
total = 22
print 'Correct answers: {:.2%}'.format(points/total)

## Type-Specific Formatting (Datetime)

import datetime

d = datetime.datetime(2010, 7, 4, 12, 15, 58)
print '{:%Y-%m-%d %H:%M:%S}'.format(d)

## Complex Example 1

for align, text in zip('<^>', ['left', 'center', 'right']):
    print '{0:{fill}{align}16}'.format(text, \
                                       fill = align, \
                                       align = align)

## Complex Example 2

width = 5
for num in range(5, 12):
    for base in 'dXob':
        print '{0:{width}{base}}'.format(num, base = base, width = width),
    print
