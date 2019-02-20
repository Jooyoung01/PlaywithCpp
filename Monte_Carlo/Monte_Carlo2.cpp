#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
double getRandomNumber(const double min, const double max){
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max-min)*temp;
	return temp;
}
bool isInsideCircle(const double x, const double y){
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	
	const double f = (x-x_c)*(x-x_c) + (y-y_c)*(y-y_c) - r*r;
	if(f>0.0)return false ;
	else return true;
}

int main() {
	FILE *of = fopen("pi_monte.txt", "w");
	
	srand((unsigned int)time(NULL));
	
	const int num_pts_square = 100000;
	int num_pts_circle = 0;
	
	for (int num_pts_square = 10; num_pts_square < 10000000; num_pts_square*=2){
		int num_pts_circle = 0;
		
		for (int i = 0; i < num_pts_square; i++) {
			double x = getRandomNumber(0.0, 1.0); 
			double y = getRandomNumber(0.0, 1.0);

			if (isInsideCircle(x, y) == true) { 
				num_pts_circle++;
			} 
		} 
		const double pi_estimation = 4.0 * (double)num_pts_circle / (double)num_pts_square;
		printf("Estimated pi with %d random pts is  %f\n",num_pts_square, pi_estimation); 
		fprintf(of,"%f\n",pi_estimation);
	}
	fclose(of);
	return 0;
}
