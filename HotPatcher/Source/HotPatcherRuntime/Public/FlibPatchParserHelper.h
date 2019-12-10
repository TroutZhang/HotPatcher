// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//project header
#include "FPakFileInfo.h"
#include "AssetManager/FAssetDependenciesInfo.h"
#include "FHotPatcherVersion.h"
#include "FlibPakHelper.h"

// engine header
#include "CoreMinimal.h"
#include "UnrealString.h"
#include "Templates/SharedPointer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FlibPatchParserHelper.generated.h"

/**
 * 
 */
UCLASS()
class HOTPATCHERRUNTIME_API UFlibPatchParserHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static TArray<FString> GetAvailableMaps(FString GameName, bool IncludeEngineMaps, bool Sorted);
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static FString GetProjectName();
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static FString GetUnrealPakBinary();
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static FString GetUE4CmdBinary();

	static FHotPatcherVersion ExportReleaseVersionInfo(const FString& InVersionId,
														const FString& InBaseVersion,
														const FString& InDate,
														const TArray<FString>& InIncludeFilter,
														const TArray<FString>& InIgnoreFilter,
														bool InIncludeHasRefAssetsOnly = false
														);
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool SerializeHotPatcherVersionToString(const FHotPatcherVersion& InVersion, FString& OutResault);
	static bool SerializeHotPatcherVersionToJsonObject(const FHotPatcherVersion& InVersion, TSharedPtr<FJsonObject>& OutJsonObject);
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool DeserializeHotPatcherVersionFromString(const FString& InStringContent, FHotPatcherVersion& OutVersion);
	static bool DeSerializeHotPatcherVersionFromJsonObject(const TSharedPtr<FJsonObject>& InJsonObject, FHotPatcherVersion& OutVersion);


	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool DiffVersion(const FAssetDependenciesInfo& InNewVersion, 
								const FAssetDependenciesInfo& InBaseVersion,
								FAssetDependenciesInfo& OutAddAsset,
								FAssetDependenciesInfo& OutModifyAsset,
								FAssetDependenciesInfo& OutDeleteAsset
		);

	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool SerializePakFileInfoToJsonString(const FPakFileInfo& InFileInfo, FString& OutJson);

		static bool SerializePakFileInfoFromJsonObjectToString(const TSharedPtr<FJsonObject>& InFileInfoJsonObject, FString& OutJson);
		static bool SerializePakFileInfoToJsonObject(const FPakFileInfo& InFileInfo, TSharedPtr<FJsonObject>& OutJsonObject);

		static bool SerializePakFileInfoListToJsonObject(const TArray<FPakFileInfo>& InFileInfoList, TSharedPtr<FJsonObject>& OutJsonObject);
		
		static bool SerializePlatformPakInfoToString(const TMap<FString, FPakFileInfo>& InPakFilesMap, FString& OutString);
		static bool SerializePlatformPakInfoToJsonObject(const TMap<FString, FPakFileInfo>& InPakFilesMap, TSharedPtr<FJsonObject>& OutJsonObject);

	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static FString SerializeDiffInfomationToString(const FAssetDependenciesInfo& InAddAsset,
		 									 const FAssetDependenciesInfo& InModifyAsset,
											 const FAssetDependenciesInfo& InDeleteAsset);

	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool GetPakFileInfo(const FString& InFile,FPakFileInfo& OutFileInfo);

	// return abslute path
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static TArray<FString> SearchCookedGlobalShaderCacheFiles(const FString& InProjectDir,const FString& InPlatformName);
	// return abslute path
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool GetCookedAssetRegistryFile(const FString& InProjectDir, const FString& InProjectName, const FString& InPlatformName,FString& OutFile);
	// return abslute path
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static TArray<FString> SearchProjectIniFiles(const FString& InProjectDir);

	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool ConvProjectIniFilesToCookCommands(const FString& InProjectDir, const FString& InProjectName,const TArray<FString>& InIniFiles, TArray<FString>& OutCommands);
	UFUNCTION(BlueprintCallable, Category = "HotPatcher|Flib")
		static bool ConvNotAssetFileToCookCommand(const FString& InProjectDir,const FString& InPlatformName,const FString& InCookedFile,FString& OutCommand);


	static FString HashStringWithSHA1(const FString &InString);

};
