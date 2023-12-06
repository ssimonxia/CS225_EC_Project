# CS225_EC_Project A* Search Algorithm
# Folder
    src: contains the main function of the A* Search Algorithm 
    test: contains the test cases file
    entry: contains a main function, which can be used to print and test algorithm or run the code. Also, we         used the main function to print out the runtime of the algorithm for different sizes of data.
    data: contains the test data we used
    code: contains the code used to generate the random test cases
    Document: contains development log, feedback, and proposal
    The final report and final presentation can be directly seen outsides.

# Running Instructions
    You can open this folder using docker we used in the class. After that, you can run
    # mkdir build
    # cd build
    # cmake ..
    which is exactly the same as what we do in the class.
    Then, you can run the test case by
    # make test
    # ./test
    This will take a while since the extremely large dataset takes time to run, especially for BFS.
    
    If you want, you can also run the main function by 
    # make main
    # ./main

    
    
