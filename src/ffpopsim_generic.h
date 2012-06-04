/**
 * @file popgen.h
 * @brief Header file with the classes and types provided with the library. 
 * @author Richard Neher, Boris Shraiman, Fabio Zanini
 * @version 
 * @date 2010-10-27
 */
#ifndef FFPOPGEN_GENERIC_H_
#define FFPOPGEN_GENERIC_H_

#include <time.h>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_eigen.h>
#include <boost/dynamic_bitset.hpp>

#define MIN(a,b) (a<b)?a:b
#define MAX(a,b) (a>b)?a:b
#define RNG gsl_rng_taus		//choose the random number generator algorithm, see http://www.gnu.org/software/gsl/manual/html_node/Random-number-generator-algorithms.html

using namespace std;

/**
 * @brief Pairs of an index and a value
 */
struct index_value_pair_t {
	int index;
	double val;
	index_value_pair_t(int index_in=0, double val_in=0) : index(index_in), val(val_in) {};
};

/**
 * @brief Pairs of a genotype and a value
 */
struct genotype_value_pair_t {
	boost::dynamic_bitset<> genotype;
	double val;
	genotype_value_pair_t(boost::dynamic_bitset<> genotype_in=boost::dynamic_bitset<>(0), double val_in=0) : genotype(genotype_in), val(val_in) {};
};

/**
 * @brief Structure for short summary statistics.
 */
struct stat_t {
	double mean;
	double variance;
	stat_t(double mean_in=0, double variance_in=0) : mean(mean_in), variance(variance_in) {};
};

#define SAMPLE_ERROR -12312154

/**
 * @brief Sample of any scalar property.
 * 
 * This class is used to store samples of scalar quantities used in the evolution of the population,
 * for instance fitness or allele frequencies. I enables simple manipulations (mean, variance, etc.).
 */
class sample {
public:
	int number_of_values;
	double *values;
	double mean;
	double variance;

	int bins;
	bool mem_dis;
	bool mem_values;
	gsl_histogram *distribution;

	bool with_range;
	double range_min;
	double range_max;

	sample();
	virtual ~sample();
	int set_up(int n);
	int set_distribution(int bins=100);
	void set_range(double min, double max) {range_min=min; range_max=max; with_range=true;}
	int calc_mean();
	int calc_variance();
	int calc_distribution();
	int print_distribution(ostream &out);
};

#endif /* FFPOPGEN_GENERIC_H_ */
