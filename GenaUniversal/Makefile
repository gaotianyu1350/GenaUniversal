PROJECT = GenaUniversal
CPPDEPS = -MT$@ -MF$@.d -MD -MP -std=gnu++11
WXINCLUDEDIR = D:/msys64/mingw64/include/wx-3.0
SETUPDIR = D:/msys64/mingw64/lib/wx/include/msw-unicode-3.0
FREETYPEDIR = D:/msys64/mingw64/include/freetype2
LIBS = -pipe -lwx_mswu_core-3.0.dll -lwx_baseu-3.0.dll -lwx_mswu_gl-3.0.dll -lpsapi -lopengl32 -lglu32 -lfreetype -lftgl
WIDGETS_CXXFLAGS = -mthreads -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMSW__ -I$(WXINCLUDEDIR) -I$(SETUPDIR) -I$(FREETYPEDIR) -fpermissive
DLLDEPS = -std=gnu++11 -fPIC -shared -lpsapi

RESOURCE = GenaUniversal.rc

DIR_DEBUG = bin/Debug
DIROBJ_DEBUG = obj/Debug
DIR_PLUGIN_DEBUG = $(DIR_DEBUG)/plugin
OBJ_PLUGIN_DEBUG = \
	$(DIROBJ_DEBUG)/File.o \
	$(DIROBJ_DEBUG)/FileManager.o \
	$(DIROBJ_DEBUG)/TempFile.o \
	$(DIROBJ_DEBUG)/Setting.o \
	$(DIROBJ_DEBUG)/Result.o \
	$(DIROBJ_DEBUG)/sdk.o \
	$(DIROBJ_DEBUG)/Contest.o \
	$(DIROBJ_DEBUG)/Player.o \
	$(DIROBJ_DEBUG)/Problem.o \
	$(DIROBJ_DEBUG)/Point.o \
	$(DIROBJ_DEBUG)/Library.o \
	$(DIROBJ_DEBUG)/Compare.o \
	$(DIROBJ_DEBUG)/Compile.o \
	$(DIROBJ_DEBUG)/RunCmd.o \
	$(DIROBJ_DEBUG)/Runner.o
PLUGIN_DEBUG = \
	$(DIR_PLUGIN_DEBUG)/Contest_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Player_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Problem_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Point_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Compile_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Compare_Normal.dll \
	$(DIR_PLUGIN_DEBUG)/Compare_Normal2.dll \
	$(DIR_PLUGIN_DEBUG)/Compare_Float.dll
$(DIR_PLUGIN_DEBUG):
	mkdir -p $@
$(DIR_PLUGIN_DEBUG)/Contest_Normal.dll: Contest_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Player_Normal.dll: Player_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Problem_Normal.dll: Problem_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Point_Normal.dll: Point_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Compile_Normal.dll: Compile_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Compare_Normal.dll: Compare_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Compare_Normal2.dll: Compare_Normal2.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g
$(DIR_PLUGIN_DEBUG)/Compare_Float.dll: Compare_Float.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) $(DLLDEPS) -o $@ -g

BIN_DEBUG = $(DIR_DEBUG)/$(PROJECT).exe
OBJ_DEBUG = \
	$(DIROBJ_DEBUG)/GenaUniversalApp.o \
	$(DIROBJ_DEBUG)/GenaUniversalMain.o \
	$(DIROBJ_DEBUG)/SettingTreeFrame.o \
	$(DIROBJ_DEBUG)/File.o \
	$(DIROBJ_DEBUG)/FileManager.o \
	$(DIROBJ_DEBUG)/TempFile.o \
	$(DIROBJ_DEBUG)/Setting.o \
	$(DIROBJ_DEBUG)/Result.o \
	$(DIROBJ_DEBUG)/sdk.o \
	$(DIROBJ_DEBUG)/Contest.o \
	$(DIROBJ_DEBUG)/Player.o \
	$(DIROBJ_DEBUG)/Problem.o \
	$(DIROBJ_DEBUG)/Point.o \
	$(DIROBJ_DEBUG)/Compare.o \
	$(DIROBJ_DEBUG)/Compile.o \
	$(DIROBJ_DEBUG)/RunCmd.o \
	$(DIROBJ_DEBUG)/Runner.o
RES_DEBUG = $(DIROBJ_DEBUG)/GenaUniversal.o
$(RES_DEBUG): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH
$(DIROBJ_DEBUG)/GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)/GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)/SettingTreeFrame.o: SettingTreeFrame.cpp SettingTreeFrame.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)/FileManager.o: FileManager.cpp FileManager.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/File.o: File.cpp File.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/TempFile.o: TempFile.cpp TempFile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Setting.o: Setting.cpp Setting.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Result.o: Result.cpp Result.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/sdk.o: sdk.cpp sdk.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Contest.o: Contest.cpp Contest.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Player.o: Player.cpp Player.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Problem.o: Problem.cpp Problem.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Point.o: Point.cpp Point.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Compare.o: Compare.cpp Compare.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Compile.o: Compile.cpp Compile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/RunCmd.o: RunCmd.cpp RunCmd.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/Runner.o: Runner.cpp Runner.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(BIN_DEBUG): $(OBJ_DEBUG) $(RES_DEBUG)
	g++ -o $(BIN_DEBUG) $(OBJ_DEBUG) $(RES_DEBUG) -mthreads $(LIBS)
$(DIR_DEBUG):
	mkdir -p $@
$(DIROBJ_DEBUG):
	mkdir -p $@
