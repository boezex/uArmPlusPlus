##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=example
ConfigurationName      :=Debug
WorkspacePath          :=C:/ti-software/uArm_serial_C-
ProjectPath            :=C:/ti-software/uArm_serial_C-/example
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jorn.bunk
Date                   :=25/10/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="example.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)..\src $(IncludeSwitch)..\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/uArm_serial_C-/example/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix): ../src/uArm.cpp $(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/uArm_serial_C-/src/uArm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix): ../src/uArm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix) -MM ../src/uArm.cpp

$(IntermediateDirectory)/up_src_uArm.cpp$(PreprocessSuffix): ../src/uArm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_src_uArm.cpp$(PreprocessSuffix) ../src/uArm.cpp

$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix): ../src/serial.cpp $(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/ti-software/uArm_serial_C-/src/serial.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix): ../src/serial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix) -MM ../src/serial.cpp

$(IntermediateDirectory)/up_src_serial.cpp$(PreprocessSuffix): ../src/serial.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_src_serial.cpp$(PreprocessSuffix) ../src/serial.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


