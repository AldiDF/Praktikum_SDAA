#include <iostream>
#include <windows.h>
#include <iomanip>
#include <algorithm>

using namespace std;

struct data_sekolah{
    string nama;
    string alamat;
    string kelurahan;
    string kecamatan;
    string jenjang_Sekolah;
    string jenis_sekolah;
    int kode_pos;
    int jumlah_siswa;

};

data_sekolah sekolah[50] = {{"SMA NEGERI 1 SAMARINDA", "Jalan Drs. H. Anang Hasyim", "Air Hitam", "Samarinda Ulu", "SMA", "Negeri", 75124, 960}, 
                            {"SMP NEGERI 1 SAMARINDA", "Jalan Drs. H. Anang Hasyim", "Air Hitam", "Samarinda Ulu", "SMP", "Negeri", 75124, 1056},
                            {"SD NEGERI 009 SAMARINDA", "Jalan KS Tubun Dalam", "Dadi Mulya", "Samarinda Ulu", "SD", "Negeri", 75243, 768}
};
int banyak_sekolah = 3;

void main_menu();

enum ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

// Fungsi Untuk Mengatur Warna Konsol
void setConsoleColor(int textColor, int bgColor = BLACK) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void data_detail_sekolah(int *indeks){
    cout << "============================================================" << endl;
    cout << "=================== DATA DETAIL SEKOLAH ====================" << endl;
    cout << "============================================================" << endl;
    cout << "Nama Sekolah    : " << sekolah[*indeks].nama << endl;
    cout << "Alamat          : " << sekolah[*indeks].alamat << endl;
    cout << "Kelurahan       : " << sekolah[*indeks].kelurahan << endl;
    cout << "Kecamatan       : " << sekolah[*indeks].kecamatan << endl;
    cout << "Jenjang Sekolah : " << sekolah[*indeks].jenjang_Sekolah << endl;
    cout << "Jenis Sekolah   : " << sekolah[*indeks].jenis_sekolah << endl;
    cout << "Kode Pos        : " << sekolah[*indeks].kode_pos << endl;
    cout << "Jumlah Siswa    : " << sekolah[*indeks].jumlah_siswa << endl;
    cout << "============================================================" << endl;
}

void show_sekolah(){
    cout << "============================================================================================================================================" << endl;
    cout << "========================================================== TAMPILKAN DATA SEKOLAH ==========================================================" << endl;
    cout << "============================================================================================================================================" << endl;
    cout << left << setw(5)  << "No"
                 << setw(30) << "Nama Sekolah"
                 << setw(30) << "Alamat"
                 << setw(15) << "Kelurahan"
                 << setw(17) << "Kecamatan"
                 << setw(10) << "Jenjang"
                 << setw(8)  << "Jenis"
                 << setw(10) << "Kode Pos"
                 << setw(15) << "Jumlah Siswa" << endl;
    cout << setfill('=') << setw(140) << "=" << setfill(' ') << endl;

    for (int i = 0; i < banyak_sekolah; i++){
        cout << left << setw(5) << i + 1
             << setw(30) << sekolah[i].nama
             << setw(30) << sekolah[i].alamat
             << setw(15) << sekolah[i].kelurahan
             << setw(17) << sekolah[i].kecamatan
             << setw(10) << sekolah[i].jenjang_Sekolah
             << setw(8)  << sekolah[i].jenis_sekolah
             << setw(10) << sekolah[i].kode_pos
             << setw(15) << sekolah[i].jumlah_siswa << endl;
    }
    cout << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
}

void tampil_sekolah(){
    string pilih;
    system("cls");
    show_sekolah();
    cout << "\t[back] -> Kembali" << endl;
    cout << "\tMasukkan: ";
    cin >> pilih;
    if (pilih == "back"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "========================== KEMBALI =========================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        main_menu();
        
    }
}