Debug: $(DIR_DEBUG) $(DIROBJ_DEBUG) $(BIN_DEBUG) $(DIR_PLUGIN_DEBUG) $(PLUGIN_DEBUG)
cleanDebug:
	rm -f $(DIROBJ_DEBUG)/*.o
	rm -f $(DIROBJ_DEBUG)/*.d
	rm -f $(DIR_PLUGIN_DEBUG)/*.dll

DIR_RELEASE = bin/Release
DIROBJ_RELEASE = obj/Release
DIR_PLUGIN_RELEASE = $(DIR_RELEASE)/plugin
OBJ_PLUGIN_RELEASE = \
	$(DIROBJ_RELEASE)/File.o \
	$(DIROBJ_RELEASE)/FileManager.o \
	$(DIROBJ_RELEASE)/TempFile.o \
	$(DIROBJ_RELEASE)/Setting.o \
	$(DIROBJ_RELEASE)/Result.o \
	$(DIROBJ_RELEASE)/sdk.o \
	$(DIROBJ_RELEASE)/Contest.o \
	$(DIROBJ_RELEASE)/Player.o \
	$(DIROBJ_RELEASE)/Problem.o \
	$(DIROBJ_RELEASE)/Point.o \
	$(DIROBJ_RELEASE)/Library.o \
	$(DIROBJ_RELEASE)/Compare.o \
	$(DIROBJ_RELEASE)/Compile.o \
	$(DIROBJ_RELEASE)/RunCmd.o \
	$(DIROBJ_RELEASE)/Runner.o
PLUGIN_RELEASE = \
	$(DIR_PLUGIN_RELEASE)/Contest_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Player_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Problem_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Point_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Compile_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Compare_Normal.dll \
	$(DIR_PLUGIN_RELEASE)/Compare_Normal2.dll \
	$(DIR_PLUGIN_RELEASE)/Compare_Float.dll
$(DIR_PLUGIN_RELEASE):
	mkdir -p $@
$(DIR_PLUGIN_RELEASE)/Contest_Normal.dll: Contest_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Player_Normal.dll: Player_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Problem_Normal.dll: Problem_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Point_Normal.dll: Point_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Compile_Normal.dll: Compile_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Compare_Normal.dll: Compare_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Compare_Normal2.dll: Compare_Normal2.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2
$(DIR_PLUGIN_RELEASE)/Compare_Float.dll: Compare_Float.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_RELEASE) $(DLLDEPS) -o $@ -O2

BIN_RELEASE = $(DIR_RELEASE)/$(PROJECT).exe
OBJ_RELEASE = \
	$(DIROBJ_RELEASE)/GenaUniversalApp.o \
	$(DIROBJ_RELEASE)/GenaUniversalMain.o \
	$(DIROBJ_RELEASE)/SettingTreeFrame.o \
	$(DIROBJ_RELEASE)/FileManager.o \
	$(DIROBJ_RELEASE)/File.o \
	$(DIROBJ_RELEASE)/TempFile.o \
	$(DIROBJ_RELEASE)/Setting.o \
	$(DIROBJ_RELEASE)/Result.o \
	$(DIROBJ_RELEASE)/sdk.o \
	$(DIROBJ_RELEASE)/Contest.o \
	$(DIROBJ_RELEASE)/Player.o \
	$(DIROBJ_RELEASE)/Problem.o \
	$(DIROBJ_RELEASE)/Point.o \
	$(DIROBJ_RELEASE)/Library.o \
	$(DIROBJ_RELEASE)/Compare.o \
	$(DIROBJ_RELEASE)/Compile.o \
	$(DIROBJ_RELEASE)/RunCmd.o \
	$(DIROBJ_RELEASE)/Runner.o
RES_RELEASE = $(DIROBJ_RELEASE)/GenaUniversal.o
$(RES_RELEASE): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH
$(DIROBJ_RELEASE)/GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)/GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)/SettingTreeFrame.o: SettingTreeFrame.cpp SettingTreeFrame.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)/File.o: File.cpp File.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/FileManager.o: FileManager.cpp FileManager.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/TempFile.o: TempFile.cpp TempFile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Setting.o: Setting.cpp Setting.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Result.o: Result.cpp Result.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/sdk.o: sdk.cpp sdk.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Contest.o: Contest.cpp Contest.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Player.o: Player.cpp Player.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Problem.o: Problem.cpp Problem.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Point.o: Point.cpp Point.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Compare.o: Compare.cpp Compare.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Compile.o: Compile.cpp Compile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/RunCmd.o: RunCmd.cpp RunCmd.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/Runner.o: Runner.cpp Runner.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(BIN_RELEASE): $(OBJ_RELEASE) $(RES_RELEASE)
	g++ -o $(BIN_RELEASE) $(OBJ_RELEASE) $(RES_RELEASE) -mthreads -Wl,--subsystem,windows $(LIBS) -mwindows
$(DIR_RELEASE):
	mkdir -p $@
$(DIROBJ_RELEASE):
	mkdir -p $@
Release: $(DIR_RELEASE) $(DIROBJ_RELEASE) $(BIN_RELEASE) $(DIR_PLUGIN_RELEASE) $(PLUGIN_RELEASE)
cleanRelease:
	rm -f $(DIROBJ_RELEASE)/*.o
	rm -f $(DIROBJ_RELEASE)/*.d
	rm -f $(DIR_PLUGIN_RELEASE)/*.dll

.PHONY: Debug Release cleanDebug cleanRelease
