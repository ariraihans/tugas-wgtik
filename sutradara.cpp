#include "sutradara.h"

void createListSutradara(listSutradara &LS){
    first(LS) = nil;
};

adrSutradara elementSutradara(infoSutradara iSutradra){
    adrSutradara adrS;
    adrS = new elmSutrada;
    infoSutradara(adrS) = iSutradra;
    next(adrS) = nil;
    createRelasi(child(adrS));

    return adrS;
};

void insertLastSutradara(listSutradara &LS, adrSutradara iSutradara){
    if(first(LS)== nil){
        first(LS) = iSutradara;
    }else{
        adrSutradara adrS;
        adrS = first(LS);
        while(next(adrS)!=nil){
            adrS = next(adrS);
        }
        next(adrS) = iSutradara;
    }
};

void deleteLastSutradara(listSutradara &LS, adrSutradara &iSutrdara){
    adrSutradara adrS;
    adrS = first(LS);

    while(next(next(adrS))!=nil){
        adrS = next(adrS);
    }
    iSutrdara = next(adrS);
    next(adrS) = nil;
};

void showSutradara(listSutradara LS){
    if(first(LS)== nil){
        cout<<"List Data Tidak Ada"<<endl;
    }else{
        adrSutradara adrS;
        adrS = first(LS);
        cout<<"Data Sutrada"<<endl;
        while(adrS !=nil){
            cout<<"Nama Sutradara: "<<infoSutradara(adrS).nama<<endl;
            cout<<"Umur Sutradara: "<<infoSutradara(adrS).umur<<endl<<endl;
            cout<<"Lama Berkarir: "<<infoSutradara(adrS).lamaKarir<<" Tahun"<<endl<<endl;
            adrS = next(adrS);
        }
    }
};

adrSutradara cariElmSutradara(listSutradara &LS, string nama, string age){
    adrSutradara adrS;
    adrS = first(LS);
    while (adrS!=nil) {
        if(infoSutradara(adrS).nama == nama && infoSutradara(adrS).umur == age){
            return adrS;
            break;
        }
        adrS = next(adrS);
    }
    return  nil;
};

infoSutradara inputSutradara(infoSutradara &input){
    cout<<"Nama Sutradara: ";
    cin>> input.nama;
    cout<<"Umur Sutradara: ";
    cin>> input.umur;
    cout<<"Lama Karir: ";
    cin>> input.lamaKarir;
    cout<<endl;

    return input;
};

void createRelasi(listRelasi &LR){
    first(LR) = nil;
};

adrRelasi elementRelasi(adrFilm elRelasi){
    adrRelasi Rel = new elmRelasi;
    infoFilm(Rel) = elRelasi;
    next(Rel) = nil;

    return Rel;
};

void insertLastRelasi(listRelasi &LR, adrRelasi iRelasi){
    if(first(LR)==nil){
        first(LR) = iRelasi;
    }else{
        adrRelasi rel;
        rel = first(LR);
        while(next(rel)!=nil){
            rel = next(rel);
        }
        next(rel) = rel;
    }
};

void showSemua(listSutradara Lstr){
    adrSutradara p = first(Lstr);

    if (p==nil){
        cout<<"Tidak Ada List"<<endl;
    }else{
        while(p!=nil){
            cout<<endl;
            cout<<"-Sutradara-"<<endl;
            cout<<"Nama: "<<infoSutradara(p).nama<<endl;
            cout<<"Umur: "<<infoSutradara(p).umur<<endl;
            cout<<"Lama Karir: "<<infoSutradara(p).lamaKarir<<endl;
            adrRelasi pF = first(child(p));
            if (pF==nil){
                cout<<"Belum Ada Pengunjung"<<endl<<endl;
            }
            int j = 1;
            while(pF!=nil){
                cout<<endl<<"Film :"<<endl;
                cout<<"Judul: "<<infoFilm(infoFilm(pF)).judul<<endl;
                cout<<"Genre: "<<infoFilm(infoFilm(pF)).genre<<endl;
                cout<<"Rate: "<<infoFilm(infoFilm(pF)).rate<<endl;
                cout<<"Kode: "<<infoFilm(infoFilm(pF)).kode<<endl;
                pF = next(pF);
                j++;
            }
            p = next(p);
        }
    }
};

void tambahDataRelasi(string &namaStr,string &umur, string &judul, int &kodeFilm){
    cout<<"Nama Sutradara: ";
    cin>>namaStr;
    cout<<"Umur: ";
    cin>>umur;
    cout<<"Judul Film: ";
    cin>>judul;
    cout<<"Kode Film: ";
    cin>>kodeFilm;
    cout<<endl;
}


int menuPilihan(){
    cout << "======FITUR======" << endl;
    cout << "1.  Menambah data Sutradara" << endl;
    cout << "2.  Menambah data Film" << endl;
    cout << "3.  Menambah data Film yang di sutradarai" << endl;
    cout << "4.  Menghapus data Sutradara" << endl;
    cout << "5.  Menampilkan jumlah film yang di Sutradarai oleh" << endl;
    cout << "6.  Mencari data sutradara atau film" << endl;
    cout << "7.  Menampilkan data sutradara atau film atau semua" << endl;
    cout << "8.  Menampilkan data sutradara dengan film terbanyak" << endl;
    cout << "9.  Menampilkan data sutradara dengan film paling sedikit" << endl;
    cout << "0.  Exit" << endl;
    cout << "Masukkan menu : ";

    int menu = 0;
    cin >> menu;
    return menu;
};
