PROJECT = GenaUniversal
CPPDEPS = -MT$@ -MF$@.d -MD -MP -std=gnu++11
WXDIR = E:\wxWidgets-3.0.2
WXLIBDIR = $(WXDIR)\lib\gcc_lib
WXINCLUDEDIR = $(WXDIR)\include
SETUPDIR = $(WXLIBDIR)\mswu
LIBS = -lwxmsw30u_core -lwxbase30u -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregexu -lwxexpat -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lwininet -lpsapi
DEFINES = -DHAVE_W32API_H -D__WXMSW__ -DNDEBUG -D_UNICODE -DNOPCH
WIDGETS_CXXFLAGS = -mthreads $(DEFINES) -I$(WXINCLUDEDIR) -I$(SETUPDIR) -W -Wno-ctor-dtor-privacy
DLLDEPS = -std=gnu++11 -fPIC -shared -lpsapi

RESOURCE = GenaUniversal.rc

DIR_DEBUG = bin\Debug
DIROBJ_DEBUG = obj\Debug
DIR_PLUGIN_DEBUG = $(DIR_DEBUG)\plugin
OBJ_PLUGIN_DEBUG = \
	$(DIROBJ_DEBUG)\File.o \
	$(DIROBJ_DEBUG)\FileManager.o \
	$(DIROBJ_DEBUG)\TempFile.o \
	$(DIROBJ_DEBUG)\Setting.o \
	$(DIROBJ_DEBUG)\Result.o \
	$(DIROBJ_DEBUG)\sdk.o \
	$(DIROBJ_DEBUG)\Contest.o \
	$(DIROBJ_DEBUG)\Player.o \
	$(DIROBJ_DEBUG)\Problem.o \
	$(DIROBJ_DEBUG)\Point.o \
	$(DIROBJ_DEBUG)\Library.o \
	$(DIROBJ_DEBUG)\Compare.o \
	$(DIROBJ_DEBUG)\RunCompile.o \
	$(DIROBJ_DEBUG)\Runner.o
PLUGIN_DEBUG = \
	$(DIR_PLUGIN_DEBUG)\Contest_Normal.dll \
	$(DIR_PLUGIN_DEBUG)\Player_Normal.dll \
	$(DIR_PLUGIN_DEBUG)\Problem_Normal.dll \
	$(DIR_PLUGIN_DEBUG)\Point_Normal.dll \
	$(DIR_PLUGIN_DEBUG)\Compare_Normal.dll \
	$(DIR_PLUGIN_DEBUG)\Compare_Normal2.dll \
	$(DIR_PLUGIN_DEBUG)\Compare_Float.dll
$(DIR_PLUGIN_DEBUG):
	-if not exist $@ mkdir $@
$(DIR_PLUGIN_DEBUG)\Contest_Normal.dll: Contest_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Player_Normal.dll: Player_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Problem_Normal.dll: Problem_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Point_Normal.dll: Point_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Compare_Normal.dll: Compare_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Compare_Normal2.dll: Compare_Normal2.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)\Compare_Float.dll: Compare_Float.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g

BIN_DEBUG = $(DIR_DEBUG)\$(PROJECT).exe
OBJ_DEBUG = \
	$(DIROBJ_DEBUG)\GenaUniversalApp.o \
	$(DIROBJ_DEBUG)\GenaUniversalMain.o \
	$(DIROBJ_DEBUG)\File.o \
	$(DIROBJ_DEBUG)\FileManager.o \
	$(DIROBJ_DEBUG)\TempFile.o \
	$(DIROBJ_DEBUG)\Setting.o \
	$(DIROBJ_DEBUG)\Result.o \
	$(DIROBJ_DEBUG)\sdk.o \
	$(DIROBJ_DEBUG)\Contest.o \
	$(DIROBJ_DEBUG)\Player.o \
	$(DIROBJ_DEBUG)\Problem.o \
	$(DIROBJ_DEBUG)\Point.o \
	$(DIROBJ_DEBUG)\Compare.o \
	$(DIROBJ_DEBUG)\RunCompile.o \
	$(DIROBJ_DEBUG)\Runner.o
RES_DEBUG = $(DIROBJ_DEBUG)\GenaUniversal.o
$(RES_DEBUG): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH
$(DIROBJ_DEBUG)\GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)\GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)\FileManager.o: FileManager.cpp FileManager.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\File.o: File.cpp File.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\TempFile.o: TempFile.cpp TempFile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Setting.o: Setting.cpp Setting.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Result.o: Result.cpp Result.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\sdk.o: sdk.cpp sdk.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Contest.o: Contest.cpp Contest.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Player.o: Player.cpp Player.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Problem.o: Problem.cpp Problem.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Point.o: Point.cpp Point.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Compare.o: Compare.cpp Compare.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\RunCompile.o: RunCompile.cpp RunCompile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)\Runner.o: Runner.cpp Runner.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(BIN_DEBUG): $(OBJ_DEBUG) $(RES_DEBUG)
	g++ -o $(BIN_DEBUG) $(OBJ_DEBUG) $(RES_DEBUG) -mthreads -L$(WXLIBDIR) $(LIBS) -static
$(DIR_DEBUG):
	-if not exist $@ mkdir $@
$(DIROBJ_DEBUG):
	-if not exist $@ mkdir $@
