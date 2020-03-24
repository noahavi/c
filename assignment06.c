// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment06.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_pancake_report(pancake_info p)
{
	printf("Name: %s\n", p.name);
	printf("Pancakes Consumed: %.3f\n", p.pancake_count);
	printf("Pancakes Per Minute: %.3f\n", p.pancakes_per_minute);
	printf("Minutes Spent Munching: %.3f\n", p.minutes_spent_munching);
}
// Checks what value is needed with if
double get_missing_pancake_info(pancake_info p)
{
	if (p.pancake_count == 0)
	{
		return p.pancakes_per_minute * p.minutes_spent_munching;
	}
	if (p.pancakes_per_minute == 0)
	{
		return p.pancake_count / p.minutes_spent_munching;
	}
	if (p.minutes_spent_munching == 0)
	{
		return p.pancake_count / p.pancakes_per_minute;
	}
}
void update_missing_pancake_info(pancake_info *p)
{
	if (p->pancake_count == 0)
	{
		p->pancake_count = p->pancakes_per_minute * p->minutes_spent_munching;
	}
	if (p->pancakes_per_minute == 0)
	{
		p->pancakes_per_minute = p->pancake_count / p->minutes_spent_munching;
	}
	if (p->minutes_spent_munching == 0)
	{
		p->minutes_spent_munching = p->pancake_count / p->pancakes_per_minute;
	}
}
pancake_info *make_pancake_info(char *name, double count, double rate, double minutes)
{
	// struct created to dynamically allocate
	struct p_info
	{	
		char *name;
		double count;
		double rate;
		double minutes;
	};
	// puts in buffer first to get length needed
	char *n;
	char buffer[1024];
	pancake_info *p_info;
	p_info = malloc(sizeof(pancake_info));
	strcpy(buffer, name);
	p_info->name = malloc(sizeof(char) * (strlen(buffer) + 1));
	strcpy(p_info->name, buffer);
	// Sets members of struct to value
	p_info->pancake_count = count;
	p_info->pancakes_per_minute = rate;
	p_info->minutes_spent_munching = minutes;
	return p_info;
}
pancake_info *clone_pancake_info(pancake_info source)
{
	struct p_info
	{
		char *name;
		double count;
		double rate;
		double minutes;
	};
	pancake_info *p_info;
	char *n;
	char buffer[1024];
	p_info = malloc(sizeof(pancake_info));
	strcpy(buffer, source.name);
	p_info->name = malloc(sizeof(char) * (strlen(buffer)+ 1));
	strcpy(p_info->name, buffer);
	// sets the values equal to members of the source struct
	p_info->pancake_count = source.pancake_count;
	p_info->pancakes_per_minute = source.pancakes_per_minute;
	p_info->minutes_spent_munching = source.minutes_spent_munching;
	return p_info;

}
double difficulty_rating(void)
{
	return 4;
}
double hours_invested(void)
{
	return 2;
}
double prior_experience(void)
{
	return 1;
}