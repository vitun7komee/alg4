#define MAX 2502
#include<iostream>
#include<string>
double min(double x, double y) {
    
    if (x > y) {
        return y;
    }
    else {
        return x;
    }
}
int main() {

	std::string boards;
	double c[MAX];

    while (std::cin >> boards)
    {
        boards = " " + boards;
        c[0] = 0;
        for (int i = 1; i < boards.length(); i++)
        {

            c[i] = 10000;
            if (boards[i] == '.') {
                c[i] = c[i - 1];
            }
            else {
                for (int j = 0; j < i; j++)
                    c[i] = min(c[i], c[j] + sqrt(1.0 * i - j));
            }

        }
        printf("%.4lf\n", c[boards.length() - 1]);
    }
}
