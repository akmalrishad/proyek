// akmal
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define panjang 6000

#define BLACK           0
#define DARK_BLUE       1
#define GREEN           2
#define TURQUOISE       3
#define DARK_RED        4
#define PURPLE          5
#define FOREST_GREEN    6
#define LIGHT_GRAY      7
#define GRAY            8
#define BLUE            9
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define PINK           13
#define YELLOW         14
#define WHITE          15
#define STDALERT      140
#define STDHEADER     143
#define STDBACKGROUND 159

const int O = 0, X = 1, kosong = 3;
const int tengah[3] = {4,12,24};
void menu();
void permainan();

void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void inisialisasi(int *board) //modul untuk memberi nilai awal ke array board
{ 
	int i = 0;
	for(i=0; i<25; i++){
		board[i]=kosong;
	}
}


void gotoxy(int x, int y) //modul untuk memfungsikan fungsi gotoxy
{ 
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

void xo(){
	warnateks(LIGHT_GREEN);
	gotoxy(9,8); printf("ÛÛ       ÛÛ \n");
	gotoxy(9,9); printf("  ÛÛ   ÛÛ \n");
	gotoxy(9,10); printf("    ÛÛÛ \n");
	gotoxy(9,11); printf("    ÛÛÛ \n");
	gotoxy(9,12); printf("  ÛÛ   ÛÛ \n");
	gotoxy(9,13); printf("ÛÛ       ÛÛ \n");	
	gotoxy(9,15);printf(" COMPUTER \n");
	warnateks(YELLOW);
	gotoxy(61,8); printf("    ÛÛÛÛ  \n");
	gotoxy(61,9); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,10); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,11); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,12); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,13); printf("    ÛÛÛÛ \n");
	gotoxy(61,15);printf("    USER   \n");	
}

void tampilan_board(const int *board) //modul untuk menampilkan array board ke layar
{ 
	int i = 0;
	char kar[] = "OX|_";
	xo();
	for(i=0; i<25; i++){
		if(i!=0 && i%5==0){ 
			printf("\n\n\n"); //memberi spasi untuk setiap baris
		}
		
		if(i%5 == 0){
			printf("\t\t\t");
		}
		
		if(board[i] == 0){
			warnateks(YELLOW); //memberi warna kuning ke karakter "O"
			printf("%6c", kar[board[i]]);
		}else if(board[i] == 1){
			warnateks(LIGHT_GREEN);  //memberi warna hijau ke karakter "X"
			printf("%6c", kar[board[i]]);
		}else{
			warnateks(WHITE);  //memberi warna putih ke karakter selain "X" "O"
			printf("%6d", i+1);
		}
	}
}

void tampilan_board_akhir(const int *board) //menampilkan kondisi array board terakhir setelah permainan selesai
{
	int i=0;
	char kar[] = "OX|_"; 
	printf("\n\n");
	warnateks(LIGHT_GREEN);
	xo();
	for(i=0; i<25; i++){
		if(i!=0 && i%5==0){
			printf("\n\n\n");
		}
		
		if(i%5 == 0){
			printf("\t\t\t");
		}
		
		if(board[i] == 0){
			warnateks(YELLOW);
			printf("%6c", kar[board[i]]);
		}else if(board[i] == 1){
			warnateks(LIGHT_GREEN);
			printf("%6c", kar[board[i]]);
		}else if(board[i] == 3){
			warnateks(WHITE);
			printf("%6c", kar[board[i]]);
		}
	}
	printf("\n\n");	
}

