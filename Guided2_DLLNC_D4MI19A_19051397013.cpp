#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

typedef struct node
{
	int data;
	node* next;
	node* prev;
}*list;

list head;
list tail;
int batas;

void initData()
{
	head = NULL;
	tail = NULL;
}

int cekHead()
{
	return (head == NULL) ? 1 : 0;
}

void tampilList()
{
	list bantu;
	bantu = head;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong";
	}
	else
	{
		for (int x = 1; x <= batas; x++)
		{
			cout << "Data Ke-" << x << " : " << bantu->data << endl;
			bantu = bantu->next;
		}
	}
}

void hapusDepan();
void hapusBelakang();
void hapusData(int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		if (nomor == 1)
		{
			hapusDepan();
		}
		else if (nomor == batas)
		{
			hapusBelakang();
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x < nomor; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = bantu->next;
			bantu->next->prev = bantu->prev;
			delete bantu;
			batas--;
			cout << "Data Ke-" << nomor << " Telah Dihapus\n\n";
		}
	}
}

void hapusDepan()
{
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		list bantu;
		bantu = head;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete bantu;
		batas--;
		cout << "Data Depan Telah Dihapus\n\n";
	}
}

void hapusBelakang()
{
	list bantu;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		bantu = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		delete bantu;
		batas--;
		cout << "Data Belakang Telah Dihapus\n\n";
	}
}

void hapusSebelumNode(int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		if (nomor == 1)
		{
			hapusBelakang();
		}
		else if (nomor == 2)
		{
			hapusDepan();
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x < nomor - 1; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = bantu->next;
			bantu->next->prev = bantu->prev;
			delete bantu;
			batas--;
			cout << "Data Sebelum Ke-" << nomor << " Telah Dihapus\n\n";
		}
	}
}

void hapusSetelahNode(int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		if (nomor == batas)
		{
			hapusDepan();
		}
		else if (nomor == batas - 1)
		{
			hapusBelakang();
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x <= nomor; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = bantu->next;
			bantu->next->prev = bantu->prev;
			delete bantu;
			batas--;
			cout << "Data Setelah Ke-" << nomor << " Telah Dihapus\n\n";
		}
	}
}

void hapusSemua()
{
	list bantu;
	list hapus;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		bantu = head;
		while (bantu != tail)
		{
			hapus = bantu;
			bantu = bantu->next;
			delete hapus;
		}
		head = NULL;
		tail = NULL;
		batas = 0;
		delete bantu;
		cout << "Semua Data Telah Terhapus\n\n";
	}
}

void gantiData(list insert, int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		cout << "Data Masih Kosong\n\n";
	}
	else
	{
		if (nomor == 1)
		{
			bantu = head;
			insert->next = bantu->next;
			bantu->next->prev = insert;
			insert->prev = tail;
			tail->next = insert;
			head = insert;
			delete bantu;
			cout << "Data Ke-" << nomor << " Telah Diganti\n\n";
		}
		else if (nomor == batas)
		{
			bantu = tail;
			bantu->prev->next = insert;
			insert->prev = bantu->prev;
			insert->next = head;
			head->prev = insert;
			tail = insert;
			delete bantu;
			cout << "Data Ke-" << nomor << " Telah Diganti\n\n";
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x < nomor; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = insert;
			insert->prev = bantu->prev;
			insert->next = bantu->next;
			bantu->next->prev = insert;
			delete bantu;
			cout << "Data Ke-" << nomor << " Telah Diganti\n\n";
		}
	}
}

void dataDepan(list insert)
{
	if (cekHead() == 1)
	{
		head = insert;
		head->next = NULL;
		head->prev = NULL;
		batas++;
	}
	else
	{
		insert->next = head;
		head->prev = insert;
		head = insert;
		head->prev = tail;
		batas++;
	}
	cout << "Data Telah Ditambahkan Di Depan\n\n";
}

void dataBelakang(list insert)
{
	if (cekHead() == 1)
	{
		dataDepan(insert);
	}
	else
	{
		tail->next = insert;
		insert->prev = tail;
		tail = insert;
		tail->next = head;
		head->prev = tail;
		batas++;
	}
	cout << "Data Telah Ditambahkan Di Belakang\n\n";
}

void DataSebelumNode(list insert, int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		dataDepan(insert);
	}
	else
	{
		if (nomor == 1)
		{
			dataBelakang(insert);
		}
		else if (nomor == 2)
		{
			dataDepan(insert);
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x < nomor; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = insert;
			insert->prev = bantu->prev;
			insert->next = bantu;
			bantu->prev = insert;
			batas++;
			cout << "Data Telah Ditambahkan Sebelum Data Ke-" << nomor << "\n\n";
		}
	}

}

