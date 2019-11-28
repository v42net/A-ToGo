default:
	: ----------------------------------------------------------------------- :
	:                                                                         :
	:     make atogo    compile both 'A-ToGo*.exe' executables                : 
	:     make atg32    compile the 32-bit 'A-ToGo32.exe' executable          : 
	:     make atg64    compile the 64-bit 'A-ToGo64.exe' executable          : 
	:     make clean    removes the already compiled 'A-ToGo*.res' files      :
	:                                                                         :
	: ----------------------------------------------------------------------- :

A-ToGo:	A-ToGo32.exe A-ToGo64.exe
	
A-ToGo32.exe: A-ToGo.cpp A-ToGo.h A-ToGo32.res
	mingw32 c++ -static A-ToGo.cpp A-ToGo32.res -lole32 -o A-ToGo32.exe
	mingw32 strip A-ToGo32.exe

A-ToGo32.res: A-ToGo.rc
	mingw32 windres A-ToGo.rc -O coff -o A-ToGo32.res

A-ToGo64.exe: A-ToGo.cpp A-ToGo.h A-ToGo64.res
	mingw64 c++ -static A-ToGo.cpp A-ToGo64.res -lole32 -o A-ToGo64.exe
	mingw64 strip A-ToGo64.exe

A-ToGo64.res: A-ToGo.rc
	mingw64 windres A-ToGo.rc -O coff -o A-ToGo64.res

clean:
	del A-ToGo*.res