void judul()//sebagai tampilan awal program
{ 
	warnateks(LIGHT_BLUE);
	gotoxy(8,1); printf("  ÛÛÛÛÛÛÛÛÛÛ  ÛÛ   ÛÛÛÛÛ             ÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛ    ÛÛÛÛÛ \n");
	printf("              ÛÛ      ÛÛ  ÛÛ                     ÛÛ      ÛÛ  ÛÛ  ÛÛ     \n");
	printf("              ÛÛ      ÛÛ  ÛÛ                     ÛÛ      ÛÛ  ÛÛ  ÛÛ     \n");
	printf("              ÛÛ      ÛÛ  ÛÛ                     ÛÛ      ÛÛÛÛÛÛ  ÛÛ     \n");
	printf("              ÛÛ      ÛÛ  ÛÛ                     ÛÛ      ÛÛ  ÛÛ  ÛÛ     \n");
	printf("              ÛÛ      ÛÛ   ÛÛÛÛÛ                 ÛÛ      ÛÛ  ÛÛ   ÛÛÛÛÛ \n \n\n\n");
	
	printf("      		           ÛÛÛÛÛÛÛÛÛÛ  ÛÛÛÛÛ   ÛÛÛÛÛ \n");
	printf("	 	               ÛÛ     ÛÛ   ÛÛ  Û     \n");
	printf("		               ÛÛ     ÛÛ   ÛÛ  ÛÛÛÛÛ \n");
	printf("		               ÛÛ     ÛÛ   ÛÛ  Û \n");
	printf("                               ÛÛ     ÛÛ   ÛÛ  Û     \n");
	printf("		               ÛÛ      ÛÛÛÛÛ   ÛÛÛÛÛ \n");
	
	warnateks(LIGHT_GREEN);
	gotoxy(9,18); printf("ÛÛ       ÛÛ \n");
	gotoxy(9,19); printf("  ÛÛ   ÛÛ \n");
	gotoxy(9,20); printf("    ÛÛÛ \n");
	gotoxy(9,21); printf("    ÛÛÛ \n");
	gotoxy(9,22); printf("  ÛÛ   ÛÛ \n");
	gotoxy(9,23); printf("ÛÛ       ÛÛ \n");	
	warnateks(YELLOW);
	gotoxy(61,18); printf("    ÛÛÛÛ  \n");
	gotoxy(61,19); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,20); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,21); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,22); printf("  ÛÛ    ÛÛ \n");
	gotoxy(61,23); printf("    ÛÛÛÛ \n");	
}

void kecepatan(float seconds){
	clock_t endwait;
	endwait=clock()+seconds*CLOCKS_PER_SEC;
	while(clock()<endwait){};
}

void loading()//modul untuk menapilkan tampilan loading
{ 
	int x = 28, y = 13, n;
	warnateks(WHITE);
	gotoxy(x,20); printf("       Please Wait");
	gotoxy(x,21);  printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	gotoxy(x,22);printf("º                        º");
	gotoxy(x,23);printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	for(n=29;n<=50;n++){
		gotoxy(n,22);printf("Û");
		kecepatan(0.1);
	};
}

void welcome_screen(){
	gotoxy(22,28); printf(" Created By : Moh. Dwi, Rangga R, Silvi \n");
	judul();
	loading();
}

void aboutus(){
	FILE *creator;
	char creat[panjang];
	
	creator = fopen("creator.txt", "rt");
	while((fgets(creat, panjang, creator))!= NULL){
		printf("%s\r", creat);
	}
	
	fclose(creator);

	
	gotoxy(22,25); printf("   Press Any Key To Return.....");getch();
	system("CLS");
	menu();
}

void instructions(){
	FILE *instruksi;
	char instruk[panjang];
	
	instruksi = fopen("instruksi.txt", "rt");
	while((fgets(instruk, panjang, instruksi))!= NULL){
		printf("%s\r", instruk);
	}
	
	fclose(instruksi);

	
	gotoxy(22,25); printf("   Press Any Key To Return.....");getch();
	system("CLS");
	menu();
}

