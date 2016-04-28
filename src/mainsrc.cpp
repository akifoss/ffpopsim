
/* Include directives */
#include "ffpopsim_highd.h"
#include "multi_population.h"
#include <cstring>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cmath>
#include <boost/foreach.hpp>
//#include <boost/filesystem.hpp>
#define HIGHD_BADARG -1354341
#define NOTHING 1e-10

/* Be verbose? */
#define HIGHD_VERBOSE 0


//#define MUTATION_RATE 1e-5
//#define MIGRATION_RATE 0
#define NUMBER_OF_TAITS 2
#define _L 100
#define GENERATIONS_Eq  150000
#define SHIFT_BEGIN 20000
#define SHIFT_END 90000
//#define SELECTIVE 1
//#define SHIFT_RATE 5000
#define GENERATIONS  10000
#define Av_Num 0
//#define SAMPLE_SIZE 1500


int main(int argc, char  *argv[]){
//        // ############################################
//        //
//        // Read the input parameters of the simulation
//        //
//        // ############################################
//        int SELECTIVE = atof(argv[1]); //MIGRATION_RATE = atof(argv[1]);
//        double POPULATION_SIZE = atoi(argv[2]);
//        const char * fileDir =  argv[3];
//        int locations = atoi(argv[4]);
//        double MUTATION_RATE = atof(argv[5]);
//        double MIGRATION_RATE = atof(argv[6]);
//        // int _L = atoi(argv[5]);

//        // ############################################

//        // ############################################
//        //
//        // Initialize the essential parameters for the simulation and load the population
//        //
//        // ############################################

//        int N = 20, N_pop = POPULATION_SIZE;
          multi_population pop(2, 100, 1, 1);
          //pop.set_migration_rate(0.1);

//        pop.set_crossover_rate(0.0);
//        pop.set_outcrossing_rate(0.0);
//        pop.set_recombination_model(0);

          vector <int> gen_loci;
          gen_loci.push_back(6);
          //pop.track_locus_genealogy(gen_loci);


          pop.set_random_genotype(2000);
          vector <int> cc;
          cc.push_back(1000);
          cc.push_back(1000);
          pop.set_carrying_capacities(cc);

          pop.set_critical_migration_rate(0.6);

          vector <double> m_r_row;
          for (int i = 0; i < pop.get_number_of_locations(); i ++){
              m_r_row.push_back(0.01);
          }

          vector < vector <double > > m_r;

          for (int i = 0; i < pop.get_number_of_locations(); i ++){
              m_r.push_back(m_r_row);
          }

          pop.set_migration_rates(m_r);




        for (int i = 0; i < 1000; i ++)
        {
            if (i % 1 == 0) cout << "generation: " << pop.get_generation() << "   " << pop.N() << "    "<<pop.point_sub_pop(0)->N()<<  endl;
            pop.evolve();
        }
return 0;
}
