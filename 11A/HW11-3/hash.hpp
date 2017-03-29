#include <vector>

using namespace std;

const int EMPTY = 0x80000000;
int hashCode(int x, int n);
void insert(vector<int>& table, int element);
void remove(vector<int>& table, int element);
