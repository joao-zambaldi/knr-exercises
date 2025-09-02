#pragma once

/*
 * hhist - Prints an horizontal histogram with each bar of the histogram
 * having label labels[i] and representing the value values[i]. We print
 * counts bars. 
 *
 * OBS:
 * 	labels ara expected to have size <= 10
 * 	the terminal width term_w should be > 30
 *
 *
 * 
 *  Exmaple of horizontal histogram
 *  
 *  blue    [#####                 ] 4 
 *  red     [############          ] 11
 *  green   [################      ] 15
 *  yellow  [######                ] 5
 *
 */
void hhist(char** labes, double* values, int count, int term_w);

