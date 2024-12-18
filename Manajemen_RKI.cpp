#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace this_thread;
using namespace chrono;

struct Komponen {
    string jenis, nama;
    double nilai;
} daftar[50];

int jumlahResistor = 0;
int jumlahKapasitor = 0;
int jumlahInduktor = 0;

void komponenUrut(int &jumlah) {
    for(int i = 0; i < jumlah; i++) {
            int indexMin = i;
            for(int j = i + 1; j < jumlah; j++) {
                if(daftar[indexMin].nama > daftar[j].nama) {
                    indexMin = j;
                }
            }
            Komponen temp = daftar[indexMin];
            daftar[indexMin] = daftar[i];
            daftar[i] = temp;
        }
}

void tambahKomponen(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Tambah Komponen ==" << endl;

    if(jumlah > 50) {
        cout << "Daftar komponen penuh!" << endl << endl;
    }
    else {
        char pilih = 'y';

        while(pilih == 'y') {
            cout << "Masukkan jenis komponen (resistor/kapasitor/induktor): "; cin >> daftar[jumlah].jenis;
            sleep_for(seconds(1));
            if(daftar[jumlah].jenis == "resistor") {
                cout << "Masukkan nama resistor" << ": "; cin >> daftar[jumlah].nama;
                cout << "Masukkan nilai resistansi (ohm)" << ": "; cin >> daftar[jumlah].nilai;
                sleep_for(seconds(1));
                cout << "Komponen resistor berhasil ditambahkan!" << endl;
                jumlahResistor++;
                jumlah++;
            }
            else if(daftar[jumlah].jenis == "kapasitor") {
                cout << "Masukkan nama kapasitor" << ": "; cin >> daftar[jumlah].nama;
                cout << "Masukkan nilai kapasitansi (F)" << ": "; cin >> daftar[jumlah].nilai;
                sleep_for(seconds(1));
                cout << "Komponen kapasitor berhasil ditambahkan!" << endl;
                jumlahKapasitor++;
                jumlah++;
            }
            else if(daftar[jumlah].jenis == "induktor") {
                cout << "Masukkan nama induktor" << ": "; cin >> daftar[jumlah].nama;
                cout << "Masukkan nilai induktansi (H)" << ": "; cin >> daftar[jumlah].nilai;
                sleep_for(seconds(1));
                cout << "Komponen induktor berhasil ditambahkan!" << endl;
                jumlahInduktor++;
                jumlah++;
            }
            else {
                cout << "Jenis komponen tidak valid!" << endl;
            }

            cout << "Apakah ingin menambahkan lagi (y/n)? "; cin >> pilih;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void hapusKomponen(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Hapus Komponen ==" << endl;

    if (jumlah == 0) {
        cout << "Belum ada komponen!" << endl << endl;
    }
    else {
        char pilih = 'y';

        while(pilih == 'y') {
            for(int i = 0; i < jumlah; i++) {
                cout << i + 1 << ". ";
                if(daftar[i].jenis == "resistor") {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " ohm (resistor)" << endl;
                }
                else if(daftar[i].jenis == "kapasitor") {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " F (kapasitor)" << endl;
                }
                else {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " H (induktor)" << endl;
                }
            }

            int nomor;
            cout << "Masukkan nomor komponen yang ingin dihapus: "; cin >> nomor;
            sleep_for(seconds(1));

            if(nomor > 0 && nomor <= jumlah) {
                if(daftar[nomor].jenis == "resistor") jumlahResistor--;
                else if(daftar[nomor].jenis == "kapasitor") jumlahKapasitor--;
                else jumlahInduktor--;

                for(int i = nomor - 1; i < jumlah - 1; i++) {
                    daftar[i] = daftar[i + 1];
                }
                cout << "Komponen berhasil dihapus!" << endl;
                jumlah--;
            }
            else {
                cout << "Nomor tidak valid!" << endl;
            }

            cout << "Apakah ingin menghapus lagi (y/n)? "; cin >> pilih;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void tampilkanKomponen(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Daftar Komponen ==" << endl;

    if (jumlah == 0) {
        cout << "Belum ada komponen!" << endl << endl;
    }
    else {
        char quit = 'n';

        while(quit != 'q') {
            for(int i = 0; i < jumlah; i++) {
                cout << i + 1 << ". ";
                if(daftar[i].jenis == "resistor") {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " ohm (resistor)" << endl;
                }
                else if(daftar[i].jenis == "kapasitor") {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " F (kapasitor)" << endl;
                }
                else {
                    cout << daftar[i].nama << " " << daftar[i].nilai << " H (induktor)" << endl;
                }
            }

            cout << endl << "Tekan (q) untuk kembali ke menu: "; cin >> quit;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void tampilkanResistor(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Daftar Resistor ==" << endl;

    if(jumlahResistor == 0) {
        cout << "Belum ada resistor!" << endl << endl;
    }
    else {
        char quit = 'n';

        while(quit != 'q') {
            int nomor = 1;
            for(int i = 0; i < jumlah; i++) {
                if(daftar[i].jenis == "resistor") {
                    cout << nomor << ". " << daftar[i].nama << " " << daftar[i].nilai << " ohm" << endl;
                    nomor++;
                }
            }

            cout << endl << "Tekan (q) untuk kembali ke menu: "; cin >> quit;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void tampilkanKapasitor(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Daftar Kapasitor ==" << endl;

    if(jumlahKapasitor == 0) {
        cout << "Belum ada kapasitor!" << endl << endl;
    }
    else {
        char quit = 'n';

        while(quit != 'q') {
            int nomor = 1;
            for(int i = 0; i < jumlah; i++) {
                if(daftar[i].jenis == "kapasitor") {
                    cout << nomor << ". " << daftar[i].nama << " " << daftar[i].nilai << " F" << endl;
                    nomor++;
                }
            }

            cout << endl << "Tekan (q) untuk kembali ke menu: "; cin >> quit;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void tampilkanInduktor(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Daftar Induktor ==" << endl;

    if(jumlahInduktor == 0) {
        cout << "Belum ada induktor!" << endl << endl;
    }
    else {
        char quit = 'n';

        while(quit != 'q') {
            int nomor = 1;
            for(int i = 0; i < jumlah; i++) {
                if(daftar[i].jenis == "induktor") {
                    cout << nomor << ". " << daftar[i].nama << " " << daftar[i].nilai << " H" << endl;
                    nomor++;
                }
            }

            cout << endl << "Tekan (q) untuk kembali ke menu: "; cin >> quit;
            cout << endl;
        }
    }
    sleep_for(seconds(1));
}

void cariKomponen(int &jumlah) {
    sleep_for(seconds(1));
    cout << endl;
    cout << "\t == Cari Nilai Komponen ==" << endl;

    char cari = 'y';
    while(cari == 'y') {
        string jenis, nama;
        cout << "Masukkan jenis komponen (resistor/kapasitor/induktor): "; cin >> jenis;
        cout << "Masukkan nama " << jenis << ": "; cin >> nama;
        cout << endl;
        sleep_for(seconds(1));

        int kiri = 0, kanan = jumlah - 1;
        bool ketemu = false;

        while(kiri <= kanan) {
            int tengah = (kiri + kanan) / 2;
            if(nama == daftar[tengah].nama && jenis == daftar[tengah].jenis) {
                ketemu = true;
                cout << "Jenis: " << daftar[tengah].jenis << endl;
                cout << "Nama: " << daftar[tengah].nama << endl;
                if(jenis == "resistor") {
                    cout << "Nilai: " << daftar[tengah].nilai << "ohm" << endl;
                }
                else if(jenis == "kapasitor") {
                    cout << "Nilai: " << daftar[tengah].nilai << "F" << endl;
                }
                else {
                    cout << "Nilai: " << daftar[tengah].nilai << "H" << endl;
                }
                break;
            }
            else if(nama < daftar[tengah].nama) {
                kanan = tengah - 1;
            }
            else {
                kiri = tengah + 1;
            }
        }

        if(!ketemu) {
            cout << "Komponen " << jenis << " tidak ditemukan!" << endl;
        }

        cout << endl << "Apakah ingin mencari lagi (y/n)? "; cin >> cari;
        cout << endl;
    }
    sleep_for(seconds(1));
}

int main() {
    int pilihan;
    int jumlahKomponen = 0;
    
    do {
        cout << "\t ==============================" << endl;
        cout << "\t MANAJEMEN KOMPONEN ELEKTRONIKA" << endl;
        cout << "\t (RESISTOR/KAPASITOR/INDUKTOR)" << endl;
        cout << "\t ==============================" << endl;
        cout << "MENU:" << endl;
        cout << "1. Tambah Komponen" << endl;
        cout << "2. Hapus Komponen" << endl;
        cout << "3. Tampilkan Seluruh Komponen" << endl;
        cout << "4. Tampilkan Resistor" << endl;
        cout << "5. Tampilkan Kapasitor" << endl;
        cout << "6. Tampilkan Induktor" << endl;
        cout << "7. Cari Nilai Komponen" << endl;
        cout << "0. Keluar" << endl;
        cout << "PILIH MENU: "; cin >> pilihan;

        if(pilihan == 1) {
            tambahKomponen(jumlahKomponen);
        }
        else if(pilihan == 2) {
            komponenUrut(jumlahKomponen);
            hapusKomponen(jumlahKomponen);
        }
        else if(pilihan == 3) {
            komponenUrut(jumlahKomponen);
            tampilkanKomponen(jumlahKomponen);
        }
        else if(pilihan == 4) {
            komponenUrut(jumlahKomponen);
            tampilkanResistor(jumlahKomponen);
        }
        else if(pilihan == 5) {
            komponenUrut(jumlahKomponen);
            tampilkanKapasitor(jumlahKomponen);
        }
        else if(pilihan == 6) {
            komponenUrut(jumlahKomponen);
            tampilkanInduktor(jumlahKomponen);
        }
        else if(pilihan == 7) {
            komponenUrut(jumlahKomponen);
            cariKomponen(jumlahKomponen);
        }
        else if(pilihan == 0) {
            cout << endl;
            cout << "Keluar dari program.";
        }
        else {
            sleep_for(seconds(1));
            cout << "Pilihan tidak valid!" << endl << endl;
        }
    } while (pilihan != 0);

    return 0;
}
