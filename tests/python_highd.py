# vim: fdm=indent
'''
author:     Fabio Zanini
date:       22/08/12
content:    Test script for the python bindings (haploid_highd)
'''

# Import module
import sys
sys.path.append('../pkg/python')
import numpy as np
import matplotlib.pyplot as plt
import FFPopSim as h



# Globals
L = 1000    # number of loci
N = 3000    # population size


# Construct class
pop = h.haploid_highd(L)

# Test fitness landscapes
rep = np.zeros(L)
rep[np.random.random(L) > 0.5] = -0.1
pop.set_additive_trait(rep)

# Show the additive part of the fitness landscape
print pop.get_additive_trait()

# Test population initialization
pop.set_allele_frequencies([0.3] * L, N)
pop.mutation_rate = 1e-5
pop.outcrossing_rate = 1e-2
pop.crossover_rate = 1e-3

# Test allele frequency readout
print np.max(pop.get_allele_frequency(4))

# Test evolution
from time import time as ti
t0 = ti()
pop.evolve(30)
t1 = ti()
print 'Time for evolving population for 30 generations: {:1.1f} s'.format(t1-t0)

## Write genotypes
#pop.write_genotypes('test.txt', 100)
#pop.write_genotypes_compressed('test.npz', 100)

# Plot histograms
plt.ion()
pop.plot_fitness_histogram()
pop.plot_divergence_histogram(color='r')
pop.plot_diversity_histogram(color='g')
