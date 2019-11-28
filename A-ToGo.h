//-----------------------------------------------------------------------------
// A-ToGo.h - AppsToGo unlock & startup tool
//-----------------------------------------------------------------------------

#define WINVER                      0x0A00
#define _WIN32_WINNT                0x0A00
#define _WIN32_IE                   0x0A00
#define NTDDI_VERSION               NTDDI_WIN10
#define PSAPI_VERSION               1
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <shellapi.h> 
#include <shobjidl.h> 

#define ORIGINAL_FILENAME           "A-ToGo.exe"
#define VERSION_PRODUCTNAME         "AppsToGo unlock & startup tool"
#define VERSION_PRODUCTVERSION      "v1.0"

#define VERSION_PRODUCTNUMBER       1,0,0
#define	VERSION_PRODUCTBUILD        0

#define VERSION_AUTHOR              "Peter Hoogendijk"
#define VERSION_COMPANYNAME         "v42.net"
#define VERSION_COPYRIGHT           "(c) v42.net 2019"

//-----------------------------------------------------------------------------
//[eof]
