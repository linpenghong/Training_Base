import sqlite3

lines = open("main.star", "r").readlines()
# print lines

print "There is ", len(lines), " particles in total."

voltage = [float(line.strip().split()[0]) for line in lines]
# print voltage

defocusU = [float(line.strip().split()[1]) for line in lines]
# print defocusU

defocusV = [float(line.strip().split()[2]) for line in lines]
# print defocusU

defocusTheta = [float(line.strip().split()[3]) for line in lines]
# print defocusTheta

imageName = [line.strip().split()[9] for line in lines]
# print imageName

micrographName = [line.strip().split()[13] for line in lines]
# print micrographName
