// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"


UMyGameInstance::UMyGameInstance()
{}

void UMyGameInstance::Init()
{
	Super::Init();

	// 객체 생성.
	FStudentData RawDataSource(TEXT("장세윤"), 42);

	// 파일로 다루기 위해 경로 설정.
	// 프로젝트 경로/Saved 경로 지정.
	const FString SavedPath
		= FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));

	// 경로 출력.
	UE_LOG(LogTemp, Log, TEXT("저장할 파일 폴더: %s"), *SavedPath);

	// 직렬화 구간.
	{
		// 저장할 파일 이름.
		const FString RawDataFileName(TEXT("RawData.bin"));

		// 파일 이름을 포함한 최종 경로.
		FString RawDataAbsolutePath 
			= FPaths::Combine(SavedPath, RawDataFileName);

		// 경로 출력 (테스트).
		UE_LOG(
			LogTemp, 
			Log, 
			TEXT("저장할 전체 파일 경로: %s"), 
			*RawDataAbsolutePath
		);

		// 경로 정리.
		FPaths::MakeStandardFilename(RawDataAbsolutePath);

		// 변경된 경로 출력.
		UE_LOG(
			LogTemp,
			Log,
			TEXT("변경된 전체 파일 경로: %s"),
			*RawDataAbsolutePath
		);

		//// 오브젝트 직렬화.
		//// 1. 직렬화 처리를 위한 아카이브 생성.
		//FArchive* RawFileWriteAr 
		//	= IFileManager::Get().CreateFileWriter(*RawDataAbsolutePath);
		//if (RawFileWriteAr)
		//{
		//	//*RawFileWriteAr << RawDataSource.Order;
		//	//*RawFileWriteAr << RawDataSource.Name;
		//
		//	// 2. 아카이브에 오브젝트 직렬화.
		//	*RawFileWriteAr << RawDataSource;
		//
		//	// 파일 닫기.
		//	RawFileWriteAr->Close();
		//
		//	// 사용한 리소스 해제.
		//	delete RawFileWriteAr;
		//	RawFileWriteAr = nullptr;
		//}

		// 역직렬화 구간.
		TUniquePtr<FArchive> RawFileReaderAr(
			IFileManager::Get().CreateFileReader(*RawDataAbsolutePath)
		);

		// 파일로부터 데이터를 복원할 객체.
		FStudentData RawDataDeserialized;
		if (RawFileReaderAr)
		{
			// 역직렬화.
			//*RawFileReaderAr << RawDataDeserialized.Order;
			//*RawFileReaderAr << RawDataDeserialized.Name;
			*RawFileReaderAr << RawDataDeserialized;

			// 파일 닫기.
			RawFileReaderAr->Close();

			// 로드한 데이터 출력.
			UE_LOG(
				LogTemp,
				Log,
				TEXT("[RawData] 이름: %s, 순번: %d"),
				*RawDataDeserialized.Name,
				RawDataDeserialized.Order
			);
		}
	}
}
