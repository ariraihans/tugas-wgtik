#include "film.h"

void createListFilm(listFilm &LF){
    first(LF) = nil;
};

adrFilm elementFilm(infoFilm iFilm){
    adrFilm adrF;
    adrF = new elmFilm;
    infoFilm(adrF) = iFilm;
    nextFilm(adrF) = nil;

    return adrF;
};

void insertLastFilm(listFilm &LF, adrFilm iFilm){
    if(first(LF)== nil){
        first(LF) = iFilm;
    }else{
        adrFilm adrF;
        adrF = first(LF);
        while(nextFilm(adrF)!=nil){
            adrF = nextFilm(adrF);
        }
        nextFilm(adrF) = iFilm;
    }
};

void deleteLastFilm(listFilm &LF, adrFilm &iFilm){
    adrFilm adrF;
    adrF = first(LF);

    while(nextFilm(nextFilm(adrF))!=nil){
        adrF = nextFilm(adrF);
    }
    iFilm = nextFilm(adrF);
    nextFilm(adrF) = nil;
};

void showFilm(listFilm LF){
    if(first(LF)== nil){
        cout<<"List Data Tidak Ada"<<endl;
    }else{
        adrFilm adrF;
        adrF = first(LF);
        cout<<"Data Sutrada"<<endl;
        while(adrF !=nil){
            cout<<"Judul: "<<infoFilm(adrF).judul<<endl;
            cout<<"Genre Sutradara: "<<infoFilm(adrF).genre<<endl;
            adrF = nextFilm(adrF);
        }
    }
};

adrFilm cariElmFilm(listFilm &LF, int kode,string title){
    adrFilm adrF;
    adrF = first(LF);
    while (adrF!=nil) {
        if(infoFilm(adrF).kode == kode && infoFilm(adrF).judul == title){
            return adrF;
            break;
        }
        adrF = nextFilm(adrF);
    }
    return  nil;
};

infoFilm inputFilm(infoFilm &input){
    cout<<"Judul Film: ";
    cin>> input.judul;
    cout<<"No Kode Film: ";
    cin>> input.kode;
    cout<<"Genre: ";
    cin>> input.genre;
    cout<<"Rate: ";
    cin>> input.rate;
    cout<<endl;

    return input;
};
