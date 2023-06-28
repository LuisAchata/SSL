conversionesTest: conversionesTest.c conversiones.o
	gcc conversionesTest.c conversiones.o -o conversionesTest

conversiones.o: conversiones.c 
	gcc -c conversiones.c

TablaDeconversiones: TablaDeconversiones.c conversiones.o
	gcc TablaDeconversiones.c conversiones.o -o TablaDeconversiones

test: conversionesTest
	./conversionesTest