// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!


// Sean Szumlanski
// COP 3223, Fall 2018

// ===========================
// assignment06: testcase03a.c
// ===========================
// FUNCTION TESTED: update_missing_pancake_info()
// OUTPUT FILE: sample_output/output03a.txt


#include <stdio.h>
#include <stdlib.h>
#include "pancake_stuff.h"

int main(void)
{
	pancake_info p;

	p.name = "Bo Bobbity Frank";
	p.pancake_count = 0.0;
	p.pancakes_per_minute = 0.12579;
	p.minutes_spent_munching = 28.00000;

	// Note: This also relies on your print_pancake_report() function working correctly.
	update_missing_pancake_info(&p);
	print_pancake_report(p);

	return 0;
}