void hapus_data(){
    system("cls");
    string pilih;
    int indeks;
    show_sekolah();
    try{
        cout << "\tMasukkan: ";
        cin >> pilih;

        indeks = stoi(pilih);

    } catch(invalid_argument){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "================== GAGAL MENGHAPUS DATA ====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        main_menu();
    }

    for (int i = 0; i < banyak_sekolah; i++){
        if (indeks - 1 == i){
            while (true){
                string konfimasi;
                system("cls");
                data_detail_sekolah(&i);
                cout << "\tApakah Anda Benar Ingin Menghapus Data? (y/n): ";
                cin.ignore() >> konfimasi;

                if (konfimasi == "y"){
                    for (int j = i; j < banyak_sekolah - 1; j++){
                        sekolah[j] = sekolah[j + 1];
                    }
                    banyak_sekolah -= 1;
                    system("cls");
                    setConsoleColor(GREEN);
                    cout << "============================================================" << endl;
                    cout << "================ BERHASIL MENGHAPUS DATA ===================" << endl;
                    cout << "============================================================" << endl;
                    setConsoleColor(BLUE);
                    Sleep(1400);
                    main_menu();

                } else if(konfimasi == "n"){
                    system("cls");
                    setConsoleColor(RED);
                    cout << "============================================================" << endl;
                    cout << "================ PENGHAPUSAN DATA DIBATALKAN ===============" << endl;
                    cout << "============================================================" << endl;
                    setConsoleColor(BLUE);
                    Sleep(1400);
                    main_menu();

                } else {
                    system("cls");
                    setConsoleColor(RED);
                    cout << "============================================================" << endl;
                    cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
                    cout << "============================================================" << endl;
                    setConsoleColor(BLUE);
                    Sleep(1400);
                }
            }
        }
    }
    system("cls");
    setConsoleColor(RED);
    cout << "============================================================" << endl;
    cout << "================== DATA TIDAK DITEMUKAN ====================" << endl;
    cout << "============================================================" << endl;
    setConsoleColor(BLUE);
    Sleep(1400);
    main_menu();
}

void ubah_data(){
    system("cls");
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis, pilih;
    int kode_pos, jumlah_siswa, indeks;
    show_sekolah();
    try{
        cout << "\tMasukkan: ";
        cin >> pilih;

        indeks = stoi(pilih);

    } catch(invalid_argument){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== GAGAL MENGUBAH DATA ====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        main_menu();
    }
    for (int i = 0; i < banyak_sekolah; i++){
        if (indeks - 1 == i){
            system("cls");
            cout << "============================================================" << endl;
            cout << "==================== UBAH DATA SEKOLAH =====================" << endl;
            cout << "============================================================" << endl;
            cout << endl << endl;
            cout << "\tMasukkan Nama Sekolah: ";
            getline(cin.ignore(), nama); sekolah[i].nama = nama;
        
            cout << "\tMasukkan Alamat Sekolah: ";
            getline(cin, alamat); sekolah[i].alamat = alamat;
        
            cout << "\tMasukkan Kelurahan: ";
            getline(cin, kelurahan); sekolah[i].kelurahan = kelurahan;
        
            cout << "\tMasukkan Kecamatan: ";
            getline(cin, kecamatan); sekolah[i].kecamatan = kecamatan;
        
            cout << "\tMasukkan Jenjang Sekolah: ";
            cin >> jenjang; sekolah[i].jenjang_Sekolah = jenjang;
        
            cout << "\tMasukkan Jenis Sekolah: ";
            cin >> jenis; sekolah[i].jenis_sekolah = jenis;
        
            cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
            cin >> kode_pos; sekolah[i].kode_pos = kode_pos;
        
            cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
            cin >> jumlah_siswa; sekolah[i].jumlah_siswa = jumlah_siswa;

            system("cls");
            setConsoleColor(GREEN);
            cout << "============================================================" << endl;
            cout << "============== BERHASIL MENGUBAH DATA SEKOLAH ==============" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            main_menu();
            
        }
    }
    system("cls");
    setConsoleColor(RED);
    cout << "============================================================" << endl;
    cout << "================== DATA TIDAK DITEMUKAN ====================" << endl;
    cout << "============================================================" << endl;
    setConsoleColor(BLUE);
    Sleep(1400);
    main_menu();
}

