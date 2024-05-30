//
// Created by Fathan on 31/05/2024.
//
#include <iostream>
#include "../include/integral.h"
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <memory>
#include <regex>
#include <functional>
#include "../SymbolicC++/headers/symbolicc++.h"


using namespace std;

// Fungsi matematika standar
double sin(double x) {
    return std::sin(x);
}

double cos(double x) {
    return std::cos(x);
}

double exp(double x) {
    return std::exp(x);
}

double sqrt(double x) {
    return std::sqrt(x);
}


#include "../SymbolicC++/headers/symbolicc++.h"

Symbolic parse_term_symbolic(const string& term, const Symbolic& x) {
    size_t pos = term.find('x');
    if (pos == string::npos) {
        // Term is a constant
        return Symbolic(stod(term));
    } else {
        // Term contains 'x'
        if (term == "x") {
            return x;
        } else if (term.find('^') != string::npos) {
            // Parse terms like x^2, x^-1, etc.
            size_t pow_pos = term.find('^');
            int exponent = stoi(term.substr(pow_pos + 1));
            return pow(x, Symbolic(exponent));
        } else {
            // Term like 2x, 3x, etc.
            double coefficient = stod(term.substr(0, pos));
            return Symbolic(coefficient) * x;
        }
    }
}


Symbolic parse_function(const string& function, const Symbolic& x) {
    if (function == "sin(x)") {
        return sin(x);
    } else if (function == "cos(x)") {
        return cos(x);
    } else if (function == "exp(x)") {
        return exp(x);
    } else if (function == "sqrt(x)") {
        return sqrt(x);
    } else if (function == "1/x") {
        return 1.0 / x;
    } else if (function == "x") {
        return x;
    }

    Symbolic result;
    stringstream ss(function);
    string term;
    bool first_term = true;

    while (getline(ss, term, '+')) {
        term.erase(0, term.find_first_not_of(' '));
        term.erase(term.find_last_not_of(' ') + 1);

        size_t minus_pos = term.find('-');
        while (minus_pos != string::npos) {
            string sub_term = term.substr(0, minus_pos);
            if (!sub_term.empty()) {
                result = first_term ? parse_term_symbolic(sub_term, x) : result + parse_term_symbolic(sub_term, x);
                first_term = false;
            }
            term = term.substr(minus_pos + 1);
            result = result - parse_term_symbolic(term, x);
            minus_pos = term.find('-');
        }

        if (first_term) {
            result = parse_term_symbolic(term, x);
            first_term = false;
        } else {
            result = result + parse_term_symbolic(term, x);
        }
    }

    return result;
}

string extract_indefinite_integral_expression(const string& input, string& variable) {
    // Patern regex untuk format ITT(ekspresi, x)
    regex pattern(R"(^ITT\((.*),\s*(\w+)\)$)");
    smatch matches;

    if (regex_match(input, matches, pattern)) {
        if (matches.size() == 3) {
            variable = matches[2];
            return matches[1];
        }
    }
    throw invalid_argument("Format input tidak valid");
}


void extract_definite_integral_input(const string& input, string& expression, string& variable, double& lower_bound, double& upper_bound) {
    // Patern regex untuk format IT(ekspresi, x, lower, upper)
    regex pattern(R"(^IT\((.*),\s*(\w+),\s*([-+]?[0-9]*\.?[0-9]+),\s*([-+]?[0-9]*\.?[0-9]+)\)$)");
    smatch matches;

    if (regex_match(input, matches, pattern)) {
        if (matches.size() == 5) {
            expression = matches[1];
            variable = matches[2];
            lower_bound = stod(matches[3]);
            upper_bound = stod(matches[4]);
            return;
        }
    }
    throw invalid_argument("Format input tidak valid");
}

