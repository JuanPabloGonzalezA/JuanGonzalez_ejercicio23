#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main(){
	double c = 0.1;
	double dx = 0.01;
	double dt = 0.001;
	double Xmin = 0;
	double Xmax = 1;
	int Nx = ((Xmax - Xmin)/dx)+1;
	double *uxt_centro, *uxt_new, *uxt_old;
	uxt_new = new double[Nx];
	uxt_old = new double[Nx];
	uxt_centro = new double[Nx];
	
	int i;
	double j;
	
	//inicializacion
	double x=0;
	for(i=0;i<Nx;i++)
	{
		uxt_old[i]=sin(2*PI*x);
		uxt_centro[i]=sin(2*PI*x);
		cout<<0<<" "<<x<<" "<<uxt_centro[i]<<endl;
		x+=dx;
	}
	
	//recursion
	int cuarto = Nx/4;
	int snap = 1;
	for(j=0.51;j>-1;j-=0.5)
	{
		while(uxt_old[cuarto]>j)
		{
			uxt_old[0]=0;
			uxt_centro[0]=0;
			uxt_old[Nx-1]=0;
			uxt_centro[Nx-1]=0;
		
			for(i=1;i<Nx-1;i++)
			{
				uxt_new[i]=c*c*dt*dt*(uxt_centro[i+1]+uxt_centro[i-1]-2*uxt_centro[i])/(dx*dx) + 2*uxt_centro[i] - uxt_old[i];
			}
		
			for(i=0;i<Nx;i++)
			{
				uxt_old[i]=uxt_centro[i];
				uxt_centro[i]=uxt_new[i];
			}
		}
		x=0;
		for(i=0;i<Nx;i++)
		{
			cout<<snap<<" "<<x<<" "<<uxt_centro[i]<<endl;
			x+=dx;
		}		
		snap++;
	}
	/*
	while(uxt_old[cuarto]>-0.99)
	{
		uxt_old[0]=0;
		uxt_centro[0]=0;
		uxt_old[Nx-1]=0;
		uxt_centro[Nx-1]=0;
		
		for(i=1;i<Nx-1;i++)
		{
			uxt_new[i]=c*c*dt*dt*(uxt_centro[i+1]+uxt_centro[i-1]-2*uxt_centro[i])/(dx*dx) + 2*uxt_centro[i] - uxt_old[i];
		}
		
		for(i=0;i<Nx;i++)
		{
			uxt_old[i]=uxt_centro[i];
			uxt_centro[i]=uxt_new[i];
		}
	}
	x=0;
	for(i=0;i<Nx;i++)
	{
		cout<<0<<" "<<x<<" "<<uxt_centro[i]<<endl;
		x+=dx;
	}
	*/
	return 0;
}

