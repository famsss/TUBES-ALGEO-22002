#include <iostream>
#include <fstream>  // Header ini untuk menambahkan file 
#include <iomanip>  // Header ini untuk setw
#include <cmath>    // Header ini untuk fungsi matematika
using namespace std;

const int size = 3;
const int baris = 2;
const int kolom = 3;
double matriks[baris][kolom];

// Fungsi untuk menampilkan menu utama
void tampilan_Menu_Utama() 
{
    cout << "===== Menu Utama =====" << endl;
    cout << "1. Pertambahan dan Pengurangan Matriks (2x2)" << endl;
    cout << "2. Transpose Matriks" << endl;
    cout << "3. inverse Matriks (2x2)" << endl;
    cout << "4. Determinan" << endl;
    cout << "5. Sistem Persamaan Linier (2x3)" << endl;
    cout << "6. Keluar" << endl;
    cout << "======================" << endl;
}

// Fungsi untuk menampilkan submenu pertambahan dan pengurangan
void tampilan_Sub_Menu_Pertambahan_Pengurangan() 
{
    cout << "----- Pertambahan dan Pengurangan ----- " << endl;
    cout << "A. Pertambahan" << endl;
    cout << "B. Pengurangan" << endl;
    cout << "C. Kembali ke Menu Utama" << endl;
    cout << "-------------------" << endl;
}

// Fungsi untuk menampilkan submenu Transpose
void tampilan_Sub_Menu_Ukuran_Matriks() 
{
    cout << "----- Pilih Ukuran Matriks ----- " << endl;
    cout << "A. 2x2" << endl;
    cout << "B. 3x3" << endl;
    cout << "C. Kembali ke Menu Utama" << endl;
    cout << "-------------------" << endl;
}

// Fungsi untuk menghitung determinan matriks 2x2
float determinant(float a, float b, float c, float d) 
{
    return (a * d - b * c);
}

// Fungsi untuk menghitung invers matriks 2x2
void inverse_Matrix(float a, float b, float c, float d) 
{
    // Menghitung determinan
    float det = determinant(a, b, c, d);

    // Memeriksa apakah matriks memiliki invers (determinan tidak boleh nol)
    if (det == 0) 
    {
        cout << "Matriks tidak memiliki invers." << endl;
        return;
    }

    // Menghitung invers matriks
    float inv_a = d / det;
    float inv_b = -b / det;
    float inv_c = -c / det;
    float inv_d = a / det;

    // Menampilkan matriks awal
    cout << "Matriks Awal:" << endl;
    cout << a << "\t" << b << endl;
    cout << c << "\t" << d << endl;

    // Menampilkan proses perhitungan
    cout << "\nProses Perhitungan:" << endl;
    cout << "Determinan = " << det << endl;
    cout << "Invers:" << endl;
    cout << inv_a << "\t" << inv_b << endl;
    cout << inv_c << "\t" << inv_d << endl;

    // Menampilkan hasil
    cout << "\nMatriks Invers:" << endl;
    cout << inv_a << "\t" << inv_b << endl;
    cout << inv_c << "\t" << inv_d << endl;
}

void hitung_Determinan(int A[size][size], int n) 
{
    int det = 0;
    if (n == 2) 
    {
        // Matriks 2x2
        det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    } 
    else if (n == 3) 
    {
        // Matriks 3x3
        det = A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]) -
              A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) +
              A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
    }
    // Menampilkan matriks
    cout << "Matriks A:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }
    // Menampilkan hasil determinan
    cout << "Determinan matriks A (" << n << "x" << n << "): " << det << endl;
}

void spl(int size) 
{
    int A[size][size + 1];
    // Eliminasi Gauss
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            if (i != j) 
            {
                double ratio = A[j][i] / A[i][i];
                for (int k = 0; k <= size; ++k) 
                {
                    A[j][k] -= ratio * A[i][k];
                }
            }
        }
    }
    // Substitusi mundur
    for (int i = 0; i < size; ++i) 
    {
        double divisor = A[i][i];
        for (int j = 0; j <= size; ++j) 
        {
            A[i][j] /= divisor;
        }
    }
    // Tampilkan solusi
    cout << "Solusi dari sistem persamaan linier:\n";
    for (int i = 0; i < size; ++i) 
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << A[i][size] << endl;
    }
}

