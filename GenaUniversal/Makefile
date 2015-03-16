PROJECT = GenaUniversal
CPPDEPS = -MT$@ -MF$@.d -MD -MP -std=gnu++11
LIBS = `wx-config --libs core,base` -ldl
WIDGETS_CXXFLAGS = `wx-config --cppflags` -std=gnu++11

SRC_RUNNER = runner_linux.c
RUNNER = runner_linux

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
	$(DIROBJ_DEBUG)/RunCompile.o
PLUGIN_DEBUG = \
	$(DIR_PLUGIN_DEBUG)/libContest_Normal.so \
	$(DIR_PLUGIN_DEBUG)/libPlayer_Normal.so \
	$(DIR_PLUGIN_DEBUG)/libProblem_Normal.so \
	$(DIR_PLUGIN_DEBUG)/libPoint_Normal.so \
	$(DIR_PLUGIN_DEBUG)/libCompare_Normal.so \
	$(DIR_PLUGIN_DEBUG)/libCompare_Normal2.so \
	$(DIR_PLUGIN_DEBUG)/libCompare_Float.so
$(DIR_PLUGIN_DEBUG):
	mkdir -p $@
$(DIR_PLUGIN_DEBUG)/libContest_Normal.so: Contest_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libPlayer_Normal.so: Player_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libProblem_Normal.so: Problem_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libPoint_Normal.so: Point_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libCompare_Normal.so: Compare_Normal.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libCompare_Normal2.so: Compare_Normal2.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g
$(DIR_PLUGIN_DEBUG)/libCompare_Float.so: Compare_Float.cpp $(OBJ_PLUGIN_DEBUG)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -g

BIN_DEBUG = $(DIR_DEBUG)/$(PROJECT)
OBJ_DEBUG = \
	$(DIROBJ_DEBUG)/GenaUniversalApp.o \
	$(DIROBJ_DEBUG)/GenaUniversalMain.o \
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
	$(DIROBJ_DEBUG)/RunCompile.o
$(DIR_DEBUG)/runner:
	mkdir -p $@
$(DIR_DEBUG)/runner/$(RUNNER): $(DIR_DEBUG)/runner $(SRC_RUNNER)
	gcc $(SRC_RUNNER) -o $@ -static -O2
$(DIROBJ_DEBUG)/GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)/GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
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
$(DIROBJ_DEBUG)/Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(DIROBJ_DEBUG)/RunCompile.o: RunCompile.cpp RunCompile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -g
$(BIN_DEBUG): $(OBJ_DEBUG) $(DIR_DEBUG)/runner/$(RUNNER)
	g++ -o $(BIN_DEBUG) $(OBJ_DEBUG) $(LIBS)
$(DIR_DEBUG):
	mkdir -p $@
$(DIROBJ_DEBUG):
	mkdir -p $@
Debug: $(DIR_DEBUG) $(DIROBJ_DEBUG) $(BIN_DEBUG) $(DIR_PLUGIN_DEBUG) $(PLUGIN_DEBUG)
cleanDebug:
	rm -f $(DIROBJ_DEBUG)/*.o
	rm -f $(DIROBJ_DEBUG)/*.d
	rm -f $(DIR_PLUGIN_DEBUG)/*.so

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
	$(DIROBJ_RELEASE)/RunCompile.o
PLUGIN_RELEASE = \
	$(DIR_PLUGIN_RELEASE)/libContest_Normal.so \
	$(DIR_PLUGIN_RELEASE)/libPlayer_Normal.so \
	$(DIR_PLUGIN_RELEASE)/libProblem_Normal.so \
	$(DIR_PLUGIN_RELEASE)/libPoint_Normal.so \
	$(DIR_PLUGIN_RELEASE)/libCompare_Normal.so \
	$(DIR_PLUGIN_RELEASE)/libCompare_Normal2.so \
	$(DIR_PLUGIN_RELEASE)/libCompare_Float.so
$(DIR_PLUGIN_RELEASE):
	mkdir -p $@
$(DIR_PLUGIN_RELEASE)/libContest_Normal.so: Contest_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libPlayer_Normal.so: Player_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libProblem_Normal.so: Problem_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libPoint_Normal.so: Point_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libCompare_Normal.so: Compare_Normal.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libCompare_Normal2.so: Compare_Normal2.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2
$(DIR_PLUGIN_RELEASE)/libCompare_Float.so: Compare_Float.cpp $(OBJ_PLUGIN_RELEASE)
	g++ $< $(OBJ_PLUGIN_DEBUG) -shared -ldl -fPIC -std=gnu++11 -o $@ -ldl -O2

BIN_RELEASE = $(DIR_RELEASE)/$(PROJECT)
OBJ_RELEASE = \
	$(DIROBJ_RELEASE)/GenaUniversalApp.o \
	$(DIROBJ_RELEASE)/GenaUniversalMain.o \
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
	$(DIROBJ_RELEASE)/RunCompile.o
$(DIR_RELEASE)/runner:
	mkdir -p $@
$(DIR_RELEASE)/runner/$(RUNNER): $(DIR_RELEASE)/runner $(SRC_RUNNER)
	gcc $(SRC_RUNNER) -o $@ -static -O2
$(DIROBJ_RELEASE)/GenaUniversalApp.o: GenaUniversalApp.cpp GenaUniversalApp.h
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)/GenaUniversalMain.o: GenaUniversalMain.cpp GenaUniversalMain.h
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
$(DIROBJ_RELEASE)/Library.o: Library.cpp Library.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(DIROBJ_RELEASE)/RunCompile.o: RunCompile.cpp RunCompile.h
	g++ -c -o $@ $(CPPDEPS) -fPIC $< -O2
$(BIN_RELEASE): $(OBJ_RELEASE) $(DIR_RELEASE)/runner/$(RUNNER)
	g++ -o $(BIN_RELEASE) $(OBJ_RELEASE) $(LIBS)
$(DIR_RELEASE):
	mkdir -p $@
$(DIROBJ_RELEASE):
	mkdir -p $@
Release: $(DIR_RELEASE) $(DIROBJ_RELEASE) $(BIN_RELEASE) $(DIR_PLUGIN_RELEASE) $(PLUGIN_RELEASE)
cleanRelease:
	rm -f $(DIROBJ_RELEASE)/*.o
	rm -f $(DIROBJ_RELEASE)/*.d
	rm -f $(DIR_PLUGIN_RELEASE)/*.so

.PHONY: Debug Release cleanDebug cleanRelease
