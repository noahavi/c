#!/bin/bash


# Sean Szumlanski
# COP 3223, Fall 2018

# =========================
# assignment05: test-all.sh
# =========================
# You can run this script at the command line like so:
#
#   bash test-all.sh
#
# For more details, see the assignment PDF.


################################################################################
# Shell check.
################################################################################

# Running this script with sh instead of bash can lead to false positives on the
# test cases. Yikes! These checks ensure the script is not being run through the
# Bourne shell (or any shell other than bash).

if [ "$BASH" != "/bin/bash" ]; then
  echo ""
  echo " Bloop! Please use bash to run this script, like so: bash test-all.sh"
  echo ""
  exit
fi

if [ -z "$BASH_VERSION" ]; then
  echo ""
  echo " Bloop! Please use bash to run this script, like so: bash test-all.sh"
  echo ""
  exit
fi


################################################################################
# Initialization.
################################################################################

PASS_CNT=0
NUM_TEST_CASES=10
TOTAL_TEST_CNT=30


################################################################################
# Magical incantations.
################################################################################

# Ensure that obnoxious glibc errors are piped to stderr.
export LIBC_FATAL_STDERR_=1

# Now redirect all local error messages to /dev/null (like "process aborted").
exec 2> /dev/null


################################################################################
# Check that all required files are present.
################################################################################

if [ ! -f assignment05.c ]; then
	echo ""
	echo " Error: You must place assignment05.c in this directory before we can"
	echo "        proceed. Aborting test script."
	echo ""
	exit
elif [ ! -f assignment05.h ]; then
	echo ""
	echo " Error: You must place assignment05.h in this directory before we can"
	echo "        proceed. Aborting test script."
	echo ""
	exit
elif [ ! -d sample_output ]; then
	echo ""
	echo " Error: You must place the sample_output folder in this directory"
	echo "        before we can proceed. Aborting test script."
	echo ""
	exit
fi

function check_test_case()
{
	local i=$1

	if [ ! -f testcase$i.c ]; then
		echo ""
		echo " Error: You must place testcase$i.c in this directory before we"
		echo "        can proceed. Aborting test script."
		echo ""
		exit
	fi

	if [ ! -f sample_output/output$i.txt ]; then
		echo ""
		echo " Error: You must place output$i.txt in the sample_output directory"
		echo "        before we can proceed. Aborting test script."
		echo ""
		exit
	fi
}

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	check_test_case "$i"a
	check_test_case "$i"b
	check_test_case "$i"c
done


egrep -s -q "^#include \"assignment05\.h\"" assignment05.c
egrep_val=$?

if [[ $egrep_val != 0 ]]; then
	echo ""
	echo "  Whoa, buddy! Your assignment05.c file does not appear to have a proper"
	echo "  #include statement for assignment05.h. Please read Section 1 of the"
	echo "  assignment PDF before proceeding."
	echo ""
	exit
fi


################################################################################
# Run test cases.
################################################################################

echo ""
echo "=================================================================="
echo "Running test cases..."
echo "=================================================================="
echo ""

run_test_case()
{
	local testcase_file=$1
	local output_file=$2

	echo -n "  [Test Case] $testcase_file ... "

	# Attempt to compile.
	gcc assignment05.c $testcase_file 2> /dev/null
	compile_val=$?

	# Check for compilation failure.
	if [[ $compile_val != 0 ]]; then
		echo "fail (failed to compile)"
		return
	fi

	# Run program. Capture return value to check whether it crashes.
	./a.out > myoutput.txt 2> /dev/null
	execution_val=$?
	if [[ $execution_val != 0 ]]; then
		echo "fail (program crashed)"
		return
	fi

	# Run diff and capture its return value.
	diff myoutput.txt sample_output/$output_file > /dev/null
	diff_val=$?
	
	# Output results based on diff's return value.
	if  [[ $diff_val != 0 ]]; then
		echo "fail (output mismatch)"
	else
		echo "PASS!"
		PASS_CNT=`expr $PASS_CNT + 1`
	fi
}

