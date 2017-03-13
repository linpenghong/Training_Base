CC = g++
CFLAGS = -lgsl

all : gsl_stats_sd \
	  gsl_cdf_gaussian

gsl_stats_sd : gsl_stats_sd.cpp
	${CC} ${CFLAGS} -o $@ $^

gsl_cdf_gaussian : gsl_cdf_gaussian.cpp
	${CC} ${CFLAGS} -o $@ $^
