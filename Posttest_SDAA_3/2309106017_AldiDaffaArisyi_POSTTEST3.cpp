#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

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
    data_sekolah *next;
};

data_sekolah *head = nullptr;

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
void setConsoleColor(int textColor, int bgColor = BLACK){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void data_awal(data_sekolah *&head){
    data_sekolah *simpulBaru = new data_sekolah;
    simpulBaru->nama = "SD NEGERI 009 SAMARINDA";
    simpulBaru->alamat = "Jalan KS Tubun Dalam";
    simpulBaru->kelurahan = "Dadi Mulya";
    simpulBaru->kecamatan = "Samarinda Ulu";
    simpulBaru->jenjang_Sekolah = "SD";
    simpulBaru->jenis_sekolah = "Negeri";
    simpulBaru->kode_pos = 75243;
    simpulBaru->jumlah_siswa = 768;

    simpulBaru->next = head;
    head = simpulBaru;

    simpulBaru = new data_sekolah;
    simpulBaru->nama = "SMP NEGERI 1 SAMARINDA";
    simpulBaru->alamat = "Jalan Drs. H. Anang Hasyim";
    simpulBaru->kelurahan = "Air Hitam";
    simpulBaru->kecamatan = "Samarinda Ulu";
    simpulBaru->jenjang_Sekolah = "SMP";
    simpulBaru->jenis_sekolah = "Negeri";
    simpulBaru->kode_pos = 75124;
    simpulBaru->jumlah_siswa = 1056;

    simpulBaru->next = head;
    head = simpulBaru;

    simpulBaru = new data_sekolah;
    simpulBaru->nama = "SMA NEGERI 1 SAMARINDA";
    simpulBaru->alamat = "Jalan Drs. H. Anang Hasyim";
    simpulBaru->kelurahan = "Air Hitam";
    simpulBaru->kecamatan = "Samarinda Ulu";
    simpulBaru->jenjang_Sekolah = "SMA";
    simpulBaru->jenis_sekolah = "Negeri";
    simpulBaru->kode_pos = 75124;
    simpulBaru->jumlah_siswa = 960;

    simpulBaru->next = head;
    head = simpulBaru;

}

void tampil_linkedList(data_sekolah *head, int indeks){
    if (head == nullptr){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

    int count = 1;
    while (head != nullptr){
        if (count == indeks){
            system("cls");
            cout << "============================================================" << endl;
            cout << "================ LINKED LIST DATA SEKOLAH ==================" << endl;
            cout << "============================================================" << endl;
            cout << "Nama Sekolah    : " << head->nama << endl;
            cout << "Alamat          : " << head->alamat << endl;
            cout << "Kelurahan       : " << head->kelurahan << endl;
            cout << "Kecamatan       : " << head->kecamatan << endl;
            cout << "Jenjang Sekolah : " << head->jenjang_Sekolah << endl;
            cout << "Jenis Sekolah   : " << head->jenis_sekolah << endl;
            cout << "Kode Pos        : " << head->kode_pos << endl;
            cout << "Jumlah Siswa    : " << head->jumlah_siswa << endl;
            cout << "============================================================" << endl;
            return;

        } else {
            system("cls");
            setConsoleColor(RED);
            cout << "============================================================" << endl;
            cout << "==================== PILIHAN TIDAK ADA =====================" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            
        }
        head = head->next;
        count++;
    }
}

void show_sekolah(data_sekolah *head){
    if (head == nullptr){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

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
    int count = 1;
    while (head != nullptr){
        cout << left << setw(5) << count
             << setw(30) << head->nama
             << setw(30) << head->alamat
             << setw(15) << head->kelurahan
             << setw(17) << head->kecamatan
             << setw(10) << head->jenjang_Sekolah
             << setw(8)  << head->jenis_sekolah
             << setw(10) << head->kode_pos
             << setw(15) << head->jumlah_siswa << endl;
        
        head = head->next;
        count++;
    }
    cout << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
    
}

void tampil_sekolah(data_sekolah *head){
    string pilih;
    int angka;
    system("cls");
    show_sekolah(head);
    cout << "\t[back] -> Kembali" << endl;
    cout << "\t[No]   -> Linked List" << endl;
    try {
        cout << "\tMasukkan: ";
        cin >> pilih;

        angka = stoi(pilih);

        tampil_linkedList(head, angka);
        cout << endl;
        cout << "\t Tekan Enter Untuk Kembali";
        getch();
        tampil_sekolah(head);

        setConsoleColor(RED);
        system("cls");
        cout << "============================================================" << endl;
        cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        tampil_sekolah(head);


    } catch (invalid_argument){
        if (pilih == "back"){
            system("cls");
            cout << "============================================================" << endl;
            cout << "========================== KEMBALI =========================" << endl;
            cout << "============================================================" << endl;
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
            tampil_sekolah(head);
        }
    }
}

void hapus_depan(data_sekolah *&head){
    if (head == nullptr){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

    data_sekolah *temp = head;
    head = head->next;
    delete temp;

    system("cls");
    setConsoleColor(GREEN);
    cout << "============================================================" << endl;
    cout << "================= BERHASIL MENGHAPUS DATA ==================" << endl;
    cout << "============================================================" << endl;
    setConsoleColor(BLUE);
    Sleep(1400);
    main_menu();
}

void hapus_belakang(data_sekolah *head){
    if (head == nullptr){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

    data_sekolah *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    system("cls");
    setConsoleColor(GREEN);
    cout << "============================================================" << endl;
    cout << "================= BERHASIL MENGHAPUS DATA ==================" << endl;
    cout << "============================================================" << endl;
    setConsoleColor(BLUE);
    Sleep(1400);
    main_menu();
}

void ubah_data(data_sekolah *head){
    system("cls");
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis, pilih;
    int kode_pos, jumlah_siswa, indeks;
    show_sekolah(head);
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
    int count = 1;
    while (head != nullptr){
        if (count == indeks){
            system("cls");
            cout << "============================================================" << endl;
            cout << "==================== UBAH DATA SEKOLAH =====================" << endl;
            cout << "============================================================" << endl;
            cout << endl << endl;
            cout << "\tMasukkan Nama Sekolah: ";
            getline(cin.ignore(), nama); head->nama = nama;
        
            cout << "\tMasukkan Alamat Sekolah: ";
            getline(cin, alamat); head->alamat = alamat;
        
            cout << "\tMasukkan Kelurahan: ";
            getline(cin, kelurahan); head->kelurahan = kelurahan;
        
            cout << "\tMasukkan Kecamatan: ";
            getline(cin, kecamatan); head->kecamatan = kecamatan;
        
            cout << "\tMasukkan Jenjang Sekolah: ";
            cin >> jenjang; head->jenjang_Sekolah = jenjang;
        
            cout << "\tMasukkan Jenis Sekolah: ";
            cin >> jenis; head->jenis_sekolah = jenis;
        
            cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
            cin >> kode_pos; head->kode_pos = kode_pos;
        
            cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
            cin >> jumlah_siswa; head->jumlah_siswa = jumlah_siswa;

            system("cls");
            setConsoleColor(GREEN);
            cout << "============================================================" << endl;
            cout << "============== BERHASIL MENGUBAH DATA SEKOLAH ==============" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            main_menu();
        }
        head = head->next;
        count++;
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

void tambah_belakang(data_sekolah *&head){
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis;
    int kode_pos, jumlah_siswa;
    data_sekolah *simpulBaru = new data_sekolah;
    system("cls");
    cout << "============================================================" << endl;
    cout << "=================== TAMBAH DATA SEKOLAH ====================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tMasukkan Nama Sekolah: ";
    getline(cin.ignore(), nama); simpulBaru->nama = nama;

    cout << "\tMasukkan Alamat Sekolah: ";
    getline(cin, alamat); simpulBaru->alamat = alamat;

    cout << "\tMasukkan Kelurahan: ";
    getline(cin, kelurahan); simpulBaru->kelurahan = kelurahan;

    cout << "\tMasukkan Kecamatan: ";
    getline(cin, kecamatan); simpulBaru->kecamatan = kecamatan;

    cout << "\tMasukkan Jenjang Sekolah: ";
    cin >> jenjang; simpulBaru->jenjang_Sekolah = jenjang;

    cout << "\tMasukkan Jenis Sekolah: ";
    cin >> jenis; simpulBaru->jenis_sekolah = jenis;

    cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
    cin >> kode_pos; simpulBaru->kode_pos = kode_pos;

    cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
    cin >> jumlah_siswa; simpulBaru->jumlah_siswa = jumlah_siswa;

    while (true){
        string konfimasi;
        system("cls");
        cout << "\tApakah Anda Benar Ingin Menambahkan Data? (y/n): ";
        cin.ignore() >> konfimasi;

        if (konfimasi == "y"){
            simpulBaru->next = nullptr;

            if (head == nullptr){
                head = simpulBaru;
                return;
            }

            data_sekolah *temp = head;
            while (temp->next != nullptr){
                temp = temp->next; 
            }
            temp->next = simpulBaru;
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

void tambah_depan(data_sekolah *&head){
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis;
    int kode_pos, jumlah_siswa;
    data_sekolah *simpulBaru = new data_sekolah;
    system("cls");
    cout << "============================================================" << endl;
    cout << "=================== TAMBAH DATA SEKOLAH ====================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tMasukkan Nama Sekolah: ";
    getline(cin.ignore(), nama); simpulBaru->nama = nama;

    cout << "\tMasukkan Alamat Sekolah: ";
    getline(cin, alamat); simpulBaru->alamat = alamat;

    cout << "\tMasukkan Kelurahan: ";
    getline(cin, kelurahan); simpulBaru->kelurahan = kelurahan;

    cout << "\tMasukkan Kecamatan: ";
    getline(cin, kecamatan); simpulBaru->kecamatan = kecamatan;

    cout << "\tMasukkan Jenjang Sekolah: ";
    cin >> jenjang; simpulBaru->jenjang_Sekolah = jenjang;

    cout << "\tMasukkan Jenis Sekolah: ";
    cin >> jenis; simpulBaru->jenis_sekolah = jenis;

    cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
    cin >> kode_pos; simpulBaru->kode_pos = kode_pos;

    cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
    cin >> jumlah_siswa; simpulBaru->jumlah_siswa = jumlah_siswa;

    while (true){
        string konfimasi;
        system("cls");
        cout << "\tApakah Anda Benar Ingin Menambahkan Data? (y/n): ";
        cin.ignore() >> konfimasi;

        if (konfimasi == "y"){
            simpulBaru->next = head;
            head = simpulBaru;

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
    cout << "\t[2] Tambah Data Sekolah (Depan)" << endl;
    cout << "\t[3] Tambah Data Sekolah (Belakang)" << endl;
    cout << "\t[4] Ubah Data Sekolah"<< endl;
    cout << "\t[5] Hapus Data Sekolah (Belakang)" << endl;
    cout << "\t[6] Hapus Data Sekolah (Depan)" << endl;
    cout << "\t[7] Keluar Dari Program" << endl;
    cout << "\tMasukkan: ";
    cin >> pilih;

    if (pilih == "1"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "================== TAMPILKAN DATA SEKOLAH ==================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        tampil_sekolah(head);

    } else if (pilih == "2"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "================ TAMBAH DEPAN DATA SEKOLAH =================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        tambah_depan(head);

    } else if (pilih == "3"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "============== TAMBAH BELAKANG DATA SEKOLAH ================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        tambah_belakang(head);

    } else if (pilih == "4"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "==================== UBAH DATA SEKOLAH =====================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        ubah_data(head);

    } else if (pilih == "5"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "=============== HAPUS DEPAN DATA SEKOLAH ================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        hapus_depan(head);

    } else if (pilih == "6"){
        system("cls");
        cout << "============================================================" << endl;
        cout << "=============== HAPUS BELAKANG DATA SEKOLAH ================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        hapus_belakang(head);

    } else if (pilih == "7"){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "==================== ANDA TELAH KELUAR =====================" << endl;
        cout << "============================================================" << endl;
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
            setConsoleColor(RED);
            cout << "============================================================" << endl;
            cout << "==================== ANDA TELAH KELUAR =====================" << endl;
            cout << "============================================================" << endl;
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
    data_awal(head);
    login(1);
}