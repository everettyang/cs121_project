#include <iostream>
#include <time.h>
using namespace std;
int main()
{
srand(time(NULL));
double val = (double)rand() / RAND_MAX;
cout << val << endl;
return 0;

}
