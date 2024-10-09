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
};

struct simpul{
    data_sekolah sekolah;
    simpul *next;
};

struct simpul*head = NULL;
struct simpul*last = NULL;

bool kosong(){
    return head == NULL;
}

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

void setConsoleColor(int textColor, int bgColor = BLACK){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void push(data_sekolah sekolah){
    string nama, alamat, kelurahan, kecamatan, jenjang, jenis;
    int kode_pos, jumlah_siswa;
    system("cls");
    cout << "============================================================" << endl;
    cout << "=================== TAMBAH DATA SEKOLAH ====================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tMasukkan Nama Sekolah: ";
    getline(cin.ignore(), nama); sekolah.nama = nama;

    cout << "\tMasukkan Alamat Sekolah: ";
    getline(cin, alamat); sekolah.alamat = alamat;

    cout << "\tMasukkan Kelurahan: ";
    getline(cin, kelurahan); sekolah.kelurahan = kelurahan;

    cout << "\tMasukkan Kecamatan: ";
    getline(cin, kecamatan); sekolah.kecamatan = kecamatan;

    cout << "\tMasukkan Jenjang Sekolah: ";
    cin >> jenjang; sekolah.jenjang_Sekolah = jenjang;

    cout << "\tMasukkan Jenis Sekolah: ";
    cin >> jenis; sekolah.jenis_sekolah = jenis;

    cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
    cin >> kode_pos; sekolah.kode_pos = kode_pos;

    cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
    cin >> jumlah_siswa; sekolah.jumlah_siswa = jumlah_siswa;

    while (true){
        string konfimasi;
        system("cls");
        cout << "\tApakah Anda Benar Ingin Menambahkan Data? (y/n): ";
        cin.ignore() >> konfimasi;

        if (konfimasi == "y"){
            if(kosong()){
                simpul *baru = new simpul;
                baru->sekolah = sekolah;
                baru->next = NULL;
                last = baru;
                head = baru;
            }
            else{
                simpul *baru = new simpul;
                baru->sekolah = sekolah;
                baru->next = NULL;
                last->next = baru;
                last = baru;
            }
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

void Dequeue(data_sekolah sekolah){
    if(kosong()){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "===================== QUEUE MASIH KOSONG ===================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        return;
    }
    else if(head==last){
        delete head;
        head = NULL;
        last = NULL;

        system("cls");
        setConsoleColor(GREEN);
        cout << "============================================================" << endl;
        cout << "============== BERHASIL MENGHAPUS DATA SEKOLAH =============" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        main_menu();
    }
    else{
        simpul*temp = head;
        head = head->next;
        delete temp;

        system("cls");
        setConsoleColor(GREEN);
        cout << "============================================================" << endl;
        cout << "============== BERHASIL MENGHAPUS DATA SEKOLAH =============" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        main_menu();
    }
}

void data_awal1(data_sekolah sekolah){
    sekolah.nama = "SD NEGERI 009 SAMARINDA";
    sekolah.alamat = "Jalan KS Tubun Dalam";
    sekolah.kelurahan = "Dadi Mulya";
    sekolah.kecamatan = "Samarinda Ulu";
    sekolah.jenjang_Sekolah = "SD";
    sekolah.jenis_sekolah = "Negeri";
    sekolah.kode_pos = 75243;
    sekolah.jumlah_siswa = 768;

    simpul *baru = new simpul;
    baru->sekolah = sekolah;
    baru->next = NULL;
    last = baru;
    head = baru;
}
    
void data_awal2(data_sekolah sekolah){
    sekolah.nama = "SMP NEGERI 1 SAMARINDA";
    sekolah.alamat = "Jalan Drs. H. Anang Hasyim";
    sekolah.kelurahan = "Air Hitam";
    sekolah.kecamatan = "Samarinda Ulu";
    sekolah.jenjang_Sekolah = "SMP";
    sekolah.jenis_sekolah = "Negeri";
    sekolah.kode_pos = 75124;
    sekolah.jumlah_siswa = 1056;

    simpul *baru = new simpul;
    baru->sekolah = sekolah;
    baru->next = NULL;
    last->next = baru;
    last = baru;
}
    
void data_awal3(data_sekolah sekolah){
    sekolah.nama = "SMA NEGERI 1 SAMARINDA";
    sekolah.alamat = "Jalan Drs. H. Anang Hasyim";
    sekolah.kelurahan = "Air Hitam";
    sekolah.kecamatan = "Samarinda Ulu";
    sekolah.jenjang_Sekolah = "SMA";
    sekolah.jenis_sekolah = "Negeri";
    sekolah.kode_pos = 75124;
    sekolah.jumlah_siswa = 960;

    simpul *baru = new simpul;
    baru->sekolah = sekolah;
    baru->next = NULL;
    last->next = baru;
    last = baru;
}

void tampil_linkedList(int indeks){
    if (head == nullptr){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

    simpul *temp = head;
    int count = 1;
    while (temp != NULL){
        if (count == indeks){
            system("cls");
            cout << "============================================================" << endl;
            cout << "================ LINKED LIST DATA SEKOLAH ==================" << endl;
            cout << "============================================================" << endl;
            cout << "Nama Sekolah    : " << temp->sekolah.nama << endl;
            cout << "Alamat          : " << temp->sekolah.alamat << endl;
            cout << "Kelurahan       : " << temp->sekolah.kelurahan << endl;
            cout << "Kecamatan       : " << temp->sekolah.kecamatan << endl;
            cout << "Jenjang Sekolah : " << temp->sekolah.jenjang_Sekolah << endl;
            cout << "Jenis Sekolah   : " << temp->sekolah.jenis_sekolah << endl;
            cout << "Kode Pos        : " << temp->sekolah.kode_pos << endl;
            cout << "Jumlah Siswa    : " << temp->sekolah.jumlah_siswa << endl;
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
        temp = temp->next;
        count++;
    }
}

void show_sekolah(){
    if (kosong()){
        system("cls");
        setConsoleColor(RED);
        cout << "============================================================" << endl;
        cout << "=================== LINKED LIST KOSONG =====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        return;
    }

    simpul *temp = head;
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
    while (temp != NULL){
        cout << left << setw(5) << count
             << setw(30) << temp->sekolah.nama
             << setw(30) << temp->sekolah.alamat
             << setw(15) << temp->sekolah.kelurahan
             << setw(17) << temp->sekolah.kecamatan
             << setw(10) << temp->sekolah.jenjang_Sekolah
             << setw(8)  << temp->sekolah.jenis_sekolah
             << setw(10) << temp->sekolah.kode_pos
             << setw(15) << temp->sekolah.jumlah_siswa << endl;
        
        temp = temp->next;
        count++;
    }
    cout << setfill('=') << setw(140) << "=" << setfill(' ') << endl;
    
}

void tampil_sekolah(){
    string pilih;
    int angka;
    system("cls");
    show_sekolah();
    cout << "\t[back] -> Kembali" << endl;
    cout << "\t[No]   -> Linked List" << endl;
    try {
        cout << "\tMasukkan: ";
        cin >> pilih;

        angka = stoi(pilih);

        tampil_linkedList(angka);
        cout << endl;
        cout << "\t Tekan Enter Untuk Kembali";
        getch();
        tampil_sekolah();

        setConsoleColor(RED);
        system("cls");
        cout << "============================================================" << endl;
        cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
        cout << "============================================================" << endl;
        setConsoleColor(BLUE);
        Sleep(1400);
        tampil_sekolah();


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
            tampil_sekolah();
        }
    }
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

    simpul *temp = head;
    int count = 1;
    while (temp != NULL){
        if (count == indeks){
            system("cls");
            cout << "============================================================" << endl;
            cout << "==================== UBAH DATA SEKOLAH =====================" << endl;
            cout << "============================================================" << endl;
            cout << endl << endl;
            cout << "\tMasukkan Nama Sekolah: ";
            getline(cin.ignore(), nama); temp->sekolah.nama = nama;
        
            cout << "\tMasukkan Alamat Sekolah: ";
            getline(cin, alamat); temp->sekolah.alamat = alamat;
        
            cout << "\tMasukkan Kelurahan: ";
            getline(cin, kelurahan); temp->sekolah.kelurahan = kelurahan;
        
            cout << "\tMasukkan Kecamatan: ";
            getline(cin, kecamatan); temp->sekolah.kecamatan = kecamatan;
        
            cout << "\tMasukkan Jenjang Sekolah: ";
            cin >> jenjang; temp->sekolah.jenjang_Sekolah = jenjang;
        
            cout << "\tMasukkan Jenis Sekolah: ";
            cin >> jenis; temp->sekolah.jenis_sekolah = jenis;
        
            cout << "\tMasukkan Kode Pos Sekolah (WAJIB ANGKA): ";
            cin >> kode_pos; temp->sekolah.kode_pos = kode_pos;
        
            cout << "\tMasukkan Jumlah Siswa (WAJIB ANGKA): ";
            cin >> jumlah_siswa; temp->sekolah.jumlah_siswa = jumlah_siswa;

            system("cls");
            setConsoleColor(GREEN);
            cout << "============================================================" << endl;
            cout << "============== BERHASIL MENGUBAH DATA SEKOLAH ==============" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            main_menu();
        }
        temp = temp->next;
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

void main_menu(){
    string pilih;
    data_sekolah sekolah;
    system("cls");
    cout << "============================================================" << endl;
    cout << "================= DATA SEKOLAH DI SAMARINDA ================" << endl;
    cout << "============================================================" << endl;
    cout << endl << endl;
    cout << "\tPilih Menu" << endl;
    cout << "\t[1] Tampilkan Data Sekolah" << endl;
    cout << "\t[2] Tambah Data Sekolah (PUSH)" << endl;
    cout << "\t[3] Ubah Data Sekolah (Show)"<< endl;
    cout << "\t[4] Hapus Data Sekolah (DEQUEUE)" << endl;
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
        cout << "============== TAMBAH BELAKANG DATA SEKOLAH ================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        push(sekolah);

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
        cout << "================= HAPUS DEPAN DATA SEKOLAH =================" << endl;
        cout << "============================================================" << endl;
        Sleep(1400);
        Dequeue(sekolah);

    } else if (pilih == "5"){
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
    data_sekolah sekolah;
    data_awal1(sekolah);
    data_awal2(sekolah);
    data_awal3(sekolah);
    login(1);
}