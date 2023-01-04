#include "film.h"
#include "sutradara.h"

#include <iostream>

using namespace std;

int main(){
    listSutradara LS;
    listFilm LF;

    adrSutradara PSutradara;
    adrFilm pFilm;
    adrRelasi pRelasi;

    infoSutradara infoStr;
    infoFilm infoFilm;
    char kembali;

    int menu;
    int angka,i,kodeFilm;

    string namaStr,judul,umur;

    createListSutradara(LS);
    createListFilm(LF);

    menu = menuPilihan();

    while (menu != 0){
        switch (menu){
            case 1:{
                i =1;
                cout<<"Masukan jumlah Sutradara: ";
                cin>> angka;
                cout<<endl;

                while(i<=angka){
                    cout<<"Data Sutradara ke-"<<i<<endl;
                    inputSutradara(infoStr);
                    PSutradara = elementSutradara(infoStr);
                    insertLastSutradara(LS,PSutradara);
                    i++;
                }
                break;
            }
            case 2:{
                i=1;
                cout<<"Masukan data film: ";
                cin>> angka;
                cout<<endl;

                while(i<=angka){
                    cout<<"Data Film ke-"<<i<<endl;
                    inputFilm(infoFilm);
                    pFilm = elementFilm(infoFilm);
                    insertLastFilm(LF, pFilm);
                    i++;
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"Input jumlah data: ";
                cin>> angka;
                cout<<endl;
                while(i<angka){
                    cout<<"Data :"<<endl;
                    tambahDataRelasi(namaStr,umur,judul,kodeFilm);
                    PSutradara = cariElmSutradara(LS,namaStr,umur);
                    pFilm = cariElmFilm(LF,kodeFilm,judul);
                    pRelasi = elementRelasi(pFilm);
                    insertLastRelasi(child(PSutradara),pRelasi );
                    i++;
                }
                break;
            }
            case 7:{
                showSemua(LS);
            }
            }
            cout << endl<< "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;

            if (kembali == 'Y'){
                cout << endl;
                menu = menuPilihan();
            }
            else if (kembali == 'N'){
                menu = 0;
            }
        }
        cout << endl<< "Program Telah Berakhir"<<endl;
    return 0;
}
