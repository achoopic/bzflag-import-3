# Microsoft Developer Studio Project File - Name="obstacle" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=obstacle - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "obstacle.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "obstacle.mak" CFG="obstacle - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "obstacle - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "obstacle - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "obstacle - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\lib\Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\include" /I "..\win32" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../src/obsacle/obstacle.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\src\obstacle\obstacle.lib"

!ELSEIF  "$(CFG)" == "obstacle - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\lib\Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\include" /I "..\win32" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../src/obstacle/obstacle.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\src\obsacle\Debug\obstacle.lib"

!ENDIF 

# Begin Target

# Name "obstacle - Win32 Release"
# Name "obstacle - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\obstacle\BaseBuilding.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\BoxBuilding.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\Intersect.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\Obstacle.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\PyramidBuilding.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\Teleporter.cxx
# End Source File
# Begin Source File

SOURCE=..\src\obstacle\WallObstacle.cxx
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\BaseBuilding.h
# End Source File
# Begin Source File

SOURCE=..\include\BoxBuilding.h
# End Source File
# Begin Source File

SOURCE=..\include\bzfgl.h
# End Source File
# Begin Source File

SOURCE=..\include\bzfio.h
# End Source File
# Begin Source File

SOURCE=..\include\BzfString.h
# End Source File
# Begin Source File

SOURCE=..\include\common.h
# End Source File
# Begin Source File

SOURCE=..\include\Intersect.h
# End Source File
# Begin Source File

SOURCE=..\include\Obstacle.h
# End Source File
# Begin Source File

SOURCE=..\include\OpenGLGState.h
# End Source File
# Begin Source File

SOURCE=..\include\PyramidBuilding.h
# End Source File
# Begin Source File

SOURCE=..\include\QuadWallSceneNode.h
# End Source File
# Begin Source File

SOURCE=..\include\Ray.h
# End Source File
# Begin Source File

SOURCE=..\include\RenderNode.h
# End Source File
# Begin Source File

SOURCE=..\include\SceneNode.h
# End Source File
# Begin Source File

SOURCE=..\include\Teleporter.h
# End Source File
# Begin Source File

SOURCE=..\include\TriWallSceneNode.h
# End Source File
# Begin Source File

SOURCE=..\include\WallObstacle.h
# End Source File
# Begin Source File

SOURCE=..\include\WallSceneNode.h
# End Source File
# End Group
# End Target
# End Project
