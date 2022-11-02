# NormalDistributionSimulation
Simulate a normal distribution, and print the results


 @class  NormalDistributionSimulation

 @brief  Simulate a normal distribution trials, keeping track of the number of
         positive occurrances per trial out of a possible number of occurrences.
         Each occurrence has a 50% chance (hence, rand()%2==0) of being a positive
         result.

         This can be thought of running "numTrials" of a simulation where --
         in each "simulation", a fair coin is flipped "occurrencesPerTrial"
         number of times.  The number of times of a "positive result" (e.g.
         if the coin lands on "heads") is tallied up in the map member
         variable "mapNumPositiveOccurrencesToFrequency", where the frequency
         will be incremented by one, every time an entire trial ends up with
         that number of positive (heads) results.

         This class provides a print() method that will print out the normal
         distribution, divided by a scale factor, in order to be able to
         visually display it in a terminal window.  A fixed-width font is
         recommended for viewing the output.

 @author Ryan Antkowiak 

Copyright 2016 Ryan Antkowiak 
