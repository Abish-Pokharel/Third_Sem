#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

string binary(int n, int bits) {
    if (n >= 0) {
        return bitset<32>(n).to_string().substr(32 - bits);
    } else {
        return bitset<32>((1 << bits) + n).to_string().substr(32 - bits);
    }
}

string add_binary(const string &a, const string &b) {
    int max_len = max(a.length(), b.length());
    string a_padded = string(max_len - a.length(), '0') + a;
    string b_padded = string(max_len - b.length(), '0') + b;

    string result(max_len, '0');
    int carry = 0;

    for (int i = max_len - 1; i >= 0; --i) {
        int total = carry + (a_padded[i] - '0') + (b_padded[i] - '0');
        result[i] = (total % 2) + '0';
        carry = total / 2;
    }

    return result;
}

void arithmetic_shift_right(string &a, string &q, char &qn) {
    string combined = a + q + qn;
    string shifted = combined[0] + combined.substr(0, combined.length() - 1);

    a = shifted.substr(0, a.length());
    q = shifted.substr(a.length(), q.length());
    qn = shifted.back();
}

int booth_multiplication(int m, int r) {
    int m_bits = max((int)ceil(log2(abs(m) + 1)), (int)ceil(log2(abs(r) + 1))) + 1;

    string m_bin = binary(m, m_bits);
    string r_bin = binary(r, m_bits);

    string a(m_bits, '0');
    string q = r_bin;
    char qn = '0';
    string m_neg = binary(-m, m_bits);
    int count = m_bits;

    cout << "Initial values: A=" << a << ", Q=" << q << ", Qn=" << qn << ", M=" << m_bin << ", -M=" << m_neg << "\n";

    while (count > 0) {
        if (q.back() == '1' && qn == '0') {
            a = add_binary(a, m_neg);
        } else if (q.back() == '0' && qn == '1') {
            a = add_binary(a, m_bin);
        }

        arithmetic_shift_right(a, q, qn);
        count--;

        cout << "Step: A= " << a << ", Q= " << q << ", Qn= " << qn << endl;
    }

    string result_bin = a + q;
    int result = stoi(result_bin, nullptr, 2);

    if (result >= (1 << (m_bits * 2 - 1))) {
        result -= (1 << (m_bits * 2));
    }

    return result;
}

int main() {
    int multiplicand, multiplier;

    cout << "Enter multiplicand (M): ";
    cin >> multiplicand;

    cout << "Enter multiplier (R): ";
    cin >> multiplier;

    int product = booth_multiplication(multiplicand, multiplier);
    cout << "Product: " << product << "\n";

    return 0;
}