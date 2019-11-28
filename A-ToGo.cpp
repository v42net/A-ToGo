//-----------------------------------------------------------------------------
// A-ToGo.cpp - AppsToGo unlock & startup tool
//-----------------------------------------------------------------------------
#include "A-ToGo"
//-----------------------------------------------------------------------------
int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
	CHAR                Target[_MAX_FNAME];
	SHELLEXECUTEINFO	ExecInfo;
	//---------------------------------------------------------------------
	CoInitialize (NULL); 

	_splitpath (__argv[0], NULL, NULL, Target, NULL);
	_strupr (Target);
	
	ZeroMemory (&ExecInfo, sizeof (SHELLEXECUTEINFO));
	ExecInfo.cbSize	= sizeof (SHELLEXECUTEINFO);
	ExecInfo.fMask	= SEE_MASK_NOASYNC | SEE_MASK_NOCLOSEPROCESS;
	ExecInfo.lpFile	= Target;
	ExecInfo.nShow	= SW_SHOWNORMAL;
	
	sprintf (Target+1, ":\\");
	ExecInfo.lpVerb	= "unlock-bde";
	if (ShellExecuteExA (&ExecInfo)) {
		if (ExecInfo.hProcess) {
            WaitForSingleObject (ExecInfo.hProcess, INFINITE);
        }
	}

	sprintf (Target+1, ":\\Start.exe");
	ExecInfo.lpVerb		= "open";
	ShellExecuteExA (&ExecInfo);

	CoUninitialize();
	//---------------------------------------------------------------------
	return 0;
}
//-----------------------------------------------------------------------------
//[eof]
