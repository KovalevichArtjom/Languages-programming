#include <iostream>
using namespace std;

auto NOD(int N, int M)
{
    if (M == 0 || N == 0) {
        return M == 0 ? M : N;
    } else if (fmod(M, N) == 0) {
        return N;
    } else {
        return NOD(fmod(M, N), N);
    }
}

int main()
{
    int N, M;

    cout << "Enter N with type[int]: ";
    cin >> N;
    cout << endl << "Enter M with type[int]: ";
    cin >> M;

    cout << endl << "Result completed function NOD: " << NOD(N, M) << endl;

	cin.get();
	return 0;
}
