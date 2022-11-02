/**
 * @brief  Simulate a normal distribution, based on random coin flips.
 *         Basically some c++ code that will print a bell curve, using
 *         pseudo-random numbers...
 *
 * @author Ryan Antkowiak 
 *
 */
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

/**
 * @class  NormalDistributionSimulation
 *
 * @brief  Simulate a normal distribution of trials, keeping track of the number of
 *         positive occurrances per trial out of a possible number of occurrences.
 *         Each occurrence has a 50% chance (hence, rand()%2==0) of being a positive
 *         result.
 *
 *         This can be thought of running "numTrials" of a simulation where --
 *         in each "simulation", a fair coin is flipped "occurrencesPerTrial"
 *         number of times.  The number of times of a "positive result" (e.g.
 *         if the coin lands on "heads") is tallied up in the map member
 *         variable "mapNumPositiveOccurrencesToFrequency", where the frequency
 *         will be incremented by one, every time an entire trial ends up with
 *         that number of positive (heads) results.
 *
 *         This class provides a print() method that will print out the normal
 *         distribution, divided by a scale factor, in order to be able to
 *         visually display it in a terminal window.  A fixed-width font is
 *         recommended for viewing the output.
 *
 * @author Ryan Antkowiak 
 *
 */
class NormalDistributionSimulation
{
public:
    // Constructor
    // int opt - The number of times to "flip the coin" per trial
    // int nt - The number of trials to run (e.g. the number if times you will
    //          run a trial where you will flip the coin "opt" times.)
    NormalDistributionSimulation(int opt, int nt) : occurrencesPerTrial(opt), numTrials(nt)
    {
        // Start out with a clear map of all zero entries.
        for (int trial = 0 ; trial < numTrials ; ++trial)
            mapNumPositiveOccurrencesToFrequency[trial] = 0;

        // Run the simulation "numTrials" times
        for (int trial = 0 ; trial < numTrials ; ++trial)
        {
            // The initial number of positive occurrences (e.g. "heads") is
            // zero
            int numPositiveOccurrences = 0;

            // Flip the coin "occurrencesPerTrial" times, looking for heads
            for (int j = 0 ; j < occurrencesPerTrial ; ++j)
            {
                // If the coin is heads, increment the number of positive
                // occurrences found
                if (rand() % 2 == 0)
                    ++numPositiveOccurrences;
            }

            // Increment the times the simulation has encountered this many
            // times of a positive frequency of "heads"
            mapNumPositiveOccurrencesToFrequency[numPositiveOccurrences]++;
        }
    }

    // Print the results of the simulation
    // double scale - A scale factor that can be used to reduce the length of
    // screen output, so the results can be interpreted visually
    void print(double scale = 1.0)
    {
        // Iterate through the map of number of possible occurrences per trial
        for (int i = 0 ; i <= occurrencesPerTrial ; ++i)
        {
            std::cout << i << "\t";

            // Print a line to visually represent the number of positive
            // occurrences with this result (taking the scale into account)
            for (double j = 0.0 ; j < mapNumPositiveOccurrencesToFrequency[i] ; j = j + (1.0 * scale))
                std::cout << "*";

            std::cout << "\n";
        }
    }

private:
    // The number of times to "flip the coin" per trial
    int occurrencesPerTrial;

    // The number of trials to run (e.g. sequences of coin filps)
    int numTrials;

    // Map to keep track of the number of times a certain number of positive
    // flips (heads) has occurred during each trial
    std::map<int, int> mapNumPositiveOccurrencesToFrequency;
};

int main(int argc, char * argv[])
{
    // Seed randomizer with current time
    srand(time(NULL));

    // Simulate a normal distribution of 1000000 trials, with 50 occurrences
    // per trial.
    NormalDistributionSimulation nds(50, 1000000);

    // Print the result of the distribution (divided by 2000 as a scale factor)
    nds.print(2000.0);

    return 0;
}
