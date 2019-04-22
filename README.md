# SPS_25Al

**** plotter.c ****
 Plot some SPS histograms, to check differences between beam on and beam off runs, for each degrader setting.                    

 Run on histogram files that have been hadded together. Execute using ROOT, using root -q plotter.c

**** stripmaker.c ****
Silly script to project the 2D energy vs ring/wedge into separate histograms, in order to check the calibration. 
The input and output files are hardcoded in for now. 

Run on unpacked data, using root -q stripmaker.c

**** sort_al25_offline.cxx ****
This is a copy of the other versions of this code, but without the trees. I found that my version with trees
had a lot of memory leak issues, so I'm reverting back to the old "version 7", but now copied to this directory
for better version control. It needs to run with hupsort, and I don't think I can or should change that. 

Run on raw data, using:
ssetep hupsort-1.x
hupsort -f sort_al25_offline.cxx path/to/Run000xx
                       