Debug: $(DIR_DEBUG) $(DIROBJ_DEBUG) $(BIN_DEBUG) $(DIR_PLUGIN_DEBUG) $(PLUGIN_DEBUG)
cleanDebug:
	-if exist $(DIROBJ_DEBUG)\*.o del $(DIROBJ_DEBUG)\*.o
	-if exist $(DIROBJ_DEBUG)\*.d del $(DIROBJ_DEBUG)\*.d
	-if exist $(DIR_PLUGIN_DEBUG)\*.dll del $(DIR_PLUGIN_DEBUG)\*.dll

DIR_RELEASE = bin\Release
DIROBJ_RELEASE = obj\Release
DIR_PLUGIN_RELEASE = $(DIR_RELEASE)\plugin
OBJ_PLUGIN_RELEASE = \
	$(DIROBJ_RELEASE)\File.o \
	$(DIROBJ_RELEASE)\FileManager.o \
	$(DIROBJ_RELEASE)\TempFile.o \
	$(DIROBJ_RELEASE)\Setting.o \
	$(DIROBJ_RELEASE)\Result.o \
	$(DIROBJ_RELEASE)\sdk.o \
	$(DIROBJ_RELEASE)\Contest.o \
	$(DIROBJ_RELEASE)\Player.o \
	$(DIROBJ_RELEASE)\Problem.o \
	$(DIROBJ_RELEASE)\Point.o \
	$(DIROBJ_RELEASE)\Library.o \
	$(DIROBJ_RELEASE)\Compare.o \
	$(DIROBJ_RELEASE)\RunCompile.o \
	$(DIROBJ_RELEASE)\Runner.o
PLUGIN_RELEASE = \
	$(DIR_PLUGIN_RELEASE)\Contest_Normal.dll \
	$(DIR_PLUGIN_RELEASE)\Player_Normal.dll \
	$(DIR_PLUGIN_RELEASE)\Problem_Normal.dll \
	$(DIR_PLUGIN_RELEASE)\Point_Normal.dll \
	$(DIR_PLUGIN_RELEASE)\Compare_Normal.dll \
	$(DIR_PLUGIN_RELEASE)\Compare_Normal2.dll \
	$(DIR_PLUGIN_RELEASE)\Compare_Float.dll
$(DIR_PLUGIN_RELEASE):
	-if not exist $@ mkdir $@
$(DIR_PLUGIN_RELEASE)\Contest_Normal.dll: Contest_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Player_Normal.dll: Player_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Problem_Normal.dll: Problem_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Point_Normal.dll: Point_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Compare_Normal.dll: Compare_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Compare_Normal2.dll: Compare_Normal2.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)\Compare_Float.dll: Compare_Float.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2

BIN_RELEASE = $(DIR_RELEASE)\$(PROJECT).exe
OBJ_RELEASE = \
	$(DIROBJ_RELEASE)\GenaUniversalApp.o \
	$(DIROBJ_RELEASE)\GenaUniversalMain.o \
	$(DIROBJ_RELEASE)\FileManager.o \
	$(DIROBJ_RELEASE)\File.o \
	$(DIROBJ_RELEASE)\TempFile.o \
	$(DIROBJ_RELEASE)\Setting.o \
	$(DIROBJ_RELEASE)\Result.o \
	$(DIROBJ_RELEASE)\sdk.o \
	$(DIROBJ_RELEASE)\Contest.o \
	$(DIROBJ_RELEASE)\Player.o \
	$(DIROBJ_RELEASE)\Problem.o \
	$(DIROBJ_RELEASE)\Point.o \
	$(DIROBJ_RELEASE)\Library.o \
	$(DIROBJ_RELEASE)\Compare.o \
	$(DIROBJ_RELEASE)\RunCompile.o \
	$(DIROBJ_RELEASE)\Runner.o
RES_RELEASE = $(DIROBJ_RELEASE)\GenaUniversal.o
$(RES_RELEASE): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH
$(DIROBJ_RELEASE)\GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)\GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)\File.o: File.cpp File.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\FileManager.o: FileManager.cpp FileManager.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\TempFile.o: TempFile.cpp TempFile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Setting.o: Setting.cpp Setting.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Result.o: Result.cpp Result.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\sdk.o: sdk.cpp sdk.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Contest.o: Contest.cpp Contest.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Player.o: Player.cpp Player.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Problem.o: Problem.cpp Problem.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Point.o: Point.cpp Point.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Compare.o: Compare.cpp Compare.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\RunCompile.o: RunCompile.cpp RunCompile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)\Runner.o: Runner.cpp Runner.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(BIN_RELEASE): $(OBJ_RELEASE) $(RES_RELEASE)
	g++ -o $(BIN_RELEASE) $(OBJ_RELEASE) $(RES_RELEASE) -mthreads -L$(WXLIBDIR) -Wl,--subsystem,windows $(LIBS) -static -mwindows
$(DIR_RELEASE):
	-if not exist $@ mkdir $@
$(DIROBJ_RELEASE):
	-if not exist $@ mkdir $@
Release: $(DIR_RELEASE) $(DIROBJ_RELEASE) $(BIN_RELEASE) $(DIR_PLUGIN_RELEASE) $(PLUGIN_RELEASE)
cleanRelease:
	-if exist $(DIROBJ_RELEASE)\*.o del $(DIROBJ_RELEASE)\*.o
	-if exist $(DIROBJ_RELEASE)\*.d del $(DIROBJ_RELEASE)\*.d
	-if exist $(DIR_PLUGIN_RELEASE)\*.dll del $(DIR_PLUGIN_RELEASE)\*.dll

.PHONY: Debug Release cleanDebug cleanRelease
