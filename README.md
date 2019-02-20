# PlaywithCpp

## 	Monte Carlo method

**Monte Carlo methods** (or **Monte Carlo experiments**) are a broad class of [computational](https://en.wikipedia.org/wiki/Computation) [algorithms](https://en.wikipedia.org/wiki/Algorithm) that rely on repeated [random sampling](https://en.wikipedia.org/wiki/Random_sampling) to obtain numerical results. Their essential idea is using [randomness](https://en.wikipedia.org/wiki/Randomness) to solve problems that might be deterministic in principle. They are often used in [physical](https://en.wikipedia.org/wiki/Physics) and [mathematical](https://en.wikipedia.org/wiki/Mathematics)
problems and are most useful when it is difficult or impossible to use 
other approaches. Monte Carlo methods are mainly used in three problem 
classes:[[1\]](https://en.wikipedia.org/wiki/Monte_Carlo_method#cite_note-1) [optimization](https://en.wikipedia.org/wiki/Optimization), [numerical integration](https://en.wikipedia.org/wiki/Numerical_integration), and generating draws from a [probability distribution](https://en.wikipedia.org/wiki/Probability_distribution).

[[Wikipedia](https://en.wikipedia.org/wiki/Monte_Carlo_method)]

### 		Monte Carlo Pi

http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopimod.html
Calculate Pi with Monte Carlo Simulation

![[Graphics:Images/MonteCarloPiMod_gr_5.gif]](http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopi/MonteCarloPiMod/Images/MonteCarloPiMod_gr_5.gif)

![[Graphics:Images/MonteCarloPiMod_gr_4.gif]](http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopi/MonteCarloPiMod/Images/MonteCarloPiMod_gr_4.gif)

![[Graphics:Images/MonteCarloPiMod_gr_10.gif]](http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopi/MonteCarloPiMod/Images/MonteCarloPiMod_gr_10.gif)

![[Graphics:Images/MonteCarloPiMod_gr_11.gif]](http://mathfaculty.fullerton.edu/mathews/n2003/montecarlopi/MonteCarloPiMod/Images/MonteCarloPiMod_gr_11.gif)




 ```c++
/* Program to compute Pi using Monte Carlo methods */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

main(int argc, char* argv)
{
    int niter=0;
    double x,y;
    int i,count=0; /* # of points in the 1st quadrant of unit circle */
    double z;
    double pi;

    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d",&niter);

    /* initialize random numbers */
    srand(SEED);
    count=0;
    for ( i=0; i<niter; i++) {
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x*x+y*y;
        if (z<=1) count++;
    }
    pi=(double)count/niter*4;
    printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
}
 ```

https://www.youtube.com/watch?v=drZt9XLjIRw

Ac  = Area of the circle
$$
A_c = {\pi}r^2
$$
As = Area of the square
$$
A_s = 4r^2
$$

r>0,
$$
\begin{align*}
\frac{A_c}{\pi}=\frac{A_s}{4} \\
{\pi} = 4 \frac{A_c}{A_s}\\
\end{align*}
$$

pi is related to the ratio of the area of circle to the area of the square.

```c++
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
```

---