string calculate_indefinite_integral_cpp(string input) {
    // Baca input dari pengguna
//    cout << "Masukkan fungsi untuk diintegrasikan (format: ITT(ekspresi, x)): ";
//    string input;
//    getline(cin, input);

    // Debugging: Tampilkan input yang diterima
//    cout << "Input yang diterima: " << input << endl;

    // Ekstrak ekspresi dan variabel dari input
    string function;
    string variable;
    try {
        function = extract_indefinite_integral_expression(input, variable);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return "";
    }

    // Debugging: Tampilkan ekspresi dan variabel yang diekstrak
    cout << "Ekspresi: " << function << ", Variabel: " << variable << endl;

    // Buat variabel simbolik
    Symbolic x(variable);

    // Buat ekspresi simbolik dari string fungsi
    Symbolic f = parse_function(function, x); // Asumsikan pustaka mendukung inisialisasi ini

    // Debugging: Tampilkan ekspresi simbolik
//    cout << "Ekspresi simbolik: " << f << endl;

    // Hitung integral tak tentu
    Symbolic integral_indefinite = integrate(f, x);

    // Debugging: Tampilkan hasil integral sebelum konversi ke string
//    cout << "Hasil integral: " << integral_indefinite << endl;

    // Konversi hasil integral ke string
    ostringstream oss;
    oss << integral_indefinite;
    return oss.str();
}


// Fungsi untuk menghitung integral tak tentu dalam C
const char* calculate_indefinite_integral(const char* function) {
    static char* result = NULL;

    printf("%s", function);
    // Panggil fungsi C++ dan dapatkan hasilnya sebagai string C++
    string cpp_result = calculate_indefinite_integral_cpp(function);

    // Bebaskan memori hasil sebelumnya jika ada
    if (result != NULL) {
        free(result);
    }

    // Alokasikan memori baru untuk hasil dan salin hasil ke dalamnya
    result = (char*)malloc(cpp_result.length() + 1);
    if (result != NULL) {
        strcpy(result, cpp_result.c_str());
    }

    return result;
}


string calculate_definite_integral_cpp(string input) {
    // Baca input dari pengguna
//    cout << "Masukkan fungsi untuk diintegrasikan (format: ITT(ekspresi, x, lower, upper)): ";
//    string input;
//    getline(cin, input);

    // Debugging: Tampilkan input yang diterima
//    cout << "Input yang diterima: " << input << endl;

    // Variabel untuk menyimpan hasil ekstraksi
    string function;
    string variable;
    double lower_bound;
    double upper_bound;

    // Ekstrak ekspresi, variabel, dan batas bawah serta atas dari input
    try {
        extract_definite_integral_input(input, function, variable, lower_bound, upper_bound);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return "";
    }

    // Debugging: Tampilkan hasil ekstraksi
//    cout << "Ekspresi: " << function << ", Variabel: " << variable
//         << ", Batas bawah: " << lower_bound << ", Batas atas: " << upper_bound << endl;

    // Buat variabel simbolik
    Symbolic x(variable);

    // Buat ekspresi simbolik dari string fungsi
    Symbolic f = parse_function(function, x); // Asumsikan pustaka mendukung inisialisasi ini

    // Debugging: Tampilkan ekspresi simbolik
//    cout << "Ekspresi simbolik: " << f << endl;

    // Hitung integral tentu dari fungsi tersebut
    Symbolic definite_integral = integrate(f, x, lower_bound, upper_bound);

    // Debugging: Tampilkan hasil integral sebelum konversi ke string
//    cout << "Hasil integral: " << definite_integral << endl;

    // Konversi hasil integral ke string
    ostringstream oss;
    oss << definite_integral;
    return oss.str();
}

// Fungsi C-style wrapper untuk dipanggil dari C
const char* calculate_definite_integral(const char* function) {
    static unique_ptr<char[]> result;

    // Panggil fungsi C++ dan dapatkan hasilnya sebagai string C++
    string cpp_result = calculate_definite_integral_cpp(function);

    // Alokasikan memori baru untuk hasil dan salin hasil ke dalamnya
    result.reset(new char[cpp_result.length() + 1]);
    strcpy(result.get(), cpp_result.c_str());

    return result.get();
}