void DataSetelahNode(list insert, int nomor)
{
	list bantu;
	if (cekHead() == 1)
	{
		dataDepan(insert);
	}
	else
	{
		if (nomor == batas)
		{
			dataDepan(insert);
		}
		else if (nomor == batas - 1)
		{
			dataBelakang(insert);
		}
		else if ((nomor > batas) || (nomor < 0))
		{
			cout << "No Urutan Tidak Ditemukan\n\n";
		}
		else
		{
			bantu = head;
			for (int x = 1; x <= nomor; x++)
			{
				bantu = bantu->next;
			}
			bantu->prev->next = insert;
			insert->prev = bantu->prev;
			insert->next = bantu;
			bantu->prev = insert;
			batas++;
			cout << "Data Telah Ditambahkan Setelah Data Ke-" << nomor << "\n\n";
		}
	}
}

void SalahMemasukkan()
{
	system("cls");
	cout << "Anda Salah Memasukkan Input\n\n";
	system("pause");
}

void KeluarProgram()
{
	system("cls");
	cout << "Anda Keluar Program \n\n";
	system("pause");
}

int main()
{
	initData();
	list n;
	list bantu;
	bantu = new node;
	do
	{
		unsigned short int pilihan, urutan;
		int data;
		cout << "Program Double Linked List Circular\n\n";
		cout << "Apakah anda ingin melanjutkan ? \n1. Iya\n2. Tidak\n\nPilihan: ";
		cin >> pilihan;
		switch (pilihan)
		{
		case 1:
			cout << "Masukkan Jumlah Data: ";
			cin >> batas;
			for (int x = 1; x <= batas; x++)
			{
				if (x == 1)
				{
					cout << "Data Ke-" << x << "\n\n";
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					n->prev = tail;
					head = n;
					bantu = n;
					cout << "\n\nData Telah Masuk Ke Data Store\n\n";
				}
				else if (x == batas)
				{
					cout << "Data Ke-" << x << "\n\n";
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					bantu->next = n;
					n->prev = bantu;
					n->next = head;
					tail = n;
					head->prev = tail;
					bantu = head;
					cout << "\n\nData Telah Masuk Ke Data Store\n\n";
				}
				else
				{
					cout << "Data Ke-" << x << "\n\n";
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					bantu->next = n;
					n->prev = bantu;
					bantu = bantu->next;
					cout << "\n\nData Telah Masuk Ke Data Store\n\n";
				}
			}
			do
			{
				cout << "Pengoperasian Data \n\n1. Tampilkan Data\n2. Hapus Data Menurut Urutan\n3. Hapus Data Depan \n4. Hapus Data Belakang\n5. Hapus Data Sebelum Urutan\n6. Hapus Data Setelah Urutan\n7. Hapus Semua Data\n8. Ganti Data\n9. Input Data Depan\n10. Input Data Belakang\n11. Input Data Sebelum Urutan\n12. Input Data Setelah Urutan\n13. Keluar Program\n\nPilihan: ";
				cin >> pilihan;
				switch (pilihan)
				{
				case 1:
					tampilList();
					cout << endl << endl;
					break;
				case 2:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					hapusData(urutan);
					break;
				case 3:
					hapusDepan();
					break;
				case 4:
					hapusBelakang();
					break;
				case 5:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					hapusSebelumNode(urutan);
					break;
				case 6:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					hapusSetelahNode(urutan);
					break;
				case 7:
					hapusSemua();
					break;
				case 8:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					cout << "Masukkan Data Baru: ";
					cin >> data;
					n = new node;
					n->data = data;
					gantiData(n, urutan);
					break;
				case 9:
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					dataDepan(n);
					break;
				case 10:
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					dataBelakang(n);
					break;
				case 11:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					DataSebelumNode(n, urutan);
					break;
				case 12:
					tampilList();
					cout << endl << endl;
					cout << "Masukkan Nomor Urutan: ";
					cin >> urutan;
					cout << "Masukkan Data: ";
					cin >> data;
					n = new node;
					n->data = data;
					DataSetelahNode(n, urutan);
					break;
				case 13:
					KeluarProgram();
					return 0;
					break;
				default:
					SalahMemasukkan();
					return 0;
					break;
				}
			} while (true);
		case 2:
			KeluarProgram();
			return 0;
		default:
			SalahMemasukkan();
			return 0;
		}
	} while (true);
}
