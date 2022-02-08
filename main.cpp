#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> check_all_possibilities(vector<vector<char>>, int);
bool does_make(vector<vector<char>>, vector<vector<char>>, int);
vector<vector<int>> get_adjacents(vector<vector<char>>);
vector<vector<char>> update_table(vector<vector<char>>);
void print_table(vector<vector<char>>);

int main() {
    int m, n, l;
    cin >> m >> n >> l;

    vector<vector<char>> table(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> table[i][j];

    print_table(check_all_possibilities(table, l));
}

vector<vector<char>> check_all_possibilities(vector<vector<char>> table, int l) {
    int m = table.size();
    int n = table[0].size();

    for (int k = 0; k < (1 << m * n); k++) {
        vector<vector<char>> new_table(m, vector<char>(n, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(k & (1 << i * n + j))
                    new_table[i][j] = '*';
            }
        }

        if (does_make(new_table, table, l)) {
            return new_table;
        }
    }
    return vector<vector<char>>(0);
}

bool does_make(vector<vector<char>> old_table, vector<vector<char>> current_table, int l) {
    for (int i = 0; i < l; i++) {
        old_table = update_table(old_table);
    }
    return old_table == current_table;
}

vector<vector<int>> get_adjacents(vector<vector<char>> table) {
    int m = table.size(), n = table[0].size();
    vector<vector<int>> adjacents(m, vector<int> (n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '*') {
                adjacents[(i + 1) % m][j]++;
                adjacents[(i - 1 + m) % m][j]++;
                adjacents[i][(j + 1) % n]++;
                adjacents[i][(j - 1 + n) % n]++;
                adjacents[(i + 1) % m][(j + 1) % n]++;
                adjacents[(i + 1) % m][(j - 1 + n) % n]++;
                adjacents[(i - 1 + m) % m][(j + 1) % n]++;
                adjacents[(i - 1 + m) % m][(j - 1 + n) % n]++;
            }
        }
    }

    return adjacents;
}

vector<vector<char>> update_table(vector<vector<char>> table) {
    int m = table.size(), n = table[0].size();

    vector<vector<char>> new_table = table;
    vector<vector<int>> adjacents = get_adjacents(table);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == '*' && !(adjacents[i][j] == 2 || adjacents[i][j] == 3))
                new_table[i][j] = '.';
            if (table[i][j] == '.' && adjacents[i][j] == 3)
                new_table[i][j] = '*';
        }
    }
    return new_table;
}

void print_table(vector<vector<char>> table) {
    if (table.size() == 0) {
        cout << "impossible\n";
        return;
    }

    for (vector<char> row : table) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}