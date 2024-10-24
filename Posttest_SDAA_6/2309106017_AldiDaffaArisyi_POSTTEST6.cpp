#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <bits/stdc++.h>
#include <math.h>

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
simpul *gabung(simpul *kiri, simpul *kanan);
bool bandingkan_merge(simpul *data1, simpul *data2);
void tampil_sekolah();

void quick_sort(simpul *&head, int &counter);
bool bandingkan_quick(simpul *data1, simpul *data2);
simpul *ambil_tail(simpul *current);
simpul *bagi(simpul *head, simpul *end, simpul *&head_baru, simpul *&akhir_baru, int counter);

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


const int chars = 256;
void badcharacter(string str, int size, int badchar[chars]){
    for (int i = 0; i < chars; i++){
        badchar[i] = -1;
    }
    for (int i = 0; i < size; i++){
        badchar[(int)str[i]] = i;
    }
}
 
void cari_string(simpul *head, string pat){
    int m = pat.size();
    simpul *temp = head;
    while (temp != NULL){
        int n = temp->sekolah.nama.size();
        int badchar[chars];
        badcharacter(pat, m, badchar);
        int s = 0;
 
        while (s <= (n - m)){
            int j = m - 1;
            while (j >= 0 && pat[j] == temp->sekolah.nama[s + j]){
                j--;
            }
            if (j < 0){
                cout << "\t" << temp->sekolah.nama << endl;
                break;
            } else {
                s += max(1, j - badchar[temp->sekolah.nama[s + j]]);
            }
        }
        temp = temp->next;
    }
}

