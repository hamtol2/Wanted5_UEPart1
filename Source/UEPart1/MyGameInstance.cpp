// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	// 기본값 설정.
	// 생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장됨.
	SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("======================="));

	// 클래스 정보 가져오기.
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();

	// 두 정보가 같은지 비교(어서트 사용).
	//check(ClassRuntime == ClassCompile);
	//ensure(ClassRuntime == ClassCompile);

	UE_LOG(
		LogTemp,
		Log,
		TEXT("학교를 담당하는 클래스 이름: %s"),
		*ClassRuntime->GetName()
	);

	SchoolName = TEXT("포텐업");

	UE_LOG(LogTemp, Log, TEXT("학교 이름: %s"), *SchoolName);

	UE_LOG(
		LogTemp, 
		Log, 
		TEXT("학교 이름 기본 값: %s"), 
		*GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName
	);

	UE_LOG(LogTemp, Log, TEXT("======================="));
}
