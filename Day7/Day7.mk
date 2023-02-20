##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Day7
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="C:/Users/Filip U/Documents/CPPCodeLite/AoC"
ProjectPath            :="C:/Users/Filip U/Documents/CPPCodeLite/AoC/Day7"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Day7
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Filip U
Date                   :=20/02/2023
CodeLitePath           :=E:/CodeLite
MakeDirCommand         :=mkdir
LinkerName             :="E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/g++.exe"
SharedObjectLinkerName :="E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/g++.exe" -shared -fPIC
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
OutputDirectory        :=C:/Users/Filip U/Documents/CPPCodeLite/AoC/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :="E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/windres.exe"
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := "E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/ar.exe" rcu
CXX      := "E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/g++.exe"
CC       := "E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/gcc.exe"
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := "E:/MINGW64/x86_64-8.1.0-release-posix-seh-rt_v6-rev0 (1)/mingw64/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=E:\CodeLite
Objects0=$(IntermediateDirectory)/Attempt2.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Attempt2.cpp$(ObjectSuffix): Attempt2.cpp $(IntermediateDirectory)/Attempt2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Filip U/Documents/CPPCodeLite/AoC/Day7/Attempt2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Attempt2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Attempt2.cpp$(DependSuffix): Attempt2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Attempt2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Attempt2.cpp$(DependSuffix) -MM Attempt2.cpp

$(IntermediateDirectory)/Attempt2.cpp$(PreprocessSuffix): Attempt2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Attempt2.cpp$(PreprocessSuffix) Attempt2.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