void tambah_data(){
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis;
    int kode_pos, jumlah_siswa;
    system("cls");
    cout << "============================================================" << endl;
    cout << "=================== TAMBAH DATA SEKOLAH ====================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tMasukkan Nama Sekolah: ";
    getline(cin.ignore(), nama); sekolah[banyak_sekolah].nama = nama;

    cout << "\tMasukkan Alamat Sekolah: ";
    getline(cin, alamat); sekolah[banyak_sekolah].alamat = alamat;

    cout << "\tMasukkan Kelurahan: ";
    getline(cin, kelurahan); sekolah[banyak_sekolah].kelurahan = kelurahan;

    cout << "\tMasukkan Kecamatan: ";
    getline(cin, kecamatan); sekolah[banyak_sekolah].kecamatan = kecamatan;

    cout << "\tMasukkan Jenjang Sekolah: ";
    cin >> jenjang; sekolah[banyak_sekolah].jenjang_Sekolah = jenjang;

    cout << "\tMasukkan Jenis Sekolah: ";
    cin >> jenis; sekolah[banyak_sekolah].jenis_sekolah = jenis;

    cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
    cin >> kode_pos; sekolah[banyak_sekolah].kode_pos = kode_pos;

    cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
    cin >> jumlah_siswa; sekolah[banyak_sekolah].jumlah_siswa = jumlah_siswa;

    while (true){
        string konfimasi;
        system("cls");
        data_detail_sekolah(&banyak_sekolah);
        cout << "\tApakah Anda Benar Ingin Menambahkan Data? (y/n): ";
        cin.ignore() >> konfimasi;

        if (konfimasi == "y"){
            banyak_sekolah += 1;
            system("cls");
            setConsoleColor(GREEN);
            cout << "============================================================" << endl;
            cout << "================= BERHASIL MENAMBAHKAN DATA ================" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            main_menu();

        } else if(konfimasi == "n"){
            system("cls");
            setConsoleColor(RED);
            cout << "============================================================" << endl;
            cout << "================ MENAMBAHKAN DATA DIBATALKAN ===============" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            main_menu();

        } else {
            system("cls");
            setConsoleColor(RED);
            cout << "============================================================" << endl;
            cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
        }
    }
    
}

void main_menu(){
    string pilih;
    system("cls");
    cout << "============================================================" << endl;
    cout << "================= DATA SEKOLAH DI SAMARINDA ================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tPilih Menu" << endl;
    cout << "\t[1] Tampilkan Data Sekolah" << endl;
    cout << "\t[2] Tambah Data Sekolah" << endl;
    cout << "\t[3] Ubah Data Sekolah" << endl;
    cout << "\t[4] Hapus Data Sekolah" << endl;
    cout << "\t[5] Keluar Dari Program" << endl;
    cout << "\tMasukkan: ";
    cin >> pilih;

    if (pilih == "1"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "================== TAMPILKAN DATA SEKOLAH ==================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        tampil_sekolah();

    } else if (pilih == "2"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "=================== TAMBAH DATA SEKOLAH ====================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        tambah_data();

    } else if (pilih == "3"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "==================== UBAH DATA SEKOLAH =====================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        ubah_data();

    } else if (pilih == "4"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "==================== HAPUS DATA SEKOLAH ====================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        hapus_data();

    } else if (pilih == "5"){
        system("cls");
        setConsoleColor(RED);
        cout << "Anda Telah Keluar" << endl;
        setConsoleColor(WHITE);

        exit(0);

    } else {
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "==================== PILIHAN TIDAK ADA =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
    Sleep(1400);
        main_menu();
    }

}

bool check_login(string username, string password){
    if (username == "aldi" && password == "2309106017"){
        return true;

    } else {
        return false;
    }
}

void login(int count){
    system("cls");
    string username, password;
    setConsoleColor(BLUE);
    cout << "==============================================" << endl;
    cout << "==================== LOGIN ===================" << endl;
    cout << "==============================================" << endl;
    cout << endl << endl;
    cout << "\tUsername (aldi): ";
    cin >> username;
    cout << "\tPassword (2309106017): ";
    cin >> password;

    if (check_login(username, password)){
        system("cls");
        setConsoleColor(GREEN);
        cout << "==============================================" << endl;
        cout << "=============== LOGIN BERHASIL ===============" << endl;
        cout << "==============================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        main_menu();

    } else {
        if (count == 3){
            system("cls");
            setConsoleColor(RED);
            cout << "==============================================" << endl;
            cout << "================= GAGAL LOGIN ================" << endl;
            cout << "==============================================" << endl;
            Sleep(1400);
            system("cls");
            cout << "\tAnda Telah Keluar" << endl;
            setConsoleColor(WHITE);
            exit(0);
        }
        system("cls");
        setConsoleColor(RED);
        cout << "==============================================" << endl;
        cout << "================= GAGAL LOGIN ================" << endl;
        cout << "==============================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        login(count + 1);
    }
}

int main(){
    login(1);
}