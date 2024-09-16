#include <iostream>


using namespace std;

string menara_asal[3] = {"Besar", "Sedang", "Kecil"};
string menara_sementara[3] = {"-", "-", "-"};
string menara_tujuan[3] = {"-", "-", "-"}; 
int indeks;

void isi_menara();

void menara_hanoi(int banyak_piring, string asal, string tujuan, string sementara){
    if (banyak_piring == 1){
        cout << "Pindahkan piringan kecil dari Menara " << asal << " ke Menara " << tujuan;
        if (asal == "Asal"){
            menara_tujuan[indeks] = menara_asal[banyak_piring + 1]; 
            menara_asal[banyak_piring + 1] = "-";

        } else if (asal == "Tujuan"){
            menara_sementara[indeks] = menara_tujuan[banyak_piring + 1];
            menara_tujuan[banyak_piring + 1] = "-";

        } else if (asal == "Sementara"){
            menara_asal[indeks] = menara_sementara[banyak_piring + 1];
            menara_sementara[banyak_piring + 1] = "-";
        }
        
        isi_menara();
        cout << endl;
        return;
    }
    
    indeks = banyak_piring;
    menara_hanoi(banyak_piring - 1, asal, sementara, tujuan);
    if (banyak_piring == 2){
        cout << "Pindahkan piringan sedang dari Menara " << asal << " ke Menara " << tujuan;
        if (asal == "Asal"){
            menara_sementara[indeks - 1] = menara_asal[banyak_piring - 1];
            menara_asal[banyak_piring - 1] = "-";

        } else if (asal == "Sementara"){
            menara_tujuan[indeks - 1] = menara_sementara[banyak_piring - 1];
            menara_sementara[banyak_piring - 1] = "-";
        }
        isi_menara();
        cout << endl;

    } else if (banyak_piring == 3){
        cout << "Pindahkan piringan besar dari Menara " << asal << " ke Menara " << tujuan;
        menara_tujuan[indeks - 2] = menara_asal[banyak_piring - 3];
        menara_asal[banyak_piring - 3] = "-";
        isi_menara();
        cout << endl;
    }
        
    menara_hanoi(banyak_piring - 1, sementara, tujuan, asal);
}

void isi_menara(){
    cout << "\nMenara Asal: ";
    for (int i = 0; i < 3; i++){
        cout << menara_asal[i] << " ";
    }
    cout << "\nMenara Sementara: ";
    for (int i = 0; i < 3; i++){
        cout << menara_sementara[i] << " ";
    }
    cout << "\nMenara Tujuan: ";
    for (int i = 0; i < 3; i++){
        cout << menara_tujuan[i] << " ";
    }
    cout << endl;
}

int main(){
    int banyak_piring = 3; 
    cout << "Sebelum diselesaikan:";
    isi_menara();

    cout << "\nProses Penyelesaian:\n" << endl;
    menara_hanoi(banyak_piring, "Asal", "Tujuan", "Sementara");
    return 0;
}
