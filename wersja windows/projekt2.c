/* 
Napisz program, który oblicza csech(x) (kosekans hiperboliczny),
gdzie x jest argumentem podanym przez użytkownika, podobnie jak 
dokładność obliczenia.

 Kompilacja Windows:
  nasm -fcoff csech.asm -o csech.obj
  gcc -m32 projekt2.c csech.obj -o projekt2.exe
*/
#include <stdio.h>

float csech (int x); //prototyp funkcji

int main()
{
	int podanyX=0;
	int dokladnosc=1; // max 54
	float wynik=0.0;

	printf("Program liczacy csech(x) (kosekans hiperboliczny). Podaj calkowite x z zakresu [-100; 100] (wieksze/mniejsze nie ma sensu).\nx= ");
	scanf("%d",&podanyX);

	//sprawdzanie otrzymanego x:
	if(fgetc(stdin) != 10) // jeśli to co "zostało" w wejściu jest inne niż enter
	{
		printf("\nPodano bledny znak!\n");
		system("PAUSE");
		return 0;
	}//endif
	else if(podanyX == 0) 
	{
		printf("csech(0)= nieskonczonosc\n");
		system("PAUSE");
		return 0;
	}//endif
	else if(podanyX >= 1 && podanyX <= 125)
	{
		wynik = csech(podanyX);
	}//endelseif
	else if(podanyX <= -1 && podanyX >= -125)
	{
		wynik = -1.0 * csech(podanyX * -1);
	}//endelseif
	else
	{
		printf("Podany x jest poza zakresem!\n");
		system("PAUSE");
		return 0;
	}//endelse



	printf("Podaj oczekiwana dokladnosc [1-54]: ");	
	scanf("%d",&dokladnosc);


	//sprawdzenie podanej dokładności:
	if(fgetc(stdin) != 10) // jeśli to co "zostało" w wejściu jest inne niż enter
	{
		printf("\nPodano bledny znak!\n");
		system("PAUSE");
		return 0;
	}//endif
	else if(dokladnosc < 1 || dokladnosc > 54)
	{
		printf("Podana dokładnosc nie miesci się w zakresie!\n");
		system("PAUSE");
		return 0;
	}//endif



	printf("csech(%d)= %.*f\n", podanyX, dokladnosc, wynik);

	system("PAUSE");
	return 0;
}//koniec main()
