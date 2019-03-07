##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=example
ConfigurationName      :=Debug
WorkspacePath          :=/Volumes/Data/Downloads/uArmPlusPlus-master
ProjectPath            :=/Volumes/Data/Downloads/uArmPlusPlus-master/example
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Daan Boezeman
Date                   :=07/03/2019
CodeLitePath           :="/Users/daan/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/Downloads/uArmPlusPlus-master/example/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix): ../src/serial.cpp $(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/Downloads/uArmPlusPlus-master/src/serial.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix): ../src/serial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_src_serial.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_src_serial.cpp$(DependSuffix) -MM ../src/serial.cpp

$(IntermediateDirectory)/up_src_serial.cpp$(PreprocessSuffix): ../src/serial.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_src_serial.cpp$(PreprocessSuffix) ../src/serial.cpp

$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix): ../src/uArm.cpp $(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/Data/Downloads/uArmPlusPlus-master/src/uArm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix): ../src/uArm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_src_uArm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_src_uArm.cpp$(DependSuffix) -MM ../src/uArm.cpp

$(IntermediateDirectory)/up_src_uArm.cpp$(PreprocessSuffix): ../src/uArm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_src_uArm.cpp$(PreprocessSuffix) ../src/uArm.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


