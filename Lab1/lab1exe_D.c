/*
*  lab1exe_D.c
*  ENCM 339 - Fall 2017 Lab 1, exercise D
*
*  Completed by: 	Alexander Gorkoff
*  Lab Section: 	B03
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);
/* REQUIRES: v >= 0
PROMISES: create_table outputs a three-column table to the terminal. The first column will
display the trajectory angle of the projectile (in units of degrees) from 0 to 90 degrees. 
The second column will display the projectile travel time (in units of seconds) and the third 
column will display the projectile travel distance (in units of meters). 
*/

double Projectile_travel_time(double a, double v);
/* REQUIRES: a>=0 and a<=pi/2, v >= 0
PROMISES: Calculates and returns the projectile travel time (in units of seconds) 
*/

double Projectile_travel_distance(double a, double v);
/* REQUIRES: a>=0 and a<=pi/2, v >= 0
PROMISES: Returns the projectile's maximum horizontal distance (in units of meters) 
*/

double degree_to_radian(double d);
/* REQUIRES: a>=0 and a<=90
PROMISES: Converts the unit of the trajectory angle from degrees to radians 
*/

int main(void)
{
    int n;
    double velocity;
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity); 
    
    return 0;
}


void create_table(double v){
	printf("Angle			t			d \n (deg)			(sec)			(m) \n");
	for(double a = 0; a<=90; a+=5){
		double angle = degree_to_radian(a);
		printf("%lf		%lf		%lf\n", a, Projectile_travel_time(angle,v), Projectile_travel_distance(angle,v));
	}
}

double Projectile_travel_time(double a, double v){
	double time = (2*v*sin(a))/G;
	return time;
}

double Projectile_travel_distance(double a, double v){
	double distance = (pow(v,2)*sin(2*a))/G;
	return distance;
}

double degree_to_radian(double d){
	return d*(PI/180);
}

