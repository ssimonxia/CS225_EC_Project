 Feedback for weekly logs from TAs

## Log from Nov 11 2023
Regarding your correctness, I believe that to prove correctness by showing that the number of loop iterations you make in the main KMP loop should be proportional to the length of the string(In which we are looking for the pattern). You could also additionally check that the number of iterations while creating the LPS is directly proportional  to the length of the pattern. 
Doing these would ensure that your algorithm is running in linear time overall.
