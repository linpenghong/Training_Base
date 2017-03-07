import matplotlib.pyplot as plt

from scipy.io import netcdf_file

ncf = netcdf_file('KTLX_20100510_22Z.nc')

data = ncf.variables['Reflectivity']
lats = ncf.variables['lat']
lons = ncf.variables['lon']

i = 0

cmap = plt.get_cmap('gist_ncar')
cmap.set_under('lightgrey')

fig, ax = plt.subplots(1, 1)

# display an image
im = ax.imshow(data[i], \
               origin = 'lower', \
               extent = (lons[0], \
                         lons[-1], \
                         lats[0], \
                         lats[-1]), \
               vmin = 0.1, \
               vmax = 80, \
               cmap = 'gist_ncar')

cb = fig.colorbar(im) # add a colorbar to this figure

cb.set_label('Reflectivity (dBZ)') # add a label to this colorbar

ax.set_xlabel('Longitude') # add x label for the axes
ax.set_ylabel('Latitude') # add y label for the axes

plt.show()
