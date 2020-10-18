#include <iostream> 
using namespace std;
const int MAX = 15;
int apartment[MAX][MAX];
void initialize(void)
{
	for (int i = 1; i < MAX; i++)
		apartment[0][i] = i;
	for (int i = 1; i < MAX; i++)
	{
		int sum = 0;
		for (int j = 1; j < MAX; j++)
		{
			apartment[i][j] += sum + apartment[i - 1][j];
			sum += apartment[i - 1][j];
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	initialize();
	for (int t = 0; t < T; t++)
	{
		int K, N;
		cin >> K >> N;
		cout << apartment[K][N] << "\n";
	} return 0;
}