// Fungsi untuk menangani pilihan di menu utama
void prosesMenuUtama(int pilihan) 
{
    switch (pilihan) 
    {
        case 1:
            // Pilih menu pertambahan dan pengurangan
            while (true) 
            {
                tampilan_Sub_Menu_Pertambahan_Pengurangan();
                char submenu;
                cout << "Pilih: ";
                cin >> submenu;
                int A[size][size], B[size][size], result[size][size];
                int size = 2;
                switch (submenu) 
                {
                    case 'A':
                    case 'a':
                        // Input matriks A
                        cout << "Masukkan elemen matriks A:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> A[i][j];
                            }
                        }
                        // Input matriks B
                        cout << "Masukkan elemen matriks B:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> B[i][j];
                                
                            }
                        }
                        cout << "Matriks A :\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << A[i][j] << " ";
                            }
                            std::cout << "\n";
                        }

                        cout << "Matriks B :\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << B[i][j] << " ";
                            }
                            std::cout << "\n";
                        }

                        // Menampilkan matriks hasil setelah pertambahan
                        std::cout << "Hasil Matriks setelah ditambah:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                result[i][j] = A[i][j] + B[i][j];
                                cout << result[i][j] << " ";
                            }
                            cout << endl;
                        }
                        break;

                    case 'B':
                    case 'b':
                        // Input matriks A
                        cout << "Masukkan elemen matriks A:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> A[i][j];
                            }
                        }
                        // Input matriks B
                        cout << "Masukkan elemen matriks B:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> B[i][j];
                                
                            }
                        }
                        cout << "Matriks A :\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << A[i][j] << " ";
                            }
                            std::cout << "\n";
                        }

                        cout << "Matriks B :\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                cout << B[i][j] << " ";
                            }
                            std::cout << "\n";
                        }

                        // Menampilkan matriks hasil setelah pengurangan
                        std::cout << "Hasil Matriks setelah dikurang:\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                result[i][j] = A[i][j] - B[i][j];
                                cout << result[i][j] << " ";
                            }
                            cout << endl;
                        }
                        break;

                    case 'C':
                    case 'c':
                        // Kembali ke menu utama
                        return;
                        default:
                        cout << "Pilihan tidak valid." << endl;
                }
            }
            break;
            
        case 2:
            
            while (true) 
            {
                tampilan_Sub_Menu_Ukuran_Matriks();
                char submenu;
                cout << "Pilih: ";
                cin >> submenu;
                int A[2][2], B[3][3], result[size][size];
                switch (submenu) 
                {
                    case 'A':
                    case 'a':
                    // Input matrix
                    cout << "Masukkan elemen matriks :\n";
                    for (int i = 0; i < 2; ++i) 
                    {
                        for (int j = 0; j < 2; ++j) 
                        {
                            std::cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                            std::cin >> A[i][j];
                        }
                    }
                        // Transpose matriks
                    for (int i = 0; i < 2; ++i) 
                    {
                        for (int j = 0; j < 2; ++j) 
                        {
                            result[j][i] = A[i][j];
                        }
                    }
                        // Output matriks sebelum dan sesudah transpose
                        std::cout << "Matriks sebelum transpose:\n";
                    for (int i = 0; i < 2; ++i) 
                    {
                        for (int j = 0; j < 2; ++j) 
                        {
                            std::cout << A[i][j] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "Matriks setelah transpose:\n";
                    for (int i = 0; i < 2; ++i) 
                    {
                        for (int j = 0; j < 2; ++j) 
                        {
                            std::cout << result[i][j] << " ";
                        }
                        std::cout << "\n";
                    }
                        break;
                    case 'B':
                    case 'b':
                        // Input matrix
                        cout << "Masukkan elemen matriks :\n";
                        for (int i = 0; i < size; ++i) 
                        {
                            for (int j = 0; j < size; ++j) 
                            {
                                std::cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                                std::cin >> B[i][j];
                            }
                        }
                    // Transpose matriks
                    for (int i = 0; i < size; ++i) 
                    {
                        for (int j = 0; j < size; ++j) 
                        {
                            result[j][i] = B[i][j];
                        }
                    }
                    // Output matriks sebelum dan sesudah transpose
                    std::cout << "Matriks sebelum transpose:\n";
                    for (int i = 0; i < size; ++i) 
                    {
                        for (int j = 0; j < size; ++j) 
                        {
                            std::cout << B[i][j] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "Matriks setelah transpose:\n";
                    for (int i = 0; i < size; ++i) 
                    {
                        for (int j = 0; j < size; ++j) 
                        {
                            std::cout << result[i][j] << " ";
                        }
                        std::cout << "\n";
                    }
                    break;
                    case 'C':
                    case 'c':
                    // Back to main menu
                    return;
                    default:
                    cout << "Pilihan tidak valid." << endl;
                }
            }
            break;
        case 3:
            while (true) 
            {
                // Memasukkan elemen-elemen matriks dari pengguna
                float a, b, c, d;
                cout << "Masukkan elemen-elemen matriks 2x2:" << endl;
                cout << "[1][1]: ";
                cin >> a;
                cout << "[1][2]: ";
                cin >> b;
                cout << "[2][1]: ";
                cin >> c;
                cout << "[2][2]: ";
                cin >> d;
                // Memanggil fungsi untuk menghitung invers matriks
                inverse_Matrix(a, b, c, d);
                return ;
            }
            break;

        case 4:
            while (true) 
            {
                tampilan_Sub_Menu_Ukuran_Matriks();
                char submenu;
                cout << "Pilih: ";
                cin >> submenu;
                int A[size][size]; // Matriks A dideklarasikan di luar blok switch
                switch (submenu) 
                {
                    case 'A':
                    case 'a':
                        // Input matriks 2x2
                        cout << "Masukkan elemen matriks (2x2):\n";
                        for (int i = 0; i < 2; ++i) 
                        {
                            for (int j = 0; j < 2; ++j) 
                            {
                                cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> A[i][j];
                            }
                        }
                        // Hitung determinan dan tampilkan hasil
                        hitung_Determinan(A, 2);
                        break;
                    case 'B':
                    case 'b':
                        // Input matriks 3x3
                        cout << "Masukkan elemen matriks (3x3):\n";
                        for (int i = 0; i < 3; ++i) 
                        {
                            for (int j = 0; j < 3; ++j) 
                            {
                                cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                                cin >> A[i][j];
                            }
                        }
                        // Hitung determinan dan tampilkan hasil
                        hitung_Determinan(A, 3);
                        break;
                    case 'C':
                    case 'c':
                        // Kembali ke menu utama
                        return;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
            }
            break;
        case 5:
            while (true) 
            {
                // Matriks koefisien
                double matriks[baris][kolom];
                // Input matriks dari pengguna
                cout << "Masukkan matriks koefisien (2x3):\n";
                for (int i = 0; i < baris; ++i) 
                {
                    for (int j = 0; j < kolom; ++j) 
                    {
                        cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                        cin >> matriks[i][j];
                    }
                }
                // Menampilkan matriks
                cout << "\nMatriks koefisien yang dimasukkan:\n";
                for (int i = 0; i < baris; ++i) 
                {
                    for (int j = 0; j < kolom; ++j) 
                    {
                        cout << setw(8) << matriks[i][j];
                    }
                    cout << endl;
                }
                // Solusi sistem persamaan linier
                if (matriks[0][0] * matriks[1][1] == matriks[0][1] * matriks[1][0]) 
                {
                    cout << "\nSistem persamaan linier tidak memiliki solusi unik.\n";
                } 
                else 
                {
                    // Menggunakan metode eliminasi Gauss untuk menyelesaikan sistem persamaan
                    double faktor = matriks[1][0] / matriks[0][0];
                    for (int j = 0; j < kolom; ++j) 
                    {
                        matriks[1][j] -= faktor * matriks[0][j];
                    }
                    // Menampilkan matriks setelah eliminasi Gauss
                    cout << "\nMatriks setelah eliminasi Gauss:\n";
                    for (int i = 0; i < baris; ++i) 
                    {
                        for (int j = 0; j < kolom; ++j) 
                        {
                            cout << setw(8) << matriks[i][j];
                        }
                        cout << endl;
                    }
                    // Menemukan solusi
                    double x2 = matriks[1][2] / matriks[1][1];
                    double x1 = (matriks[0][2] - matriks[0][1] * x2) / matriks[0][0];
                    // Menampilkan solusi
                    cout << "\nSolusi sistem persamaan linier:\n";
                    cout << "x1 = " << x1 << endl;
                    cout << "x2 = " << x2 << endl;
                }
                cout << "\n";
                return;
            }
            break;

            case 6:
            // Keluar dari program
            cout << "Program selesai." << endl;
            cout << "Terima kasih!" << endl;
            exit(0);
            default:
            cout << "Pilihan tidak valid." << endl;
        
    }
}

int main() 
{
    while (true) 
    {
        tampilan_Menu_Utama();

        int pilihan;
        cout << "Pilih: ";
        cin >> pilihan;

        prosesMenuUtama(pilihan);
    }

    return 0;
}
