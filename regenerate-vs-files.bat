echo off

set ProjectName=UnrealJordaka
set ProjectPath="%cd%\%ProjectName%"
set UnrealVSPath="C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe"
set UnrealBTPath="C:\Program Files\Epic Games\UE_5.0\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"

del %ProjectName%.sln
rmdir /s /q .vs
rmdir /s /q Binaries
rmdir /s /q Intermediate
rmdir /s /q DerivedDataCache

echo %ProjectPath%

%UnrealVSPath% /projectfiles %ProjectPath%.uproject
%UnrealBTPath% Development Win64 -Project=%ProjectPath%.uproject -TargetType=Editor -Progress -NoEngineChanges -NoHotReloadFromIDE
rem %ProjectPath%.uproject
rem %ProjectPath%.sln

pause