for i in `seq -f "%02g" 1 $NUM_TEST_CASES`;
do
	run_test_case testcase"$i"a.c output"$i"a.txt
	run_test_case testcase"$i"b.c output"$i"b.txt
	run_test_case testcase"$i"c.c output"$i"c.txt
done

echo ""
echo "  Total tests passed: $PASS_CNT/$TOTAL_TEST_CNT"


############################################################################
# Check for warnings.
############################################################################

echo ""
echo "=================================================================="
echo "Checking for compiler warnings..."
echo "=================================================================="
echo ""

gcc assignment05.c -c -o assignment05.o &>> ./err.log
compile_flag=$?

if [[ $compile_flag != 0 ]]; then
	echo "  Failed to compile. Type the following for details:"
	echo ""
	echo "     gcc assignment05.c -c"
else
	grep --silent "warning" err.log
	warnings_flag=$?

	if [[ $warnings_flag == 0 ]]; then
		echo "  Warnings detected. :( To see the warnings generated"
		echo "  by your code, try running the following command:"
		echo ""
		echo "     gcc -c assignment05.c"
	else
		echo "  No warnings detected. Hooray!"
	fi
fi


################################################################################
# Cleanup phase.
################################################################################

# Clean up the executable file.
rm -f a.out
rm -f myoutput.txt
rm -f assignment05.o
rm -f err.log


################################################################################
# Final thoughts.
################################################################################

echo ""
echo "=================================================================="
echo "Final Report"
echo "=================================================================="

if [ $PASS_CNT -eq $TOTAL_TEST_CNT ]; then
	echo ""
	echo "              ,)))))))),,,"
	echo "            ,(((((((((((((((,"
	echo "            )\\\`\\)))))))))))))),"
	echo "     *--===///\`_    \`\`\`((((((((("
	echo "           \\\\\\ b\\  \\    \`\`)))))))"
	echo "            ))\\    |     ((((((((               ,,,,"
	echo "           (   \\   |\`.    ))))))))       ____ ,)))))),"
	echo "                \\, /  )  ((((((((-.___.-\"    \`\"((((((("
	echo "                 \`\"  /    )))))))               \\\`)))))"
	echo "                    /    ((((\`\`                  \\((((("
	echo "              _____|      \`))         /          |)))))"
	echo "             /     \\                 |          / ((((("
	echo "            /  --.__)      /        _\\         /   )))))"
	echo "           /  /    /     /'\`\"~----~\`  \`.       \\   (((("
	echo "          /  /    /     /\`              \`-._    \`-. \`)))"
	echo "         /_ (    /    /\`                    \`-._   \\ (("
	echo "        /__|\`   /   /\`                        \`\\\`-. \\ ')"
	echo "               /  /\`                            \`\\ \\ \\"
	echo "              /  /                                \\ \\ \\"
	echo "             /_ (                                 /_()_("
	echo "            /__|\`                                /__/__|"
	echo ""
	echo "                             Legendary."
	echo ""
	echo "                10/10 would run this program again."
	echo ""
	echo "  CONGRATULATIONS! You appear to be passing all the test cases!"
	echo "  (Now, don't forget to create some extra test cases of your own."
	echo "  These test cases are not comprehensive.)"
	echo ""
else
	echo "                           ."
	echo "                          \":\""
	echo "                        ___:____     |\"\\/\"|"
	echo "                      ,'        \`.    \\  /"
	echo "                      |  o        \\___/  |"
	echo "                    ~^~^~^~^~^~^~^~^~^~^~^~^~"
	echo ""
	echo "                           (fail whale)"
	echo ""
	echo "Note: The fail whale is friendly and adorable! He is not here to"
	echo "      demoralize you, but rather, to bring you comfort and joy"
	echo "      in your time of need. \"Keep plugging away,\" he says! \"You"
	echo "      can do this!\""
	echo ""
fi