int panjang_simpul(simpul *head){
    int count = 0;
    simpul *temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int cari_simpul(simpul *head, int index){
    for (int i = 0; i < index; i++){
        head = head->next;
    }
    return head->sekolah.jumlah_siswa;
}

int jump_search_ascending(simpul *head, int angka, int panjang_simpul){
    int step = sqrt(panjang_simpul);
    int prev = 0;
 
    int index = min(step, panjang_simpul) - 1;
    while (cari_simpul(head, index) < angka){
        prev = step;
        step += sqrt(panjang_simpul);
        index = min(step, panjang_simpul) - 1;
        if (prev >= panjang_simpul){
            return -1;
        }
    }
    while (cari_simpul(head, prev) < angka){
        prev++;
    }
    if (cari_simpul(head, prev) == angka){
        return prev;
    }
    return -1;
}

int fibonaci_search_descending(simpul *head, int angka, int panjang_simpul){
    simpul *temp = head;
    int fibonaci1 = 0;
    int fibonaci2 = 1;
    int f1f2 = fibonaci1 + fibonaci2;
    while (f1f2 < panjang_simpul){
        fibonaci1 = fibonaci2;
        fibonaci2 = f1f2;
        f1f2 = fibonaci1 + fibonaci2;
    }
    int offset = -1;
    while (f1f2 > 1){
        int i = min(offset + fibonaci1, panjang_simpul - 1);
 
        temp = head;
        for (int j = 0; j < i; j++){
            temp = temp->next;
        }
        if (temp->sekolah.jumlah_siswa > angka){
            f1f2 = fibonaci2;
            fibonaci2 = fibonaci1;
            fibonaci1 = f1f2 - fibonaci2;
            offset = i;
        } else if (temp->sekolah.jumlah_siswa < angka){
            f1f2 = fibonaci1;
            fibonaci2 = fibonaci2 - fibonaci1;
            fibonaci1 = f1f2 - fibonaci2;
        } else
            return i;
    }
    temp = head;
    for (int j = 0; j < offset + 1; j++){
        temp = temp->next;
    }
    if (fibonaci2 && temp->sekolah.jumlah_siswa == angka)
        return offset + 1;
    return -1;
}

simpul *rekursif(simpul *head, simpul *akhir, int &counter){
    counter++;
    if (!head || head == akhir){
        counter--;
        return head;
    }

    simpul *head_baru = nullptr;
    simpul *akhir_baru = nullptr;
    simpul *pivot = bagi(head, akhir, head_baru, akhir_baru, counter);

    if (head_baru != pivot){
        simpul *temp = head_baru;
        while (temp->next != pivot){
            temp = temp->next;
        }
        temp->next = nullptr;
        head_baru = rekursif(head_baru, temp, counter);
        temp = ambil_tail(head_baru);
        temp->next = pivot;
    }
    pivot->next = rekursif(pivot->next, akhir_baru, counter);
    counter--;
    return head_baru;
}

void quick_sort(simpul *&head, int &counter){
    head = rekursif(head, ambil_tail(head), counter);
    return;
}

simpul *ambil_tail(simpul *current){
    while (current && current->next){
        current = current->next;
    }
    return current;
}

simpul *bagi(simpul *head, simpul *akhir, simpul *&head_baru, simpul *&akhir_baru, int counter){
    simpul *pivot = akhir;
    simpul *prev = nullptr;
    simpul *current = head;
    simpul *tail = pivot;

    while (current != pivot){
        if (bandingkan_quick(current, pivot)){
            if (head_baru == nullptr){
                head_baru = current;
            }
            prev = current;
            current = current->next;
        }
        else{
            if (prev){
                prev->next = current->next;
            }
            simpul *temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (head_baru == nullptr){
        head_baru = pivot;
    }
    akhir_baru = tail;
    return pivot;
}

bool bandingkan_quick(simpul *data1, simpul *data2){
    return data1->sekolah.jumlah_siswa > data2->sekolah.jumlah_siswa;
}

void merge_sort(simpul *&head, int &counter){
    counter++;
    if (!head || !head->next){
        counter--;
        return;
    }

    simpul *lewati1 = head;
    simpul *lewati2 = head->next;
    while (lewati2 && lewati2->next){
        lewati1 = lewati1->next;
        lewati2 = lewati2->next->next;
    }
    simpul *tengah = lewati1->next;
    lewati1->next = nullptr;

    merge_sort(head, counter);
    merge_sort(tengah, counter);

    head = gabung(head, tengah);
    counter--;
}

simpul *gabung(simpul *kiri, simpul *kanan){
    simpul *temp = new simpul;
    simpul *tail = temp;
    while (kiri && kanan){
        if (bandingkan_merge(kiri, kanan)){
            tail->next = kiri;
            kiri = kiri->next;
        }

        else{
            tail->next = kanan;
            kanan = kanan->next;
        }
        tail = tail->next;
    }

    tail->next = kiri ? kiri : kanan;

    simpul *result = temp->next;
    delete temp;
    return result;
}

bool bandingkan_merge(simpul *data1, simpul *data2){
    return data1->sekolah.jumlah_siswa <= data2->sekolah.jumlah_siswa;
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
            if (kosong()){
                simpul *baru = new simpul;
                baru->sekolah = sekolah;
                baru->next = NULL;
                last = baru;
                head = baru;

            } else if (last->next != NULL){
                simpul *baru = new simpul;
                baru->sekolah = sekolah;
                baru->next = NULL;
                last->next->next = baru;
                last = baru;
            
            } else {
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

void menu_search(string type){
    string cari;
    int angka;
    int index;
    while (true){
        system("cls");
        show_sekolah();
        try{
            cout << "\t[back]           -> Kembali" << endl;
            cout << "\t[Jumlah Siswa]   -> Search Angka" << endl;
            cout << "\t[Nama Sekolah]   -> Search String" << endl;
            cout << "\tSearch: ";

            getline(cin, cari);
            
            angka = stoi(cari);

            if (type == "asc"){
                index = jump_search_ascending(head, angka, panjang_simpul(head));
                if (index >= 0){
                    cout << endl;
                    cout << "\tData sekolah dengan jumlah siswa " << angka << " ditemukan di indeks ke " << index << endl;
                    cout << endl;
                    cout << "\tTekan Enter Untuk Kembali";
                    getch();

                } else{
                    cout << endl;
                    cout << "\tData sekolah dengan jumlah siswa " << angka << " Tidak ditemukan" << endl;
                    cout << endl;
                    cout << "\tTekan Enter Untuk Kembali";
                    getch();
                }

            } else if (type == "desc"){
                index = fibonaci_search_descending(head, angka, panjang_simpul(head));
                if (index >= 0){
                    cout << endl;
                    cout << "\tData sekolah dengan jumlah siswa " << angka << " ditemukan di indeks ke " << index << endl;
                    cout << endl;
                    cout << "\tTekan Enter Untuk Kembali";
                    getch();

                } else{
                    cout << endl;
                    cout << "\tData sekolah dengan jumlah siswa " << angka << " Tidak ditemukan" << endl;
                    cout << endl;
                    cout << "\tTekan Enter Untuk Kembali";
                    getch();
                }
            }

        } catch (invalid_argument){
            if (cari == "back"){
                system("cls");
                cout << "============================================================" << endl;
                cout << "========================== KEMBALI =========================" << endl;
                cout << "============================================================" << endl;
                Sleep(1400);
                main_menu();

            } else if (cari == " " || cari == ""){
                system("cls");

            } else {
                cari_string(head, cari);
                cout << endl;
                cout << "\tTekan Enter Untuk Kembali";
                getch();
            }
        }   
    }
}

void menu_sorting(){
    string pilih;
    int counter = 0;
    string type;
    while (true){
        cout << "\tPilih Sorting:" << endl;
        cout << "\t[asc]    -> Sort Ascending Merge Sort" << endl;
        cout << "\t[desc]   -> Sort Descending Quick Sort" << endl;
        cout << "\t[back]   -> Kembali" << endl;
        cout << "\tMasukkan: ";
        cin >> pilih;

        if (pilih == "asc"){
            system("cls");
            cout << "============================================================" << endl;
            cout << "===================== SORTING ASCENDING ====================" << endl;
            cout << "============================================================" << endl;
            Sleep(1400);
            merge_sort(head, counter);
            system("cls");
            cout << "============================================================" << endl;
            cout << "================ BERHASIL SORTING ASCENDING ================" << endl;
            cout << "============================================================" << endl;
            Sleep(1400);
            type = "asc";
            menu_search(type);

        } else if (pilih == "desc"){
            system("cls");
            cout << "============================================================" << endl;
            cout << "==================== SORTING DESCENDING ====================" << endl;
            cout << "============================================================" << endl;
            Sleep(1400);
            quick_sort(head, counter);
            system("cls");
            cout << "============================================================" << endl;
            cout << "================ BERHASIL SORTING DESCENDING ===============" << endl;
            cout << "============================================================" << endl;
            Sleep(1400);
            type = "desc";
            menu_search(type);

        } else if (pilih == "back"){
            system("cls");
            cout << "============================================================" << endl;
            cout << "========================== KEMBALI =========================" << endl;
            cout << "============================================================" << endl;
            Sleep(1400);
            tampil_sekolah();

        } else {
            setConsoleColor(RED);
            system("cls");
            cout << "============================================================" << endl;
            cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);
            
        }
    }
}

void tampil_sekolah(){
    string pilih;
    int angka;
    while (true){
        system("cls");
        show_sekolah();
        cout << "\t[back]   -> Kembali" << endl;
        cout << "\t[sort]   -> Sorting" << endl;

        try {
            cout << "\tMasukkan: ";
            cin >> pilih;

            angka = stoi(pilih);

            setConsoleColor(RED);
            system("cls");
            cout << "============================================================" << endl;
            cout << "===================== PILIHAN TIDAK ADA ====================" << endl;
            cout << "============================================================" << endl;
            setConsoleColor(BLUE);
            Sleep(1400);

        } catch (invalid_argument){
            if (pilih == "back"){
                system("cls");
                cout << "============================================================" << endl;
                cout << "========================== KEMBALI =========================" << endl;
                cout << "============================================================" << endl;
                Sleep(1400);
                main_menu();

            } else if (pilih == "sort"){
                system("cls");
                cout << "============================================================" << endl;
                cout << "======================= MENU SORTING =======================" << endl;
                cout << "============================================================" << endl;
                Sleep(1400);
                menu_sorting();
            
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