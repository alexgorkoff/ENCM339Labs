/*
 *
 * lab2exe_F.c
 * ENCM 339 Fall 2017 - Lab 2 - Execise F
 *
 *  Code written by: Alexander Gorkoff
 *	Lab section: B03
 * 	Date: Friday Sept. 29th, 2017
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 void get_user_input(double *distance, double *speed);
 /* REQUIRES: User input for distance & speed must be greater than zero. 
 `	PROMISES: Stores the values of user input into main function variables 
 	travel_distance and average_speed using double pointer arguments *distance 
 	and *speed. If an invalid input has been entered, the program terminates and 
 	an error message will be displayed in the terminal. 
 */
 void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
 /* REQUIRES: Valid user input from function get_user_input.
 	PROMISES: Stores the calculated values for travel time into main function variables
 	hours and minutes using double pointer arguments *hours and *minutes. 
 */
 void display_info(double distance, double speed, double hours, double minutes);
 /* REQUIRES: Valid user input from function get_user_input.
 	PROMISES: Displays message to terminal listing the distance travelled, the travel
 	speed, and the calculated travel time in hours and minutes. 
 */
 
 int main(void)
 {
 	double travel_distance;
 	double average_speed;
 	double hours;
 	double minutes;


 	get_user_input(&travel_distance, &average_speed);
	travel_time_hours_and_minutes(travel_distance, average_speed, &hours, &minutes);
	display_info(travel_distance, average_speed, hours, minutes);

 	return 0;
 }
 
void get_user_input(double *distance, double *speed)
{
	double distance_value;
	int distance_scan;
	printf("Please enter the travel distance in km:");
	distance_scan = scanf("%lf", &distance_value);
	
	if(distance_scan != 1 || distance_value < 0)
	{
		printf("Invalid distance input. Please try again.\nEnd of program.");
		exit(1);
	}
	
	*distance = distance_value;
	
	double speed_value;
	int speed_scan;
	printf("Now enter the vehicle's average speed (km/hr):");
	speed_scan = scanf("%lf", &speed_value);
	
	if(speed_scan != 1 || speed_value < 0)
	{
		printf("Invalid speed input. Please try again.\nEnd of program.");
		exit(1);
	}
	
	*speed = speed_value;
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes)
{
	*hours = (int)(distance/speed);
	*minutes = (distance/speed)*60 - *hours*60;
	
}

void display_info(double distance, double speed, double hours, double minutes)
{
	printf("You have travelled %lf (km) with a speed of %lf (km/hr) in %lf hour(s) and %lf minutes(s)\n", distance, speed, hours, minutes);

}