void menu() //modul untuk menampilkan main menu dari program
{ 
	int pilih_menu, i = 28;
	judul();
	warnateks(WHITE);
	gotoxy(i,18); printf(" ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
   	gotoxy(i,19);printf(" º      MAIN MENU        º\n");
   	gotoxy(i,20);printf(" º                       º\n");
   	gotoxy(i,21);printf(" º   [1] PLAY NOW !      º\n");
   	gotoxy(i,22);printf(" º   [2] INSTRUCTIONS    º\n");
   	gotoxy(i,23);printf(" º   [3] THE CREATOR     º\n");
   	gotoxy(i,24);printf(" º   [0] Exit            º\n");
   	gotoxy(i,25);printf(" º                       º\n");
   	gotoxy(i,26);printf(" ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");
	gotoxy(i,28);printf("    Choose :            \n");
   	gotoxy(41,28);scanf("%d",&pilih_menu);
   	switch(pilih_menu){
			case 1:
				system("CLS");
				permainan();
			break;
			
			case 2:
				system("CLS");
				instructions();
			break;

			case 3:
				system("CLS");
				aboutus();
			break;

			case 0:
				exit(1);
			break;

			default:
				menu();
			break;
	 }
}
	
int cek_h1(int kotak_a, const int *board, const int giliran, const int j){
	int status1 = 0, ketemu = 0; 
	int k = kotak_a + j;
	while( status1 == 0){
		if(k % 5 == 0){
			break;
		}
					
		if ( board[k] != giliran || k > 24 || ketemu == 3){
			break;
		}else{
		ketemu++;
		}
				
		k = k + j;
	}
	return ketemu;
}

int cek_h2(int kotak_a, const int *board, const int giliran, const int j){
	int status1 = 0, ketemu = 0; 
	int k = kotak_a + j;
	while( status1 == 0 && k >= 0){
		if ( board[k] != giliran || ketemu == 3 || kotak_a % 5 == 0){
			break;
		}else{
			ketemu++;
		}
				
		k = k + j;
		if (k == 4 || k == 9 || k == 14 || k == 19){
			break;
		}
	}
	return ketemu;
}

int cek_v(int kotak_a, const int *board, const int giliran, const int j){
	int status1 = 0, ketemu = 0; 
	int k = kotak_a + j;
	while(k >= 0 && k <= 24){
		if ( board[k] != giliran || ketemu == 3){
			break;
		}else{
			ketemu++;
		}
				
		k = k + j;
	}
	return ketemu;
}

int cek_d(int kotak_a, const int *board, const int giliran, const int j, const int m, const int n){
	int status1 = 0, ketemu = 0; 
	int k = kotak_a + j;
	while(k >= m && k <= n){
		if ( board[k] != giliran || ketemu == 3){
			break;
		}else{
			ketemu++;
		}
		k = k + j;
	}
	return ketemu;
}

int cek_menang(const int *board, const int n_kotak, const int giliran)//modul untuk mengecek apakah ada yang menang
{ 
	int j, status = 1;
	while (status == 1){
		j = 1; 			//cek horizontal
		status = status + cek_h1(n_kotak, board, giliran, j);
		status = status + cek_h2(n_kotak, board, giliran, j*-1);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		// cek vertikal
		j = 5; 
		status = status + cek_v(n_kotak, board, giliran, j);
		status = status + cek_v(n_kotak, board, giliran, j*-1);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 4 - 20
		j = 4; 
		int m = 4, n = 20;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 0 - 24 
		j = 6; 
		m = 0;
		n = 24;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 5 - 23 
		j = 6; 
		m = 5;
		n = 23;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 1 - 19 
		j = 6; 
		m = 1;
		n = 19;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 3 - 15 
		j = 4; 
		m = 3;
		n = 15;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}
		
		status = 1;		//cek diagonal kolom 9 - 21 
		j = 4; 
		m = 9;
		n = 21;
		status = status + cek_d(n_kotak, board, giliran, j, m, n);
		status = status + cek_d(n_kotak, board, giliran, j*-1, m, n);
		if(status >= 4){
			//status = 4;
			break;
		}else{
			status = 1;
			break;
		}
	}
	return status;
}

int menangin_blocking(int *board, const int giliran)//modul untuk menentukan langkah yang akan diambil oleh komputer untuk memenangkan permainan dan mencegah user menang
{ 
	int no_kotak = -1, status = 0, i = 0;
	for(i = 0; i < 25; i++){
		if(board[i] == kosong){
			no_kotak = i;
			board[no_kotak] = giliran;
			if (cek_menang(board, no_kotak, giliran) == 4){
				break;
			} else{
				board[no_kotak] = kosong;
				no_kotak = -1;
			}			
		}			
	}
	return no_kotak;
}

int isi_tengah(const int *board)// modul untuk menentukan
{ 
	int i = 0, j, k = -1;
	for(i = 0; i < 8; i++) {
		j = 3;
		j = (rand() % j);
		k = tengah[j];
		if(board[k] == kosong) {
			break;
		}
		k = -1;
	}
	return k;
}

int cek_draw(const int *board)//modul untuk mengecek apakah permainan draw atau tidak
{ 
	int i=0;
	for(i=0; i<25; i++){
		if(board[i] == kosong) 
		return 1;
	}
	return 0;
}

