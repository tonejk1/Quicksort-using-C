#include <stdio.h>
#include <stdlib.h>

double quicksort_med(int *a, int l, int r);

int main()
{
	FILE *f = fopen("QuickSort.txt", "r");
	if (f == NULL)
	{
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}

	int n = 0, num;
	while (fscanf(f, "%d", &num) != EOF)
		n++;
	int *a = (int*) malloc(n* sizeof(int));
	rewind(f);
	int i = 0;
	while (fscanf(f, "%d", &a[i]) != EOF)
		i++;
	fclose(f);
	double d = quicksort_med(a, 0, n - 1);
	printf("%.lf", d);
	fclose(f);
	free(a);
	return 0;
}

double quicksort_med(int *a, int l, int r)
{
	static double n = 0;
	if (l >= r)
		return 0;
	int piv;
	int indi;
	if (r - l > 1)
	{
		int in ; in = l + ((r - l) / 2);
		if ((a[ in ] >= a[l] && a[ in ] <= a[r]) || (a[ in ] >= a[r] && a[ in ] <= a[l]))
		{
			indi = in ;
			piv = a[ in ];
		}
		else if ((a[l] >= a[ in ] && a[l] <= a[r]) || (a[l] >= a[r] && a[l] <= a[ in ]))
		{
			indi = l;
			piv = a[l];
		}
		else if ((a[r] >= a[ in ] && a[r] <= a[l]) || (a[r] >= a[l] && a[r] <= a[ in ]))
		{
			indi = r;
			piv = a[r];
		}
	}
	else
	{
		if (a[l] >= a[r])
		{
			indi = l;
			piv = a[l];
		}
		else
		{
			indi = r;
			piv = a[r];
		}
	}

	int i = l + 1;

	a[indi] = a[l];
	a[l] = piv;
	piv = a[l];

	for (int j = l + 1; j <= r; j++)
	{
		if (a[j] <= piv)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
	}

	int temp = a[i - 1];
	a[i - 1] = a[l];
	a[l] = temp;
	n = n + (r - l);
	int l1 = l;
	quicksort_med(a, l1, i - 2);
	quicksort_med(a, i, r);
	return n;

}
