# A-ToGo
`A-ToGo` is PortableApps starter for a BitLocker To Go encrypted disk. 

I'm already using an encrypted PortableApps disk for many years and, until now, depended on hardware encryption. Recent developments show that this is not the most reliable encryption method, so I switched to BitLocker To Go.

Security also depends on disciplin, so for me this means that I want to be able to access my PortableApps menu and data with one click (and a password to unlock BitLocker To Go). This wish resulted in this `A-ToGo` tool.

My current setup is like this:
*  A [Samsung T5 Portable SSD](https://www.samsung.com/semiconductor/minisite/ssd/product/portable/t5/)
formatted with NTFS and encrypted with [BitLocker To Go](https://docs.microsoft.com/en-us/windows/security/information-protection/bitlocker/bitlocker-to-go-faq).
*  A [PortableApps](https://portableapps.com/) installation which provides `Start.exe` in the root of the portable disk.
*  Four Microsoft Windows 10 computers where I use this disk on a regular basis, each with my own account.
*  On each computer I have assigned drive letter `A:` to my portable disk and placed `A-ToGo.exe` on the local harddisk.

By pinning `A-ToGo.exe` to the Start Menu, it allows me to unlock `A:` and run `A:\Start.exe` very easily
without depending on auto-unlock, which might be a security risk ... I'm only a little bit paranoid :smile:

### The A-Question

What if you are not using `A:` but `B:` or any other drive letter?
*  Just rename `A-ToGo.exe` to `B-ToGo.exe` or any other name: the first letter of the name determines the drive letter!

### How it works

The context (right-click) menu of a locked encrypted drive starts with an `Unlock Drive ...` option. Internally this triggers the 
`shell unlock-bde` method. `A-ToGo.exe` simply invokes this method and waits for the unlock process to complete. 
As soon as the unlock process completes, it invokes the `shell open` method on `Start.exe` to start the PortableApps menu.

### Compiling A-ToGo

I'm using [MinGW-w64](http://mingw-w64.org/) to compile `A-ToGo` and, to stay portable, am using some cmd-files as a wrapper:
*  `CmdHere.cmd` opens a command prompt while defining an alias for `make` to point to the correct executable.
*  `mingw32.cmd` is a wrapper to call various executables that are part of the 32-bit MinGW64 installation.
*  `mingw64.cmd` is a wrapper to call various executables that are part of the 64-bit MinGW64 installation.

My portable drive contains both MinGW-w64 installations in two subdirectories in `A:\Tools\MinGW-w64\`. 
If you are using different locations, just modify the three cmd-files to match your MinGW-w64 installations.

### The zip-file

The included zip-file contains the compiled versions of `A-ToGo`. Feel free to use the pre-compiled version, or compile your own copy.