int input_user(const int *board)//modul untuk memproses inputan langkah dari user pada saat permainan
{ 
	//char userinput[12];
	warnateks(WHITE);
	int keluar = 0;
	int pilih_kotak = -1;
	while (keluar == 0) {
		printf("\n\n\n\t\t\tMasukan nomor kotak (1-25) :");	
		label2 :
		scanf("%d", &pilih_kotak);
		
		if (pilih_kotak < 1 || pilih_kotak > 25){
			pilih_kotak = -1;
			printf("\n\t\t\tnomor yang anda masukan salah\n");
			continue; 
		}
		
		pilih_kotak--;
		if( board[pilih_kotak] != kosong ){
			pilih_kotak=-1;
			printf("\n\t\t\tkotak tersebut sudah terisi, pilih kotak lain : ");
			continue;	
		}
		//if(pilih_kotak>1 || pilih_kotak)
		keluar=1;
	}
	return pilih_kotak;
}

void isi_kotak(int *board,const int no_kotak,const int giliran)//modul untuk mengisi array board dengan tanda dari user dan komputer
{ 
	board[no_kotak] = giliran;
}

int gilirankomputer( int *board, const int _giliran)//modul yang berfungsi untuk menentukan langkah komputer
{ 
	int i = 0, nomor_kotak = 0;
	
	nomor_kotak = menangin_blocking(board, _giliran);
	if(nomor_kotak != -1){
		return nomor_kotak;
	}
	
	nomor_kotak = menangin_blocking(board, _giliran ^ 1);
	if(nomor_kotak != -1){
		return nomor_kotak;
	}
	
	nomor_kotak = isi_tengah(board);
	if(nomor_kotak != -1){
		return nomor_kotak;
	}
	
	nomor_kotak = 0;
	int nomor_kotak_kosong = 0;
	int kotak_tersedia[25];
	for(i = 0; i < 25; i++){
		if(board[i] == kosong){
			kotak_tersedia[nomor_kotak_kosong] = i;
			nomor_kotak_kosong++;
		}
	}  
	nomor_kotak = (rand() % nomor_kotak_kosong);
	
	return kotak_tersedia[nomor_kotak];  
}

void permainan()//modul yang berfungsi untuk menentukan dan mengatur jalannya permainan
{ 
	int board[25];
	int game_over = 0, giliran = O, no_kotak = -1;
	inisialisasi(&board[0]);
		
	while(game_over != 1) {
		system("cls");
		tampilan_board(&board[0]);
		if(giliran == O){
			no_kotak = input_user(&board[0]);
			isi_kotak(&board[0],no_kotak,giliran);
			giliran = X;
		}else{
			no_kotak = gilirankomputer(&board[0], giliran);
			isi_kotak(&board[0], no_kotak, giliran);
			giliran = O;
			tampilan_board(&board[0]);
					
		}
								
		
		if( cek_menang(board, no_kotak, giliran^1) >= 4 ){
			int i = 15, j = -1;
			system("cls");
			warnateks(WHITE);
			printf("\n\n\t\t\t\tG A M E  O V E R\n");
			tampilan_board_akhir(&board[0]);			
				if(giliran == O){
					warnateks(LIGHT_GREEN);
					printf("\n\n\t\t\t\t Komputer Menang!\n");
				} else {
					warnateks(YELLOW);
					printf("\n\t\t\t\t    Anda Menang!\n\n");
				}
			warnateks(WHITE);
			printf("\n\t\t\t Anda Ingin Bermain Lagi? \n\t\t\t [1] YA\n\t\t\t [2] TIDAK\n\t\t\t Masukan No Pilihan : "); scanf("%d", &j);
				if(j==2){
					game_over = 1;	
					system("CLS");
					menu();
				}else{
					game_over = 0;
					inisialisasi(&board[0]);
				}
		}
		
		if(cek_draw(board) == 0) {
			int j = -1;
			game_over = 1;
			system("cls");
			printf("\n\t\t\tD R A W\n");
			tampilan_board_akhir(&board[0]);
			warnateks(WHITE);
			printf("\n\t\t\t Anda Ingin Bermain Lagi? \n\t\t\t[1] YA\n\t\t\t[2] TIDAK\n\t\t\tMasukan No Pilihan : "); scanf("%d", &j);
				if(j==2){
					game_over = 1;
					break;	
				}else{
					game_over = 0;
					inisialisasi(&board[0]);
				}
		}
		
		//tampilan_board(&board[0]);	
	}
}

 main(){
	welcome_screen();
	system("CLS");
	menu();
	srand(time(NULL));
	system("CLS");
	getch();
}
