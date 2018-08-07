BITS 32
; trzeba policzyć 2 / (e^x - e^-x)
; liczymy tylko całkowite x, bo byłoby zbyt skomplikowanie dla wymiernych
section .text

global _csech ;żeby funkcja była widzialna (dla windows _csech)

_csech:

 %idefine a [ebp+8] ; a podane przez użytkownika

 push ebp ;tworzenie ramki stosu
 mov ebp,esp

 mov ecx, a ;zapisanie podanego a do ecx

 finit ;inicjalizacja stosu
 fld dword [eulera] ;wrzuć e na stos
 fld dword [eulera] ;wrzuć e na stos

 ;dla dodatniego x (dla ujemnego całość*-1 w C):
 
 call edox ;procedura e^x
 ; w tym momencie st0=e^x, st1=e

 fld1 ;wrzuć 1 na stos
 ; w tym momencie st0=1, st1=e^x, st2=e

 call edomx ;procedura e^-x
 ; w tym momencie st0=e^-x, st1=e^x, st2=e

 fxch st1 ; w tym momencie st0=e^x, st1=e^-x, st2=e 

 fsub st0, st1 ; w tym momencie st0=(e^x - e^-x), st1=e^-x, st2=e 


 fld dword [dwa] ;wrzuć 2 na stos
 ; w tym momencie st0=2, st1=(e^x - e^-x), st2=e^-x, st3=e

 fdiv st0, st1
 ; w tym momencie st0=2/(e^x - e^-x), st1=(e^x - e^-x), st2=e^-x, st3=e




 mov esp, ebp ;kasowanie ramki stosu (może być "leave")
 pop ebp

ret ;wyłaź

;e^x:
edox:
 cmp ecx, 1
 je koniec
 fmul st0, st1
 dec ecx
 call edox
 koniec:
ret

;e^-x = 1/e^x:
edomx:
 fdiv st0, st1
ret

section .data	
 dwa dd 2.0 ;liczba 2
 eulera dd 2.718281828459 ;stała liczba e	
