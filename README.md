# simple_Batch_Testing

`./produceOutputs suite.txt ./sampleCPP`

`./runSuite suite.txt ./sampleCPP`

The argument suite is a ﬁle containing a list of ﬁlename stems (test1.in, test1.args, etc.), and the ./sampleCPP is the program to be run. 

Note that stems will not contain spaces.

## The produceOutputs script runs program on each test in the test suite and, for each test, creates a ﬁle that contains the output produced for that test. 

For example, suppose our suite.txt contains the following entries:

"test1 test2 reallyBigTest"

Then our test suite consists of three tests. The ﬁrst one (test1) will use the ﬁle test1.in and test1.args.  The last one (reallyBigTest) will use the ﬁle reallyBigTest.in and reallyBigTest.args. 

## For runSuite, we make .out files the expected outcome, then it compare the actual output when run the program with .in and .args with exprected given output (i.e. test1.outm reallyBigTest.out), if they are not the same, it prints:

Test failed:

test1 Args: 

(contents of test1.args, if it exists) 

Expected: 

(contents of test1.out) 

Actual: 

(contents of the actual program output)

## example also provided

./produceOutput suite ./sample

(produces .out files)

./runSuite suite ./sample

(as we run on the same program, all output are the same, print nothing, you can try to modify .out file first then run ./runSuite to see the case that a test fail)

